cmake_minimum_required(VERSION 3.0.2)
project(gtri_based_fls)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
  pcl_ros
  cv_bridge
  image_transport
  tf
)

find_package(gazebo REQUIRED)
find_package(OpenCV)
include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIR} 
  ${catkin_INCLUDE_DIRS} 
  ${GAZEBO_INCLUDE_DIRS}
)
link_directories(${GAZEBO_LIBRARY_DIRS})

catkin_package(
LIBRARIES
INCLUDE_DIRS
DEPENDS
)

add_library(gtri_based_fls_plugin src/ImagingSonar.cc)

add_library(cloud_to_image src/cloud_to_image.cpp)

add_library(color_maps src/ColorMaps.cpp)

target_link_libraries(gtri_based_fls_plugin
  cloud_to_image color_maps
  ${catkin_LIBRARIES} 
  ${OpenCV_LIBRARIES}
  ${GAZEBO_LIBRARIES}
  )

# for launch
install(DIRECTORY launch
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
        PATTERN "*~" EXCLUDE)
