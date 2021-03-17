#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <iostream>

float capstone_sub_data;

void msgCallback(const std_msgs::Float64& msg)
{
    capstone_sub_data = msg.data;
    std::cout << "topic: " << capstone_sub_data << std::endl;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "capstone_practice_sub_node2");
    ros::NodeHandle nh;
    ros::Subscriber capstone_practice_sub2 = nh.subscribe("capstone_pub_topic2", 1000, msgCallback);
    
    
    ros::spin();

    
}