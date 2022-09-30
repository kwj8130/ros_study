#!/usr/bin/python3
# -*- coding: utf-8 -*-
import rospy
from yh_star.msg import YhStarMsg

def msgCallback(msg):
    n = msg.data
    # n/2 => 실수 + 정수 ===> 숫자형

    for i in range(1, n//2+1): # 목 연산자//, i = 1 ~ n//2까지 들어감 
        for j in range(i): # j = 0
            print("*", end='') # end에는 줄바꿈이 기본으로 있지만 엔터치지 말고 별을 찍으라고 ''을 입력시킴
        print()
    for i in range(n//2+1, n+1): # i = n//2부터 n까지 들어감 n에 숫자를 넣어서 비교를하고, 숫자를세는 기준은 처음부터센다. ex. n = 3 3//2+1, 3+1 = 2, 4 즉, 2, 3을 i에 집어넣고 차례대로 계산해보면됨.
        for j in range(n-i+1):
            print("*", end='')
        print()

def star_printer():
    rospy.init_node("yh_star_sub")
    rospy.Subscriber("yh_star_topic", YhStarMsg, msgCallback)
    rospy.spin()

if __name__ == "__main__":
    star_printer()