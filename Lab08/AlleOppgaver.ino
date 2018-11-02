#define AUTOTEST

void setup() {
  Serial.begin(57600);
}

void loop()
{
  String s1 = getString();
  Serial.println(s1);
  reportLetter(s1, 'e');
  String s2 = getString();
  Serial.println(s2);
  reportLetter(s2, 'e');
  String s3 = getString();
  Serial.println(s3);
  s3 = replaceLetter(s3, 'e', 'i');
  Serial.println(s3);
  String s4 = getString();
  Serial.println(s4);
  s4 = removePar(s4);
  Serial.println(s4);
  String s5 = getString();
  Serial.println(s5);
  s5 = removePar(s5);
  Serial.println(s5);
}

String getString()
{
#ifdef AUTOTEST
  String testStrings[] = { 
    "En tekst med bokstaven 'e'",
    "En tkst utn bokstavn...",
    "Tre små kinesere",
    "En tekst (med) et par paranteser",
    "En tekst (med) to (par) paranteser"
    };
  const int stringCount = 5;
  static int stringIndex = 0;
  if (stringIndex == stringCount)
    while (true);
  return testStrings[stringIndex++];
#elif
  while (Serial.available() == 0) {}
  String s = Serial.readString();
  while (Serial.available() > 0) {
    Serial.read();
  }
#endif
}

void reportLetter(String s, char c)
{
  int ePos = s.indexOf(c);
  char message[64];
  if (ePos == -1) {
    sprintf(message, "Det fins ingen %c", c);
  }
  else {
    sprintf(message, "Den første %c er på plass %i", c, ePos);
  }
  Serial.println(message);
}

String replaceLetter(String s, char oldLetter, char newLetter)
{
  s.replace(oldLetter, newLetter);
  return s;
}

String removePar(String s)
{
  String result;
  bool insideBrackets = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      insideBrackets = true;
    else if (s[i] == ')')
      insideBrackets = false;
    else if (!insideBrackets)
      result += s[i];
  }
  return result;
}
