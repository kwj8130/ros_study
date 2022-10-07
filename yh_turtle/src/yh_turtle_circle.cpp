#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main (int argc, char** argv)
{
    ros::init(argc, argv, "yh_turtle_circle");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

    while(ros::ok())
    {
        geometry_msgs::Twist cmd_vel;

        cmd_vel.linear.x = 2.0;
        cmd_vel.linear.y = 2.0;
        cmd_vel.linear.z = 2.0;

        cmd_vel.angular.x = 0.0;
        cmd_vel.angular.y = 0.0;
        cmd_vel.angular.z = 2.0;

        pub.publish(cmd_vel);
        ros::spinOnce();
    }

    return 0;
}