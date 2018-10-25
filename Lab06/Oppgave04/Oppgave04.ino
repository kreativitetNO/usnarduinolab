#include "DHT.h"
#define DHTPIN 2      // what digital pin we're connected to
#define DHTTYPE DHT11 // DHT 11

const unsigned long measurementDelay = 1500;
const unsigned int measurementCount = 10;
const unsigned int outputBufferSize = 256;

struct Measurement
{
  float humidity;
  float temperature;
  bool validHumidity;
  bool validTemperature;
};

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void prepareMeasurementsArray(Measurement measurements[], unsigned int measurementCount)
{
  for (int i = 0; i < measurementCount; i++)
  {
    // Dette heter å etablere en "invariant". Det fins
    // bedre måter å gjøre det på (se: constructor), men
    // hensikten er å sikre at et nyopprettet objekt har
    // forutsigbare verdier.
    measurements[i].temperature = 0.0f;
    measurements[i].humidity = 0.0f;
    measurements[i].validTemperature = false;
    measurements[i].validHumidity = false;
  }
}

void takeMeasurements(Measurement measurements[], unsigned int measurementCount)
{
  for (int i = 0;
       i < measurementCount;
       i++) {
    delay(measurementDelay);

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (!isnan(h)) {
      measurements[i].humidity = h;
      measurements[i].validHumidity = true;
    }
    if (!isnan(t)) {
      measurements[i].temperature = t;
      measurements[i].validTemperature = true;
    }
  }
}

void calculateSummary(Measurement measurements[], unsigned int measurementCount,
                      double *avgTemperature, unsigned int *validTemperatureCount,
                      double *avgHumidity, unsigned int *validHumidityCount)
{
  double temperatureSum = 0.0, humiditySum = 0.0;
  for (int i = 0; i < measurementCount; i++)
  {
    if (measurements[i].validTemperature)
    {
      temperatureSum += (double)measurements[i].temperature;
      (*validTemperatureCount)++;
    }
    if (measurements[i].validHumidity)
    {
      humiditySum += (double)measurements[i].humidity;
      (*validHumidityCount)++;
    }
  }
  *avgTemperature = temperatureSum / *validTemperatureCount;
  *avgHumidity = humiditySum / *validHumidityCount;
}

void printSummary(unsigned int measurementCount,
                  double avgTemperature, unsigned int validTemperatureCount,
                  double avgHumidity, unsigned int validHumidityCount)
{
  Serial.print("Out of a total of ");
  Serial.print(measurementCount);
  Serial.print(" measurements, there were ");
  Serial.print(validTemperatureCount);
  Serial.print(" valid temperature readings with an average of ");
  Serial.print(avgTemperature, 2);
  Serial.print(" degrees Celsius, and ");
  Serial.print(validHumidityCount);
  Serial.print(" valid humidity readings with an average of ");
  Serial.print(avgHumidity, 2);
  Serial.print(" percent.");
  Serial.println();
  String fString(1.20, 2);
  Serial.print(fString);
}

void loop()
{
  Measurement measurements[measurementCount];
  unsigned int validTemperatureCount = 0, validHumidityCount = 0;
  double avgTemperature = 0.0, avgHumidity = 0.0;

  prepareMeasurementsArray(measurements, measurementCount);
  Serial.print("Taking ");
  Serial.print(measurementCount);
  Serial.print(" measurements at ");
  Serial.print(measurementDelay);
  Serial.print("ms intervals...");
  takeMeasurements(measurements, measurementCount);
  Serial.println("done!");
  calculateSummary(measurements, measurementCount,
                   &avgTemperature, &validTemperatureCount,
                   &avgHumidity, &validHumidityCount);
  printSummary(measurementCount, avgTemperature, validTemperatureCount,
               avgHumidity, validHumidityCount);
}