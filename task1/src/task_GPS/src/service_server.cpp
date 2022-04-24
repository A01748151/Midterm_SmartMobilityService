#include "ros/ros.h"
#include "task_GPS/GPS_check.h"

bool determineLocation(task_GPS::GPS_check::Request &req,
                       task_GPS::GPS_check::Response &res)
{
    int latitude = req.latitude;
    int longitude = req.longitude;

    if(latitude == 35 && longitude == 128)
    {
        res.answer = "19°C";
    }
    else if(latitude == 35 && longitude == 129)
    {
        res.answer = "28°C";
    }
    else if(latitude == 37 && longitude == 126)
    {
        res.answer = "22°C";
    }
    else if(latitude == 37 && longitude == 127)
    {
        res.answer = "16°C";
    }
    else if(latitude == 36 && longitude == 127)
    {
        res.answer = "10°C";
    }
    else
    {
        return false;
    }

    return true;

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "GPS_service_server_node");
    ros::NodeHandle node_handle;
    ros::ServiceServer service = node_handle.advertiseService("GPS_check_s", determineLocation);
    ROS_INFO("GPS Check Server Running...");

    ros::spin();

    return 0;

}