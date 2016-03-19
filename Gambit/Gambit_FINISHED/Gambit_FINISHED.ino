//Arduino code for the X-MENs Gambit throwing card.

int led1 = 2;
int led2 = 3;  //PWM
int led3 = 4;
int led4 = 5;  //PWM
int led5 = 6;  //PWM
int led6 = 9;  //PWM
int led7 = 10; //PWM
int led8 = 11; //PWM

//////////////////////////////////////////////////////////

void setup()  { 
 pinMode(led1, OUTPUT);   // sets the digital pin as output
 pinMode(led2, OUTPUT);   // sets the digital pin as output
 pinMode(led3, OUTPUT);   // sets the digital pin as output
 pinMode(led4, OUTPUT);   // sets the digital pin as output
 pinMode(led5, OUTPUT);   // sets the digital pin as output
 pinMode(led6, OUTPUT);   // sets the digital pin as output
 pinMode(led7, OUTPUT);   // sets the digital pin as output
 pinMode(led8, OUTPUT);   // sets the digital pin as output
 
} 
//////////////////////////////////////////////////////////
void loop()  { 
  
  digitalWrite(led1, HIGH);   
  digitalWrite(led3, HIGH);    
  delay(80);
  
  digitalWrite(led2, HIGH);    
  digitalWrite(led4, HIGH);    
  delay(60); 
  
  digitalWrite(led5, HIGH); 
  digitalWrite(led6, HIGH);
  delay(40);
  
  digitalWrite(led7, HIGH);   
  digitalWrite(led8, HIGH);   
  delay(80);
 
//////////////////////////////////////////////////////////

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 25; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led2, fadeValue);
    analogWrite(led4, fadeValue);
    analogWrite(led5, fadeValue); 
    analogWrite(led6, fadeValue); 
    analogWrite(led7, fadeValue); 
    analogWrite(led8, fadeValue);   
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
  
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 25 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(led2, fadeValue);
    analogWrite(led4, fadeValue);
    analogWrite(led5, fadeValue); 
    analogWrite(led6, fadeValue); 
    analogWrite(led7, fadeValue); 
    analogWrite(led8, fadeValue);       
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
}


