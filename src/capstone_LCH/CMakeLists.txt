cmake_minimum_required(VERSION 3.0.2)
project(capstone_LCH)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  pointXY.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES capstone_LCH
#  DEPENDS system_lib
  CATKIN_DEPENDS 
  roscpp 
  std_msgs
  message_runtime
)


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher  ${catkin_LIBRARIES})
add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber  ${catkin_LIBRARIES})

