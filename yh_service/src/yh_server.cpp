#include "ros/ros.h"
#include "yh_service/YhSrv.h"

bool add(yh_service::YhSrv::Request& req, yh_service::YhSrv::Response& res)
{
    res.result = req.a * req.b;
    ROS_INFO("request a=%d, b=%d", req.a, req.b);
    ROS_INFO("response: result=%d", res.result);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_server");
    ros::NodeHandle nh;

    ros::ServiceServer yh_server = nh.advertiseService("yh_srv", add);

    ROS_INFO("Service Server Ready.");

    ros::spin();

    return 0;
}