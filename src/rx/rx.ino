#include "./on_data.h"
//MAC: fc:b4:67:f0:dd:00
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  pinMode(LED_BUILTIN, OUTPUT);
  setup_send();
  setup_rec();
}

void loop() {
  if(Serial.available()>0){
    DataSend = Serial.readStringUntil('\n');
    send_data();
  }
}