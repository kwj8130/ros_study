#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from std_msgs.msg import Int32

def msgCallback(msg):
    rospy.loginfo("msg : %d", msg.data)

def my_listener():
    rospy.init_node("py_second_sub")
    rospy.Subscriber("my_count", Int32, msgCallback, queue_size=100)
     #토픽이름, c++에서는 큐사이즈가 바로나왔지만 콜백에는 자료형이 없기때문에 정수타입인 Int32을 넣어줘야함, 메세지받았을 때 실행하는 콜백함수, 큐사이즈

    rospy.spin()

if __name__ == "__main__": # 메인일때만 마이 리스너를 실행시킬것이다.
    my_listener()