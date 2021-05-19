#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <cmath>

ros::Publisher pub;

float a1, a2, b1, b2;
float getLineY(float x1, float x2, float y1, float y2, float x3){
  return (float(y2 - y1)/float(x2 - x1) * (x3 - x1) + y1);
}

struct dense_w {
  float d_w0;
  float d_w1;
}


dese_w dmse_line(float[] x, float[] t, float[] w){
  
  float y = w[0] * x + w[1];
  


  float d_w0 = 2 * mean((y - t) * x);
  

}

void msgCallback(const sensor_msgs::PointCloud2::ConstPtr& msg){
  
  pcl::PointCloud<pcl::PointXYZ> inputCloud;
  pcl::fromROSMsg(*msg, inputCloud);

  
  // draw linels
  visualization_msgs::Marker line;
  line.header.frame_id = "map";
  line.header.stamp = ros::Time::now();
  line.ns = "points_and_lines";
  line.id = 0;
  line.type = visualization_msgs::Marker::LINE_LIST;
  line.action = visualization_msgs::Marker::ADD;
  
  line.scale.x = 0.1;
  line.scale.y = 0;
  line.scale.z = 0;

  line.color.a = 1.0;
  line.color.r = 1.0;

  line.pose.orientation.w = 1.0;

  int arr_size = inputCloud.points.size();
  
  float error_sum = float(3.4E+38);
  float x1, x2, y1, y2;
  for(int i = 0; i < 10; i++){
    geometry_msgs::Point p;

    float sx = inputCloud.points[0].x;
    float sy = inputCloud.points[0].y;

    float ex = inputCloud.points[arr_size-1].x;
    float ey = inputCloud.points[arr_size-1].y;

    float left_end = rand() % (arr_size / 2);
    float right_end = rand() % (arr_size / 2) + (arr_size / 2);
    
    x1 = inputCloud.points[left_end].x;
    y1 = inputCloud.points[left_end].y;
    
    x2 = inputCloud.points[right_end].x;
    y2 = inputCloud.points[right_end].y;


    
    // 3. calculate distance from all dots
    float cur_err = 0;
    for(int j = arr_size -1; j > arr_size - 20; j--){
      float x3 = inputCloud.points[j].x;
      float y3 = getLineY(x1, x2, y1, y2, x3);  
      if(x3 > x2){
        x2 = x3; y2 = y3;
      } else if (x3 < x1){
        x1 = x3; y1 = y3;
      }
    }


    for(int j = 0; j < 20; j++){
      float x3 = inputCloud.points[j].x;
      float y3 = getLineY(x1, x2, y1, y2, x3);
      if (x3 < x1){
        x1 = x3; y1 = y3;
      } else if(x3 > x2){
        x2 = x3; y2 = y3;
      }
      
      cur_err += pow((inputCloud.points[j].y - y3), 2);
    } 
    
    if(cur_err < error_sum){
      a1 = x1; a2 = x2; b1 = y1; b2 = y2;
    }


    
  }
  geometry_msgs::Point p1;
  p1.x = a1;
  p1.y = b1;
  p1.z = 0;
  line.points.push_back(p1);
  
  geometry_msgs::Point p2;
  p2.x = a2;
  p2.y = b2;
  p2.z = 0;
  line.points.push_back(p2);


  pub.publish(line);

}


int main(int argc, char** argv){
  ros::init(argc, argv, "laneFitting");
  ros::NodeHandle nh;

  pub = nh.advertise<visualization_msgs::Marker>("/lane", 1);

  ros::Subscriber lane_sub = nh.subscribe("/input", 10, msgCallback);
  
  ros::spin();
  return 0;

}