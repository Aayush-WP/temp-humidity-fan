#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#define DHTPIN 12 // Pin for DHT sensor 
#define PWM 9 // PWM pin for fan
// I2C LCD (Address may vary: 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Create degree symbol
byte degree[8] = {
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

// Create DHT object dht11 DHT11;
void setup() {
   lcd.init(); lcd.backlight(); 
   lcd.createChar(1, degree); lcd.clear();
   lcd.print(" Fan Speed "); 
   lcd.setCursor(0,1); 
   lcd.print(" Controlling "); 
   delay(2000);

  analogWrite(PWM, 255); // Fan test
  lcd.clear(); lcd.print("Robu "); delay(2000);
  Serial.begin(9600);
}

void loop() { 
  delay(2000); // Delay between readings
  int chk = DHT11.read(DHTPIN);
  float h = (float)DHT11.humidity; 
  float t = (float)DHT11.temperature;
  Serial.print("Humidity (%): "); 
  Serial.println(h, 2);
  Serial.print("Temperature (C): "); 
  Serial.println(t, 2);
  // Display temperature on LCD 
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Temp: ");
  lcd.print(t, 1); 
  lcd.write(1); // Degree symbol 
  lcd.print("C"); 
  lcd.setCursor(0, 1);
  // Adjust fan speed based on temperature
  
  int fanSpeed = 0; 
  String status = "";
  if (t < 20) {
  fanSpeed = 0; 
  status = "Fan OFF"; 
  }

  else if (t >= 20 && t < 24) {
    fanSpeed = 51; 
    // ~20% 
    status = "Fan Speed: 20%"; 
    } 
  else if (t >= 24 && t < 26) { 
    fanSpeed = 102; // ~40% 
    status = "Fan Speed: 40%";
    } 
  else if (t >= 26 && t < 28) { 
    fanSpeed = 153; // ~60% 
    status = "Fan Speed: 60%"; 
    } 
  else if (t >= 28 && t < 30) { 
    fanSpeed = 204; // ~80% 
    status = "Fan Speed: 80%";
  } 
  else {
    fanSpeed = 255; // 100%
    status = "Fan Speed: 100%";
  }
  analogWrite(PWM, fanSpeed); 
  lcd.print(status);
  delay(3000); 
}
