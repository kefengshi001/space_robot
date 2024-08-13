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





class space_driver:public rclcpp::Node
{
    private:
        // static const int _joint_2 = 1;
        // static const int _joint_5 = 4;
        bool connection_status = false;
        double _speed = 0.0;
        std::thread jogging_thread;
        std::mutex jogging_mtx;         // 互斥锁,是一个互斥量，用于保护对 stop_jogging 的访问。
        std::condition_variable jogging_cv;     // 条件变量,是一个条件变量，用于通知 jogging_thread 停止循环。jogging_cv 是一个条件变量，用于通知线程停止。
        std::atomic<bool> stop_jogging{false};  // 停止标志，用于通知 jogging_thread 停止循环。

        rocos::Robot *robot_ptr;
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::TimerBase::SharedPtr robot_state_timer_;    // 机器人状态定时器
        rclcpp::Service<space_interfaces::srv::Connection>::SharedPtr start_connect_service;    // 启动连接服务端
        rclcpp::Service<space_interfaces::srv::JointEnable>::SharedPtr set_enable_service;      // 设置使能服务端
        rclcpp::Service<space_interfaces::srv::SpeedSet>::SharedPtr set_speed_service;          // 设置速度服务端
        rclcpp::Publisher<space_interfaces::msg::RobotState>::SharedPtr robot_state_publisher;        // 机器人状态发布
        rclcpp::Service<space_interfaces::srv::MultiAxis>::SharedPtr rocos_movej_service;        // 启动rocos_movej服务端
        rclcpp::Service<space_interfaces::srv::MultiAxisOffset>::SharedPtr rocos_movej_offset_service;  // 启动rocos_movej_offset服务端
        rclcpp::Service<space_interfaces::srv::JointJogging>::SharedPtr joint_jogging_service;  // 启动关节 jog服务端
        rclcpp::Subscription<space_interfaces::msg::JointJoggingMsg>::SharedPtr joint_jogging_sub;  // 关节 jog订阅
   

        void start_connect_callback(const std::shared_ptr<space_interfaces::srv::Connection::Request> request, std::shared_ptr<space_interfaces::srv::Connection::Response> response);
        void timer_callback();     // 定时器回调函数，判断连接状态，启动其余服务端等
        void set_enable_callback(const std::shared_ptr<space_interfaces::srv::JointEnable::Request> request, std::shared_ptr<space_interfaces::srv::JointEnable::Response> response);
        void set_speed_callback(const std::shared_ptr<space_interfaces::srv::SpeedSet::Request> request, std::shared_ptr<space_interfaces::srv::SpeedSet::Response> response);
        void robot_state_timer_callback();
        void rocos_movej_callback(const std::shared_ptr<space_interfaces::srv::MultiAxis::Request> request,std::shared_ptr<space_interfaces::srv::MultiAxis::Response> response);
        void rocos_movej_offset_callback(const std::shared_ptr<space_interfaces::srv::MultiAxisOffset::Request> request,std::shared_ptr<space_interfaces::srv::MultiAxisOffset::Response> response);
        void joint_jogging_ser_callback(const std::shared_ptr<space_interfaces::srv::JointJogging::Request> request,std::shared_ptr<space_interfaces::srv::JointJogging::Response> response);
        void joint_jogging_sub_callback(const space_interfaces::msg::JointJoggingMsg::SharedPtr msg);

        bool check_isEnable_before_move();  //运动前使能检查
    public:
        space_driver(rocos::Robot *robot_ptr);
        ~space_driver();
        double pi = 3.1415926535;
        void Start_connect();   // 启动连接
        void Set_enable();      // 设置使能
        void Set_speed();       // 设置速度
        void Pub_robot_state(); // 发布机器人状态
        void RocosMoveJ();      // 关节空间移动
        void RocosMoveJOffset();// 关节空间移动偏移
        void JointJoggingSer();    // 关节 jogging
        void JointJoggingSub();    // 关节 jogging
        


};



