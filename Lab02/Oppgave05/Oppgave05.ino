const int ledPin = 13;
const int buzzerPin = 2;
const int buttonPin1 = 5;
const int buttonPin2 = 6;
const unsigned long debounceDelay = 20;
const unsigned int toneFrequency = 500;
const unsigned long notificationTime = 1000;
int button1_press1 = 0;
int button2_press1 = 0;
int button1_press2 = 0;
int button2_press2 = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
}

void loop()
{
    while (digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH){}
    button1_press1 = !digitalRead(buttonPin1);
    button2_press1 = !digitalRead(buttonPin2);
    delay(debounceDelay); // For å motvirke "bounce"
    while (digitalRead(buttonPin1) == LOW || digitalRead(buttonPin2) == LOW){}
    while (digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH){}    
    button1_press2 = !digitalRead(buttonPin1);
    button2_press2 = !digitalRead(buttonPin2);
    delay(debounceDelay);
    while (digitalRead(buttonPin1) == LOW || digitalRead(buttonPin2) == LOW){}
    if (button1_press1 == HIGH && button2_press2 == HIGH) {
        digitalWrite(ledPin, HIGH);
    } else {
        tone(buzzerPin, toneFrequency);
    }
    delay(notificationTime);
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
}

