cmake_minimum_required(VERSION 3.0.2)
project(pcl_tutorial)
find_package(catkin REQUIRED COMPONENTS
pcl_ros
roscpp
sensor_msgs
)
catkin_package(
)
include_directories(
${catkin_INCLUDE_DIRS}
)
add_executable(vLidar src/vLidar.cpp)
target_link_libraries(vLidar ${catkin_LIBRARIES})

add_executable(voxel src/voxel.cpp)
target_link_libraries(voxel ${catkin_LIBRARIES})

add_executable(passthrough src/passthrough.cpp)
target_link_libraries(passthrough ${catkin_LIBRARIES})

add_executable(kdtree src/kdtree.cpp)
target_link_libraries(kdtree ${catkin_LIBRARIES})

add_executable(clustering src/clustering.cpp)
target_link_libraries(clustering ${catkin_LIBRARIES})