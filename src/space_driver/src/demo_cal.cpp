#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <rocos_app/drive.h>
#include <rocos_app/ethercat/hardware.h>
#include <rocos_app/ethercat/hardware_sim.h>
#include <rocos_app/robot.h>
#include <rocos_app/robot_service.h>
#include <gflags/gflags.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace rocos;
using namespace std::chrono_literals;
using namespace KDL;
// DEFINE_string(urdf, "robot.urdf", "Urdf file path");
// DEFINE_string(urdf, "robot_white.urdf", "Urdf file path");
DEFINE_string(urdf, "/home/landau/Documents/GitHub/space_robot/src/space_driver/config/urdf0_24_09_01/urdf0_base_4.urdf", "Urdf file path");
DEFINE_string(base, "base_link", "Base link name");
DEFINE_string(tip, "Link7", "Tip link name");
DEFINE_bool(sim, false, "Sim or not");
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

void check_input(int &count)
{
  std::string input;
  std::cout << "请输入y来移动到第 " << count << " 个位置..." << std::endl;
  std::getline(std::cin, input);
  while (input != "y")
  {
    std::cout << "输入有误，请重新输入y..." << std::endl;
    std::getline(std::cin, input);
  }
  count++;
}

int main(int argc, char *argv[])
{

  double speed_t = 0.025;
  double accel_t = 0.025;
  // double speed_t = 1;
  // double accel_t = 1;
  int count = 1;

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
  // robotService->runServer();

  sleep(3);
  robot_ptr->setJointEnabled(3);
  sleep(3);
  robot_ptr->setJointEnabled(4);
  sleep(3);
  robot_ptr->setJointEnabled(6);
  sleep(3);

  // 移动到初始位置
  JntArray q_init(robot.getJointNum());
  q_init(0) = 0;
  q_init(1) = 0 * KDL::deg2rad;
  q_init(2) = 0;
  q_init(3) = -100 * KDL::deg2rad;
  q_init(4) = 30 * KDL::deg2rad;
  q_init(5) = 0;
  q_init(6) = 0 * KDL::deg2rad;
  robot_ptr->MoveJ(q_init, speed_t, accel_t);

  // // 打开CSV文件
  // std::ifstream file("/home/landau/Documents/GitHub/space_robot/src/space_driver/src/jointvalue.csv");
  // if (!file.is_open())
  // {
  //   std::cerr << "无法打开文件！" << std::endl;
  //   return -1;
  // }

  // std::string line;

  // // 逐行读取CSV文件
  // while (std::getline(file, line))
  // {
  //   std::stringstream ss(line);
  //   std::string first_value;
  //   std::string second_value;

  //   std::getline(ss, first_value, ',');
  //   // q_init(3) = std::stod(first_value);
  //   std::getline(ss, second_value);
  //   // q_init(4) = std::stod(second_value);
  //   q_init(3) = std::stod(first_value);
  //   q_init(4) = std::stod(second_value);

  //   // 输出读取的值以检查
  //   std::cout << "Row " << ": q_init(3) = "
  //             << q_init(3) << " rad, q_init(4) = "
  //             << q_init(4) << " rad" << std::endl;

  //   // check_input(count);
  //   // robot_ptr->MoveJ(q_init, speed_t, accel_t);

  //   // // 打印笛卡尔空间坐标
  //   // Frame tmp = robot_ptr->getFlange();
  //   // Vector tmp_pos =  tmp.p;
  //   // Rotation tmp_rot = tmp.M;
  //   // double roll, pitch, yaw;
  //   // tmp_rot.GetRPY(roll, pitch, yaw);
  //   // std::cout<<tmp_pos[0]<<","<<tmp_pos[1]<<","<<tmp_pos[2]<<","<<roll<<","<<pitch<<","<<yaw<<std::endl;
  // }

  JntArray q_max = q_init;
  q_max(3) = -1.29626;

  q_init(3) = -1.71123;
  q_init(4) = 0.51243;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.85496;
  q_init(4) = 0.35872;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.89067;
  q_init(4) = 0.47685;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.73214;
  q_init(4) = 0.63924;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.80345;
  q_init(4) = 0.58123;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.76982;
  q_init(4) = 0.44657;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.71475;
  q_init(4) = 0.52019;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.82034;
  q_init(4) = 0.66432;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.78542;
  q_init(4) = 0.38761;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.79912;
  q_init(4) = 0.45794;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.87129;
  q_init(4) = 0.62514;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.75487;
  q_init(4) = 0.49832;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.70234;
  q_init(4) = 0.55948;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.88261;
  q_init(4) = 0.47109;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.76432;
  q_init(4) = 0.63725;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.81847;
  q_init(4) = 0.41986;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.74209;
  q_init(4) = 0.54871;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.84971;
  q_init(4) = 0.66283;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.76540;
  q_init(4) = 0.53762;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.83124;
  q_init(4) = 0.48294;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.71028;
  q_init(4) = 0.36042;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.86745;
  q_init(4) = 0.52361;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.74356;
  q_init(4) = 0.59478;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.77321;
  q_init(4) = 0.41025;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.80563;
  q_init(4) = 0.60634;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.79485;
  q_init(4) = 0.57218;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.82902;
  q_init(4) = 0.39973;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.78215;
  q_init(4) = 0.65924;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.84473;
  q_init(4) = 0.52917;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.76783;
  q_init(4) = 0.46785;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.71183;
  q_init(4) = 0.45327;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.87509;
  q_init(4) = 0.64981;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.70321;
  q_init(4) = 0.37456;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.84672;
  q_init(4) = 0.58791;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.71127;
  q_init(4) = 0.41875;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.69341;
  q_init(4) = 0.66132;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.78956;
  q_init(4) = 0.50024;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.76589;
  q_init(4) = 0.35588;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.84915;
  q_init(4) = 0.63245;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);
  q_init(3) = -1.68154;
  q_init(4) = 0.57107;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);
  robot_ptr->MoveJ(q_init, speed_t, accel_t);

  robot_ptr->setDisabled();

  return 0;
}
