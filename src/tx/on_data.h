#include <esp_now.h>
#include <WiFi.h>

// KIRIM DATA
uint8_t broadcastAddress[] = {0x48, 0xE7, 0x29, 0xB6, 0xF4, 0x98};

esp_now_peer_info_t peerInfo;

String DataSend;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  if (status == ESP_NOW_SEND_SUCCESS) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }
}

void setup_send(){
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_register_send_cb(OnDataSent);

    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
     
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        Serial.println("Failed to add peer");
        return;
    }
}

void send_data(){
  // Konversi String ke array byte
  uint8_t dataToSend[DataSend.length() + 1];
  DataSend.getBytes(dataToSend, DataSend.length() + 1);

  esp_err_t result = esp_now_send(broadcastAddress, dataToSend, DataSend.length() + 1);
}

// TERIMA DATA
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
    Serial.println((char*)data);
}

void setup_rec(){
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
    }

    esp_now_register_recv_cb(OnDataRecv);
}