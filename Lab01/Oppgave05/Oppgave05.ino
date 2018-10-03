const int ledPin = 13;
const int buzzerPin = 2;
const int delayTime = 250;
const int potPin = A3;
const int buzzLimit = 500;
const int ledLimit = 300;
int potValue;
int ledValue = LOW;
int buzzerValue = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    potValue = analogRead(potPin);
    if (potValue > buzzLimit) {
        // Litt moro må vi ha
        tone(buzzerPin, (potValue - buzzLimit) * 15 + 500);
    } else {
        noTone(buzzerPin);
    }
    digitalWrite(ledPin, potValue < ledLimit);
}