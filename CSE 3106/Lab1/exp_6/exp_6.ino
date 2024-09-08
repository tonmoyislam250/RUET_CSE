
const int LED=PB0;
const int BUTTON=PC15;
bool prev=LOW;
bool current=LOW;
bool led=false;
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
}

bool debounce(bool last){
  bool current1=digitalRead(BUTTON);
  if(last!=current1)
  {
    delay(5);
    current1=digitalRead(BUTTON);
  }
  return current1;
}

void loop() {
  current=debounce(prev);
  if (prev == LOW && current == HIGH)
  {
    led = !led;
  }
  prev = current;
  digitalWrite(LED, led);
}
