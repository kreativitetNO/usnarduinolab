const int ledPin = 13;
const int switchPin = 3;
const int debounceTime = 5;
volatile unsigned long delayTime = 1000;
int ledValue = HIGH;

void setup()
{
    pinMode(switchPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(switchPin), isr, FALLING);
    Serial.begin(9600);
}

void isr()
{
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();
    if (interruptTime - lastInterruptTime >= debounceTime) {
        delayTime -= 0.1 * delayTime;
    }
    lastInterruptTime = millis();
}

void loop()
{
    static unsigned long lastChangeTime = 0;
    if (millis() - lastChangeTime >= delayTime) {
        ledValue = !ledValue;
        lastChangeTime = millis();
    }
    digitalWrite(ledPin, ledValue);
}