#include "./on_data.h"
 
void setup() {
  Serial.begin(115200);
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