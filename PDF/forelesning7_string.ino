void setup() {
  Serial.begin(9600);
}

void loop() {
  String s = "hei du";
  Serial.println(s);
  while (!Serial.available()) {}
  String s2 = Serial.readString();
  Serial.println(s2);
  String s3 = "2";
  //s3 = s3 + 4;
  s3.concat(4);
  Serial.println(s3);

  String s4 = reverseAndCap(s2);

  Serial.println(s4);

}

String reverseAndCap(String org) {
  String s;
  s = reverse(org);
  s = capFirst2(s);
  return s; 
}

String reverse(String org) {
  String rev = "";
  for (int i = 0; i < org.length(); i++) {
    rev = org.charAt(i) + rev;
  }
  return rev;
}

String capFirst(String org){
  org.toLowerCase();
  char c = org[0];
  c = c - ('a' - 'A');
  org.setCharAt(0, c);
  return org;
}

String capFirst2(String org){
  org.toLowerCase();
  char c = org[0];
  String first = (String)c;
  first.toUpperCase();
  c = first[0];
  org.setCharAt(0, c);
  return org;
}



