// BLUETOOTH
#include "esp_bt_main.h"
#include "BluetoothSerial.h"
#include "esp_bt_device.h"
BluetoothSerial SerialBT;


//================================================================
void setup() 
//================================================================
{ 
  Serial.begin(57600);
  bluetooth_setup();

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

//================================================================
void loop() 
//================================================================
{  
  test_bluetooth();      
}


//================================================================
bool bluetooth_setup() 
//================================================================
{    
  delay(3000);
  if (!btStart()) {
    Serial.println("Failed to initialize controller");
    return false;
  }
 
  if (esp_bluedroid_init() != ESP_OK) {
    Serial.println("Failed to initialize bluedroid");
    return false;
  }
 
  if (esp_bluedroid_enable() != ESP_OK) {
    Serial.println("Failed to enable bluedroid");    
  }
  
  const uint8_t* point = esp_bt_dev_get_address();
  if (point == NULL) {
      Serial.println("esp_bt_dev_get_address() = NULL");
      return false;
  } 

  char bt_device_name[20];
  sprintf(bt_device_name, "ET-Board(%02X:%02X:%02X)", (int)point[3], (int)point[4], (int)point[5]); 
  //sprintf(bt_device_name, "TESTTEST");    
  SerialBT.begin(bt_device_name); //Bluetooth device name

  Serial.print("\n\n");
  Serial.print("Bluetooth Name is ");
  Serial.println(bt_device_name);  
}


//================================================================
void test_bluetooth()
//================================================================
{ 
  //test
  int temperature = analogRead(A0)/4;
  int humdity = analogRead(A1);
  
  char send_buffer[128] = "temperature : ";
  char buf1[16];    
  //String str = String(millis()/1000, DEC);
  String str1 = String(temperature, DEC);
  str1.toCharArray(buf1,6);
  strcat(send_buffer, buf1);
  strcat(send_buffer, " \xe2\x84\x83  humdity : ");
  char buf2[16];
  String str2 = String(humdity, DEC);
  str2.toCharArray(buf2,6);
  strcat(send_buffer, buf2);
  strcat(send_buffer, " %\n\r");
  
  Serial.print(send_buffer);
  SerialBT.write((const uint8_t *)send_buffer, strlen(send_buffer));
  
  
  delay(1000);
}
