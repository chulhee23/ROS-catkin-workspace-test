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
    ros::Publisher capstone_practice_pub = nh.advertise<std_msgs::Float64>("capstone_pub_topic2", 1000);
    
    std::cout << "test" << std::endl;
    ros::Rate loop_rate(100);
    
    

    while(ros::ok()){
        std_msgs::Float64 msg2;
        msg2.data = capstone_sub_data + 1;
        capstone_practice_pub.publish(msg2);
        ros::spinOnce();
        loop_rate.sleep();

    }
}