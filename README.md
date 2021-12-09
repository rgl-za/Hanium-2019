# Hanium-2019: 돌꽁 🐳

<p float="left">
  <img src="https://user-images.githubusercontent.com/76260153/145200119-23556933-652f-43cc-ba8c-ceadf199f688.jpeg" width="400" />
  <img src="https://user-images.githubusercontent.com/76260153/145201321-cf5bfdd8-384a-443a-b319-338f7be2b91c.jpg" width="400" height="400"/> 
</p>

## 프로젝트 설명 
안전에 취약한 독거노인을 위한 인공지능 서비스를 겸비한 생활 안전 IoT 가습기   

- 개발 환경: Arduino IDE
- 개발 언어: C언어
- 인공지능 관련: KT AI Makers Kit 사용

## 프로젝트 목표(개요)
1) 3D 프린터를 이용한 돌고래 외형 모형 제작
2) 시판 가습기를 탑재하여 사용자가 원할 때 작동 가능
3) 생활 안전과 관련된 센서를 이용하여 돌고래 움직임 제어
4) 사용자와 간단한 일상 대화 나눔

## 팀원 및 역할 분담

- 하드웨어

|윤영미(팀장)|이미진|지현정|
|:-:|:-:|:-:|
|<img src="https://user-images.githubusercontent.com/76260153/145205942-d2de1b99-3e47-44fe-919f-ef52963441b0.png" width="300" height="300">|<img src="https://user-images.githubusercontent.com/76260153/145202298-80ceb27c-48f4-4dd9-9fca-036390af3a22.jpeg" width=300 height="300">|<img src="https://user-images.githubusercontent.com/76260153/145205067-7e76dd29-1de4-4409-9f85-f2ab73ed39a4.jpg" width=300 height="300">|

- 인공지능: 강서현
- 3D 프린터: 최예진

## 개발과정
#### 1. 외형 (외/내부)
![그림1](https://user-images.githubusercontent.com/76260153/145192368-717a679a-1876-4e9c-a06e-48dcde7982cf.png)
![그림2](https://user-images.githubusercontent.com/76260153/145192404-35464eae-10b1-4b58-b880-cbdfd7985870.png)
![그림3](https://user-images.githubusercontent.com/76260153/145192452-9d3a5f1f-8398-4673-bf23-fe6ad9f6dc80.png)
- Sketch UP을 활용하여 돌고래 모형의 모델링 작업
- 3D 프린터 사용
   
#### 2. 하드웨어
- 생활 안전과 관련된 센서 사용: 온습도 센서 (DHT11), 가스 센서 (MQ-5, 움직임 센서, 적외선 인체(움직임) 감지 센서 (HC-SR501)
<br>
<img width="1536" alt="스크린샷 2021-12-08 오후 7 30 01" src="https://user-images.githubusercontent.com/76260153/145192884-5ae6daab-d195-411b-be2f-085f5963eda8.png">

- 센서 값이 평균일 때 돌고래의 눈 상태는 '^' 이며, LED 색상은 일반 무드등 색상인 주황색이 default 상태
 
- 센서 값이 기준치 이상일 때 각기 상황에 맞춰 LED 색상이 변함, 돌고래의 눈이 'ㅠ'로 변하고 돌고래의 날개가 움직임 
  - 온습도 센서 (DHT11)
    ![그림4](https://user-images.githubusercontent.com/76260153/145192570-af0cda8f-b32a-4e1e-bd12-aea1aecac67e.jpg)
    <br>
    습도가 70% 이상일 때 돌고래 하단에 부착된 LED가 파랗게 변함 
    
  - 가스 센서 (MQ-5)
    ![그림5](https://user-images.githubusercontent.com/76260153/145192693-636e9151-47e6-44bc-82b7-7fb7d27faabc.png)
    <br>
    일산화탄소가 30ppm 이상 시 돌고래 하단에 부착된 LED가 붉게 변함 
    
  - 적외선 인체(움직임) 감소 (HC-SR501)
    사용자의 움직임 감지
  
    
## 프로젝트 목표 변경 
#### 1) 라즈베리파이 사용 ➡️ 아두이노 사용
#### 변경 사유: 라즈베리파이의 결함으로 기한에 맞춰 제출하기 위해 아두이노 사용 

#### 2) KT AI Makers을 활용한 학습된 인공지능 사용 ➡️ KT AI Makers에서 기본으로 제공해주는 인공지능 사용
#### 변경 사유: 프로젝트 목표 변경 (1)의 이유로 아두이노를 사용함으로써 학습된 인공지능 적용이 불가능해져 기본 제공 인공지능 사용 
    
## 프로젝트 결과물
프로젝트 소개 영상: https://youtu.be/MUQgg_9Oza8
<br>
1. default 상태 
<img src="https://user-images.githubusercontent.com/76260153/145196207-f5c5bef6-808b-4e3f-bd22-6f2369f43fc2.gif">
<br> 
2. 높은 습도 감지 상태 
<img src="https://user-images.githubusercontent.com/76260153/145196113-b3480d1a-ac93-43d6-b8a2-8f875e2be4a5.gif">
<br>
3. 가스 누출 감지 상태
<img src="https://user-images.githubusercontent.com/76260153/145196850-b138c0f4-e8b4-4ae4-ab7a-9bee22422cd6.gif">
