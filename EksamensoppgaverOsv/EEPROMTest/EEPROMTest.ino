#include <EEPROM.h>

void setup()
{
    Serial.begin(57600);
}

void getStringFromEEPROM(char s[], int len)
{
    int i = 0;
    do {
        s[i++] = EEPROM.read(i);
    } while (s[i] != 0 && i < len - 1);
}

void setEEPROMFromString(char s[], int len)
{
    for (char *c = s; *c && c-s < len - 1; c++)
        EEPROM.write(c-s, *c);
}

void loop()
{
    char test[1024];
    getStringFromEEPROM(test, 1024);
    Serial.print("Retrieved from EEPROM: ");
    Serial.println(test);
    while (true) {
        if (Serial.available() > 0) {
            memset(test, 0, 1024);
            for (int i = 0; Serial.available() && i < 1023; i++)
                test[i++] == Serial.read();
            while (Serial.available())
                Serial.read();
            setEEPROMFromString(test, 1024);
            Serial.print("Written to EEPROM: ");
            Serial.println(test);
        }
    }
}