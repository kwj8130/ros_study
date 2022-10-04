#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from param_tutorial.srv import Calculate, CalculateResponse

PLUS = 1
MINUS = 2
MULTIPLICATION = 3
DIVISION = 4

def calculation(req):
    my_operator = rospy.get_param("calculation_method")
    if my_operator == PLUS:
        result = req.a + req.b
    elif my_operator == MINUS:
        result = req.a - req.b
    elif my_operator == MULTIPLICATION:
        result = req.b * req.b
    elif my_operator == DIVISION:
        result = req.a // req.b 
        #result = int(req.a / req.b)

        #if req.b == 0:
        #    result = 0
        #else:
        #    result = req.a // req.b

        #try:
        #    result = req.a // req.b
        #except ZeroDivisionError:
        #   result = 0
            
    else:
        result = req.a + req.b

    rospy.loginfo(f"a : {req.a}, b : {req.b}, result : {result}")
    res = CalculateResponse()
    res.result = result

    return res

def calculate_server():
    rospy.init_node("calculate_server")

    rospy.set_param("calculation_method", PLUS) # "이름"을 PLUS로 파라미터를 세트하겠다.

    my_server = rospy.Service("calculate", Calculate, calculation)
    rospy.loginfo("Service Server Ready")
    rospy.spin()
    # spinOnce는 없고, 파이썬의 경우는 콜백함수가 나올때 그때그때 값을 바꿔주면 대응하는 방식으로 사용할 수 있다.

if __name__ == "__main__":
    calculate_server()