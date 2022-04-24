#include "ros/ros.h"
#include "task_GPS/GPS_check.h"

#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "GPS_service_client_node");
    ros::NodeHandle node_handle;
    ros::ServiceClient client = node_handle.serviceClient<task_GPS::GPS_check>("GPS_check_s");
    task_GPS::GPS_check GPS_check_srv;

    int input_latitude;
    int input_longitude;

    std::cout << "Type '0' to quit" << std::endl;

    while (ros::ok())
    {
        std::cout << "Daegu = 35 \n Busan = 35 \n Seoul = 37 \n Suwon = 37 \n Anseong = 36 \n Enter a city latitude: ";
        std::cin >> input_latitude;
        std::cout << "Daegu = 128 \n Busan = 129 \n Seoul = 126 \n Suwon = 127 \n Anseong = 127 \n Enter a city longitude: ";
        std::cin >> input_longitude;

        GPS_check_srv.request.latitude = input_latitude;
        GPS_check_srv.request.longitude = input_longitude;

        if (input_latitude == 0 && input_longitude == 0)
        {
            ROS_INFO("Exiting Application...");

            return 0;
        }

        if (client.call(GPS_check_srv))
        {
            std::string resp;
            resp = GPS_check_srv.response.answer;

            std::cout << "The temperature in the city is: " << resp << std::endl;
    
        }
        else
        {
            ROS_ERROR("Service Call Failed");
            return 1;
        }

        std::cin.clear();

    }


}