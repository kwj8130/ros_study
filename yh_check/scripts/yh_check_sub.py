#!/usr/bin/python3
#-*- coding: utf-8 -*-

import rospy
from yh_check.msg import YhCheck

class MyCheck:
    def __init__(self):
        self.sub_distance = rospy.Subscriber("check_distance", YhCheck, self.distanceCallback)
        self.sub_camera = rospy.Subscriber("check_camera", YhCheck, self.cameraCallback)
        self.distance = True
        self.camera = True

    def distanceCallback(self, msg): #클래스 안에서 생성하려면 무조건 self를 작성해야함.
        self.distance = msg.data
        if self.distance and self.camera:
            rospy.loginfo("OK")

    def cameraCallback(self, msg):
        self.camera = msg.data
        if self.distance and self.camera:
            rospy.loginfo("OK")

if __name__ == "__main__":
    rospy.init_node("yh_check_sub")
    my_check = MyCheck()
    rospy.spin()



'''class Calculator:
    def __init__(self): # 첫번째는 무조건 self
        self.result = 0

    def add(self, num):
        self.result += num
        return self.result

    def sub(self, num):
        self.result -= num
        return self.result

    def mul(self, num):
        self.result *= num
        return self.result

    def div(self, num):
        return self.result / num  # 바로계산을해버림

cal = Calculator()
cal.add(10) 
cal.sub(4)
cal.mul(2)
cal.div(3)

print(cal.add(4))
print(cal.add(1))
print(cal.add(5))
print(cal.add(8))
print(cal.add(-14))
print(cal.add(40))

class MyCalculator(Calculator):
'''