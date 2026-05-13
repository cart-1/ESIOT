#include <SoftwareSerial.h>

#define LED_pin 13

SoftwareSerial bluetooth(2, 3);   // RX, TX

float data = 25.98;
char charArray[10];

void setup() {
  Serial.begin(9600);       // Serial Monitor
  bluetooth.begin(9600);    // Bluetooth

  pinMode(LED_pin, OUTPUT);

}

void loop() {

  // Check Bluetooth data
  if (bluetooth.available()) {

    char receivedChar = bluetooth.read();

    Serial.print("Received: ");
    Serial.println(receivedChar);

    if (receivedChar == '1') {
      digitalWrite(LED_pin, HIGH);
      Serial.println("LED_ON");
    }

    else if (receivedChar == '0') {
      digitalWrite(LED_pin, LOW);
      Serial.println("LED_OFF");
    }

    else if (receivedChar == '2') {
      dtostrf(data, 6, 2, charArray);
      bluetooth.write(charArray);
      delay(100);
    }
  }
}