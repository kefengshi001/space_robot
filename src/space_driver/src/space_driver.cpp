#include "space_driver.h"
#include <string>
using namespace std::chrono_literals;
using namespace KDL;
space_driver::space_driver(rocos::Robot *robot_ptr) : rclcpp::Node("space_driver"), robot_ptr(robot_ptr) ,
        robot_information_callback_group_(this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive)),
        robot_command_callback_group_(this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive))// 初始化robot_ptr成员变量
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
        // JointJoggingSer();
        Jogging();
        RocosMoveJOffset();
        RocosMoveJIK();
        Pub_joint_state();
        Set_chain();
        robot_description_updater();

        // 取消定时器
        this->timer_->cancel();
    }
    else
    {
        RCLCPP_INFO(this->get_logger(), "等待连接！！！");
    }
}

void space_driver::Pub_robot_state()
{
    // 创建一个发布者，发布机器人状态

    this->robot_state_publisher = this->create_publisher<space_interfaces::msg::RobotState>("robot_state", 10);
    this->robot_state_timer_ = this->create_wall_timer(
        100ms, std::bind(&space_driver::robot_state_timer_callback, this),robot_information_callback_group_);
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

void space_driver::Pub_joint_state()
{
    // 创建一个发布者，发布关节状态
    this->joint_state_publisher = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    this->joint_state_timer_ = this->create_wall_timer(
        100ms, std::bind(&space_driver::joint_state_timer_callback, this),
        this->robot_information_callback_group_);
        RCLCPP_INFO(this->get_logger(), "关节状态发布者启动");
}

void space_driver::joint_state_timer_callback()
{
 
    auto joint_state_msg = sensor_msgs::msg::JointState();
    if (!robot_ptr)
    {
        RCLCPP_ERROR(this->get_logger(), "robot_ptr 未初始化");
        return;
    }

    joint_state_msg.header.stamp = this->get_clock()->now();

    if (robot_ptr->getUrdfState() == 1) // urdf1
    {
        for (int i = 0; i < 7; i++)
        {
            joint_state_msg.name.push_back("joint" + std::to_string(i + 1));
            joint_state_msg.position.push_back((robot_ptr->getJointPosition(6 - i)));

            joint_state_msg.velocity.push_back((robot_ptr->getJointVelocity(6 - i)));
        }
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            joint_state_msg.name.push_back("joint" + std::to_string(i + 1));
            joint_state_msg.position.push_back((robot_ptr->getJointPosition(i)));

            joint_state_msg.velocity.push_back((robot_ptr->getJointVelocity(i)));
        }
    }

    joint_state_publisher->publish(joint_state_msg);


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
    // this->_speed = request->speed * 0.01 * 0.01 * 5;
    this->_speed = request->speed * 0.01  * 0.1 * 5;

    RCLCPP_INFO(this->get_logger(), "速度设置成功,大小为 %f m/s | rad/s", this->_speed);
    response->success = true;
}



