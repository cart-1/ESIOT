#include <Arduino.h>

#define buttonPin 2

void setup() {
  // Initialize the button pin as input
  pinMode(buttonPin, INPUT);

  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Active-High Push Button Status:");
}

void loop() {
  // Read button status
  bool buttonState = digitalRead(buttonPin);

  // Print button status
  if (buttonState == HIGH) {
    Serial.println("Button is not pressed");
  } 
  else {
    Serial.println("Button is pressed (Active-High)");
  }

  delay(1000);
}