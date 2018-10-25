/*
  Blink
  Turns an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
*/

/*
  Dette eksempelet fra eksempelsamlingen som følger med Arduino IDE
  danner utgangspunkt for den første oppgaven.
*/

int led = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println(sizeof(int));
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
