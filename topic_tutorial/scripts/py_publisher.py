#!/usr/bin/python
#-*- coding: utf-8 -*-
import rospy # ros 파이썬
from std_msgs.msg import String #스탠다드 메세지의 스트링을 가져다 쓰겠다.

def talker():
    pub = rospy.Publisher("my_topic", String, queue_size=100) #토픽이름, 메세지타입(자료형), 큐사이즈
    rospy.init_node("py_publisher") #노드 이름설정, c++의 ros.init과 같음

    loop_rate = rospy.Rate(10) # 주기설정 0.1초에 1번

    msg = String() # 메세지는 스트링타입이다
    msg.data = "Hi"

    while not rospy.is_shutdown(): # 안꺼졌으면 트루, 결국 계속 반복
        pub.publish(msg) # 위의 메시지를 퍼블리시함
        loop_rate.sleep()

if __name__ == "__main__": # __name__변수가 __main__일때만 talker를 실행 즉, 이 파일을 먼저 실행시킬때가 진짜 name이 되고, 먼저 실행을 시켰기 때문에 다른곳에서 작동을 시켜도 실행이안된다.
    try:
        talker()
    except rospy.ROSInterruptException:
        pass