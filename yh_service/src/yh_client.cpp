#include "ros/ros.h"
#include "yh_service/YhSrv.h"
#include <cstdlib>

int main (int argc, char** argv)
{
    ros::init(argc, argv, "yh_client");

    if(argc != 3) // 프로그램 이름(yh_client), arg1, arg2 가 들어오기때문에 3이다. 0, 1, 2순으로 읽음
    {
        ROS_INFO("command: rosrun yh_service yh_client arg1 arg2");
        ROS_INFO("arg1, arg2 : int32 number");
        return 1;
    }

    ros::NodeHandle nh;

    ros::ServiceClient yh_client = nh.serviceClient<yh_service::YhSrv>("yh_srv");

    yh_service::YhSrv srv;

    srv.request.a = atoi(argv[1]);
    srv.request.b = atoi(argv[2]);

    if(yh_client.call(srv))
    {
        ROS_INFO("send srv: srv.request.a = %d, srv.request.b = %d", srv.request.a, srv.request.b);
        ROS_INFO("receive srv: srv.response.result = %d", srv.response.result);
    }

    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    return 0;
}