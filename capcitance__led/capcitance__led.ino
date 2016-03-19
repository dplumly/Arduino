/* Sketch that turns on LED when metal object is touched
   
   You can use the onboard LED, put an LED in pin 13, or wire one to another pin.
*/

#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

// threshold for turning the lamp led
int threshold = 1000;

const int ledPin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long capValue = capSensor.capacitiveSensor(30);

  Serial.println(capValue);

  if (capValue > threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}
