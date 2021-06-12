#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

const int RedPin = D6;
const int BluePin = D7;
const int GreenPin = D8;
const int YellowPin = D9;

void setup() {
  // 시리얼 통신 속도
  Serial.begin(9600);
  // 스위치 입력 선언
  pinMode(RedPin,INPUT);
  pinMode(BluePin,INPUT);
  pinMode(GreenPin,INPUT);
  pinMode(YellowPin,INPUT);
  // 블루투스 키보드 셋업
  bleKeyboard.begin();
}

void loop() {

  int RedState = digitalRead(RedPin);
  int BlueState = digitalRead(BluePin);
  int GreenState = digitalRead(GreenPin);
  int YellowState = digitalRead(YellowPin);
  // 빨간색 버튼 (비상 버튼 ALT+F4)
  if(RedState == LOW){
    Serial.println("Red Switch LOW...");
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_F4);
    delay(100);
    bleKeyboard.release(KEY_LEFT_ALT);
    bleKeyboard.release(KEY_F4);
  }
  // 파란색 버튼
  if(BlueState == LOW){
    Serial.println("Blue Switch LOW...");
    bleKeyboard.print("1234"); //암호를 입력할 부분
    bleKeyboard.press(KEY_RETURN);
    delay(100);
    bleKeyboard.release(KEY_RETURN);
  }
  // 초록색 버튼
  if(GreenState == LOW){
    Serial.println("Green Switch LOW...");
    bleKeyboard.print("4567"); //암호를 입력할 부분
    bleKeyboard.press(KEY_RETURN);
    delay(100);
    bleKeyboard.release(KEY_RETURN);
  }
  // 노란색 버튼
  if(YellowState == LOW){
    Serial.println("Yellow Switch LOW...");
    bleKeyboard.print("6789"); //암호를 입력할 부분
    bleKeyboard.press(KEY_RETURN);
    delay(100);
    bleKeyboard.release(KEY_RETURN);
  }
  delay(200);
}
