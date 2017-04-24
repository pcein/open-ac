/* Read from ADC pin A1 and
 * write resulting 12 bit data to
 * the UART
 */

#define NSAMPLES 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

// 12 bit ADC

uint16_t A1_data; /* Data from ADC pin A1, refer energia pinout 
                   * of the stellaris launchpad:
                   * http://energia.nu/Guide_StellarisLaunchPad.html
                   */
  
uint8_t samples = 0;
uint32_t sum = 0;                

void loop() {

  sum += analogRead(A1);
  samples++;

  if (samples == NSAMPLES) {
    samples = 0;
    A1_data = sum / NSAMPLES; 
    sum = 0; 
    // Note: the two bytes are transmitted without
    // any encoding to differentiate between lower
    // and higher order bytes. Use for testing only
  
    // write high byte
    Serial.write((A1_data >> 8) & 0xff);
    // write low byte
    Serial.write(A1_data & 0xff);
  
 }

 delay(100);

}
