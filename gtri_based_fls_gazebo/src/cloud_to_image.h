/*
 * Copyright (C) 2012-2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
/*
 * Desc: Ray Plugin
 * Author: Nate Koenig mod by John Hsu
 */

#ifndef CLOUD_TO_IMAGE_H
#define CLOUD_TO_IMAGE_H

/*
#include <ros/ros.h>
#include <ros/callback_queue.h>
#include <ros/advertise_options.h>

#include <sdf/Param.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/TransportTypes.hh>
#include <gazebo/msgs/MessageTypes.hh>
#include <gazebo/common/Time.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/sensors/SensorTypes.hh>
#include <gazebo/plugins/RayPlugin.hh>

#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include "gazebo/util/system.hh"
*/

#include <sensor_msgs/PointCloud.h>

//namespace gazebo
void init_cloud_to_image(ros::NodeHandle* n_,
                         const sdf::ElementPtr _sdf);
void publish_cloud_to_image(const sensor_msgs::PointCloud& msg,
                            const ros::Publisher& camera_info_pub_,
                            const ros::Publisher& image_pub_);
#endif

