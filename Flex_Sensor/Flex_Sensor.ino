const int flexpin = 0; 


void setup() 
{ 
  Serial.begin(9600);
} 


void loop() 
{ 
  int flexposition;   

  flexposition = analogRead(flexpin);


  Serial.print("sensor: ");
  Serial.print(flexposition);

  delay(20);  
} 
