#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  

int serial_byte = 0;

int car_speed;
int car_rpm;
int car_gear;
int car_fuel;
int car_damage;
int car_lights;
int car_handbrake;
int car_indicators;

int kilometrage_total[6];
int kilometrage_local[5];

void setup() {
  lcd.begin(16, 2);              // set up the LCD's number of columns and rows:
  //lcd.print("Hello, world!");   // Print a message to the LCD.

  Serial.begin(115200);

  delay(25);
}

void processLCD(){
    lcd.clear();
    //lcd.setCursor(0, 0); lcd.print("s=");
    //lcd.setCursor(2, 0); lcd.print(car_speed);

    //lcd.setCursor(7, 0); lcd.print("r=");
    //lcd.setCursor(9, 0); lcd.print(car_rpm);
    //14, 0
    //lcd.setCursor(7, 0); lcd.print(car_gear);
    
    //lcd.setCursor(0, 1); lcd.print(car_lights);
    //lcd.setCursor(3, 1); lcd.print(car_handbrake);

    for (int i = 0; i < 6; i++){
      lcd.setCursor(10 + i, 0); lcd.print(kilometrage_total[i]);
    }
    for (int i = 0; i < 4; i++){
      lcd.setCursor(10 + i, 1); lcd.print(kilometrage_local[i]);
    }
    lcd.setCursor(14, 1); lcd.print(".");
    lcd.setCursor(15, 1); lcd.print(kilometrage_local[4]);
}

void loop() {
  serial_byte = Serial.read();


  //lcd.setCursor(12, 0); lcd.print(serial_byte);
  
  if (serial_byte == 232){
    car_speed = Serial.read();
    car_rpm = Serial.read();
    car_gear = Serial.read();
    car_fuel = Serial.read();
    car_damage = Serial.read();
    car_lights = Serial.read();
    car_handbrake = Serial.read();
    car_indicators = Serial.read();
    
    for (int i = 0; i < 6; i++){
        kilometrage_total[i] = Serial.read();
    }
    for (int i = 0; i < 5; i++){
        kilometrage_local[i] = Serial.read();
    }

    serial_byte = Serial.read();

    //lcd.setCursor(12, 1); lcd.print(kilometrage_local[5]);

    if (serial_byte == 210){
      processLCD();
    }
  }

  //при 20 пропадает последний байт, если всего 23 передаётся
  delay(10); //15 //50
}
