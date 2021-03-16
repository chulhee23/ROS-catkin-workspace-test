#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "capstone_practice_pub_node");
  ros::NodeHandle nh;
  ros::Publisher capstone_practice_pub = nh.advertise<std_msgs::Float64>("capstone_pub_topic", 1000);
  ros::Rate loop_rate(10);
  float count = 0;
  
  while (ros::ok())
  {
    std_msgs::Float64 msg;
    msg.data = count;
    ROS_INFO("%f", msg.data);
    capstone_practice_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}