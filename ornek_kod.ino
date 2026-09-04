#include <Keypad.h>

const byte SATIR = 4; 
const byte SUTUN = 4; 

char tusHaritasi[SATIR][SUTUN] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Aldığınız hatalı çıktılara göre düzeltilmiş gerçek pin haritası:
byte satirPinleri[SATIR] = {9,8,7,6}; // Satırlar D5, D4, D3, D2 olarak ters sıralandı
byte sutunPinleri[SUTUN] = {5,4,3,2}; // Sütunlar D9, D8, D7, D6 olarak ters sıralandı

Keypad keypad = Keypad(makeKeymap(tusHaritasi), satirPinleri, sutunPinleri, SATIR, SUTUN);

void setup() {
  Serial.begin(9600);
  Serial.println("Keypad Hazir. Bir tusa basin...");
}

void loop() {
  char basilanTus = keypad.getKey();
  
  if (basilanTus) {
    Serial.print("Basilan Tus: ");
    Serial.println(basilanTus);
  }
}
