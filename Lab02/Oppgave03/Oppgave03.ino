const int ledPin = 13;
const int buttonPin = 5;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    int i = 10;
    while (i <= 2000) {
        int j = 0;
        while (j < 2) {
            if (digitalRead(buttonPin) == LOW) {
                i = 10;
                break;
            }
            digitalWrite(ledPin, j);
            delay(i);
            j++;
        }
        i = i + 199;
    }
}