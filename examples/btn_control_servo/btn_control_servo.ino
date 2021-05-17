#include <ESP32_Servo.h>

static const int servoPin = D5;

const int red_btn = D6;
const int blue_btn = D7;
const int yellow_btn = D8;
const int green_btn = D9;

Servo servo;

void setup() {
    Serial.begin(115200);
    servo.attach(servoPin);
    
    pinMode(red_btn, INPUT);
    pinMode(blue_btn, INPUT);
    pinMode(green_btn, INPUT);
    pinMode(yellow_btn, INPUT);
    
    servo.write(0);
}

void loop() {

  if (digitalRead(red_btn) == LOW) {
    Serial.println("빨간색 버튼이 눌렸습니다.");
    for(int posDegrees = 0; posDegrees <= 90; posDegrees++) {
        servo.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
  }
  if (digitalRead(blue_btn) == LOW) {
    Serial.println("파란색 버튼이 눌렸습니다.");
    for(int posDegrees = 90; posDegrees <= 180; posDegrees++) {
        servo.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
  }
  
  if (digitalRead(yellow_btn) == LOW) {
    Serial.println("노랑색 버튼이 눌렸습니다.");
    for(int posDegrees = 90; posDegrees >= 0; posDegrees--) {
        servo.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
  }
  
  if (digitalRead(green_btn) == LOW) {
    Serial.println("초록색 버튼이 눌렸습니다.");
    for(int posDegrees = 180; posDegrees >= 90; posDegrees--) {
        servo.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
  }
  
}
