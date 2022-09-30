#!/usr/bin/python
# -*- coding: utf-8 -*-
import rospy
from service_tutorial.srv import AddTwoInts # 패키지이름, 우리가만든 srv를 꺼낸다
import sys # a와 b를 가져오기위함

def add_two_ints_client(a, b):

    rospy.wait_for_service("add_two_ints") # 서비스 서버가 켜질때까지 기다리는것, 서비스 이름넣기

    try:
        my_client = rospy.ServiceProxy("add_two_ints", AddTwoInts) # 켜지면 클라이언트를 만들어주는 함수(프록시), 서비스 이름과 서비스타입을 넣어준다.
        res = my_client(a, b) # a와 b를 넣고 클라이언트를 부르면 알아서 요청을 보내고 응답을 받아온다.
        return res.result

    except rospy.ServiceException as e: # 에러발생 시 잡아내는것. (현재는 서비스에러)
        rospy.logerr("Service call failed: %s", e)

if __name__ == "__main__": # 이 파일을 실행했을때만 아래의 함수들을 사용하게된다.
    rospy.init_node("py_client") # 노드 이름넣기


# rosrun service_tutorial 'py_client.py 1 2'
    if len(sys.argv) != 3: # 값이 3개인지 아닌지 확인차
        rospy.loginfo("rosrun service_tutorial py_client.py a b")
        rospy.loginfo("a, b: int32 number")
        sys.exit(1) # 프로그램으로 종료하는 장치

    a = int(sys.argv[1]) # a와 b를 숫자로 변경(int의 역할)하여 입력됨
    b = int(sys.argv[2])
    result = add_two_ints_client(a, b) # a, b를 가져와 결과값을 뽑음
    rospy.loginfo("send: a=%d b=%d", a, b)
    rospy.loginfo("response: result=%d", result)