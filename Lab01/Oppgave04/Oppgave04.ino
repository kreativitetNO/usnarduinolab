const int ledPin = 13;
const int buttonPin1 = 5;
const int buttonPin2 = 6;
const int delayTime = 250;
int buttonValue1 = LOW;
int buttonValue2 = LOW;
int ledValue = LOW;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
}

void loop()
{
    buttonValue1 = digitalRead(buttonPin1);
    buttonValue2 = digitalRead(buttonPin2);
    if (buttonValue1 == LOW && buttonValue2 == LOW) {
        delay(delayTime);
        ledValue = !ledValue;
    }
    else if (buttonValue1 == LOW || buttonValue2 == LOW) {
        ledValue = HIGH;
    }
    else {
        ledValue = LOW;
    }
    digitalWrite(ledPin, ledValue);
}