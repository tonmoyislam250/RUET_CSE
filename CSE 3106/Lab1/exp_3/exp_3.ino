void setup() {
  pinMode(PA15, OUTPUT);
}

void loop() {
  for(int i = 100; i <= 1000; i=i+100) {
    digitalWrite(PA15, HIGH);
    delay(i);
    digitalWrite(PA15, LOW);
    delay(i);
  }
}
