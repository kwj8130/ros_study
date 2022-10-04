#include "ros/ros.h"
#include "yh_dual/YhDual.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_dual_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_dual::YhDual>("yh_dual_topic", 100);
    ros::Rate loop_rate(8);

    yh_dual::YhDual msg;
    int cnt = 0;

    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = cnt;
        ROS_INFO("send msg : %d", msg.stamp.sec);
        ROS_INFO("send msg : %d", msg.stamp.nsec);
        ROS_INFO("send msg : %d", msg.data);

        pub.publish(msg);
        cnt++;
        loop_rate.sleep();
    }
    
    return 0;
}