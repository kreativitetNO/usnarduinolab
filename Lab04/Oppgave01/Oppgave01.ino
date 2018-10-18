void setup()
{
    Serial.begin(115200);
}

void loop()
{
    int tall1 = -2;
    int tall2 = -7;
    
    //så kaller jeg noen funksjoner
    tall1 = abs1(tall1);
    abs2(&tall2);
    Serial.print(tall1);
    Serial.print(tall2);
}

int abs1(int tall)
{
    // Dette kalles en ternary operator. Det er et
    // av de få tilfellene der en ternary operator
    // ikke gjør koden mindre oversiktlig.
    return tall < 0 ? -tall : tall;
}

void abs2(int* tall)
{
    if (*tall < 0)
        *tall *= -1;
}

// Dere lærer nok om alias parametre ganske snart.
void abs3(int& tall)
{
    if (tall < 0)
        tall *= -1;
}