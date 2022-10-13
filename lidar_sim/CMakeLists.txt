cmake_minimum_required(VERSION 3.0.2)
project(lidar_sim)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
  tf2
  tf2_ros
)

catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(data_acquire src/data_acquire.cpp)
target_link_libraries(data_acquire ${catkin_LIBRARIES})

add_executable(lidar_avoid src/lidar_avoid.cpp)
target_link_libraries(lidar_avoid ${catkin_LIBRARIES})