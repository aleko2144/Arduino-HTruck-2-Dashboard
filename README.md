# Arduino-HTruck-2-Dashboard
Hard Truck 2/King of the Road v8.2/1.3 Arduino dashboard (server + controller).

Repository structure:
- \Arduino_sketch\sketch_dashboard.ino - sketch for dashboard with SG90 servo;
- \Arduino_sketch\sketch_display.ino - sketch for dashboard with LCD display only;
- \Server\Dashboard_version - server source code (for Code::Blocks v20.03).

How it works: </br>
1) Arduino Nano with three SG90s connected to PC via USB cable;
2) Server application connects to a running game process and takes values from it (speed, engine speed, etc.);
3) Server application prepares data and sends it to Arduino controller.

Server app receives the next data from game: </br>
- speed;
- engine RPM;
- fuel level;
- vehicle damage level;
- vehicle mileage;
- current gear;
- headlight switch state;
- handbrake state.

The server app also has code for calculating the daily (resettable) mileage of a car. In the sketch for arduino, this data is also read, but not applied.
