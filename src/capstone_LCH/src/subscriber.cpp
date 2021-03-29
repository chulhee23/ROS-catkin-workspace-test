#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <cmath>
#include <std_msgs/Float64.h>

float line_list_type;

void callback(const visualization_msgs::Marker &msg)
{
  line_list_type = msg.type;
  ROS_INFO("%f", line_list_type);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "points_and_lines");
  ros::NodeHandle nh;

  ros::Subscriber marker_sub = n.subscribe('/points', 1000, callback);
  // ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("initial", 10);

  nh.subscribe("/points", 1000, callback);

      ros::spin();
}