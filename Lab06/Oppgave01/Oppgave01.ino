const int ledPin = 13;
const int switchPin = 3;
const int debounceTime = 5;
volatile int ledValue = HIGH;

void setup()
{
    pinMode(switchPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(switchPin), isr, CHANGE);
    Serial.begin(9600);
}

void isr()
{
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();
    if (interruptTime - lastInterruptTime >= debounceTime) {
        ledValue = !ledValue;
    }
    lastInterruptTime = millis();
}

void loop()
{
    digitalWrite(ledPin, ledValue);
}