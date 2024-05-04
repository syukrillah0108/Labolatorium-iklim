#include "./on_data.h"

void setup(){
    Serial.begin(115200);
    setup_espnow();
}

void loop(){
    if(Serial.available()){
        sendData(Serial.readStringUntil('\n').toInt())
    }
}