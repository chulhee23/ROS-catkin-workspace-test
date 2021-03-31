#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>

ros::Publisher marker_pub;

void callback(const capstone_LCH::pointXY::ConstPtr& input)
{
  visualization_msgs::Marker line_list;
  line_list.header.frame_id = "/my_frame";
  line_list.header.stamp = ros::Time::now();
  line_list.ns = "points_and_lines";
  line_list.action = visualization_msgs::Marker::ADD;
  line_list.pose.orientation.w = 1.0;
  line_list.id = 2;
  line_list.type = visualization_msgs::Marker::LINE_LIST;
  line_list.scale.x = 0.1;
  line_list.scale.r = 1.0;
  line_list.scale.a = 1.0;

  for (int i = 0; i < 26; i++)
  {
    geometry_msgs::Point p;
    p.x = input -> x[i];
    p.y = input -> y[i];
    p.z = 0;
    line_list.points.push_pack(p);

  }
  
  marker_pub.publish(line_list);


}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "/initial");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/points", 1, callback);
  


}