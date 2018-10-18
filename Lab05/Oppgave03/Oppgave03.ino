#include "BYJ48Stepper.h"

const unsigned int xJoyPin = A1;
const unsigned int stepCount = 4096;
const double speed = 5;
const int speedFactor = 5;
int xCalib = 0;

Stepper stepper(14, 15, 16, 17);

void setup() {
  stepper.setSpeed(speed);
  xCalib = analogRead(xJoyPin);
}

void loop() {
    int xJoyVal = analogRead(xJoyPin);
    int speed = abs((xCalib - xJoyVal)/xCalib);
    stepper.setSpeed(speed);
    if (speed > 0)
        stepper.step(xJoyVal > XCalib ? 1 : -1);
}