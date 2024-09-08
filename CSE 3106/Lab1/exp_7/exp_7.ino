const int BLED=PB10; 
const int GLED=PB0;
const int RLED=PB1; 
const int TEMP=PA0;

const int LOWER_BOUND=100;

const int UPPER_BOUND=900;
int val = 0;

void setup() {
  pinMode (TEMP, INPUT);
  pinMode (BLED, OUTPUT); 
  pinMode (GLED, OUTPUT); 
  pinMode (RLED, OUTPUT);
}

void loop() {
  val = analogRead(TEMP);
  if (val < LOWER_BOUND) {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }

  else if (val > UPPER_BOUND) { 
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  else { 
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
}
