unsigned char * const lab_uke_9 = 0x27;
unsigned char * const loeser_seg_selv = 0x28;
unsigned char ballbinge = 0;

void setup()
{
    *lab_uke_9 |= 0xf0;
    Serial.begin(57600);
}

void loop()
{
    *loeser_seg_selv = 1 << 4 + (ballbinge = ++ballbinge % 4), delay(200);
}