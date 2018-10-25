const int ledPin1 = 11;
const int ledPin2 = 12;
const int delayTime = 500;

void setup()
{
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
}

void loop()
{
    static unsigned long lastChangeTime = 0;
    static int ledStatus = LOW;
    if (millis() - lastChangeTime > delayTime) {
        ledStatus = !ledStatus;
        lastChangeTime = millis();
    }
    digitalWrite(ledPin1, ledStatus);
    digitalWrite(ledPin2, !ledStatus);
}