/* Multivibe software -- written by A Quitmeyer / Comingle. First released Dec 1, 2014 */
/* Public Domain - adapted from other processing and arduino sketches */
/* This software comes pre-loaded on Comingle Multivibe sex toys */
bool clicked = false;
#define LED_N_SIDE A2
#define LED_P_SIDE A3
int darkamount = 0;
int incomingByte;      // a variable to read incoming serial data into
int ledPin = 9;    // LED connected to digital pin 9

void setup() {Serial.begin(9600);}
int prevValue=0;

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    analogWrite(ledPin, incomingByte);         

  }
  
  else{
       // Toy.setOutput(1,0);

  }


}
