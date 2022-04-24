//limit speed (suscriber)

#include "ros/ros.h"

#include "std_msgs/Float32.h"

float SPEED_LIMIT;

ros::Publisher limit_pub;

void subCallback(const std_msgs::Float32::ConstPtr& speed)
{
    ros::NodeHandle callback_node_handle;
    if(callback_node_handle.getParam("speed_limit", SPEED_LIMIT))
     {

            //Verification of speed and the speed limit
        if(SPEED_LIMIT > (speed -> data)) //if the car is going below the speed_limit
            {
                std_msgs::Float32 car_msg;
                
                car_msg.data = speed -> data;

                limit_pub.publish(car_msg);                
                
            }
            else if(SPEED_LIMIT < (speed -> data)) //if the car is over the speed_limit
            {
                std_msgs::Float32 car_plate_msg;
                
                car_plate_msg.data = 8530;
                
                limit_pub.publish(car_plate_msg);
            }
            
     }
    else
    {
        ROS_WARN(" No Value set for speed_limit server parameter.");
    }
    
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "speed_measure_node");
    ros::NodeHandle node_handle;
    
    limit_pub = node_handle.advertise<std_msgs::Float32>("car", 10);
    
    ros::Subscriber speed_sub = node_handle.subscribe("speed", 10, subCallback);
    
    ros::spin();
    
    return 0;
    
}
