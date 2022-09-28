# ros_study
my first ros study

### 2022년 9월 27일 ROS 학습시작
- topic_tutorial 패키지생성
- my_publisher, my_subscriber 노드 생성
- cm으로 빌드실행 후 roscore, rosrun 실행

### 2022년 9월 28일 ROS 파이썬
- topic_tutorial 패키지에 python script 추가
- py_publisher.py, py_subscriber.py 노드생성
- cm으로 빌드실행 후 roscore, rosrun 실행

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