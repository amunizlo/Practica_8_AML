#include <Arduino.h>

#define RXD2 16
#define TXD2 17

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial Txd is on pin: " + String(TX));
  Serial.println("Serial Rxd is on pin: " + String(RX));
  Serial.println("Hola, esta es una prueba de funcionamiento");
}

void loop() {
  Serial2.print(char(Serial.read()));
  Serial.print(char(Serial2.read()));
  delay(1000);
}
