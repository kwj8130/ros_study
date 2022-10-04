#include "ros/ros.h"
#include "param_tutorial/Calculate.h"

#define PLUS 1  
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4
// ex. printf("%d", PLUS); = 1로 표기. 각 이름 다음에 나오는 부분을 담아서 컴파일

int my_operator = PLUS; // 전역변수로 빼놓음.
bool calculation(param_tutorial::Calculate::Request& req, param_tutorial::Calculate::Response& res)
{
    switch(my_operator)
    {   
        case PLUS:
            res.result = req.a + req.b;
            break;
        case MINUS:
            res.result = req.a - req.b;
            break;
        case MULTIPLICATION:
            res.result = req.a * req.b;
            break;
        case DIVISION:
            res.result = req.a / req.b;
            break;
        default:
            res.result = req.a + req.b;
            break;
    }
    ROS_INFO("a : %d, b : %d, result : %d", req.a, req.b, res.result);
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "calculate_server");
    ros::NodeHandle nh;

    nh.setParam("calculation_method", PLUS); // 파라미터 초기 설정
    // 파라미터 서버에 "이름"엔 플러스라는 것을 넣을거다. 즉, 플러스가 1이기때문에 "이름"을 1로바꾸는것.

    ros::ServiceServer calculate_server = nh.advertiseService("calculate", calculation);

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        nh.getParam("calculation_method", my_operator);
        // "이름"에 my_operator에서 설정한 값을 넣고 파라미터 서버에서 가져오는것.

        ros::spinOnce(); // 스핀(계속 대기하면서 콜백함수를 호출)을 한번만 하는것. 동작을 한번하고 기다리는것을 하기 위해서 한번만 실행.(위의 함수계산들이 각각다르기때문)
        // ros::spin() == while(true)

        loop_rate.sleep();
    }

    return 0;
}

