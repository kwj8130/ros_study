#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"

ros::Publisher pub; // 전역함수

void msgCallback(const std_msgs::Int32::ConstPtr& msg) // pub에서 받는것이기 때문에 먼저 Int를 받는다.
{
    if (msg->data % 5 == 0) // 5의 배수라면
    {
        std_msgs::Float32 float_msg;
        float_msg.data = (float) msg->data / 3.0f; 
        // msg.data = int32를 float형으로 바꾸겠다.
        pub.publish(float_msg);
    }   
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_connect_sub_pub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("yh_connect_int", 10, msgCallback);
    pub = nh.advertise<std_msgs::Float32>("yh_connect_float", 10);

    ros::spin();

    return 0;
}

