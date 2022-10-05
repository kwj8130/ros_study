#!/usr/bin/python3
#-*- coding: utf-8 -*-

import rospy
from std_msgs.msg import Float32

class ConnectSub:
    def __init__(self):
        self.sub = rospy.Subscriber("yh_connect_float", Float32, self.msgCallback) #클래스 내부에서 만들것이기 때문에 self를 앞에붙여준것.

    def msgCallback(self, msg):
        rospy.loginfo(msg.data)

if __name__ == "__main__":
    rospy.init_node("yh_connect_sub")
    connect_sub = ConnectSub()
    rospy.spin()