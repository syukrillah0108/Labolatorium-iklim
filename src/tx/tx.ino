#include "./on_data.h"

//FC:B4:67:F0:DD:00
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
  setup_send();
  setup_rec();
}

void loop() {
  if(Serial2.available()>0){
    DataSend = Serial2.readStringUntil('\n');
    send_data();
  }
}