void space_driver::RocosMoveJ()
{
    this->rocos_movej_service = this->create_service<space_interfaces::srv::MultiAxis>("multi_axis",
                                                                                       std::bind(&space_driver::rocos_movej_callback, this, std::placeholders::_1, std::placeholders::_2),
                                                                                       rmw_qos_profile_services_default,
                                                                                       this->robot_command_callback_group_);
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

    // if (this->_speed > 0.1)
    // {
    //     response->success = false;
    //     response->message = "关节角速度过大";
    //     // RCLCPP_INFO(this->get_logger(), "关节角速度过大，请重新赋值");
    //     return;
    // }

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
    if (robot_ptr->getUrdfState() == 0)
    {
        q(0) = robot_ptr->getJointPosition(0);
        q(6) = request->goalangle[6] * pi / 180.0;
    }
    else if (robot_ptr->getUrdfState() == 1)
    {
       q(0) =request->goalangle[0] * pi / 180.0;
       q(6) = robot_ptr->getJointPosition(6);
    }
    else
    {
        throw std::runtime_error("urdf_state error");
    }
    
    
    
    
    q(1) = request->goalangle[1] * pi / 180.0;
    // q(1) = robot_ptr->getJointPosition(1);
    // q(2) = request->goalangle[2] * pi / 180.0;
    q(2) = robot_ptr->getJointPosition(2);
    q(3) = request->goalangle[3] * pi / 180.0;
    q(4) = request->goalangle[4] * pi / 180.0;
    // q(5) = request->goalangle[5] * pi / 180.0;
    q(5) = robot_ptr->getJointPosition(5);
    
    RCLCPP_INFO(this->get_logger(), "MoveJ执行开始");
    robot_ptr->MoveJ(q, this->_speed, this->_accel);
    // usleep(10000000);
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

    // if (this->_speed > 0.1)
    // {
    //     response->success = false;
    //     response->message = "关节角速度过大";
    //     // RCLCPP_INFO(this->get_logger(), "关节角速度过大，请重新赋值");
    //     return;
    // }

    if (this->_speed == 0)
    {
        response->success = false;
        response->message = "关节角速度为0,请设置速度";
        // RCLCPP_INFO(this->get_logger(), "关节角速度为0，请设置速度");
        return;
    }

    KDL::JntArray q(7);

    if (robot_ptr->getUrdfState() == 0)
    {
        q(0) = robot_ptr->getJointPosition(0);
        q(6) = request->offsetangle[6] * pi / 180.0 + robot_ptr->getJointPosition(6);
    }
    else if (robot_ptr->getUrdfState() == 1)
    {
        q(0) = request->offsetangle[0] * pi / 180.0 + robot_ptr->getJointPosition(0);
        q(6) = robot_ptr->getJointPosition(6);
    }
    else
    {
        throw std::runtime_error("urdf_state error");
    }

    // q(0) = robot_ptr->getJointPosition(0);
    q(2) = robot_ptr->getJointPosition(2);
    q(5) = robot_ptr->getJointPosition(5);

    q(1) = robot_ptr->getJointPosition(1) + request->offsetangle[1] * pi / 180.0;
    q(3) = robot_ptr->getJointPosition(3) + request->offsetangle[3] * pi / 180.0;
    q(4) = robot_ptr->getJointPosition(4) + request->offsetangle[4] * pi / 180.0;
    // q(6) = robot_ptr->getJointPosition(6) + request->offsetangle[6] * pi / 180.0;

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

    // if (this->_speed > 0.1)
    // {
    //     response->success = false;
    //     response->message = "关节角速度过大";
    //     // RCLCPP_INFO(this->get_logger(), "关节角速度过大，请重新赋值");
    //     return;
    // }

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
    // robot_ptr->MoveJ_IK(init_frame, this->_speed, this->_accel);
    robot_ptr->MoveJ_IK(init_frame, this->_speed, this->_accel);

   
    RCLCPP_INFO(this->get_logger(), "MoveJIK执行结束");
    response->success = true;
    response->message = "MoveJIK执行结束";


}

// void space_driver::JointJoggingSer()
// {
//     this->joint_jogging_service = this->create_service<space_interfaces::srv::JointJogging>("joint_jogging",
//                                                                                             std::bind(&space_driver::joint_jogging_ser_callback, this, std::placeholders::_1, std::placeholders::_2));
//     RCLCPP_INFO(this->get_logger(), "关节 jog 服务端启动...");
// }

// void space_driver::joint_jogging_ser_callback(const std::shared_ptr<space_interfaces::srv::JointJogging::Request> request,
//                                               std::shared_ptr<space_interfaces::srv::JointJogging::Response> response)
// {
//     RCLCPP_INFO(this->get_logger(), "收到关节 jog 服务请求");

//     std::string joint = request->joint;
//     int _id = joint[(joint.size() - 1)] - '1';
//     // 使能检查
//     if (!(robot_ptr->isEnabled()))
//     {
//         RCLCPP_INFO(this->get_logger(), "机器人未使能，请先使能机器人");
//         return;
//     }

//     // 停止并等待之前的线程
//     {
//         std::unique_lock<std::mutex> lock(jogging_mtx);
//         stop_jogging = true;
//     }
//     jogging_cv.notify_all();
//     if (jogging_thread.joinable())
//     {
//         jogging_thread.join();
//     }

//     // 启动新线程
//     stop_jogging = false;
//     jogging_thread = std::thread([this, request, _id]()
//                                  {
//         while (!stop_jogging && request->run)
//         {
//             // 执行jogging操作
//             // robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(_id),
//             //                     static_cast<rocos::Robot::DRAGGING_DIRRECTION>(request->signal),
//             //                     this->_speed, 0.01);
                  
//             robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(0),
//                                             static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
//                                             _speed,_accel);
                
//             // 延时1ms
//             // std::this_thread::sleep_for(std::chrono::milliseconds(1));
//             RCLCPP_INFO(this->get_logger(), "关节 jog 执行中");
//         }
//         RCLCPP_INFO(this->get_logger(), "关节 jog 执行结束"); });

