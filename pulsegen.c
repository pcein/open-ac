
#define PULSE1_PIN PE_4

void setup() {
  // put your setup code here, to run once:
  pinMode(PULSE1_PIN, OUTPUT);
}


void loop() {

  digitalWrite(PULSE1_PIN, LOW);
  delay(100);
  digitalWrite(PULSE1_PIN, HIGH);
  delay(100);
}
