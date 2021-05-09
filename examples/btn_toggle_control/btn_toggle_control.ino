int red_led_state = LOW;      // LED 상태
int red_btn_reading;          // btn 상태
int red_btn_previous = LOW;   // btn 이전 상태

int blue_led_state = LOW;      // LED 상태
int blue_btn_reading;          // btn 상태
int blue_btn_previous = LOW;   // btn 이전 상태

int green_led_state = LOW;      // LED 상태
int green_btn_reading;          // btn 상태
int green_btn_previous = LOW;   // btn 이전 상태

int yellow_led_state = LOW;      // LED 상태
int yellow_btn_reading;          // btn 상태
int yellow_btn_previous = LOW;   // btn 이전 상태
 
unsigned long previousMillis = 0;       // LED가 ON/OFF 토글된 마지막 시간
long debounce = 200;                    // Debounce 타임 설정
 
void setup()
{
  
  pinMode(D2, OUTPUT);       // 빨강 LED 출력모드 설정
  pinMode(D3, OUTPUT);       // 파랑 LED 출력모드 설정
  pinMode(D4, OUTPUT);       // 초록 LED 출력모드 설정
  pinMode(D5, OUTPUT);       // 노랑 LED 출력모드 설정
  
  pinMode(D6, INPUT);       // 빨강 버튼 입력모드 설정
  pinMode(D7, INPUT);       // 파랑 버튼 입력모드 설정
  pinMode(D8, INPUT);       // 초록 버튼 입력모드 설정
  pinMode(D9, INPUT);       // 노랑 버튼 입력모드 설정
    
}
 
void loop()
{

red_led_control(D6, D2);
blue_led_control(D7, D3);
green_led_control(D8, D4);
yellow_led_control(D9, D5);


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

void blue_led_control(int btn, int led)
{  
  blue_btn_reading = digitalRead(btn);  // btn 상태 읽음
  //btn 가 눌려졌고 스위치 토글 눌림 경과시간이 Debounce 시간보다 크면 실행
  if (blue_btn_reading == HIGH && blue_btn_previous == LOW && millis() - previousMillis > debounce) {
    if (blue_led_state == HIGH)    // LED 가 HIGH 면 LOW 로 바꿔준다.
      blue_led_state = LOW;
    else                  // LED 가 LOW 면 HIGH 로 바꿔준다.
      blue_led_state = HIGH;
    previousMillis = millis();
  }
  digitalWrite(led, blue_led_state);
  blue_btn_previous = blue_btn_reading;
}

void green_led_control(int btn, int led)
{  
  green_btn_reading = digitalRead(btn);  // btn 상태 읽음
  //btn 가 눌려졌고 스위치 토글 눌림 경과시간이 Debounce 시간보다 크면 실행
  if (green_btn_reading == HIGH && green_btn_previous == LOW && millis() - previousMillis > debounce) {
    if (green_led_state == HIGH)    // LED 가 HIGH 면 LOW 로 바꿔준다.
      green_led_state = LOW;
    else                  // LED 가 LOW 면 HIGH 로 바꿔준다.
      green_led_state = HIGH;
    previousMillis = millis();
  }
  digitalWrite(led, green_led_state);
  green_btn_previous = green_btn_reading;
}

void yellow_led_control(int btn, int led)
{  
  yellow_btn_reading = digitalRead(btn);  // btn 상태 읽음
  //btn 가 눌려졌고 스위치 토글 눌림 경과시간이 Debounce 시간보다 크면 실행
  if (yellow_btn_reading == HIGH && yellow_btn_previous == LOW && millis() - previousMillis > debounce) {
    if (yellow_led_state == HIGH)    // LED 가 HIGH 면 LOW 로 바꿔준다.
      yellow_led_state = LOW;
    else                  // LED 가 LOW 면 HIGH 로 바꿔준다.
      yellow_led_state = HIGH;
    previousMillis = millis();
  }
  digitalWrite(led, yellow_led_state);
  yellow_btn_previous = yellow_btn_reading;
}
