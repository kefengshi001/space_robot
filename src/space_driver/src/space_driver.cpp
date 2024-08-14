#include "space_driver.h"
#include <string>
using namespace std::chrono_literals;
using namespace KDL;
space_driver::space_driver(rocos::Robot *robot_ptr) : rclcpp::Node("space_driver"), robot_ptr(robot_ptr) // 初始化robot_ptr成员变量
{
    RCLCPP_INFO(this->get_logger(), "启动space_driver节点");

    Start_connect();

    // 创建一个定时器，每秒钟检查一次连接状态
    this->timer_ = this->create_wall_timer(
        1000ms, std::bind(&space_driver::timer_callback, this));
}

space_driver::~space_driver()
{
    // 停止并等待线程结束
    {
        std::unique_lock<std::mutex> lock(jogging_mtx);
        stop_jogging = true;
    }
    jogging_cv.notify_all();
    if (jogging_thread.joinable())
    {
        jogging_thread.join();
    }
    RCLCPP_INFO(this->get_logger(), "space_driver节点关闭");
    RCLCPP_INFO(this->get_logger(), "space_driver节点关闭");
}

void space_driver::Start_connect()
{
    // 创建一个ros2服务端，等待客户端连接请求
    this->start_connect_service = this->create_service<space_interfaces::srv::Connection>("connection_service",
                                                                                          std::bind(&space_driver::start_connect_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "等待连接请求...");
}

void space_driver::start_connect_callback(const std::shared_ptr<space_interfaces::srv::Connection::Request> request,
                                          std::shared_ptr<space_interfaces::srv::Connection::Response> response)
{
    if (request->connect)
    {
        RCLCPP_INFO(this->get_logger(), "收到连接请求");
        this->connection_status = true;

        response->success = true;
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "断开连接");
        this->connection_status = false;
    }
}

void space_driver::timer_callback()
{
    // RCLCPP_INFO(this->get_logger(), "等待连接！！！");
    if (this->connection_status)
    {
        Set_enable();
        Set_speed();
        Pub_robot_state();
        RocosMoveJ();
        JointJoggingSer();
        JointJoggingSub();
        RocosMoveJOffset();
        RocosMoveJIK();

        // 取消定时器
        this->timer_->cancel();
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "等待连接！！！");
    }
}

