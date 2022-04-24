#include "ros/ros.h"

#include "std_msgs/Float32.h"

const float RPM = 40;
const float wheel_radius = 30;


int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_pub_node");

  ros::NodeHandle node_handle;

  ros::Publisher speed_pub = node_handle.advertise<std_msgs::Float32>("speed", 10);

  ros::Rate speed_rate(10);

  ROS_INFO("Publishing Speed...");

  while(ros::ok())
  {

    std_msgs::Float32 speed_msg;
    
    speed_msg.data = (2 * wheel_radius * 3.14159)*(RPM / 60);

    speed_pub.publish(speed_msg);

    speed_rate.sleep();
  }

}
