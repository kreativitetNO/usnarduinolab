const int ledPin = 13;
int delayTime = 500;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    for (int j = 1; j >= 0; j--) {
        digitalWrite(ledPin, j);
        delay(delayTime);
    }
    if (Serial.available() > 0) {
        int newDelayTime = Serial.parseInt();
        if (newDelayTime > 0) {
            delayTime = newDelayTime;
        }
        while (Serial.available()) {
            Serial.read();
        }
    }
}