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
#include <unistd.h>

using namespace rocos;
using namespace std::chrono_literals;
using namespace KDL;
// DEFINE_string(urdf, "robot.urdf", "Urdf file path");
// DEFINE_string(urdf, "robot_white.urdf", "Urdf file path");
DEFINE_string(urdf, "/home/landau/Documents/GitHub/space_robot/src/space_driver/config/urdf0/urdf0modified.urdf", "Urdf file path");
DEFINE_string(base, "base_link", "Base link name");
DEFINE_string(tip, "link_7", "Tip link name");
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

  double speed_t = 1;
  double accel_t = 1;
  double length = 0.25;
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


  // 移动到初始位置
  check_input(count);
  JntArray q(robot.getJointNum());
  q(0) = 0;
  // q(1) = 10 * KDL::deg2rad;
  q(1) = 0 * KDL::deg2rad;
  q(2) = 0;
  q(3) = -110 * KDL::deg2rad;
  q(4) = 30  * KDL::deg2rad;
  q(5) = 0;
  q(6) = 0 * KDL::deg2rad;
  robot_ptr->MoveJ(q, speed_t, accel_t);
 

  //测试movej_ik
  check_input(count);
  Frame p1 = robot_ptr->getFlange();
  p1.p(0) = p1.p(0) + length;
  p1.p(2) = p1.p(2) + length;
  robot_ptr->MoveJ_IK(p1, speed_t, accel_t);

  JntArray q1(robot.getJointNum());
  q1(0) = robot_ptr->getJointPosition(0);
  q1(1) = robot_ptr->getJointPosition(1);
  q1(2) = robot_ptr->getJointPosition(2);
  q1(3) = robot_ptr->getJointPosition(3);
  q1(4) = robot_ptr->getJointPosition(4);
  q1(5) = robot_ptr->getJointPosition(5);
  q1(6) = robot_ptr->getJointPosition(6);
   // sleep(5);
  
  //测试movel_fk
  check_input(count);
  robot_ptr->MoveJ(q, speed_t, accel_t);
  robot_ptr->MoveL_FK(q1, speed_t, accel_t);

  //测试movel
  check_input(count);
  robot_ptr->MoveJ(q, speed_t, accel_t);
  p1 = robot_ptr->getFlange();
  Frame p2 = p1;
  Frame p3 = p1;
  Frame p4 = p1;
  
  p2.p(0) = p2.p(0) - length;
  p2.p(2) = p2.p(2) + length;
  // // robot_ptr->MoveJ_IK(p2,0.1,0.2);

  p3.p(0) = p3.p(0) - length;
  p3.p(2) = p3.p(2) - length;
  // // robot_ptr->MoveJ_IK(p3,0.1,0.2);

  p4.p(0) = p4.p(0) + length;
  p4.p(2) = p4.p(2) - length;

  for (int i = 0; i < 5; i++)
  {
    robot_ptr->MoveJ(q, speed_t, accel_t);
    robot_ptr->MoveL(p1, 0.1, 0.1);
    sleep(2);
    robot_ptr->MoveJ(q, speed_t, accel_t);
    robot_ptr->MoveL(p2, 0.1, 0.1);
    sleep(2);
    robot_ptr->MoveJ(q, speed_t, accel_t);
    robot_ptr->MoveL(p3, 0.1, 0.1);
    sleep(2);
    robot_ptr->MoveJ(q, speed_t, accel_t);
    robot_ptr->MoveL(p4, 0.1, 0.1);
    sleep(2);
  }
  

  ////直线movel
  // Frame frame_end = robot_ptr->getFlange();
  // frame_end.p(2) = frame_init.p(0) + 0.1;
  // robot_ptr->MoveL(frame_end,speed_t, accel_t);


  // sleep(3);
  // Frame p1 = robot_ptr->getFlange();


  

  // // robot_ptr->MoveJ_IK(p1,0.1,0.2);


  return 0;
}