//     response->success = true;
// }

void space_driver::Jogging()
{
    this->Jogging_sub = this->create_subscription<space_interfaces::msg::Jogging>("Jogging", 100, std::bind(&space_driver::Jogging_sub_callback, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "订阅关节 jog");
}

void space_driver::Jogging_sub_callback(const space_interfaces::msg::Jogging::SharedPtr msg)
{
    if (msg->run)
    {
        if (msg->flags >=0 && msg->flags <=6)
        {
            //单关节使能检查
            if (robot_ptr->isJointEnabled(msg->flags) == false)
            {
                RCLCPP_INFO(this->get_logger(), "关节 %d 未使能", msg->flags + 1);
                return;
            }
            RCLCPP_INFO(this->get_logger(), "进入关节空间点动");

            if (msg->signal == true)
            {
                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 + 执行中");
            }
            else
            {

                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(-1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 - 执行中");
            }
        }
        else if (msg->flags >=100 && msg->flags <=105)
        {
            // 活动关节序号列表
            int arr[] = {1, 3, 4, 6};
            for (int val : arr)
            {
                // 关节使能检查
                if (robot_ptr->isJointEnabled(val) == false)
                {
                    RCLCPP_INFO(this->get_logger(), "关节 %d 未使能", val + 1);
                    return;
                } 
            }

            RCLCPP_INFO(this->get_logger(), "进入工具坐标系空间点动");

            if (msg->signal == true)
            {
                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 + 执行中");
            }
            else
            {

                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(-1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 - 执行中");
            }
            
        }
        else if (msg->flags >=200 && msg->flags <=205)
        {
            // 活动关节序号列表
            int arr[] = {1, 3, 4, 6};
            for (int val : arr)
            {
                // 关节使能检查
                if (robot_ptr->isJointEnabled(val) == false)
                {
                    RCLCPP_INFO(this->get_logger(), "关节 %d 未使能", val + 1);
                    return;
                } 
            }

            RCLCPP_INFO(this->get_logger(), "进入法兰坐标系空间点动");

            if (msg->signal == true)
            {
                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 + 执行中");
            }
            else
            {

                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(-1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 - 执行中");
            }
            
        }
        else if (msg->flags >=400 && msg->flags <=405)
        {
            // 活动关节序号列表
            int arr[] = {1, 3, 4, 6};
            for (int val : arr)
            {
                // 关节使能检查
                if (robot_ptr->isJointEnabled(val) == false)
                {
                    RCLCPP_INFO(this->get_logger(), "关节 %d 未使能", val + 1);
                    return;
                } 
            }

            RCLCPP_INFO(this->get_logger(), "进入基座坐标系空间点动");

            if (msg->signal == true)
            {
                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 + 执行中");
            }
            else
            {

                robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(msg->flags),
                                    static_cast<rocos::Robot::DRAGGING_DIRRECTION>(-1),
                                    this->_speed, this->_accel);
                // RCLCPP_INFO(this->get_logger(), "关节 - 执行中");
            }
            
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "未识别的flags");
            return;
        }
       

        
    }
    else
    {
        // 打印消息
        RCLCPP_INFO(this->get_logger(), "run信号为false");
        return;
    }
    
    // std::string joint = msg->joint;
    // int _id = joint[(joint.size() - 1)] - '1';

    // // 单关节使能检查
    // if (robot_ptr->isJointEnabled(_id) == false)
    // {
    //     RCLCPP_INFO(this->get_logger(), "关节 %d 未使能", _id + 1);
    //     return;
    // }

    // if (msg->run == true)
    // {
    //     if (msg->signal == true)
    //     {
    //         robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(_id),
    //                             static_cast<rocos::Robot::DRAGGING_DIRRECTION>(1),
    //                             this->_speed, this->_accel);
    //         // RCLCPP_INFO(this->get_logger(), "关节 + 执行中");
    //     }
    //     else
    //     {

    //         robot_ptr->Dragging(static_cast<rocos::Robot::DRAGGING_FLAG>(_id),
    //                             static_cast<rocos::Robot::DRAGGING_DIRRECTION>(-1),
    //                             this->_speed, this->_accel);
    //         // RCLCPP_INFO(this->get_logger(), "关节 - 执行中");
    //     }
    // }
    // else
    // {
    //     RCLCPP_INFO(this->get_logger(), "run 为false，结束运行！");
    //     return;
    // }
}

void space_driver::Set_chain()
{   
    //创建一个服务端用于设置运动链
    this->set_chain_service = this->create_service<space_interfaces::srv::SetChain>("setchain",
        std::bind(&space_driver::Set_chain_callback, this, std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "设置运动链服务端已启动");   
}

void space_driver::Set_chain_callback(const std::shared_ptr<space_interfaces::srv::SetChain::Request> request,
                                       std::shared_ptr<space_interfaces::srv::SetChain::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Received request with urdf_id=%d, adapter_status=%s", request->urdf_id, request->adapter_status ? "true" : "false");
    
    if (robot_ptr->getUrdfState() == -1 || request->adapter_status == true) //第一次设置运动链或adapter_status为true
    {
        //初始设置运动链
        if (request->urdf_id == 0)
        {
            if(robot_ptr->setKinematics(0) == 0)
            {
                set_rviz2_robot_description(0);
                response->success = true;
                RCLCPP_INFO(this->get_logger(), "Set Kinematics and Robot Description for URDF ID 0 successfully");
            }   
            else
            {
                response->success = false;
                RCLCPP_WARN(this->get_logger(), "Failed to set Kinematics for URDF ID 0");
            }
        }
        else if (request->urdf_id == 1)
        {
            if(robot_ptr->setKinematics(1) == 0)
            {
                set_rviz2_robot_description(1);
                response->success = true;
                RCLCPP_INFO(this->get_logger(), "Set Kinematics and Robot Description for URDF ID 1 successfully");
            }
            else
            {
                response->success = false;
                RCLCPP_WARN(this->get_logger(), "Failed to set Kinematics for URDF ID 1");
            }
        }  
        else
        {
            response->success = false;
            RCLCPP_WARN(this->get_logger(), "Invalid URDF ID: %d", request->urdf_id);
        }
    }
    else
    {
        response->success = false;
        RCLCPP_WARN(this->get_logger(), "Conditions not met to set URDF: getUrdfState()=%d, adapter_status=%s",
                    robot_ptr->getUrdfState(), request->adapter_status ? "true" : "false");
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

void space_driver::robot_description_updater()
{
    // 创建一个参数客户端
    this->param_client_ = std::make_shared<rclcpp::SyncParametersClient>(this, "/robot_state_publisher");

    // // 等待服务可用，只在初始化时调用一次
    //     if (!param_client_->wait_for_service(std::chrono::seconds(5))) {
    //         RCLCPP_ERROR(this->get_logger(), "Parameter server not available.");
    //     }
}


void space_driver::set_rviz2_robot_description(int urdf_id)
{
    std::string urdf0_path = "src/space_driver/config/urdf0/urdf0.urdf";
    std::string urdf1_path = "src/space_driver/config/urdf1/urdf1.urdf";
    std::string selected_urdf_path;
    // std::string urdf_str = this->declare_parameter("robot_description", std::string(""));
    std::string urdf_str;

    // 根据传入的urdf_id选择正确的URDF文件路径
    if (urdf_id == 0)
    {
        selected_urdf_path = urdf0_path;
    }
    else if (urdf_id == 1)
    {
        selected_urdf_path = urdf1_path;
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Invalid URDF ID: %d. Please use 0 or 1.", urdf_id);
        return;
    }

    // 尝试打开URDF文件
    std::ifstream urdf_file(selected_urdf_path);
    if (!urdf_file.is_open())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to open URDF file: %s", selected_urdf_path.c_str());
        return;
    }

   
    // 读取文件内容并存储为字符串
    urdf_str = std::string((std::istreambuf_iterator<char>(urdf_file)),
                           std::istreambuf_iterator<char>());

    // 检查是否成功读取内容
    if (urdf_str.empty())
    {
        RCLCPP_ERROR(this->get_logger(), "URDF file is empty: %s", selected_urdf_path.c_str());
        return;
    }

    // 设置robot_state_publisher中的robot_description参数以便在RViz2中使用
    // 如果未声明 robot_description 参数，则声明它
    try {
            // 设置新的robot_description参数值
            param_client_->set_parameters({rclcpp::Parameter("robot_description", urdf_str)});
            RCLCPP_INFO(this->get_logger(), "Successfully updated robot_description parameter.");
        } catch (const std::exception &e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to set parameter: %s", e.what());
        }


    
    RCLCPP_INFO(this->get_logger(), "Robot description parameter set from %s", selected_urdf_path.c_str());
    return;
}






