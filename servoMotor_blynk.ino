#include "Servo.h"
#include "ESP8266WiFi.h"
#include "BlynkSimpleEsp8266.h"

Servo servo;
int d = 1000;
int potSlider = 180;

char auth[]= "98c91ae531ae41af9a77aec3ec3c511b";
char ssid[]= "brisa-261934";
char pass[]= "q5ngnaon";

void setup() {
  Serial.begin(115200);
  servo.attach(D1);
  pinMode(A0, INPUT);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0){
  potSlider = param.asInt();
}

void loop() {
  Blynk.run();
  servo.write(potSlider);
}
