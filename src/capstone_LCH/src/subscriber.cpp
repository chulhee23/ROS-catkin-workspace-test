#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>

ros::Publisher pub;

void callback(const capstone_LCH::pointXY::ConstPtr& input)
{
  
  
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "/initial");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/points", 1, callback);
  
  

}