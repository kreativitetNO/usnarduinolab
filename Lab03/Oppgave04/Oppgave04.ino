void setup()
{
    Serial.begin(115200);
    Serial.println(sizeof(int));
}

unsigned long faktorial1(int tall)
{
    unsigned long result = 1; // Hvorfor?
    for (int i = tall; i > 1; i--) { // Hvorfor 'i > 1'?
        result *= i; // Snarvei for result = result * i
    }
    return result;
}

// Dette er en rekursiv løsning som ligger litt over deres
// nivå foreløpig, men ikke spesielt komplisert og litt artig.
unsigned long faktorial2(int tall)
{
    if (tall < 2) return 1; // Ett av de få tilfellene dette er greit
    return tall * faktorial2(tall - 1);
}

void loop()
{
    while (Serial.available() == 0){}
    int number = Serial.parseInt();
    while (Serial.available() > 0) {
        Serial.read();
    }
    if (number >= 0 && number <= 12) {
        // Bytt kommentartegn på de 2 neste linjene for
        // å teste de 2 forskjellige funksjonene.
        // unsigned long svar = faktorial1(number);
        unsigned long svar = faktorial2(number);
        // Dere som har hatt Python kurset skjønner kanskje
        // hvordan sprintf() fungerer.
        // Serial.print("Faktorial av ");
        // Serial.print(number);
        // Serial.print(" er ");
        // Serial.println(svar);
        char svarTekst[100];
        sprintf(svarTekst, "Faktorial av %d er %lu", number, svar);
        Serial.println(svarTekst);
    }
    else {
        // Faktorial av negative tall er ikke definert, og
        // en unsigned long klarer ikke tall større enn 2
        // opphøyd i 32. 13! blir omtrent 2 milliarder for
        // mye.
        Serial.println("Illegal number");
    }
}
