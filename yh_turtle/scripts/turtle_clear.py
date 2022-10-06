#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
from std_srvs.srv import Empty

class TurtleClear:
    def __init__(self):
        self.clear_client = rospy.ServiceProxy("clear", Empty)
    
    def call(self):
        try:
            self.clear_client() # 서비스통신을 리턴도 안받고 호출만하겠다.
        except rospy.ServiceException as e: #트라이가 실행하는 도중 오류가 나면 이 줄을 실행하는것이지만 아래의 구문을 수행하겠다는것.
            rospy.logerr(f"Failed : {e}")

if __name__ == "__main__":
    rospy.init_node("turtle_clear")
    turtle_clear = TurtleClear() 
    turtle_clear.call()