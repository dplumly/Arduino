   /* 
  Modified code for use of a remote to power on/off an LED by two different buttons
  
  Use the "IRecord" sketch from the IRemote library to get your remotes HEX code. You can use the same circuit as this sketch-----make sure to put 0x in front of your HEX numbers---e.g. 0x123456

  */  

  #include <IRremote.h>  //include IRremote Library
  
  //#define ms_remote_map.h
  
  //below mappings are for Microsoft Media Center Remote
  #define OFF 0x61A07E81 // next chapter button code received from my insignia remote------replace with your remotes code---make sure to put 0x infront of the HEX number
  #define ON 0x61A0BE41  // previous chapter button code received from my insignia remote------replace with your remotes code
  
  
  #define RECV_PIN 11
  #define led 5 // choose the pin for the LED
  
  byte ledState;
  IRrecv irrecv(RECV_PIN);
  decode_results results;
  boolean power_state = LOW;
  
  void setup(){
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
    pinMode(led, OUTPUT);  // declare LED as output
  }
  
  void loop() {
    if (irrecv.decode(&results)) {  //If IR receive results are detected
     // Serial.println(results.value, HEX);
      switch (results.value) {
  
       //Power
      case OFF:  //case to turn LED OFF
        //   Serial.println("Power");
           ledState = LOW;
           digitalWrite(led, LOW);  // turn LED OFF
           Serial.println("led off");
      break;
  
      case ON:  //case to turn LED ON
           digitalWrite(led, HIGH);  // turn LED ON
           Serial.println("led on");
      break;
    }
  
      delay(200);  // 1/5 second delay for arbitrary clicks.  Will implement debounce later.
      irrecv.resume(); // Receive the next value
    }
  }
