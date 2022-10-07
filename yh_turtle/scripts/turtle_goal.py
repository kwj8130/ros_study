#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

class TurtleGoal:
    def __init__(self):
        self.sub = rospy.Subscriber("turtle1/pose", Pose, self.update_pose)
        self.pub = rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=100)
        self.pose = Pose() # 시작지점의 정보
        self.goal_pose = Pose() # 목표지점의 정보
        self.loop_rate = rospy.Rate(10)

        #self.goal_x = float(input("x : "))
        #self.goal_y = float(input("y : "))
        #self.goal_theta = float(input("theta : "))
        
    def update_pose(self, msg):
        self.pose = msg
        self.pose.x = round(self.pose.x, 4) # round 함수를 써서 소수점 4자리까지만 표기하게끔 정리
        self.pose.y = round(self.pose.y, 4)

    def euclidean_distance(self):
        # self.pose ----> self.goal_pose
        diff_x = self.goal_pose.x - self.pose.x
        diff_y = self.goal_pose.y - self.pose.y
        return math.sqrt((diff_x * diff_x) + (diff_y * diff_y))

    def linear_vel(self, constant=1.5):
        return constant * self.euclidean_distance()
    
    def steering_angle(self):
        return math.atan2((self.goal_pose.y - self.pose.y), (self.goal_pose.x - self.pose.x))

    def angular_vel(self, constant=6):
        return constant * (self.steering_angle() - self.pose.theta)

    def run(self):
        self.goal_pose.x = float(input("x 좌표 : "))
        self.goal_pose.y = float(input("y 좌표 : "))

        tolerance = float(input("오차 : "))

        msg = Twist()

        while self.euclidean_distance() >= tolerance:
            msg.linear.x = self.linear_vel()
            msg.angular.z = self.angular_vel()

            self.pub.publish(msg)
            self.loop_rate.sleep()

        msg.linear.x = 0
        msg.angular.z = 0
        self.pub.publish(msg)
        rospy.loginfo("Goal!")

if __name__ == "__main__":
    rospy.init_node("turtle_goal")
    turtle_goal = TurtleGoal()
    turtle_goal.run()