cmake_minimum_required(VERSION 3.0.2)
project(capstone_practice)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	std_msgs
)
catkin_package(
	CATKIN_DEPENDS
	roscpp
	std_msgs
)

include_directories(
	# include
	${catkin_INCLUDE_DIRS}
)

add_executable(capstone_practice_pub src/capstone_practice_pub.cpp)
target_link_libraries(capstone_practice_pub  ${catkin_LIBRARIES})

add_executable(capstone_practice_sub src/capstone_practice_sub.cpp)
target_link_libraries(capstone_practice_sub  ${catkin_LIBRARIES})
