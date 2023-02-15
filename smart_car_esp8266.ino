#include <SoftwareSerial.h>

SoftwareSerial esp8266(2, 3);

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  esp8266.println("AT+CWJAP=\"WIFI_SSID\",\"WIFI_PASSWORD\"");
}

void loop() {
  while (esp8266.available()) {
    Serial.write(esp8266.read());
  }
}
