#include "ros/ros.h"
#include "yh_star/YhStarMsg.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_star_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_star::YhStarMsg>("yh_star_topic", 10);
    ros::Rate loop_rate(5);

    yh_star::YhStarMsg msg; // 메세지 생성
    msg.data = 1;

    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        pub.publish(msg);
        msg.data++;
        loop_rate.sleep();
    }

    return 0;
}