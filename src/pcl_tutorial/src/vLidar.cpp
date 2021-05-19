#include <ros/ros.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "vLidar");
    ros::NodeHandle nh;
    // << Publish Topic >>
    // topic name : /vLidarPC
    // topic type : sensor_msgs::PointCloud2
    ros::Publisher pub = nh.advertise<sensor_msgs::PointCloud2>("/vLidarPC", 1);
    ros::Rate loop_rate(10); //10Hz
    
    while (ros::ok())
    {
        // Point Cloud Template Class Variable : x, y, z
        pcl::PointCloud<pcl::PointXYZ> cloud;
        cloud.width = 101*101;
        cloud.height = 1; //2D Lidar data
        // is_dense : if lidar data empty? 
        cloud.is_dense = true;
        // cloud.is_dense = false; // in lecture

        cloud.points.resize (cloud.width * cloud.height); //Allocate Memory
        for (int i = -50 ; i <= 50 ; i++) {
            for (int j = -50 ; j <= 50 ; j++)
            {
                cloud.points[101*(i+50)+(j+50)].x = float(i)/10; // x : -5.0 ~ 5.0
                cloud.points[101*(i+50)+(j+50)].y = float(j)/10; // y : -5.0 ~ 5.0
                cloud.points[101*(i+50)+(j+50)].z = 0;
            }
        }
        // Message Class Variable
        sensor_msgs::PointCloud2 output;
        // Convert pcl::PointCloud to sensor_msgs::PointCloud2
        
        // pcl cloud type 
        pcl::toROSMsg(cloud, output);
        
        output.header.frame_id = "/map"; // “fixed frame” of rviz
        pub.publish(output);
        ros::spinOnce();
        loop_rate.sleep(); // CPU speed -> 10Hz
    }
    return 0;
}