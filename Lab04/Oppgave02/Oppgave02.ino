const int potPin = A3;
const unsigned int measurementDelay = 50;
const unsigned int numberOfMeasurements = 100;

void setup()
{
    Serial.begin(115200);
}

void getMeasurements(int measurements[], unsigned int length)
{
    for (int i = 0; i < length; i++) {
        measurements[i] = analogRead(potPin);
        delay(measurementDelay);
    }
}

void displayMeasurements(int measurements[], unsigned int length)
{
    for (int i = 0; i < length; i++) {
        Serial.print("Measurement ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(measurements[i]);
    }
}

void loop()
{
    int measurements[numberOfMeasurements];
    Serial.println("Starting measurements:");
    getMeasurements(measurements, numberOfMeasurements);
    displayMeasurements(measurements, numberOfMeasurements);
    while (true){}
}