#!/usr/bin/python
# -*- coding: utf-8 -*-
import rospy
from service_tutorial.srv import AddTwoInts, AddTwoIntsResponse

def add(req):  #콜백함수
    result = req.a + req.b
    rospy.loginfo("a=%d, b=%d", req.a, req.b)
    rospy.loginfo("response: result=%d", result)
    return AddTwoIntsResponse(result) #더한값을 넣어서 돌려보내준다.

#class MyClass():
#    def __init__(self, a):
#        self.a = a
#
#myclass = MyClass(10)

def add_two_ints_server():
    rospy.init_node("py_server") #노드이름
    
    my_server = rospy.Service("add_two_ints", AddTwoInts, add) # my_server는 굳이 안써도됨. 서비스이름 서비스타입 콜백

    rospy.loginfo("Service Server Ready.") # 뭐라고 출력하는지 표시해주는 함수
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()
