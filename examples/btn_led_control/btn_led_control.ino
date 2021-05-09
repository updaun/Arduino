void setup() {
  
  pinMode(D2, OUTPUT);       // LED 출력모드 설정
  pinMode(D3, OUTPUT);       // LED 출력모드 설정
  pinMode(D4, OUTPUT);       // LED 출력모드 설정
  pinMode(D5, OUTPUT);       // LED 출력모드 설정
  
  pinMode(D6, INPUT); // 빨강 버튼 입력모드 설정
  pinMode(D7, INPUT); // 빨강 버튼 입력모드 설정
  pinMode(D8, INPUT); // 빨강 버튼 입력모드 설정
  pinMode(D9, INPUT); // 빨강 버튼 입력모드 설정
  
}
 
void loop() {
  
  int red_btn = digitalRead(D6); // 버튼의 디지털 값을 변수에 저장
  int blue_btn = digitalRead(D7); // 버튼의 디지털 값을 변수에 저장
  int yellow_btn = digitalRead(D8); // 버튼의 디지털 값을 변수에 저장
  int green_btn = digitalRead(D9); // 버튼의 디지털 값을 변수에 저장
  
  
  if (red_btn == HIGH) {  // 변수가 HIGH면
    digitalWrite(D2, LOW);  // LED 끄기
  } else {                  // 아니면
    digitalWrite(D2, HIGH); // LED 켜기
  }
  
  if (blue_btn == HIGH) {  // 변수가 HIGH면
    digitalWrite(D3, LOW);  // LED 끄기
  } else {                  // 아니면
    digitalWrite(D3, HIGH); // LED 켜기
  }
  
  if (yellow_btn == HIGH) {  // 변수가 HIGH면
    digitalWrite(D4, LOW);  // LED 끄기
  } else {                  // 아니면
    digitalWrite(D4, HIGH); // LED 켜기
  }
  
  if (green_btn == HIGH) {  // 변수가 HIGH면
    digitalWrite(D5, LOW);  // LED 끄기
  } else {                  // 아니면
    digitalWrite(D5, HIGH); // LED 켜기
  }
  
}
