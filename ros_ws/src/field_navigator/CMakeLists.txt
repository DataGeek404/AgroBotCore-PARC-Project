cmake_minimum_required(VERSION 3.8)
project(field_navigator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -std=c++17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(navigator_node src/navigator_node.cpp)

ament_target_dependencies(navigator_node
  rclcpp
  geometry_msgs
  nav_msgs
  sensor_msgs
)

install(TARGETS navigator_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
