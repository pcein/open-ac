/* Energia test program: transmit a byte 
 * through the uart, in a loop.
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  Serial.write('A');
  delay(1000);
}
