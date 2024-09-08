void setup() {
  pinMode(PB0, OUTPUT);
}

void loop() {
  for(int i=0; i <=256; i++) {
    analogWrite(PB0, i);
    delay(10);
  }
    for(int i=255; i>=0; i--) {
    analogWrite(PB0, i);
    delay(10);
  }
}
