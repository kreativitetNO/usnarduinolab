#include <Servo.h>

const unsigned int xJoyPin = A1;

Servo servo;

void setup() {
  servo.attach(7);
}

void loop() { 
    servo.write(map(analogRead(xJoyPin), 0, 1023, 0, 180));
}