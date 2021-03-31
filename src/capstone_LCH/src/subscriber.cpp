#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>



void callback(const capstone_LCH::pointXY::ConstPtr& input)
{
  visualization_msgs::Marker line_list;
  
  line_list.header.frame_id = "/my_frame";
  line_list.header.stamp = ros::Time::now();
  
  line_list.ns = "points_and_lines";
  line_list.id = 0;
  
  line_list.type = visualization_msgs::Marker::LINE_LIST;
  
  line_list.action = visualization_msgs::Marker::ADD;
  
  line_list.scale.x = 1;
  line_list.scale.y = 1;
  line_list.scale.z = 1;
  
  line_list.pose.orientation.w = 1.0;

  for (int i = 0; i < 26; i++)
  {
    geometry_msgs::Point p;
    p.x = input -> x[i];
    p.y = input -> y[i];
    p.z = 0;
    line_list.points.push_back(p);

  }

  marker_pub.publish(line_list);


}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "initial");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber sub = n.subscribe("/points", 1, callback);

  ros::spin();
}