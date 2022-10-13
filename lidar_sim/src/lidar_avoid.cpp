#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

ros::Publisher vel_pub;

void lidarCallback(const sensor_msgs::LaserScan& msgs) {
  float frontDistance = msgs.ranges[180];
  ROS_INFO("Front distance: %f m.", frontDistance);

  geometry_msgs::Twist vel_cmd;

  if (frontDistance < 1.5) {
    vel_cmd.angular.z = 0.3;
  } else {
    vel_cmd.linear.x = 0.2;
  }
  vel_pub.publish(vel_cmd);
}

int main(int argc, char** argv) {
  setlocale(LC_ALL, "");  // For Chinese

  ros::init(argc, argv, "lidar_node");
  ros::NodeHandle nh;

  ros::Subscriber lidar_sub = nh.subscribe("/scan", 10, &lidarCallback);

  vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

  ros::spin();
}