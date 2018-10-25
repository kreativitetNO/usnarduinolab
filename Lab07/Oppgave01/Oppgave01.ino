const int ledPin = 12;
const int buttonCount = 3;
const int blinkDelay = 250;
const int debounceTime = 200;
const int buttonPins[] = { 18, 19, 20 };
const int stateCount = 3;

enum States { On, Off, Blinking };
volatile States currentState = Off;
volatile bool keepRunning = true;

void setup()
{
    pinMode(ledPin, OUTPUT);
    for (int i = 0; i < buttonCount; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
    attachInterrupt(digitalPinToInterrupt(buttonPins[0]), prevState, FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonPins[1]), nextState, FALLING);
    attachInterrupt(digitalPinToInterrupt(buttonPins[2]), terminate, FALLING);
}

void loop()
{
    int ledState = LOW;
    while (keepRunning) {
        implementState(&ledState, currentState);
        digitalWrite(ledPin, ledState);
    }
}

void implementState(int* ledState, States state)
{
    static int blinkValue = HIGH;
    static unsigned long lastToggle = millis();
    if (millis() - lastToggle > blinkDelay) {
        blinkValue = !blinkValue;
        lastToggle = millis();
    }
    switch (state) {
        case On:
            *ledState = HIGH;
            return;
        case Blinking:
            *ledState = blinkValue;
            return;
        case Off:
            *ledState = LOW;
            return;
    }
}

void prevState()
{
    static unsigned long lastInterrupt = 0;
    if (millis() - lastInterrupt > debounceTime) {
        currentState = (States)(currentState - 1);
        if (currentState < 0)
            currentState = (States)(stateCount - 1);
    }
    lastInterrupt = millis();
}

void nextState()
{
    static unsigned long lastInterrupt = 0;
    if (millis() - lastInterrupt > debounceTime) {
        currentState = (States)((currentState + 1) % stateCount);
    }
    lastInterrupt = millis();
}

void terminate()
{
    keepRunning = false;
}