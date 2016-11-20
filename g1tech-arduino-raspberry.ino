#include <Wire.h>

int SLAVE_ADDRESS = 0x04;
int ledPin = 13;
int analogPin = A0;
boolean ledOn = false;


void setup() {
  pinMode(ledPin, OUTPUT);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(processMessage);
  Wire.onRequest(sendAnalogReading);
}

void loop() {
}

void processMessage(int n) {
  char ch = Wire.read();
  if (ch == 'l')
  {
    toggleLED();
  }
}

void toggleLED() {
  ledOn = ! ledOn;
  digitalWrite(ledPin, ledOn);
}

void sendAnalogReading() {
  int reading = analogRead(analogPin);
  Wire.write(reading >> 2);
}
