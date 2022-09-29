#include "ros/ros.h"
#include "msg_tutorial/Mymsg.h" //Mymsg 메세지 헤더파일, 빌드시 자동생성

//void msgCallback(const std_msg::Int64::ConstPtr& msg)
void msgCallback(const msg_tutorial::Mymsg::ConstPtr& msg)
{
    ROS_INFO("receive msg : %d", msg->stamp.sec);  // msg의 stamp의 sec를 출력한다.
    ROS_INFO("receive msg : %d", msg->stamp.nsec); // msg의 stamp의 nsec를 출력한다.
    ROS_INFO("receive msg : %d", msg->data); // msg의 data를 출력한다.
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "msg_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("burger", 20, msgCallback);

    ros::spin();

    return 0;
}