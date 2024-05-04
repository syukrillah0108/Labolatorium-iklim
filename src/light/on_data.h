#include <ESP8266WiFi.h>
#include <espnow.h>

typedef struct struct_message {
    int LED1, LED2, LED3, LED4;
} struct_message;

struct_message LED;

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&LED, incomingData, sizeof(LED));
  Serial.println(LED.LED1);
}

void setupRec() {
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}