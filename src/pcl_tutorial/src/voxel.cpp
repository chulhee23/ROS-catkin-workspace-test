#include <ros/ros.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/voxel_grid.h>

ros::Publisher pub;

void callbackFcn(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
    pcl::PointCloud<pcl::PointXYZ> inputCloud;
    pcl::PointCloud<pcl::PointXYZ> filteredCloud;
    // Convert sensor_msgs::PointCloud2 to pcl::PointCloud
    pcl::fromROSMsg(*msg, inputCloud);
    pcl::VoxelGrid<pcl::PointXYZ> vox;
    vox.setInputCloud (inputCloud.makeShared()); // send address by makeShared function == &
    vox.setLeafSize (1.0f, 1.0f, 1.0f); // set Grid Size(1.0m)
    vox.filter (filteredCloud); // filteredCloud = filtered result

    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(filteredCloud, output);
    output.header.frame_id = "/map";
    
    pub.publish(output);
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "voxel");
    ros::NodeHandle nh;
    // << Subscribe Topic >>
    // topic name : /vLidarPC
    // topic type : sensor_msgs::PointCloud2
    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("/vLidarPC", 1, callbackFcn);
    // << Publish Topic >>
    // topic name : /voxelPC
    // topic type : sensor_msgs::PointCloud2
    pub = nh.advertise<sensor_msgs::PointCloud2>("/voxelPC", 1);
    ros::spin();
    return 0;
}

