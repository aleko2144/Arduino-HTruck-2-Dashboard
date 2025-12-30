#include <Servo.h>

Servo srv_speed;
Servo srv_tacho;
Servo srv_fuel;

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

int car_speed_prev = 0;
int car_rpm_prev = 0;
int car_fuel_prev = 0;

void do_test(){
  //set 1/2 position
  srv_speed.write(90);
  srv_tacho.write(90);
  srv_fuel.write(55);

  delay(1000);

  //set max position
  srv_speed.write(170);
  srv_tacho.write(0);
  srv_fuel.write(105);

  delay(1000);

  //set zero position
  srv_speed.write(10);
  srv_tacho.write(180);
  srv_fuel.write(10);

  delay(1000);
}

void setup() {
  srv_speed.attach(12);
  srv_tacho.attach(11);
  srv_fuel.attach(10);

  Serial.begin(115200);

  do_test();
}

void loop() {
  serial_byte = Serial.read();
  
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

    if (serial_byte == 210){
      //проблема SG90 - в обратном направлении они движутся на меньший угол,
      //чем задан. данный код частично компенсирует этот недостаток

      //если в прошлый раз скорость была выше
      if (car_speed_prev - car_speed > 1){
        if (car_speed - 3 < 0){
          srv_speed.write(car_speed - 3);
          delay(25);
          srv_speed.write(car_speed);
        }
      } else {
        srv_speed.write(car_speed); 
      }
      
      //srv_speed.write(car_speed); 
      srv_tacho.write(car_rpm);
      srv_fuel.write(car_fuel);
      
      car_speed_prev = car_speed;     
      car_rpm_prev = car_rpm;
      car_fuel_prev = car_fuel;
      
    }
  }

  //при 20 пропадает последний байт, если всего 23 передаётся
  delay(10); //15 //50
}
