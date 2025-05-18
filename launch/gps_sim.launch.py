# launch/gps_sim.launch.py  
from launch import LaunchDescription  
from launch_ros.actions import Node  

def generate_launch_description():  
    return LaunchDescription([  
        Node(  
            package='agrobot_gps',  
            executable='gps_node',  
            name='gps_processor',  
            parameters=['config/gps_params.yaml']  
        )  
    ])  