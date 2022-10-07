#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
import math
import sys
from turtlesim.srv import TeleportAbsolute, TeleportAbsoluteRequest

class YhTurtleCircle:
    def __init__(self, radius):
        self.radius = radius # 넣어줄값
        self.pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=10)  #cmd_vel 속도
        self.teleport_client = rospy.ServiceProxy("turtle1/teleoport_absolute", TeleportAbsolute)
        self.msg = Twist()
        self.loop_rate = rospy.Rate(1)

    def run(self):
        self.call(5.544445, 5.544445 - self.radius, 0)

        self.msg.linear.x = self.radius * math.pi * 2 # 보고있는 방향으로 전진
        self.msg.angular.z = math.pi * 2  # 앞으로가면서 1바퀴를 돈다.


        while not rospy.is_shutdown():
            self.pub.publish(self.msg)
            self.loop_rate.sleep()

    def call(self, x, y, theta):
        req = TeleportAbsoluteRequest()
        req.x = x
        req.y = y
        req.theta = theta
        try:
            self.teleport_client(req)
        except rospy.ServiceException as e:
            rospy.logerr("Teleport failed : {e}")


if __name__ == "__main__":
    rospy.init_node("yh_turtle_circle")
    yh_turtle_circle = YhTurtleCircle(float(sys.argv[1]))
    yh_turtle_circle.run()