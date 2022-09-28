#!/usr/bin/python
#-*- coding: utf-8-*-

import rospy
from std_msgs.msg import Int64

def my_test():
    rospy.init_node("py_test_publisher")
    pub = rospy.Publisher("my_test", Int64, queue_size=100)

    loop_rate = rospy.Rate(1)

    msg = Int64()
    msg.data = 0

    while not rospy.is_shutdown():
        pub.publish(msg)
        loop_rate.sleep()
        msg.data += 1

if __name__ == "__main__":
    try:
        my_test()
    except rospy.ROSInterruptException:
        pass