const uint8_t MAX_VALUES = 4;

void processAndStoreCSV(String data) {
  String values[MAX_VALUES];

  for (int i = 0; i < MAX_VALUES; i++) {
    int commaIndex = data.indexOf(',');
    if (commaIndex != -1) {
      values[i] = data.substring(0, commaIndex);
      data = data.substring(commaIndex + 1);
    } else {
      // Jika tidak ada koma lagi, simpan nilai terakhir
      values[i] = data;
    }
  }

  for (int i = 0; i < MAX_VALUES; i++) {
    Serial.print(values[i]);
    Serial.print(",");
  }Serial.println();
}

