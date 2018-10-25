const int ledPin = 13;
const int switch1Pin = 2;
const int switch2Pin = 3;
const int debounceTime = 5;
volatile unsigned long delayTime = 1000;
int ledValue = HIGH;
double changeFactor = 0.1;

void setup()
{
    pinMode(switch1Pin, INPUT_PULLUP);
    pinMode(switch2Pin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(switch1Pin), doItFaster, FALLING);
    attachInterrupt(digitalPinToInterrupt(switch2Pin), doItSlower, FALLING);
    Serial.begin(9600);
}

void doItFaster()
{
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();
    if (interruptTime - lastInterruptTime >= debounceTime) {
        int change = delayTime * changeFactor;
        if (change > 0)
            delayTime -= change;
    }
    lastInterruptTime = millis();
}

void doItSlower()
{
    static unsigned long lastInterruptTime = 0;
    unsigned long interruptTime = millis();
    if (interruptTime - lastInterruptTime >= debounceTime) {
        int change = delayTime * changeFactor;
        if (change > 0)
            delayTime += change;
        else
            delayTime += 1;
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