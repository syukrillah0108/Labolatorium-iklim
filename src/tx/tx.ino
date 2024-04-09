#include "./on_data.h"

//MAC: 48:e7:29:b6:f4:98
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  setup_send();
  setup_rec();
}

void loop() {
  if(Serial.available()>0){
    DataSend = Serial.readStringUntil('\n');
    send_data();
  }
}