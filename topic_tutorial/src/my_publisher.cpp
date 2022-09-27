#include "ros/ros.h" // ros 헤더파일
#include "std_msgs/String.h" // String 메세지 헤더파일


int main(int argc, char** argv) //반환데이터자리, 함수자리()
{
    ros::init(argc, argv, "my_publisher"); // 노드 이름 초기화
    ros::NodeHandle nh; // ros 시스템과 통신을 위한 노드 핸들 선언

    // 퍼블리셔 선언
    // 패키지(std_msgs)의 메세지파일(String)를 이용한 퍼블리셔(pub)를 만든다.
    // 토픽은 ("my_topic")이며, 퍼블리셔큐(queue) 사이즈는 (100)이다.

    ros::Publisher pub = nh.advertise<std_msgs::String>("my_topic", 100); // Publisher : 자료형, pub : 변수이름, < > 어떤 형태를 쓸것인가?, nh.advertise - 퍼블리셔를 만드는 함수
    
    ros::Rate loop_rate(10); // 루프 주기를 10Hz로 설정한다.(0.1초마다), Rate : 자료형(타입)
    
    std_msgs::String msg;
    msg.data = "Hello"; // msg의 data에 Hello를 넣는다.

    while (ros::ok()) // ros(프로그램자체)가 켜져있는동안 퍼블리셔한다
    {
        pub.publish(msg); // pub이 msg를 퍼블리시한다.
        loop_rate.sleep(); // 위에서 정한 주기에 따라 sleep 한다. 즉, 시간을 맞추기 위함
    }

    return 0; //문제없이 끝냄
}