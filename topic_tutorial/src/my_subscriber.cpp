#include "ros/ros.h" // ROS 헤더파일
#include "std_msgs/String.h" // std_msgs 패키지의 String 메세지 헤더파일

void msgCallback(const std_msgs::String::ConstPtr& msg) // ConstPtr(c++의 포인터일종), Callback -> 특정이벤트가 호출되는 함수 
{
    ROS_INFO("msg : %s", msg->data.c_str()); // 메세지에 데이터라고하는 애를 사용해 꺼낸다. c_str(c스타일의 스트링을 사용한다.) 
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_subscriber"); // 노드 이름 초기화
    ros::NodeHandle nh; // 노드 핸들 선언
    
    // 서브스크라이버 선언
    // 패키지(std_msgs)의 메세지(String)를 이용한 서브스크라이버(sub)를 선언한다. *퍼블리셔와는 다르게 위의 콜백함수를 확인하면 답이 나온다.
    // 토픽은 ("my_topic")이며, 서버스크라이버큐(queue) 사이즈를 (100)으로 설정한다.
    // 콜백 함수는 (msgCallback)이다.

    ros::Subscriber sub = nh.subscribe("my_topic", 100, msgCallback);

    // 콜백 함수 호출을 위한 함수. 메세지가 수신되기를 대기
    // 수신되었을 경우 콜백 함수를 호출한다.

    ros::spin(); // 계속 대기하면서 콜백함수가 호출되기를 기다림

    return 0;
}