const int ledPin = 13;
const int buttonPin = 5;

void setup()
{
    pinMode(ledPin, OUTPUT);
    // Les om INPUT_PULLUP på arduino.cc - vi slipper å koble til en motstand
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    digitalWrite(ledPin, !digitalRead(buttonPin));
}