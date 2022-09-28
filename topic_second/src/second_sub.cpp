#include "ros/ros.h"
#include "std_msgs/Int32.h"

void msgCallback(const std_msgs::Int32::ConstPtr& msg) // const는 원본메세지를 건드리지 말라고 작성.(불변), std_msgs::Int32(메세지타입), msg에 앞의 함수가 포함되어있는 상태.
{
    ROS_INFO("count : %d", msg->data); // msg를 data로 보냄
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "second_sub"); // 노드 이름 초기화
    ros::NodeHandle nh; // 노드 핸들설정

    // 서브스크라이버 선언
    // 패키지(std_msgs)의 메세지(Int32)를 이용한 서브스크라이버(sub)를 선언한다. *퍼블리셔와는 다르게 위의 콜백함수를 확인하면 이미 정해졌기 때문에 
    // 토픽은 ("my_count")이며, 서버스크라이버큐(queue) 사이즈를 (100)으로 설정한다.
    // 콜백 함수는 (msgCallback)이다.

    ros::Subscriber sub = nh.subscribe("my_count", 100, msgCallback);

    ros::spin(); // 

    return 0;
}