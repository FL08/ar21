/*
 예제 7.2
 서보모터 구동
*/
 
// 서보모터 라이브러리 불러오기
#include <Servo.h> 

// 서보모터 이름 설정
Servo motor1; 

// 서보 모터 신호핀 설정
int servoMotorPin = 9;
                   
int Switch1_Pin = 2;                   
int Switch2_Pin = 3;                  
// 포텐쇼미터 핀 설정
int potentioMeterPin = 0;

// 모터 각도 변수 설정
int motorAngle;
int motorAngleOld;

void setup() {
  
  // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
  motor1.attach(servoMotorPin,600,2400);
  pinMode(Switch1_Pin,INPUT);
  pinMode(Switch2_Pin,INPUT);

  // 시리얼 통신 설정  
  Serial.begin(9600);
}

void loop(){
  // 포텐쇼미터 값을 읽어옴
  int potentioMeter = analogRead(potentioMeterPin);

  // 포텐쇼미터 값을 모터 각도로 변환한다
  motorAngle = map(potentioMeter,0,1023,0,180);

  // 모터에 각도값을 전달한다
  motor1.write(motorAngle);

  // 이전각도와 현재 각도가 같지 않으면 시리얼 모니터에 각도를 출력한다.  
  if(motorAngle != motorAngleOld){
    Serial.print("Servo Motor Angle is: ");
    Serial.println(motorAngle);
  }
 if (digitalRead(Switch1_Pin) == LOW) {
    motorAngle += 15;
 }
    else if (digitalRead(Switch2_Pin) == LOW) {
    motorAngle -= 15;
    motor1.write(motorAngle);
    // 1초 동안 대기합니다.
   
  }
  delay(500);

  // 현재의 모터 각도를 저장한다.
  motorAngleOld = motorAngle;
  
  delay(20);

}
