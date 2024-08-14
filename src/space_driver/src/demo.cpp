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
  // robotService->runServer("0.0.0.0:30001", true);
  robotService->runServer();

  sleep(5);
  robot_ptr->setJointEnabled(1);
  sleep(3);
  robot_ptr->setJointEnabled(3);
  sleep(3);
  robot_ptr->setJointEnabled(4);
  sleep(3);
  robot_ptr->setJointEnabled(6);
  sleep(3);
  // robot_ptr->setEnabled();
  // sleep(3);

  JntArray q_init(robot.getJointNum());
  q_init(0) = robot_ptr->getJointPosition(0);
  q_init(1) = robot_ptr->getJointPosition(1);
  q_init(2) = robot_ptr->getJointPosition(2);
  q_init(3) = robot_ptr->getJointPosition(3);
  q_init(4) = robot_ptr->getJointPosition(4);
  q_init(5) = robot_ptr->getJointPosition(5);
  q_init(6) = robot_ptr->getJointPosition(6);
  // robot_ptr->MoveJ(q_init, 1, 0.2);

  // sleep(5);
  Frame frame_init = robot_ptr->getFlange();
  Frame frame_end = robot_ptr->getFlange();
  Frame p1 = robot_ptr->getFlange();
  Frame p2 = robot_ptr->getFlange();
  Frame p3 = robot_ptr->getFlange();
  Frame p4 = robot_ptr->getFlange();

  frame_end.p(2) = frame_init.p(2) + 1;
  // robot_ptr->MoveL(frame_end,0.1,0.2);
  // sleep(3);

  p1.p(0) = p1.p(0) + 0.25;
  p1.p(2) = p1.p(2) + 0.25;
  // // robot_ptr->MoveJ_IK(p1,0.1,0.2);

  p2.p(0) = p2.p(0) - 0.25;
  p2.p(2) = p2.p(2) + 0.25;
  // // robot_ptr->MoveJ_IK(p2,0.1,0.2);

  p3.p(0) = p3.p(0) - 0.25;
  p3.p(2) = p3.p(2) - 0.25;
  // // robot_ptr->MoveJ_IK(p3,0.1,0.2);

  p4.p(0) = p4.p(0) + 0.25;
  p4.p(2) = p4.p(2) - 0.25;
  // // robot_ptr->MoveJ_IK(p4,0.1,0.2);

  double speed_t = 0.005;
  double accel_t = 0.01;
  for (int i = 0; i < 3; i++)
  {
    robot_ptr->MoveJ_IK(p1, speed_t, accel_t);
    sleep(2);
    robot_ptr->MoveJ_IK(p2, speed_t, accel_t);
    sleep(2);
    robot_ptr->MoveJ_IK(p3, speed_t, accel_t);
    sleep(2);
    robot_ptr->MoveJ_IK(p4, speed_t, accel_t);
    sleep(2);
    robot_ptr->MoveJ_IK(frame_init, speed_t, accel_t);
    sleep(2);
  }

  robot_ptr->setDisabled();

  return 0;
}
