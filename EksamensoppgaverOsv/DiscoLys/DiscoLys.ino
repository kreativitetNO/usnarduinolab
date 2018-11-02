const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop()
{
    double r = 0.0;
    while (true) {
        analogWrite(redPin, sin(r) * 127 + 127);
        analogWrite(greenPin, sin(r + 2*PI/3) * 90 + 90);
        analogWrite(bluePin, sin(r + 4*PI/3) * 100 + 100);
        r += 0.002;
        if (r >= 2 * PI)
            r = 0.0;
    }
}