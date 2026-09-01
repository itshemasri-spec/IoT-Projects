#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID     ""
#define WIFI_PASS     ""

#define APP_KEY       ""
#define APP_SECRET    ""

#define DEVICE_ID     ""

#define LED_PIN D2

bool onPowerState(const String &deviceId, bool &state) {
  digitalWrite(LED_PIN, state);

  Serial.printf("Device %s turned %s\r\n",
                deviceId.c_str(),
                state ? "ON" : "OFF");

  return true;
}

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  setupWiFi();

  SinricProSwitch &mySwitch =
      SinricPro[DEVICE_ID];

  mySwitch.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY, APP_SECRET);
}

void loop() {
  SinricPro.handle();
}
