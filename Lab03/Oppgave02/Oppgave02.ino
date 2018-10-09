const int ledPin = 13;
const int buzzerPin = 2;
int delayTime = 500;

// Se notat fra Oppgave 1.
// Se dokumentasjonen til parseInt(). Den ignorerer alt som
// ikke er et tall fram til den finner et tall, eller eventuelt
// ikke finner et tall og går ut på tid. Dette er en vesentlig
// grunn til at koden her kan skrives på denne måten. Selv med
// linjeskift og mellomrom og alt i serieport køen.

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    if (Serial.available() > 0)
    {
        int choice = Serial.parseInt();
        int userValue = Serial.parseInt();
        while (Serial.available() > 0)
        {
            Serial.read();
        }
        if (choice == 1 && userValue > 0)
        {
            delayTime = userValue;
        }
        // Hvorfor sjekker vi om userValue < 256? Les analogWrite()
        // dokumentasjon.
        else if (choice == 2 && userValue > 0 && userValue < 256)
        {
            analogWrite(buzzerPin, userValue);
        }
        else
        {
            analogWrite(buzzerPin, 0); // Så dere ikke blir sprø av lyden
        }
    }
    for (int j = 1; j >= 0; j--)
    {
        digitalWrite(ledPin, j);
        delay(delayTime);
    }
}