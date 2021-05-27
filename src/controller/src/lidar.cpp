#include <ros/ros.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <cmath>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  // for Arduino publish start ================================
  // The second parameter to advertise() is the size of the message queue used for publishing messages.
  // If messages are published more quickly than we can send them,
  // the number here specifies how many messages to buffer up before throwing some away.
  ros::Publisher del_pub = nh.advertise<std_msgs::Float64>("/del", 1000);
  
  ros::Publisher vel_pub = nh.advertise<std_msgs::Float64>("/del", 1000);
  // for Arduino publish end ================================

  // while Lidar On
  while(ros::ok()){
    // 1. get slope by gradient descent
    

    // 2. publish delta value to Arduino

    ros::spinOnce();
    loop_rate.sleep();

  }

  

  // ros::Subscriber lane_sub = nh.subscribe("/input", 10, msgCallback);

  ros::spin();
  return 0;
}