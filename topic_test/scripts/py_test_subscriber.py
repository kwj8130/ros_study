#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from std_msgs.msg import Int64

def msgCallback(msg):
    rospy.loginfo("msg : %d", msg.data)

def my_tester():
    rospy.init_node("py_test_subscriber")
    rospy.Subscriber("my_test", Int64, msgCallback, queue_size=100)

    rospy.spin()

if __name__ == "__main__":
    my_tester()