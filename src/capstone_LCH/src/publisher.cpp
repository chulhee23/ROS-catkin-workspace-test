#include <ros/ros.h>
#include <cmath>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>
#include <iostream>

void drawL(capstone_LCH::pointXY input)
{
  for (int i = 20; i <= -10; i--)
  {
    input.x.push_back(-10);
    input.y.push_back(i);
  }
  for (int i = -10; i <= 0; i++)
  {
    input.x.push_back(-10);
    input.y.push_back(-10);
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher_node"); //initiation
  ros::NodeHandle nh;

  ros::Rate loop_rate(10);
  ros::Publisher publisher = nh.advertise<capstone_LCH::pointXY>("/points", 10);

  while (ros::ok())
  {
    capstone_LCH::pointXY input;
    
    // draw L
    drawL(input);
    
    publisher.publish(input);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
