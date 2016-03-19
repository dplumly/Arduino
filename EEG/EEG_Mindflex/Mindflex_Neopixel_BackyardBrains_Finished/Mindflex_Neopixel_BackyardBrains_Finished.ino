  /*
    Schematic
    Arduino: pin 6     Neopixel: In
             VCC                 +
             GND                 -
              
    Arduino: RX        Mindflex: TX 
             GND                 GND
  */
  
  #include <Brain.h>
  #include <Adafruit_NeoPixel.h>
  #include <avr/power.h>
  
  #define NUM_LED 6  //sets the maximum numbers of LEDs
  #define Threshold 3 // this sets the light to activate TENS
  #define PIN 6
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
  
  byte litLeds = 0;
  byte multiplier = 1;
  byte leds[] = {8, 9, 10, 11, 12, 13};
  int aQ1 = 11;
  int aQ2 = 13;
  int aQ3 = 8;
  
  int StimPin = 3; // TENS Digital 3
  int attentionVal;
  int signalVal;
  Brain brain(Serial);
  
  
  void setup() {
    Serial.begin(9600); //begin serial communications
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    pinMode(StimPin, OUTPUT); // Set TENS output to StimPin
    
    for(int i = 0; i < NUM_LED; i++){ //initialize LEDs as outputs
      pinMode(leds[i], OUTPUT);
    pinMode(aQ1, OUTPUT);
    }
  }
    
   
  
  void loop() {
     if (brain.update()) {
           attentionVal = brain.readAttention();
           signalVal = brain.readSignalQuality();
           
           Serial.println(signalVal);
           Serial.println(attentionVal);
           
            if (attentionVal >= 1) {
                colorWipe(strip.Color(0, 0, 255), 50); // Solid Blue Light
                  
                 if (attentionVal > 30) {
                    digitalWrite(StimPin, HIGH);
                 } 
            }
              else {
                  theaterChase(strip.Color(127,   0,   0), 50); // FLashing Red Light
                  digitalWrite(StimPin, LOW);
           }
           delay(10);
      }
  }
    
    
    
    
    
  

  
  
  

  
    
  // Neopixel functions //  
  /////////////////////////////////////////////////////// 
  // FLashing Red Light 
  void theaterChase(uint32_t c, uint8_t wait) {
    for (int j=0; j<10; j++) {  //do 10 cycles of chasing
      for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, c);    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
      }
    }
  }

  // Solid Blue Light //
  void colorWipe(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
  }

   
    
