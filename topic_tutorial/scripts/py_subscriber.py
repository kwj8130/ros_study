#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from std_msgs.msg import String

def msgCallback(msg):
    rospy.loginfo("msg : %s", msg.data) #메세지는 클래스, 데이터는 클래스변수기 때문에 풀로 써줘야함.

def listener():
    rospy.init_node("py_subscriber")
    rospy.Subscriber("my_topic", String, msgCallback, queue_size=100) 
    #토픽이름, c++에서는 큐사이즈가 바로나왔지만 콜백에는 자료형이 없기때문에 메세지타입인 스트링을 넣어줘야함, 메세지받았을 때 실행하는 콜백함수, 큐사이즈

    rospy.spin() #대기하는 동시에 무한반복하면서 함수가 오길 기다림

if __name__ == "__main__": # 이 파일을 실행할때만 이 함수를 쓴다. 즉, 리스너를 쓰겠다. 다른곳에서 리스너를 쓸때는 메인이안됨.
    listener()