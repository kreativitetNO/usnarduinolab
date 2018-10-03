const int buzzerPin = 2;
const int toneFrequency = 500;
const int shortBuzz = 200;
const int longBuzz = 2 * shortBuzz;
const int buttonPin1 = 5;
const int buttonPin2 = 6;
char symbol = ' ';
int delayValue = 0;

void setup()
{
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    if (digitalRead(buttonPin1) == LOW) {
        delayValue = shortBuzz;
        symbol = '.';
    }
    if (digitalRead(buttonPin2) == LOW) {
        delayValue = longBuzz;
        symbol = '-';
    }
    if (delayValue > 0) {
        Serial.print(symbol);
        tone(buzzerPin, toneFrequency);
        delay(delayValue);
        noTone(buzzerPin);
        delayValue = 0;
    }
}