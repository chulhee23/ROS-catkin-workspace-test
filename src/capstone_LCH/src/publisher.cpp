#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <capstone_LCH/pointXY.h>


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
    input.x = {-1, -1, -1, 0,     2, 2, 2, 1, 1, 1, 1, 2, 2, 2,          3, 3, 3, 4, 4, 4   };
    input.y = {1, -1, -1, -1,   0.5, 1, 1, 1, 1, -1, -1, -1, -1, -0.5,  1, -1, 0, 0, 1, -1  };
    

    publisher.publish(input);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
