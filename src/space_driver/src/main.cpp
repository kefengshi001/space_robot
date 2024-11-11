#include <rclcpp/rclcpp.hpp>
#include "space_driver.h"

using namespace rocos;
using namespace std::chrono_literals;
using namespace KDL;

DEFINE_string(urdf, "/home/landau/Documents/GitHub/space_robot/src/space_driver/config/urdf0/urdf0initialized.urdf", "Urdf file path");
DEFINE_string(base, "base_link", "Base link name");
DEFINE_string(tip, "Link7", "Tip link name");
DEFINE_bool(sim, true, "Sim or not");
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

  void printJntArray(const KDL::JntArray &q_out)
  {
    std::cout << "JntArray:" << std::endl;
    for (unsigned int i = 0; i < q_out.rows(); ++i)
    {
      std::cout << "q[" << i << "] = " << q_out(i) << std::endl;
    }
  }

  void printEndEffectorPose(const KDL::Frame &p_out)
  {
    // 打印末端执行器的位置
    std::cout << "End effector position: "
              << p_out.p.x() << " "
              << p_out.p.y() << " "
              << p_out.p.z() << std::endl;

    // 打印末端执行器的旋转矩阵
    std::cout << "End effector rotation: " << std::endl;
    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        std::cout << p_out.M(i, j) << " ";
      }
      std::cout << std::endl;
    }
  }
}

int main(int argc, char *argv[])
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

  // 初始化 ROS 2
  rclcpp::init(argc, argv);

  // 创建节点
  auto node = std::make_shared<space_driver>(robot_ptr);

  // 使用 MultiThreadedExecutor 来允许多个回调并行处理
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);

  // 运行 executor（阻塞）
  executor.spin();

  // 关闭 ROS 2
  rclcpp::shutdown();
  return 0;
  

  // // 初始化ROS 2
  // rclcpp::init(argc, argv);

  // // 运行节点（阻塞）
  // rclcpp::spin(std::make_shared<space_driver>(robot_ptr));

  // // 关闭ROS 2
  // rclcpp::shutdown();

  // return 0;
}
