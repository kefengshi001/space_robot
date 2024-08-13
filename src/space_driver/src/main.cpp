// #include <rclcpp/rclcpp.hpp>
#include "space_driver.h" 

using namespace rocos;
using namespace std::chrono_literals;
using namespace KDL;
// DEFINE_string(urdf, "robot.urdf", "Urdf file path");
DEFINE_string(urdf, "robot_white.urdf", "Urdf file path");
DEFINE_string(base, "base_link", "Base link name");
DEFINE_string(tip, "link_7", "Tip link name");
DEFINE_bool(sim, true , "Sim or not");
DEFINE_int32(id, 0, "hardware id, only work for real hardware");
bool isRuning = true;

rocos::Robot *robot_ptr = nullptr;

namespace rocos
{
  void signalHandler(int signo)
  {
    if (signo == SIGINT)
    {
      std::cout << "\033[1;31m"
                << "[!!SIGNAL!!]"
                << "INTERRUPT by CTRL-C"
                << "\033[0m" << std::endl;

      isRuning = false;

      robot_ptr->setDisabled();
      // robot.setDisabled();

      exit(0);
    }
  }
}

int main(int argc, char * argv[])
{
    if (signal(SIGINT, signalHandler) == SIG_ERR)
    {
        std::cout << "\033[1;31m"
                << "Can not catch SIGINT"
                << "\033[0m" << std::endl;
    }
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    HardwareInterface *hw;
    if (FLAGS_sim)
        hw = new HardwareSim(20); // 仿真
    else
        hw = new Hardware(FLAGS_urdf, FLAGS_id); // 真实机械臂

    Robot robot(hw, FLAGS_urdf, FLAGS_base, FLAGS_tip);
    robot_ptr = &robot;

    auto robotService = RobotServiceImpl::getInstance(&robot);
    robotService->runServer("0.0.0.0:30001", true);
    // 初始化ROS 2
    rclcpp::init(argc, argv);
 
    // 运行节点（阻塞）
    rclcpp::spin(std::make_shared<space_driver>(robot_ptr));

    // 关闭ROS 2
    rclcpp::shutdown();

    return 0;
}
