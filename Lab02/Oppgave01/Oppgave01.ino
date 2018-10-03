const int ledPin = 13;
int ledValue = 0;
int ledValueDelta = 1;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    // Kjedelig versjon
//    ledValue = ledValue + ledValueDelta;
//    if (ledValue == 255 || ledValue == 0)
//        ledValueDelta = ledValueDelta * -1;
//    analogWrite(ledPin, ledValue);
    // Morsom versjon - Se om dere finner ut hvordan den fungerer
    ledValue = (ledValue + 1) % 256;
    analogWrite(ledPin, 128 + 128 * sin(2*PI*(ledValue/255.0)));
    delay(5);
}