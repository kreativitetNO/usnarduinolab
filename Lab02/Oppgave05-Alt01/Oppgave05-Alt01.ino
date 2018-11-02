const int led1Pin = 12;
const int led2Pin = 11;
const int button1Pin = 18;
const int button2Pin = 19;

void setup() {
    pinMode(led1Pin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
}

void loop() {
    unsigned long lastBlinkTime1 = 0;
    unsigned long lastBlinkTime2 = 0;
    int led1Value = LOW;
    int led2Value = LOW;
    while (true) {
        unsigned long led2BlinkTime = map(analogRead(potPin), 0, 1023, 100, 1000);
        if (millis() - lastBlinkTime1 >= led1BlinkTime) {
            led1Value = !led1Value;
            lastBlinkTime1 = millis();
        }
        if (millis() - lastBlinkTime2 >= led2BlinkTime) {
            led2Value = !led2Value;
            lastBlinkTime2 = millis();
        }
        digitalWrite(led1Pin, led1Value);
        digitalWrite(led2Pin, led2Value);
    }
}