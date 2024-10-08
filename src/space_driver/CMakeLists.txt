cmake_minimum_required(VERSION 3.5)
project(space_driver)

list(APPEND CMAKE_PREFIX_PATH /opt/rocos/app)
list(APPEND CMAKE_PREFIX_PATH /opt/grpc)
include_directories(/opt/grpc/include)
include_directories(include)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rocos_app REQUIRED)
find_package(Eigen3 REQUIRED)
add_subdirectory(3rdparty/gflags)
find_package(space_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(main src/main.cpp src/space_driver.cpp)
target_link_libraries(main  ${catkin_LIBRARIES} rocos::hardware rocos::kinematics rocos::drive rocos::protocol rocos::robot  Eigen3::Eigen gflags::gflags)
ament_target_dependencies(main rclcpp std_msgs space_interfaces)


add_executable(demo src/demo.cpp)
target_link_libraries(demo  ${catkin_LIBRARIES} rocos::hardware rocos::kinematics rocos::drive rocos::protocol rocos::robot  Eigen3::Eigen gflags::gflags)
ament_target_dependencies(demo rclcpp std_msgs)
# target_include_directories(main PUBLIC
#   ${catkin_LIBRARIES}  rocos::hardware rocos::kinematics rocos::drive rocos::protocol rocos::robot  Eigen3::Eigen gflags::gflags
#   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#   $<INSTALL_INTERFACE:include>)

install(TARGETS main demo
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
