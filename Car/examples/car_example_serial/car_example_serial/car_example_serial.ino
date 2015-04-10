#include <Servo.h>
#include "Car.h"
#include "Rgb.h"
Car car;
char device;
int value;
bool parar;

void setup(){
  Serial.begin(115200);
  //Serial.println("Connected!");
  car.attachMotor(11);
  car.attachServo(9);
  car.attachLineSensor(A3);
  car.neutral(); // in case of failure (safety)
  parar = false;
}

void loop(){
  //Serial.println(analogRead(A3));
  if(Serial.available()){
    delay(1);
    device=Serial.read();
    Serial.print(device);
    switch(device){
      case 'f':
        car.setSpeed(FORWARD, Serial.parseInt());
        break;
      case 'b':
        car.setSpeed(BACKWARD, Serial.parseInt());
        break;
      case 'r':
        car.turn(RIGHT, Serial.parseInt());
        break;
      case 'l':
        car.turn(LEFT, Serial.parseInt());
        break;
      case 's':
        car.stop();
        break;
      case 'n':
        car.neutral();
        break;
      case 'p':
        parar=true;
      default:
        //DO NOTHING
        break;
    }
  }
  if(parar){
    if(car.detectedLine()){
      parar = false;
      Serial.println("VOU PARAR");
      car.stop(); 
    }
  }
}
