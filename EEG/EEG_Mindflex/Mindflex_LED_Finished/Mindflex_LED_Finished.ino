#include <Brain.h>

int ledPin = 13;
int ledPin2 = 12;
int ledPin3 = 11;

Brain brain(Serial);
long interval = 500; // Changes based on attention value.

void setup() {
    Serial.begin(9600); 
    pinMode(ledPin, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
}

void loop() {
     if (brain.update()) {
        Serial.println(brain.readAttention());
        
        // Attention runs from 0 to 100.
        interval = (100 - brain.readAttention()) * 10;
        digitalWrite(ledPin, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
    }
    
     
     
     if (brain.readAttention() == 0) 
     { 
       digitalWrite(ledPin, LOW);
       digitalWrite(ledPin2, LOW);
       digitalWrite(ledPin3, LOW);
     }
      else if (brain.readAttention() >= 1 && brain.readAttention() <= 25)  
     {
       digitalWrite(ledPin, HIGH);
     }
     else if (brain.readAttention() >= 26 && brain.readAttention() <= 50)  
     {
       digitalWrite(ledPin2, HIGH);
     }
     else if (brain.readAttention() >= 51 && brain.readAttention() <= 90)  
     {
       digitalWrite(ledPin3, HIGH);
     }
     else 
     {
       digitalWrite(ledPin, HIGH);
       digitalWrite(ledPin2, HIGH);
       digitalWrite(ledPin3, HIGH);
     }
}
