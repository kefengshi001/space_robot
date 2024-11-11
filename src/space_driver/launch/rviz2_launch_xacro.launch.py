import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # URDF 文件的相对路径
    urdf_file = os.path.join(
        get_package_share_directory('space_driver'), 'config/urdf0', 'urdf0initialized.urdf'
    )

    # 读取 URDF 文件内容
    with open(urdf_file, 'r') as infp:
        robot_description_config = infp.read()

    # robot_description_config 以字典形式存储，键为 'robot_description'，值为URDF文件的内容。
    robot_description = {'robot_description': robot_description_config}

    return LaunchDescription([

        # # joint_state_publisher_gui 节点，用于提供 GUI 控制关节角
        # Node(
        #     package='joint_state_publisher_gui',
        #     executable='joint_state_publisher_gui',
        #     output='screen',
        # ),

        # # 创建一个 ROS 2 节点 joint_state_publisher，用于发布机器人关节状态信息---发布tf变化前必须启动
        # Node(
        #     package='joint_state_publisher',
        #     executable='joint_state_publisher',
        #     output='screen'
        # ),

        # 创建一个 ROS 2 节点 robot_state_publisher，用于发布机器人状态信息
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',    # 指定节点的输出类型
            parameters=[robot_description]  # 将机器人描述作为参数传递给节点
        ),

        Node(
            package='rviz2',
            executable='rviz2',
            output='screen',
            # arguments=['-d', os.path.join(get_package_share_directory('space_driver'), 'rviz', 'config.rviz')]
        )
    ])

