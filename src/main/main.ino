#include "./Sensors.h"
#include "./Controls.h"

void setup() {
  Serial.begin(115200);
  
  pinMode(p_led1, OUTPUT);
  pinMode(p_led2, OUTPUT);
  pinMode(p_led3, OUTPUT);
  pinMode(p_led4, OUTPUT);
  pinMode(p_lembap, OUTPUT);

  dht.begin();
  Wire.begin();
  lightMeter.begin();
}

String data;
String Received;

void loop() {

  h = dht.readHumidity();
  t = dht.readTemperature();
  l = lightMeter.readLightLevel();

  data += String((l == -2.0 ? -1: l)) + ",";
  data += String(analogRead(A0)) + ",";
  data += String((isnan(h) ? 0 : h)) + ",";
  data += String((isnan(t) ? 0 : t));
  Serial.println(data);
  data = "";
  delay(100);
  if(Serial.available() > 0){
    Received = Serial.readStringUntil('\n');
    up_con_val(Received);
    con_led();
  }
}