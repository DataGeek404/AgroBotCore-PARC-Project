#!/bin/bash

set -e

echo "[SIM] Building workspace (if not already built)..."
cd ros_ws
colcon build --symlink-install || true

echo "[SIM] Sourcing ROS 2 workspace..."
source /opt/ros/humble/setup.bash
source install/setup.bash

echo "[SIM] Launching simulation..."
ros2 launch simple_robot simulation.launch.py
