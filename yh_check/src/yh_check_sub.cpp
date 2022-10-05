#include "ros/ros.h"
#include "yh_check/YhCheck.h"

/*class MySub
{
    public:
        //함수들
        MySub(void) = init
        {
            sub_distance = nh.subscribe("check_distance", 10, &MySub::distanceCallback, this);
            sub_camera = nh.subscribe("check_camera", 10, &MySub::cameraCallback, this);
        }
    private:
        //변수들
        ros::NodeHandle nh;
        ros::Subscriber sub_distance;
        ros::Subscriber sub_camera;
        bool distance = true;
        bool camera = true;
};  c++ 클래스는 중괄호 끝에 반드시 세미콜론을 붙여야함
*/

bool distance = true; // 전역변수 선언, 여러곳에서 동시에 쓰겠다.
bool camera = true;

void distanceCallback(const yh_check::YhCheck::ConstPtr& msg)
{
    distance = msg->data;
    if (distance && camera)
    {
        ROS_INFO("OK");
    }
}

void cameraCallback(const yh_check::YhCheck::ConstPtr& msg)
{
    camera = msg->data;
    if (distance && camera)
    {
        ROS_INFO("OK");
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_check_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub_distance = nh.subscribe("check_distance", 10, distanceCallback);
    ros::Subscriber sub_camera = nh.subscribe("check_camera", 10, cameraCallback);

    ros::spin();

    return 0;
}