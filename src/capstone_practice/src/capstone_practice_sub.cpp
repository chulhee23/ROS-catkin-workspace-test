#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <iostream>
float capstone_sub_data;

void msgCallback(const std_msgs::Float64& msg)
{
    capstone_sub_data = msg.data;
    ROS_INFO("%f", capstone_sub_data);
}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "capstone_practice_sub_node");
    ros::NodeHandle nh;
    ros::Subscriber capstone_practice_sub = nh.subscribe("capstone_pub_topic", 1000, msgCallback);
    std::cout << "test" << std::endl;
    ros::spin();
}