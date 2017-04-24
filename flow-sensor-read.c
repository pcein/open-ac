/* Read from ADC pin A1 and
 * write resulting 12 bit data to
 * the UART
 */

#define PULSE1_PIN PE_4
#define MAX_PULSE_WIDTH 1000 // in milli seconds

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PULSE1_PIN, INPUT);
}


uint8_t catch_rising_edge()
{
    unsigned long t1, t2;
    
    t1 = millis();
    while (digitalRead(PULSE1_PIN)) {
        t2 = millis();
        if ((t2 - t1) > MAX_PULSE_WIDTH) {
            return 0;
        }
    }

    t1 = millis();
    
    while (!digitalRead(PULSE1_PIN)) {
        t2 = millis();
        if ((t2 - t1) > MAX_PULSE_WIDTH) {
            return 0;
        }
    }

    return 1;
}

uint16_t count_pulses_in_one_second() 
{
    unsigned long t1, t2;
    uint16_t npulses = 0;

    t1 = millis();

    while (1) {
        if (catch_rising_edge() == 0) 
            return npulses;
        npulses++;
        
        t2 = millis();
        if ((t2 - t1) > MAX_PULSE_WIDTH) {
            return npulses;
        }
    }
}   


uint16_t num_pulses;

void loop() {

  num_pulses = count_pulses_in_one_second();
  
  // Note: the two bytes are transmitted without
  // any encoding to differentiate between lower
  // and higher order bytes. Use for testing only
  
  // write high byte
  Serial.write((num_pulses >> 8) & 0xff);
  // write low byte
  Serial.write(num_pulses & 0xff);
  
  delay(100);
}
