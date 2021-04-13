/*   Tested for CALT HAE28 Absolute Rotary Encoder
 *   
 *   Encoder Red (Power +)  <-> Arduino +5V
 *   Encoder Black (GND)    <-> Arduino GND
 *   Encoder Blue (Clock)   <-> Arduino Pin 5
 *   Encoder Green (DATA)   <-> Arduino Pin 6
 *   Encoder Yellow (CS)    <-> Arduino Pin 7
 */
 
const int CLOCK_PIN = 5; // Blue Pin
const int DATA_PIN = 6; // Green Pin
const int CS_PIN = 7; // Yellow Pin
const int BIT_COUNT = 12; // 12 Bit Mode

void setup()
{
  //setup our pins
  pinMode(DATA_PIN, INPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(CS_PIN, OUTPUT);
  //give some default values
  digitalWrite(CLOCK_PIN, HIGH);
  digitalWrite(CS_PIN, HIGH);
  Serial.begin(115200);
}

void loop()
{
  float reading = readPosition();
  if (reading >= -0.5)
  {
    Serial.print("Reading: ");
    Serial.println(reading, 2);
  }
  delay(50);
}

//read the current angular position
float readPosition()
{
  // Read the same position data twice to check for errors
  unsigned long sample1 = shiftIn(DATA_PIN, CLOCK_PIN, CS_PIN, BIT_COUNT);
  unsigned long sample2 = shiftIn(DATA_PIN, CLOCK_PIN, CS_PIN, BIT_COUNT);
  delayMicroseconds(20); // Clock must be high for 20 microseconds before a new sample can be taken
  if (sample1 != sample2) return -1.0;
  return ((sample1 & 0x0FFF) * 360UL) / 4096.0;
}

//read in a byte of data from the digital input of the board.
unsigned long shiftIn(const int data_pin, const int clock_pin, const int cs_pin, const int bit_count)
{
  unsigned long data = 0;

  digitalWrite(cs_pin, LOW);
  for (int i = 0; i < bit_count; i++)
  {
    data <<= 1;
    digitalWrite(clock_pin, LOW);
    delayMicroseconds(1);
    digitalWrite(clock_pin, HIGH);
    delayMicroseconds(1);

    data |= digitalRead(data_pin);
  }
  digitalWrite(cs_pin, HIGH);
  return data;
}
