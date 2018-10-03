const int ledPin = 13;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j >= 0; j--) {
            digitalWrite(ledPin, j);
            delay(500);
        }
    }
    while (true);
}