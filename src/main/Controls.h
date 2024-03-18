const uint8_t MAX_VALUES = 6;
uint8_t con_val[MAX_VALUES];

uint8_t led1, led2, led3, led4, lembap = 0;

#define p_led1 6
#define p_led2 9
#define p_led3 10
#define p_led4 11
#define p_lembap 5

void up_con_val(String data){
    for (int i = 0; i < MAX_VALUES; i++) {
        int commaIndex = data.indexOf(',');
        
        if (commaIndex != -1) {
            con_val[i] = data.substring(0, commaIndex).toInt();
            data = data.substring(commaIndex + 1);
        } else {
            // Jika tidak ada koma lagi, simpan nilai terakhir
            con_val[i] = data.toInt();
    }
  }
}

void con_led(){
    analogWrite(p_led1, con_val[0]);
    analogWrite(p_led2, con_val[1]);
    analogWrite(p_led3, con_val[2]);
    analogWrite(p_led4, con_val[3]);
}