void space_driver::Set_enable()
{
    // 创建一个ros2服务端，等待客户端使能
    this->set_enable_service = this->create_service<space_interfaces::srv::JointEnable>("joint_enable",
                                                                                        std::bind(&space_driver::set_enable_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "等待设置关节使能服务端启动...");
}

void space_driver::set_enable_callback(const std::shared_ptr<space_interfaces::srv::JointEnable::Request> request,
                                       std::shared_ptr<space_interfaces::srv::JointEnable::Response> response)
{
    std::string joint_id = request->joint;
    int enable_id = joint_id[(joint_id.size() - 1)] - '1';

    RCLCPP_INFO(this->get_logger(), "enable_id: %d", enable_id);
    // RCLCPP_INFO(this->get_logger(),"关节数量为：%d",robot_ptr->getJointNum());
    if (-1 > enable_id || enable_id > (robot_ptr->getJointNum()) - 1)
    {
        RCLCPP_INFO(this->get_logger(), "关节输入有误,请重新输入");
        return;
    }

    if (-1 < enable_id && enable_id < (robot_ptr->getJointNum()) && request->data == true)
    {

        robot_ptr->setJointEnabled(enable_id);
        response->message = "enable successed";
        response->success = true;
    }
    else
    {
        robot_ptr->setJointDisabled(enable_id);
        response->message = "disable successed";
        response->success = true;
        RCLCPP_INFO(this->get_logger(), "关节%s关闭使能成功", request->joint.c_str());
    }
}

void space_driver::Set_speed()
{
    this->set_speed_service = this->create_service<space_interfaces::srv::SpeedSet>("speed_set",
                                                                                    std::bind(&space_driver::set_speed_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "设置速度服务端启动...");
}

void space_driver::set_speed_callback(const std::shared_ptr<space_interfaces::srv::SpeedSet::Request> request,
                                      std::shared_ptr<space_interfaces::srv::SpeedSet::Response> response)
{
    this->_speed = request->speed * 0.01 * 0.01 * 5;
    RCLCPP_INFO(this->get_logger(), "速度设置成功,大小为 %f m/s | rad/s", this->_speed);
    response->success = true;
}

void space_driver::Pub_robot_state()
{
    // 创建一个发布者，发布机器人状态

    this->robot_state_publisher = this->create_publisher<space_interfaces::msg::RobotState>("robot_state", 10);
    this->robot_state_timer_ = this->create_wall_timer(
        100ms, std::bind(&space_driver::robot_state_timer_callback, this));
    RCLCPP_INFO(this->get_logger(), "机器人状态发布者启动");
}

void space_driver::robot_state_timer_callback()
{
    auto robot_state_msg = space_interfaces::msg::RobotState();

    if (!robot_ptr)
    {
        RCLCPP_ERROR(this->get_logger(), "robot_ptr 未初始化");
        return;
    }

    robot_state_msg.jointposition = {static_cast<float>(robot_ptr->getJointPosition(0) * 180.0 / pi),
                                     static_cast<float>(robot_ptr->getJointPosition(1) * 180.0 / pi),
                                     static_cast<float>(robot_ptr->getJointPosition(2) * 180.0 / pi),
                                     static_cast<float>(robot_ptr->getJointPosition(3) * 180.0 / pi),
                                     static_cast<float>(robot_ptr->getJointPosition(4) * 180.0 / pi),
                                     static_cast<float>(robot_ptr->getJointPosition(5) * 180.0 / pi),
                                     static_cast<float>(robot_ptr->getJointPosition(6) * 180.0 / pi)};

    KDL::Vector p = (robot_ptr->getFlange()).p;
    robot_state_msg.position.x = p[0];
    robot_state_msg.position.y = p[1];
    robot_state_msg.position.z = p[2];

    KDL::Rotation M = (robot_ptr->getFlange()).M;
    M.GetQuaternion(robot_state_msg.orientation.x, robot_state_msg.orientation.y, robot_state_msg.orientation.z, robot_state_msg.orientation.w);

    robot_state_publisher->publish(robot_state_msg);
    // RCLCPP_INFO(this->get_logger(), "机器人状态发布成功");
}

void space_driver::RocosMoveJ()
{
    this->rocos_movej_service = this->create_service<space_interfaces::srv::MultiAxis>("multi_axis",
                                                                                       std::bind(&space_driver::rocos_movej_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "RocosMoveJ服务端启动...");
}

void space_driver::rocos_movej_callback(const std::shared_ptr<space_interfaces::srv::MultiAxis::Request> request,
                                        std::shared_ptr<space_interfaces::srv::MultiAxis::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "收到RocosMoveJ服务请求");

    // if (request->goalangle.size() != 4)
    // {
    //     RCLCPP_INFO(this->get_logger(), "输入关节角数量有误,请重新输入");
    //     return;
    // }

    // if (!(this->check_isEnable_before_move()))
    // {
    //     response->success = false;
    //     response->message = "机器人未正确使能";
    //     return;
    // }

    if (this->_speed > 0.1)
    {
        response->success = false;
        response->message = "关节角速度过大";
        // RCLCPP_INFO(this->get_logger(), "关节角速度过大，请重新赋值");
        return;
    }

    if (this->_speed == 0)
    {
        response->success = false;
        response->message = "关节角速度为0,请设置速度";
        // RCLCPP_INFO(this->get_logger(), "关节角速度为0，请设置速度");
        return;
    }

    // 调用MoveJ函数
    // robot_ptr -> setEnabled();
    // 延时1ms
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    KDL::JntArray q(7);
    // 当前机械臂的3和6关节没法运动
    // q(0) = request->goalangle[0] * pi / 180.0;
    q(0) = robot_ptr->getJointPosition(0);
    q(1) = request->goalangle[1] * pi / 180.0;
    // q(1) = robot_ptr->getJointPosition(1);
    // q(2) = request->goalangle[2] * pi / 180.0;
    q(2) = robot_ptr->getJointPosition(2);
    q(3) = request->goalangle[3] * pi / 180.0;
    q(4) = request->goalangle[4] * pi / 180.0;
    // q(5) = request->goalangle[5] * pi / 180.0;
    q(5) = robot_ptr->getJointPosition(5);
    q(6) = request->goalangle[6] * pi / 180.0;
    RCLCPP_INFO(this->get_logger(), "MoveJ执行开始");
    robot_ptr->MoveJ(q, this->_speed, this->_accel);
    RCLCPP_INFO(this->get_logger(), "MoveJ执行结束");
    response->success = true;
    response->message = "MoveJ执行结束";
    // RCLCPP_INFO()
}

void space_driver::RocosMoveJOffset()
{
    this->rocos_movej_offset_service = this->create_service<space_interfaces::srv::MultiAxisOffset>("multi_axis_offset",
                                                                                                    std::bind(&space_driver::rocos_movej_offset_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "RocosMoveJOffset服务端启动...");
}

void space_driver::rocos_movej_offset_callback(const std::shared_ptr<space_interfaces::srv::MultiAxisOffset::Request> request,
                                               std::shared_ptr<space_interfaces::srv::MultiAxisOffset::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "收到RocosMoveJOffset服务请求");

    if (this->_speed > 0.1)
    {
        response->success = false;
        response->message = "关节角速度过大";
        // RCLCPP_INFO(this->get_logger(), "关节角速度过大，请重新赋值");
        return;
    }

    if (this->_speed == 0)
    {
        response->success = false;
        response->message = "关节角速度为0,请设置速度";
        // RCLCPP_INFO(this->get_logger(), "关节角速度为0，请设置速度");
        return;
    }

    KDL::JntArray q(7);
    q(0) = robot_ptr->getJointPosition(0);
    q(2) = robot_ptr->getJointPosition(2);
    q(5) = robot_ptr->getJointPosition(5);

    q(1) = robot_ptr->getJointPosition(1) + request->offsetangle[1] * pi / 180.0;
    q(3) = robot_ptr->getJointPosition(3) + request->offsetangle[3] * pi / 180.0;
    q(4) = robot_ptr->getJointPosition(4) + request->offsetangle[4] * pi / 180.0;
    q(6) = robot_ptr->getJointPosition(6) + request->offsetangle[6] * pi / 180.0;

    RCLCPP_INFO(this->get_logger(), "MoveJOffset执行开始");
    robot_ptr->MoveJ(q, this->_speed, this->_accel);
    RCLCPP_INFO(this->get_logger(), "MoveJOffset执行结束");
    response->success = true;
    response->message = "MoveJOffset执行结束";
}

void space_driver::RocosMoveJIK()
{
    this->movej_ik_service = this->create_service<space_interfaces::srv::MoveJIK>("movej_ik",
                                                                                  std::bind(&space_driver::movej_ik_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "RocosMoveJIK服务端启动...");
}

void space_driver::movej_ik_callback(const std::shared_ptr<space_interfaces::srv::MoveJIK::Request> request,
                                     std::shared_ptr<space_interfaces::srv::MoveJIK::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "收到MoveJIK服务请求");

    if (this->_speed > 0.1)
    {
        response->success = false;
        response->message = "关节角速度过大";
        // RCLCPP_INFO(this->get_logger(), "关节角速度过大，请重新赋值");
        return;
    }

    if (this->_speed == 0)
    {
        response->success = false;
        response->message = "关节角速度为0,请设置速度";
        // RCLCPP_INFO(this->get_logger(), "关节角速度为0，请设置速度");
        return;
    }

    KDL::Frame init_frame = robot_ptr->getFlange();

    // 当前机器人只在平面运动，故限制y方向和姿态的值
    init_frame.p(0) = request->goalposition.x; // 修改x
    // init_frame.p(1) = request->goalposition.y  //修改y
    init_frame.p(2) = request->goalposition.z; // 修改z
    // init_frame.M = KDL::Rotation::RPY(request->goalposition[3], request->goalposition[4], request->goalposition[5]);

    RCLCPP_INFO(this->get_logger(), "MoveJIK执行开始");
    robot_ptr->MoveJ_IK(init_frame, this->_speed, this->_accel);
    RCLCPP_INFO(this->get_logger(), "MoveJIK执行结束");
    response->success = true;
    response->message = "MoveJIK执行结束";


}

void space_driver::JointJoggingSer()
{
    this->joint_jogging_service = this->create_service<space_interfaces::srv::JointJogging>("joint_jogging",
                                                                                            std::bind(&space_driver::joint_jogging_ser_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "关节 jog 服务端启动...");
}

void space_driver::joint_jogging_ser_callback(const std::shared_ptr<space_interfaces::srv::JointJogging::Request> request,
                                              std::shared_ptr<space_interfaces::srv::JointJogging::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "收到关节 jog 服务请求");

    std::string joint = request->joint;
    int _id = joint[(joint.size() - 1)] - '1';
    // 使能检查
    if (!(robot_ptr->isEnabled()))
    {
        RCLCPP_INFO(this->get_logger(), "机器人未使能，请先使能机器人");
        return;
    }

    // 停止并等待之前的线程
    {
        std::unique_lock<std::mutex> lock(jogging_mtx);
        stop_jogging = true;
    }
    jogging_cv.notify_all();
    if (jogging_thread.joinable())
    {
        jogging_thread.join();
    }

    // 启动新线程
    stop_jogging = false;
    jogging_thread = std::thread([this, request, _id]()
                                 {
        while (!stop_jogging && request->run)
        {
            // 执行jogging操作
            // robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(_id),
            //                     static_cast<rocos::Robot::DRAGGING_DIRRECTION>(request->signal),
            //                     this->_speed, 0.01);
                  
            robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(0),
                                            static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
                                            0.01,0.01);
                
            // 延时1ms
            // std::this_thread::sleep_for(std::chrono::milliseconds(1));
            RCLCPP_INFO(this->get_logger(), "关节 jog 执行中");
        }
        RCLCPP_INFO(this->get_logger(), "关节 jog 执行结束"); });

    response->success = true;
}

void space_driver::JointJoggingSub()
{
    this->joint_jogging_sub = this->create_subscription<space_interfaces::msg::JointJoggingMsg>("joint_jogging", 100, std::bind(&space_driver::joint_jogging_sub_callback, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "订阅关节 jog");
}

void space_driver::joint_jogging_sub_callback(const space_interfaces::msg::JointJoggingMsg::SharedPtr msg)
{

    std::string joint = msg->joint;
    int _id = joint[(joint.size() - 1)] - '1';

    // 单关节使能检查
    if (robot_ptr->isJointEnabled(_id) == false)
    {
        RCLCPP_INFO(this->get_logger(), "关节 %d 未使能", _id + 1);
        return;
    }

    if (msg->run == true)
    {
        if (msg->signal == true)
        {
            robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(_id),
                                static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
                                this->_speed, 0.01);
            // RCLCPP_INFO(this->get_logger(), "关节 + 执行中");
        }
        else
        {

            robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(_id),
                                static_cast<rocos::Robot::DRAGGING_DIRRECTION>(-1),
                                this->_speed, 0.01);
            // RCLCPP_INFO(this->get_logger(), "关节 - 执行中");
        }
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "run 为false，结束运行！");
        return;
    }
}

bool space_driver::check_isEnable_before_move()
{
    for (int i = 0; i < 7; i++)
    {
        if (i == 0 || i == 1 || i == 2 || i == 5)
        {
            if (robot_ptr->isJointEnabled(i) == true)
            {
                RCLCPP_INFO(this->get_logger(), "joint%d使能,请先关闭使能", i + 1);
                return false;
            }
        }
        else
        {
            if (robot_ptr->isJointEnabled(i) == false)
            {
                RCLCPP_INFO(this->get_logger(), "joint%d未使能,请使能", i + 1);
                return false;
            }
        }
    }
    return true;
}