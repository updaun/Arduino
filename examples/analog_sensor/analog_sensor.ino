/**********************************************************************************
 * Author : (주)한국공학기술연구원
 * Program ID : analog_sensor
 * Description : 아날로그 센서(가변저항, 조도센서, 온도센서)값 확인
 **********************************************************************************/

const int potentiometer = A0;       // 가변저항
const int photoresistor = A1;       // 조도센서
const int temperature_sensor = A2;  // 온도센서

const int red_led = D2;     // 빨간색 LED
const int blue_led = D3;    // 파란색 LED
const int green_led = D4;   // 초록색 LED
const int yellow_led = D5;  // 노란색 LED

const int potentiometer_threshold = 1000;        // 가변저항 임계치
const int photoresistor_threshold = 500;         // 조도센서 임계치
const int temperature_sensor_threshold = 2250;   // 온도센서 임계치

void setup() {
  Serial.begin(9600);
  // 센서 모드 설정
  pinMode(potentiometer, INPUT);
  pinMode(temperature_sensor, INPUT);
  pinMode(photoresistor, INPUT);

  // LED 출력모드 설정
  pinMode(red_led, OUTPUT); 
  pinMode(blue_led, OUTPUT); 
  pinMode(green_led, OUTPUT); 
  pinMode(yellow_led, OUTPUT); 
}

void loop() {

  int A0_sensor_value = analogRead(potentiometer);
  int A1_sensor_value = analogRead(photoresistor);
  int A2_sensor_value = analogRead(temperature_sensor);
  
  // 가변저항
  if (A0_sensor_value > potentiometer_threshold) { // 조도 센서값이 cds_threshold 이상이면
    digitalWrite(green_led, HIGH); // LED 켜짐
    } else {
    digitalWrite(green_led, LOW); // LED 꺼짐
    }
  Serial.print("  가변저항 : ");
  Serial.println(A0_sensor_value);

  // 조도센서
  if (A1_sensor_value < photoresistor_threshold) { 
    digitalWrite(yellow_led, HIGH); // LED 켜짐
    } else {
    digitalWrite(yellow_led, LOW); // LED 꺼짐
    }
  Serial.print("  조도센서 : ");
  Serial.println(A1_sensor_value);

  // 온도센서
  if (A2_sensor_value > temperature_sensor_threshold) { 
    digitalWrite(red_led, HIGH); // LED 켜짐
    digitalWrite(blue_led, LOW); // LED 꺼짐
    } else {
    digitalWrite(red_led, LOW); // LED 꺼짐
    digitalWrite(blue_led, HIGH); // LED 켜짐
    }
    
  Serial.print("  온도센서 : ");
  Serial.println(A2_sensor_value);
  Serial.println("------------------------");
  
  delay(1000);
}


//┌────────────────────────────────┐
//│                                                      │
//│     (주)한국공학기술연구원 http://et.ketri.re.kr        │
//│                                                      │ 
//└────────────────────────────────┘
