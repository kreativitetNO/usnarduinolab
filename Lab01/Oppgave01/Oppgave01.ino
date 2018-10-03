/*
  Oppdaterer Blink eksempelet så den blinker dobbelt så fort.
*/

const int ledPin = 13; // Bruk gode variabelnavn - denne kan også være konstant så vi unngår
                       // å endre det ved en feiltagelse.

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);        // Halverer vi dette og neste delay vil LED lyset blinke dobbelt så fort.
  digitalWrite(ledPin, LOW);
  delay(500);
}
