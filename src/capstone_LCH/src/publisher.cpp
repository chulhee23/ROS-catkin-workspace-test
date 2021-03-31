#include <ros/ros.h>
#include <cmath>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher_node"); //initiation
  ros::NodeHandle nh;

  ros::Rate loop_rate(10);
  // ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Publisher publisher = nh.advertise<capstone_LCH::pointXY>("/points", 10);
  visualization_msgs::Marker line_list;

  while (ros::ok())
  {
    capstone_LCH::pointXY input;

    for (int i = 0; i < 4; i++)
    {
      input.x.push_back(i);
      input.y.push_back(0);
    }
    
    publisher.publish(input);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
