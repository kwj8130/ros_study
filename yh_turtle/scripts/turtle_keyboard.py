#!/usr/bin/python3
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist

class TurtleKeyboard:
    def __init__(self):  # 인스턴스(클래스로 만들어진 객체(오브젝트))가 만들어질때 호출이되는게 init
        self.sub = rospy.Subscriber("cmd_vel", Twist, self.msgCallback)
        self.pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=100)

    def msgCallback(self, msg): # 메세지를 서브스크라이브했을때 호출
        self.pub.publish(msg)

if __name__ == "__main__":
    rospy.init_node("turtle_keyboard")
    turtle_keyboard = TurtleKeyboard()
    rospy.spin() #서브스크라이버가 메세지 받는거 대기

