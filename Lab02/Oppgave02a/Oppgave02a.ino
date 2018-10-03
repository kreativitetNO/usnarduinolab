const int ledPin = 13;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    for (int i = 10; i <= 2000; i = i + 199) {
        for (int j = 1; j >= 0; j--) {
            digitalWrite(ledPin, j);
            delay(i);
        }
    }
}