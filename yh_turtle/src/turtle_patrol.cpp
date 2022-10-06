#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_patrol");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
    ros::Rate loop_rate(1);

    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;

    while(ros::ok())
    {
        pub.publish(msg);
        msg.linear.x *= -1; // *= msg.linear.x 곱하기 -1을 한 뒤 다시 msg.linear.x에 넣음
        loop_rate.sleep();
    }

    return 0;
}