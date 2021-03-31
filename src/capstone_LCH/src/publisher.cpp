#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>

void drawL(capstone_LCH::pointXY input)
{
  input.x = {-1, -1, -1, 0};
  input.y = {1, -1, -1, -1};
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
