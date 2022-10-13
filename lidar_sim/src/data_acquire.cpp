#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void lidarCallback(const sensor_msgs::LaserScan& msgs) {
  float frontDistance = msgs.ranges[180];
  ROS_INFO("Front distance: %f m.", frontDistance);
}

int main(int argc, char** argv) {
  setlocale(LC_ALL, "");  // For Chinese

  ros::init(argc, argv, "lidar_node");
  ros::NodeHandle nh;

  ros::Subscriber lidar_sub = nh.subscribe("/scan", 10, &lidarCallback);

  ros::spin();
}
