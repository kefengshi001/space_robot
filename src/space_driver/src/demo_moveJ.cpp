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

void Rotation_to_Quertation(Rotation R)
{
  double a = -1, b = -1, c = -1, d = -1;
  R.GetQuaternion(a, b, c, d);
  std::cout << a << " " << b << " " << c << " " << d << std::endl;
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

  // sleep(3);
  // robot_ptr->setJointEnabled(1);
  sleep(3);
  robot_ptr->setJointEnabled(3);
  sleep(3);
  robot_ptr->setJointEnabled(4);
  sleep(3);
  robot_ptr->setJointEnabled(6);
  sleep(3);

  // 移动到初始位置
  // check_input(count);
  JntArray q_init(robot.getJointNum());
  q_init(0) = 0;
  q_init(1) = 0 * KDL::deg2rad;
  q_init(2) = 0;
  q_init(3) = -100 * KDL::deg2rad;
  q_init(4) = 30 * KDL::deg2rad;
  q_init(5) = 0;
  q_init(6) = 0 * KDL::deg2rad;
  // robot_ptr->MoveJ(q_init, speed_t, accel_t);
  // check_input(count);

  JntArray q1(robot.getJointNum());
  q1(0) = 0;
  q1(1) = 0 * KDL::deg2rad;
  q1(2) = 0;
  q1(3) = -90 * KDL::deg2rad;
  q1(4) = 40 * KDL::deg2rad;
  q1(5) = 0;
  q1(6) = 0 * KDL::deg2rad;

  JntArray q2(robot.getJointNum());
  q2(0) = 0;
  q2(1) = 0 * KDL::deg2rad;
  q2(2) = 0;
  q2(3) = -90 * KDL::deg2rad;
  q2(4) = 20 * KDL::deg2rad;
  q2(5) = 0;
  q2(6) = 0 * KDL::deg2rad;

  JntArray q3(robot.getJointNum());
  q3(0) = 0;
  q3(1) = 0 * KDL::deg2rad;
  q3(2) = 0;
  q3(3) = -110 * KDL::deg2rad;
  q3(4) = 40 * KDL::deg2rad;
  q3(5) = 0;
  q3(6) = 0 * KDL::deg2rad;

  JntArray q4(robot.getJointNum());
  q4(0) = 0;
  q4(1) = 0 * KDL::deg2rad;
  q4(2) = 0;
  q4(3) = -110 * KDL::deg2rad;
  q4(4) = 20 * KDL::deg2rad;
  q4(5) = 0;
  q4(6) = 0 * KDL::deg2rad;

  JntArray q_max = q_init;
  q_max(3) = -80 * KDL::deg2rad;
  check_input(count);
  robot_ptr->MoveJ(q_max, speed_t, accel_t);

  // check_input(count);
  // robot_ptr->MoveJ(q_init, speed_t, accel_t);
  // // sleep(2);
  // check_input(count);
  // robot_ptr->MoveJ(q1, speed_t, accel_t);
  // // sleep(2);
  // check_input(count);
  // robot_ptr->MoveJ(q4, speed_t, accel_t);
  // // sleep(2);
  // check_input(count);
  // robot_ptr->MoveJ(q2, speed_t, accel_t);
  // // sleep(2);
  // check_input(count);
  // robot_ptr->MoveJ(q3, speed_t, accel_t);

  // check_input(count);
  int point_num = 0;
  for (int i = 0; i < 35; i++)
  {
    // check_input(count);
    // robot_ptr->MoveJ(q_max, speed_t, accel_t);
    // check_input(count)check_input(count);;
    std::cout<<"当前运行至第 "<<++point_num<<" 点"<<std::endl;
    robot_ptr->MoveJ(q_init, speed_t, accel_t);
    sleep(10);
    // Frame p1 = robot_ptr->getFlange();
    
    // check_input(count);
    // robot_ptr->MoveJ(q_max, speed_t, accel_t);
    // check_input(count);
    std::cout<<"当前运行至第 "<<++point_num<<" 点"<<std::endl;
    robot_ptr->MoveJ(q1, speed_t, accel_t);
    sleep(10);

    // Frame p2 = robot_ptr->getFlange();
    
    // check_input(count);
    // robot_ptr->MoveJ(q_max, speed_t, accel_t);
    // check_input(count);
    std::cout<<"当前运行至第 "<<++point_num<<" 点"<<std::endl;
    robot_ptr->MoveJ(q4, speed_t, accel_t);
    sleep(10);

    // Frame p3 = robot_ptr->getFlange();
    
    // check_input(count);
    // robot_ptr->MoveJ(q_max, speed_t, accel_t);
    // check_input(count);
    std::cout<<"当前运行至第 "<<++point_num<<" 点"<<std::endl;
    robot_ptr->MoveJ(q2, speed_t, accel_t);
    sleep(10);

    // Frame p4 = robot_ptr->getFlange();
    
    // check_input(count);
    // robot_ptr->MoveJ(q_max, speed_t, accel_t);
    // check_input(count);
    std::cout<<"当前运行至第 "<<++point_num<<" 点"<<std::endl;
    robot_ptr->MoveJ(q3, speed_t, accel_t);
    sleep(10);

    // Frame p5 = robot_ptr->getFlange();
    // Rotation_to_Quertation(p1.M);
    // Rotation_to_Quertation(p2.M);
    // Rotation_to_Quertation(p3.M);
    // Rotation_to_Quertation(p4.M);
    // Rotation_to_Quertation(p5.M);
  }

  robot_ptr->setDisabled();

  return 0;
}
