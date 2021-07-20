# 1. 리눅스 설치

## 1-1. virtualBox 및 ubuntu 설치 (ubuntu 20.04)

![2 iso설치완료](https://user-images.githubusercontent.com/14107670/126293324-7e1fa3ab-338d-4356-a250-5ebb3887817e.png)
![3 우분투설치중](https://user-images.githubusercontent.com/14107670/126293538-1d206603-58d2-4e0b-a94d-f53e34e54157.png)
![4 설치완료+터미널](https://user-images.githubusercontent.com/14107670/126294148-7c4e04a5-65b7-474e-8246-be58452113c0.png)


## 1-2. ssh환경 구축
![6 sudo_apt_install_openssh-server](https://user-images.githubusercontent.com/14107670/126294274-e2e2963d-038b-46ce-be80-8986973b0444.png)
![7 sudo_systemctl_status_ssh](https://user-images.githubusercontent.com/14107670/126294283-7975c726-836b-4ad1-84ce-15dbd11a59ae.png)

sudo apt install opernssh-serverd 명령어를 이용하여 ssh환경을 설치하고

sudo systemctl status ssh 명령어를 통해 ssh가 잘 작동하는지 확인하였다.

## 1-3. 계정생성
![8 id와비밀번호추가](https://user-images.githubusercontent.com/14107670/126294514-c437f180-6b2c-4fbe-a8c0-7286a9f3cdbc.png)

sudo useradd [ID] 를 통해 K009라는 계정을 생성

sudo userpwd [ID] 를 통해 K009라는 계정에 비밀번호를 설정했다.

## 1-4. 로컬 환경에서 ssh로 접속
![10 로그인](https://user-images.githubusercontent.com/14107670/126295426-3b6a8c17-3616-4d25-96a8-276210846820.png)

우분투에선 포트포워딩 및 로컬환경에선 ssh [ID]@[IP] 를 통해 ssh로 접속하였다.

## 1-5. backup 디렉토리를 생성하고 권한을 764로 바꾼다
![11 mkdir_backup](https://user-images.githubusercontent.com/14107670/126295898-7628e191-3f2d-4425-9fad-d8c6fe28567f.png)

mkdir backup 을 통해 디렉토리를 생성하고 chmod를 통해 권한을 바꾼것을 ls -l을 통해 확인하였다.

## 1-6. 오늘날짜 + 서울 시간대로 동기화 및 출력
![12 시간동기화](https://user-images.githubusercontent.com/14107670/126296361-adc2998b-31ac-4463-aa5a-e5a792681e3d.png)
우측하단의 시간과 비교하면 동기화된 것을 확인할 수 있다.

## 1-7. 코틀린 설치 및 실행
![13 코틀린설치_](https://user-images.githubusercontent.com/14107670/126297140-f8da76ed-8259-4339-9a6c-21db4ff85589.png)
![14 코틀린설치2_](https://user-images.githubusercontent.com/14107670/126297189-d5f17eb2-4bc3-4759-8ac0-e0b2bbb1f580.png)
![14-2 코틀린버전_](https://user-images.githubusercontent.com/14107670/126297195-7cc88144-9f85-41e3-bfc6-c1bc3e495ae5.png)
위의 두 명령어를 통해 코틀린을 설치하고

kotlin -version을 이용하여 설치되었음을 확인하였다.

![15-1 코틀린실행](https://user-images.githubusercontent.com/14107670/126297438-c0bba8a1-c74d-4917-9d27-ff72c0eca88d.png)
kotlinc main.kt 로인해 MainKt.class가 만들어지고 kotlin MainKt로 실행하였다.



