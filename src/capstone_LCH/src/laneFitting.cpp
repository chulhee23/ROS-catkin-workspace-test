#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>


ros::Publisher pub;
void msgCallback(const sensor_msgs::PointCloud2::ConstPtr& msg){
  
  pcl::PointCloud<pcl::PointXYZ> inputCloud;
  
  // sensor msgs to pcl
  pcl::fromROSMsg(*msg, inputCloud);

  // 
  sensor_msgs::PointCloud2 output;
  pcl::toROSMsg(inputCloud, output);
  
  output.header.frame_id = "/map";  
  pub.publish(output);

}


int main(int argc, char** argv){
  ros::init(argc, argv, "lane");
  ros::NodeHandle nh;
  pub = nh.advertise<sensor_msgs::PointCloud2>("/lane", 1);

  ros::Subscriber lane_sub = nh.subscribe("/input", 1000, msgCallback);
  
  ros::spin();
  return 0;

}