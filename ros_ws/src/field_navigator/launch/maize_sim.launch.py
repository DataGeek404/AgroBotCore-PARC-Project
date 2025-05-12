from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        ExecuteProcess(
            cmd=['gazebo', '--verbose', '/home/vscode/ros_ws/worlds/maize_field.world', '-s', 'libgazebo_ros_factory.so'],
            output='screen'
        ),
        Node(
            package='field_navigator',
            executable='navigator_node',
            output='screen'
        )
    ])
