#include "ros/ros.h"
#include "yh_dual/YhDual.h"

void msgCallback(const yh_dual::YhDual::ConstPtr& msg)
{
    ROS_INFO("receive msg : %d", msg->stamp.sec);
    ROS_INFO("receive msg : %d", msg->stamp.nsec);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_dual_time");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("yh_dual_topic", 100, msgCallback);
    
    ros::spin();

    return 0;
}