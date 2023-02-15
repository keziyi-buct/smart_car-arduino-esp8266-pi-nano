#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial esp8266(2, 3);

const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  esp8266.println("AT+CWJAP=\"WIFI_SSID\",\"WIFI_PASSWORD\"");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    while (client.connected()) {
      if (client.available()) {
        String command = client.readStringUntil('\r');
        if (command.startsWith("forward")) {
          // 控制小车向前运动
        } else if (command.startsWith("backward")) {
          // 控制小车向后运动
        }
      }
    }

    client.stop();
  }
}
