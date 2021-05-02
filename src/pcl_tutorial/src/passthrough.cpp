#include <ros/ros.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/passthrough.h>

ros::Publisher pub;

void callbackFcn(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
    pcl::PointCloud<pcl::PointXYZ> inputCloud;
    pcl::PointCloud<pcl::PointXYZ> filteredCloud;
    pcl::fromROSMsg(*msg, inputCloud);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud (inputCloud.makeShared());
    pass.setFilterFieldName ("x"); // set Axis(x)
    
    pass.setFilterLimits (-1.0, 1.0); // x : -1.0 ~ 1.0
    pass.setFilterLimitsNegative (true); // x : -inf ~ -1.0 && 1.0 ~ inf
    // area turn around 

    pass.filter (filteredCloud);
    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(filteredCloud, output);
    output.header.frame_id = "/map";
    pub.publish(output);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "passthrough");
    ros::NodeHandle nh;
    // << Subscribe Topic >>
    // topic name : /voxelPC
    // topic type : sensor_msgs::PointCloud2
    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("/voxelPC", 1, callbackFcn);
    // << Publish Topic >>
    // topic name : /passPC
    // topic type : sensor_msgs::PointCloud2
    pub = nh.advertise<sensor_msgs::PointCloud2>("/passPC", 1);
    ros::spin();
    return 0;
}