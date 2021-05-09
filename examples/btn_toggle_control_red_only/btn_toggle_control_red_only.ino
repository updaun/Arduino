int red_led_state = LOW;      // LED 상태
int red_btn_reading;          // btn 상태
int red_btn_previous = LOW;   // btn 이전 상태
 
unsigned long previousMillis = 0;       // LED가 ON/OFF 토글된 마지막 시간
long debounce = 200;                    // Debounce 타임 설정
 
void setup()
{
  pinMode(D2, OUTPUT);       // 빨강 LED 출력모드 설정
  pinMode(D6, INPUT);       // 빨강 버튼 입력모드 설정
}
 
void loop()
{
red_led_control(D6, D2);
}

void red_led_control(int btn, int led)
{  
  red_btn_reading = digitalRead(btn);  // btn 상태 읽음
  //btn 가 눌려졌고 스위치 토글 눌림 경과시간이 Debounce 시간보다 크면 실행
  if (red_btn_reading == HIGH && red_btn_previous == LOW && millis() - previousMillis > debounce) {
    if (red_led_state == HIGH)    // LED 가 HIGH 면 LOW 로 바꿔준다.
      red_led_state = LOW;
    else                  // LED 가 LOW 면 HIGH 로 바꿔준다.
      red_led_state = HIGH;
    previousMillis = millis();
  }
  digitalWrite(led, red_led_state);
  red_btn_previous = red_btn_reading;
}
