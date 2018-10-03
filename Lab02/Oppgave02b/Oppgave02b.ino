const int ledPin = 13;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int i = 10;
    while (i <= 2000) {
        int j = 0;
        while (j < 2) {
            digitalWrite(ledPin, j);
            delay(i);
            j++;
        }
        i = i + 199;
    }
}