// Project: Air Quality Monitoring System
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

#define MQ135_PIN A0
BlynkTimer timer;

void sendSensorData() {
  int airQuality = analogRead(MQ135_PIN);
  Serial.print("Air Quality: ");
  Serial.println(airQuality);
  Blynk.virtualWrite(V1, airQuality);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
