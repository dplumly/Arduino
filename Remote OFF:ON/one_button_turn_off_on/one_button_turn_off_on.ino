
  /* Orignial code from http://www.electroschematics.com/9522/arduino-control-leds-ir-remote/ 
  Modified code for use of a remote to power on/off an LED by one button
  
  Use the "IRecord" sketch from the IRremote library to get your remotes HEX code. You can use the same circuit as this sketch-----make sure to put 0x in front of your HEX numbers---e.g. 0x123456
  */
  
    #include <IRremote.h>
   
  int RECV_PIN = 11; //  output pin of IR Receiver
  int led = 5;
  int itsONled[] = {0,0,0,0};
  /* the initial state of LEDs is OFF (zero) */
  #define remoteCode  0x61A07E81 // rewind button code received from my insignia remote
   
  IRrecv irrecv(RECV_PIN);
   
  decode_results results;
   
  void setup()
  {
    Serial.begin(9600);   // be able to see in serial port
    irrecv.enableIRIn();  // Start the receiver
    pinMode(led, OUTPUT);  // declaring led as an output
  }
   
  void loop() {
    if (irrecv.decode(&results)) {
      unsigned int value = results.value;
      switch(value) {
         case remoteCode:
           if(itsONled[1] == 1) {        // if first led is on then
              digitalWrite(led, LOW);   // turn it off when button is pressed
              itsONled[1] = 0;           // and set its state as off
              Serial.println("led off");          
           } else {                      // else if first led is off
               digitalWrite(led, HIGH); // turn it on when the button is pressed
               itsONled[1] = 1;          // and set its state as on
               Serial.println("led on");
           }
            break;      
      }
      Serial.println(value); // you can comment this line
      irrecv.resume(); // Receive the next value
    }
  }
  
