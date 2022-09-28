#include "ros/ros.h" // ros 헤더파일
#include "std_msgs/Int32.h" // std_msgs 패키지의 Int32 메세지 헤더파일, int32 4바이트 정수. 같은 int여도 메모리에 따라 다양하다. 1바이트 = 8비트

int main(int argc, char** argv)
{
    ros::init(argc, argv, "second_pub"); // 노드 이름 초기화
    ros::NodeHandle nh; // 노드 핸들설정
    
    // 퍼블리셔 선언
    // 패키지(std_msgs)의 메세지파일(Int32)를 이용한 퍼블리셔(pub)를 만든다.
    // 토픽은 ("my_count")이며, 퍼블리셔큐(queue) 사이즈는 (100)이다.

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("my_count", 100);
    // 앞에 자료형 뒤에는 변수이름이 들어감 Publisher : 자료형, pub : 변수이름, < >의 안에는 어떤 형태(타입)의 메세지를 쓸것인가를 작성, nh.advertise - 퍼블리셔를 만드는 함수

    ros::Rate loop_rate(2); // 루프 주기를 10Hz로 설정한다.(10은 0.1초마다, 현재는 2이므로 0.5초), Rate : 자료형(타입)

    std_msgs::Int32 msg;
    msg.data = 0;

    while (ros::ok())
    {
        pub.publish(msg); // pub이 msg를 퍼블리시
        loop_rate.sleep(); // 주기에 맞게 멈춰서 시간을 맞춤.
        msg.data++; // 보낼때마다 1씩 카운트됨
    }

    return 0;
}