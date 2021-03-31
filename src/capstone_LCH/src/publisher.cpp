#include <ros/ros.h>
#include <cmath>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>
#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher_node"); //initiation
  ros::NodeHandle nh;

  ros::Rate loop_rate(10);
  ros::Publisher publisher = nh.advertise<capstone_LCH::pointXY>("/points", 10);

  while (ros::ok())
  {
    capstone_LCH::pointXY input;

    for (int i = 0; i < 1000; i++)
    {
      input.x.push_back(i);
      input.y.push_back(i);
    }
    
    publisher.publish(input);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
