cmake_minimum_required(VERSION 2.8.3)
project(gtri_based_fls)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
  pcl_ros
  cv_bridge
  image_transport
  tf
  pcl_ros
  cmake_modules
)

find_package(gazebo REQUIRED)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

catkin_package(
LIBRARIES
INCLUDE_DIRS
DEPENDS
)

include_directories(include)
include_directories(
  ${Boost_INCLUDE_DIR} 
  ${catkin_INCLUDE_DIRS} 
  ${GAZEBO_INCLUDE_DIRS}
)

set(IMAGING_SONAR_PLUGIN_NAME "gtri_based_fls")

add_library(${IMAGING_SONAR_PLUGIN_NAME} 
  src/ImagingSonar.cc
  )

add_library(cloud_to_iamge
  src/cloud_to_image.cpp
  )

add_library(color_maps
  src/ColorMaps.cpp
  )

add_dependencies(${IMAGING_SONAR_PLUGIN_NAME} 
                 gtri_based_fls_generate_messages_cpp)

target_link_libraries(${IMAGING_SONAR_PLUGIN_NAME}
  cloud_to_image color_maps
  ${catkin_LIBRARIES} 
  ${OpenCV_LIBRARIES}
  ${GAZEBO_LIBRARIES}
  )

# for launch
install(DIRECTORY launch
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
        PATTERN "*~" EXCLUDE)
