#include <Wire.h>

#define SLAVE_ADDRESS 0x2A        // عنوان السليف لازم يطابق STM32
#define MAX_BUFFER     32

volatile uint8_t rxBuffer[MAX_BUFFER];
volatile uint8_t rxLength = 0;
volatile bool newDataFlag = false;

// رسالة جاهزة يرد بيها السليف عند قراءة الماستر
const char txMessageOk[] = "OK";
const char txMessageError[] = "ERROR";

void setup() {
  Serial.begin(115200);
  Serial.println("=== Arduino I2C Slave (Interrupt Mode) ===");
  Serial.print("Slave Address: 0x");
  Serial.println(SLAVE_ADDRESS, HEX);

  // تهيئة I2C كسليف + ربط الـ ISR callbacks
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(onReceiveISR);
  Wire.onRequest(onRequestISR);
}

void loop() {
  // نتحقق إن كان في داتا جديدة وصلت من الماستر
  if (newDataFlag) {
    noInterrupts();  // نحمي الوصول للـ buffer
    uint8_t length = rxLength;
    rxLength = 0;
    newDataFlag = false;
    interrupts();

    Serial.print("[I2C] Received (");
    Serial.print(length);
    Serial.print(" bytes): ");
    for (uint8_t i = 0; i < length; i++) {
      if (rxBuffer[i] < 0x10) Serial.print("0");
      Serial.print(rxBuffer[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
  delay(50);
}

// ====================================================================

void onReceiveISR(int numBytes) {
  uint8_t i = 0;
  while (Wire.available() && i < MAX_BUFFER) {
    rxBuffer[i++] = Wire.read();
  }
  rxLength = i;
  newDataFlag = true;
}

// ====================================================================

void onRequestISR() 
{
  if(rxBuffer[0] >= 0 && rxBuffer[0] <= 9)
  {
  Wire.write(txMessageOk, 3);
  }
  else
  {
  Wire.write(txMessageError, 5);
  }
}
