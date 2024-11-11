#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <memory>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <rocos_app/drive.h>
#include <rocos_app/ethercat/hardware.h>
#include <rocos_app/ethercat/hardware_sim.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <rocos_app/robot.h>
#include <rocos_app/robot_service.h>
#include <string>
#include <gflags/gflags.h>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include "space_interfaces/srv/connection.hpp"
#include "space_interfaces/srv/joint_enable.hpp"
#include "space_interfaces/srv/speed_set.hpp"
#include "space_interfaces/msg/robot_state.hpp"
#include "space_interfaces/srv/multi_axis.hpp"
#include "space_interfaces/srv/joint_jogging.hpp"
#include "space_interfaces/msg/joint_jogging_msg.hpp"
#include "space_interfaces/srv/multi_axis_offset.hpp"
#include "space_interfaces/srv/move_jik.hpp"
#include "space_interfaces/msg/jogging.hpp"
#include <sensor_msgs/msg/joint_state.hpp>
#include "space_interfaces/srv/set_chain.hpp"


class space_driver:public rclcpp::Node
{
    private:
        // static const int _joint_2 = 1;
        // static const int _joint_5 = 4;
        //创建两个回到组
        rclcpp::CallbackGroup::SharedPtr robot_information_callback_group_;
        rclcpp::CallbackGroup::SharedPtr robot_command_callback_group_;

        
        bool connection_status = false;
        double _speed = 0.0;
        // double _accel = 0.01;
        double _accel = 1;

        std::thread jogging_thread;
        std::mutex jogging_mtx;         // 互斥锁,是一个互斥量，用于保护对 stop_jogging 的访问。
        std::condition_variable jogging_cv;     // 条件变量,是一个条件变量，用于通知 jogging_thread 停止循环。jogging_cv 是一个条件变量，用于通知线程停止。
        std::atomic<bool> stop_jogging{false};  // 停止标志，用于通知 jogging_thread 停止循环。

        rocos::Robot *robot_ptr;
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::TimerBase::SharedPtr robot_state_timer_;    // 机器人状态定时器
        rclcpp::TimerBase::SharedPtr joint_state_timer_;    // 关节状态定时器
        rclcpp::Service<space_interfaces::srv::Connection>::SharedPtr start_connect_service;    // 启动连接服务端
        rclcpp::Service<space_interfaces::srv::JointEnable>::SharedPtr set_enable_service;      // 设置使能服务端
        rclcpp::Service<space_interfaces::srv::SpeedSet>::SharedPtr set_speed_service;          // 设置速度服务端
        rclcpp::Publisher<space_interfaces::msg::RobotState>::SharedPtr robot_state_publisher;        // 机器人状态发布
        rclcpp::Service<space_interfaces::srv::MultiAxis>::SharedPtr rocos_movej_service;        // rocos_movej服务端
        rclcpp::Service<space_interfaces::srv::MultiAxisOffset>::SharedPtr rocos_movej_offset_service;  // 启动rocos_movej_offset服务端
        rclcpp::Service<space_interfaces::srv::JointJogging>::SharedPtr joint_jogging_service;  // 关节 jog服务端
        rclcpp::Subscription<space_interfaces::msg::Jogging>::SharedPtr Jogging_sub;  // 关节 jog订阅

        rclcpp::Service<space_interfaces::srv::MoveJIK>::SharedPtr movej_ik_service;    // movejik服务端
        rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_publisher;   // 发布关节状态
        rclcpp::Service<space_interfaces::srv::SetChain>::SharedPtr set_chain_service;  // 设置运动链路服务端
        std::shared_ptr<rclcpp::SyncParametersClient> param_client_;    // 参数客户端-用于修改robot_state_publisher节点中robot_description参数

   

        void start_connect_callback(const std::shared_ptr<space_interfaces::srv::Connection::Request> request, std::shared_ptr<space_interfaces::srv::Connection::Response> response);
        void timer_callback();     // 定时器回调函数，判断连接状态，启动其余服务端等
        void robot_state_timer_callback();
        void joint_state_timer_callback();  // 发布关节状态
        void set_enable_callback(const std::shared_ptr<space_interfaces::srv::JointEnable::Request> request, std::shared_ptr<space_interfaces::srv::JointEnable::Response> response);
        void set_speed_callback(const std::shared_ptr<space_interfaces::srv::SpeedSet::Request> request, std::shared_ptr<space_interfaces::srv::SpeedSet::Response> response);
        void rocos_movej_callback(const std::shared_ptr<space_interfaces::srv::MultiAxis::Request> request,std::shared_ptr<space_interfaces::srv::MultiAxis::Response> response);
        void rocos_movej_offset_callback(const std::shared_ptr<space_interfaces::srv::MultiAxisOffset::Request> request,std::shared_ptr<space_interfaces::srv::MultiAxisOffset::Response> response);
        void movej_ik_callback(const std::shared_ptr<space_interfaces::srv::MoveJIK::Request> request,std::shared_ptr<space_interfaces::srv::MoveJIK::Response> response);
        // void joint_jogging_ser_callback(const std::shared_ptr<space_interfaces::srv::JointJogging::Request> request,std::shared_ptr<space_interfaces::srv::JointJogging::Response> response);
        void Jogging_sub_callback(const space_interfaces::msg::Jogging::SharedPtr msg);
        void Set_chain_callback(const std::shared_ptr<space_interfaces::srv::SetChain::Request> request,std::shared_ptr<space_interfaces::srv::SetChain::Response> response);
    
        void set_rviz2_robot_description(int urdf_id);
        bool check_isEnable_before_move();  //运动前使能检查
        void robot_description_updater();   // 更新robot_description参数
    public:
        space_driver(rocos::Robot *robot_ptr);
        ~space_driver();
        double pi = 3.1415926535;
        void Start_connect();   // 启动连接
        void Pub_robot_state(); // 发布机器人状态
        void Pub_joint_state(); // 发布关节状态
        void Set_enable();      // 设置使能
        void Set_speed();       // 设置速度
        void RocosMoveJ();      // 关节空间移动
        void RocosMoveJOffset();// 关节空间移动偏移
        void RocosMoveJIK();    // 关节空间移动（输入笛卡尔空间位姿）
        // void JointJoggingSer();    // 关节 jogging
        void Jogging();    // 关节 jogging
        void Set_chain();


        


};



