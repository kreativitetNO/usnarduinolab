void setup()
{
    Serial.begin(115200);
}

// Oppgave 3a
void skrivStjerner(int antall)
{
    for (int i = 0; i < antall; i++) {
        Serial.print('*');
    }
    Serial.println();
}

// Oppgave 3b
// Merk at jeg bruker funksjonen fra 3a. Både fordi
// det er fornuftig, og fordi det står i oppgaveteksten...
void skrivMangeStjerner(int antall)
{
    for (int i = 1; i <= antall; i++)
        skrivStjerner(i);
}

void loop()
{
    while (Serial.available() == 0){}
    int starCount = Serial.parseInt();
    while (Serial.available() > 0) {
        Serial.read();
    }
    if (starCount > 0 && starCount < 100) {
        skrivMangeStjerner(starCount);
    }
}