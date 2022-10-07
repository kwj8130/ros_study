# ROS_STUDY
my first ros study

### 2022년 9월 27일 ROS 학습시작
- [topic_tutorial](./topic_tutorial) 
- topic_tutorial 패키지생성
- my_publisher, my_subscriber 노드 생성
- cm으로 빌드실행 후 roscore, rosrun 실행

### 2022년 9월 28일 ROS 학습내용
- [topic_tutorial](./topic_tutorial) 
- topic_tutorial 패키지에 python script 추가
- py_publisher.py, py_subscriber.py 노드생성
- cm으로 빌드실행 후 roscore, rosrun 실행

- topic_second 패키지 생성
- second_pub, second_sub, py_second_pub, py_second_sub 노드 생성
- 과제 1

### 2022년 9월 29일 ROS 학습내용
- [msg_tutorial](./msg_tutorial)
    - msg_tutorial 패키지 생성
    - msg 디렉토리에 Mymsg.msg 생성
    - msg_publisher, msg_subscriber, py_msg_pub.py, py_msg_sub.py 노드생성
    - 빌드, 실행

### 2022년 9월 30일 ROS 학습내용
- [과제2 yh_star](./yh_star)
- for문 활용해서 별 찍기
    - yh_star 패키지 생성
    - yh_star_pub, yh_star_sub, yh_star_pub.py, yh_star_sub.py 노드생성
    - 빌드, 실행

- [과제3 yh_service](./yh_service)
    - yh_service 패키지 생성
    - yh_server, yh_client의 .cpp, .py를 작성
    - 빌드, 실행

### 2022년 10월 4일 ROS 학습내용
### [param_tutorial](./param_tutorial/)
- param_tutorial 패키지 생성
- 과제4, 과제5 패키지 생성
- calculate_server, calculate_client, calculate_server.py, calculate_client.py 노드 생성
- 빌드, 실행
- 파라미터 서버 활용
- [파라미터 서버 활용](#parameter-server)

### 2022년 10월 5일 ROS 학습내용
- 과제6, 과제7 패키지 생성
- yh_check_distance, yh_check_camera, yh_check_sub, yh_check_sub.py
- yh_connect_pub, yh_connect_sub_pub, yh_connect_sub.cpp와 .py 생성
- 빌드, 실행
- python class로 작성

### 2022년 10월 6일 ROS 학습내용
### [yh_turtle](./yh_turtle/)
- turtlesim 사용
- turtle_patrol, turtle_keyboard, turtle_clear, turtle_keyboard_clear .cpp, .py파일 생성
- [teleop_twist_keyboard] 설치

### 2022년 10월 7일 ROS 학습내용
### [yh_turtle](./yh_turtle/)
- turtlesim 사용2
- yh_turtle_circle, yh_turtle_triangle.py, turtle_goal.py 작성
- 빌드, 실행


### [과제4 yh_dual](./yh_dual/)
### [과제5 yh_difference](./yh_difference/)
### [과제6 yh_check](./yh_check/)
### [과제7 yh_connect](./yh_connect/)


## ROS 명령어
### roscore
- ROS Master를 실행시키는 명령어.
- 노드를 켜기 전에 가장 먼저 실행
'''bash 
    roscore
'''

### rosrun
- 노드를 실행시키는 명령어.
- rosrun 패키지이름 노드이름
'''bash
    rosrun <패키지이름> <노드이름>
'''

### catkin_create_pkg
- 현재 위치한 작업 공간에 패키지를 생성한다.
- catkin_creat_pkg 패키지이름 의존성
'''bash
    catkin_create_pkg <패키지이름> <의존성1> <의존성2>.... 
'''
''' bash
    catkin_create_pkg topic_tutorial roscpp rospy std_msgs
'''

### Publisher Node (정리할 예시)
- name :
- topic :
- msg : 
- 노드 설명


## msg 만드는 법
1. 패키지 안에 msg 디렉토리를 만든다. (패키지 생성 시 언어 및 모듈작성에서 message_generation를 추가.)
2. .msg 확장자의 파일을 만든다. (Mymsg.msg로 생성했다.)
3. 안에 내용을 작성한다.
4. CMakelists.txt 에서 설정한다.
5. 빌드 시 생성된다.

# service_tutorial
- 직접 작성한 AddTwoInts 서비스로 통신하는 패키지

### service node
- name :
- service :
- srv :
- 노드 설명

## srv 만드는 법
1. 패키지 안에 srv 디렉토리를 만든다.
2. .srv 확장자의 파일을 만든다.

### 같은 이름의 서버는 동시에 켤 수 없는게 서비스형태다.


### Parameter(변수) Server
- ROS Master에서 실행되고, 변수들을 담고 있는 서버
- ros::setParam(), ros::getParam(), rospy.set_param(), rospy.get_param() 등의 함수로 사용
- command line에서 rosparam으로 사용 가능

- rosparam list
    - 파라미터 서버의 모든 파라미터를 출력

'''bash
- juchajam@ubuntu:~$ rosparam list rosparam get <파라미터 이름>
'''

'''bash
- juchajam@ubuntu:~$ rosparam get <파라미터 이름>
    - 파라미터의 값을 출력함
'''

- rosparam set <파라미터 이름> [파라미터 값]
    - 파라미터의 값을 지정함
'''bash
- juchajam@ubuntu:~$ rosparam set <파라미터 이름> [파라미터 값]
'''

### teleop_twist_keyboard
- 키보드 입력을 받아 /cmd_vel 토픽의 geometry_msgs/Twist 메세지로 publish하는 노드
- 설치
'''bash
$ sudo apt install ros-melodic-teleop-twist-keyboard
'''
- 실행
'''bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
'''

### [roslaunch 실습] (#roslaunch)
- roscore와 launch파일에 있는 노드들을 실행시키는 명령
- launch 파일은 "패키지 디렉토리/launch'에 만든다.
- roslaunch 실행

'''bash
$ roslaunch <패키지이름> <런치파일이름>
'''

- launch 파일은 <launch> </launch> 태그 사이에 내용을 입력한다.
- node 태그는 패키지 이름, 노드타입, 노드이름을 입력한다.
- param 태그는 파라미터 이름, 값, 타입을 입력한다.
- rosluanch