#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider

#define PIN            6
#define NUMPIXELS      3

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);  
}

void loop() {
   photocellReading = analogRead(photocellPin);
   Serial.print("Analog reading = ");
   Serial.println(photocellReading);     // the raw analog reading

  if (photocellReading < 200 && photocellReading > 2) {
      for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,255)); // Moderately bright blue color.
        pixels.show(); 
      }
    }
    else if (photocellReading < 1 && photocellReading > 0) {
      for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(255,0,0)); // Moderately bright red color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        //delay(delayval); // Delay for a period of time (in milliseconds).
      }
    }
     else {
      for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,0)); // No color
        pixels.show(); // This sends the updated pixel color to the hardware.
      }
    }
}  
