#include "ros/ros.h"
// #include "std_msg/Int64.h", 기존의 msg 헤더파일
#include "msg_tutorial/Mymsg.h" // Mymsg 메세지 헤더파일, 빌드시 자동생성

int main(int argc, char** argv)
{
    ros::init(argc, argv, "msg_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<msg_tutorial::Mymsg>("burger", 20); // 토픽이름을 burger로 했고, 큐 사이즈는 20이다.

    ros::Rate loop_rate(2);

    msg_tutorial::Mymsg msg;
    int cnt = 0;

    while(ros::ok())
    {
        /*msg
        {
            time stamp
            int32 data
        }
        */

        msg.stamp = ros::Time::now(); // 현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt;  // cnt 변수의 값을 msg의 data에 담는다.
        ROS_INFO("send msg : %d", msg.stamp.sec);  // stamp.sec를 출력한다.
        ROS_INFO("send msg : %d", msg.stamp.nsec);  // stamp.nsec를 출력한다.
        ROS_INFO("send msg : %d", msg.data);  // data를 출력한다.

        pub.publish(msg);
        cnt++;
        loop_rate.sleep();
    }

    return 0;
}