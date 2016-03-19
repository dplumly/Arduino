#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)



/*
 Connect pin 1 (on the left) of the sensor to +5V
     NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
     to 3.3V instead of 5V!
 Connect pin 2 of the sensor to whatever your DHTPIN is
 Leave pin 3 open
 Connect pin 4 (on the right) of the sensor to GROUND
 Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
 
 LCD
 -----------------------------------------------
 VSS- connect to ground
 VDD- Connect to 5v
 VO- Connect to single lead on 10k potentiometer
 RS- Pin 12
 RW- Ground
 E- Pin 11
 D4- Pin 5
 D5- Pin 4
 D6- Pin 3
 D7- Pin 2
*/


// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  dht.begin();
  Serial.println("DHT22 test!");
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius
  int t = dht.readTemperature();
  // Read temperature as Fahrenheit
  int f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Must send in temp in Fahrenheit!
  int hi = dht.computeHeatIndex(f, h); //change to float for more accurate reading if needed
  
  lcd.setCursor(0, 0);

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print("%");
  
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(0,1);
  
  Serial.print(" Temp: ");
  Serial.print(hi);
  Serial.println(" F");
  
  lcd.print("Temp: ");
  lcd.print(hi);
  lcd.print("F");
}



