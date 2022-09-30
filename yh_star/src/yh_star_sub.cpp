#include "ros/ros.h"
#include "yh_star/YhStarMsg.h"

void msgCallback(const yh_star::YhStarMsg::ConstPtr& msg)
{
    int n = msg->data; 
    for(int i = 0; i < n/2; i++) //별찍기. n/2까지
    {
        for(int j = 0; j < i+1; j++) //첫줄에 무조건 별을찍기위해
        {
            printf("*"); //가로로 쭉찍음
        }
        printf("/n"); //수행하면 엔터치면서 줄바꿈
    }

    for(int i=n/2; i<n; i++) //별을 줄임
    {
        for(int j = n; j > i; j--) // 
        {
            printf("*");
        }
        printf("\n");
    }
}

// n/2 주어진 숫자의 절반만큼까지는 증가. 그 다음부터는 감소.
// * 3나누기 2는 1이다. (정수기때문에 소수점은 상관없다.)

int main (int argc, char** argv)
{
    ros::init(argc, argv, "yh_star_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("yh_star_pub", 10, msgCallback);

    ros::spin();

    return 0;
}