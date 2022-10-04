#include "ros/ros.h"
#include "yh_difference/YhDifference.h"
#include <cstdlib>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_difference_client");
    if (argc != 3)
    {
        ROS_INFO("command : rosrun yh_difference yh_difference_client a b");
        ROS_INFO("a, b : int32 number");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient yh_difference_client = nh.serviceClient<yh_difference::YhDifference>("yh_difference_service");

    yh_difference::YhDifference srv;

    srv.request.a = atoi(argv[1]);
    srv.request.b = atoi(argv[2]);

    if(yh_difference_client.call(srv))
    {
        ROS_INFO("a = %d, b = %d", srv.request.a, srv.request.b);
        ROS_INFO("result = %d", srv.response.result);
    }

    else
    {
        ROS_ERROR("Failed to call service");

        return 1;
    }

    return 0;
}