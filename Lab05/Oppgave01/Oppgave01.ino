const unsigned int xJoyPin = A1;
const unsigned int yJoyPin = A2;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.print("X: ");
    Serial.print(analogRead(xJoyPin));
    Serial.print(" Y: ");
    Serial.print(analogRead(yJoyPin));
    Serial.println();
}