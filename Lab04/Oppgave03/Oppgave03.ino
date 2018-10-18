#include<IRremote.h>

const unsigned int irrecvPin = 38;
const unsigned int rLedPin = 40;
const unsigned int gLedPin = 42;
const unsigned int bLedPin = 44;

IRrecv irrecv(irrecvPin);
decode_results results;

void setup()
{
    Serial.begin(115200);
    Serial.println("Enabling IRin");
    irrecv.enableIRIn();
    Serial.println("Enabled IRin");
    pinMode(rLedPin, OUTPUT);
    pinMode(gLedPin, OUTPUT);
    pinMode(bLedPin, OUTPUT);
}

void handleResult(unsigned long value)
{
    switch (value) {
        case 0xFF30CF:
            digitalWrite(rLedPin, HIGH);
            break;
        case 0xFF18E7:
            digitalWrite(gLedPin, HIGH);
            break;
        case 0xFF7A85:
            digitalWrite(bLedPin, HIGH);
            break;
        case 0xFF10EF:
            digitalWrite(rLedPin, LOW);
            break;
        case 0xFF38C7:
            digitalWrite(gLedPin, LOW);
            break;
        case 0xFF5AA5:
            digitalWrite(bLedPin, LOW);
            break;
        default:
            Serial.println("Unknown code");
    }
}

void loop()
{
    if (irrecv.decode(&results))
    {
        handleResult(results.value);
        irrecv.resume();
    }
    delay(100);
}