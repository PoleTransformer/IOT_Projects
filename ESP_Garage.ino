#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "IU-eocotkYjexiSZMgUB9mQidJxU6PLf";
char ssid[] = "TELUS0284-2.4G";
char pass[] = "7cqsszkf3n";

#define out 4
#define reed 0

void setup()
{
  pinMode(out, OUTPUT);
  pinMode(reed, INPUT_PULLUP);
  Blynk.begin(auth, ssid, pass);
  if (Blynk.connected()) {
    readSwitch();
  }
}

void loop()
{
  Blynk.run();
  readSwitch();
}

BLYNK_WRITE(V3) {
  int val = param.asInt();
  if (val == 1) {
    digitalWrite(out, HIGH);
  }
  else {
    digitalWrite(out, LOW);
  }
}

void readSwitch() {
  int state = digitalRead(reed);
  if (state == 0) {
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, 1023);
  }
  else {
    Blynk.virtualWrite(V1, 1023);
    Blynk.virtualWrite(V2, 0);
  }
}
