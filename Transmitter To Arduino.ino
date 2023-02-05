// Define Input Connections
//input pin gula PWM a connect korbi
#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9
// Integers to represent values from sticks and pots
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value;
//--------------------------------------------------//
void setup() {
  Serial.begin(115200);
  // Set all pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
}
//----------------------------------------------------//
void loop() {
  // Get values for each channel
  ch1Value = readChannel(CH1, -100, 100, 0);  // readChannel je function ta ase oita call kortece input pin ch1 dia
  ch2Value = readChannel(CH2, -100, 100, 0);  // r aksathe mapping kore nicce
  ch3Value = readChannel(CH3, -100, 100, 0);
  ch4Value = readChannel(CH4, -100, 100, 0);
  // Print to Serial Monitor
  Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print(" | Ch2: ");
  Serial.print(ch2Value);
  Serial.print(" | Ch3: ");
  Serial.print(ch3Value);
  Serial.print(" | Ch4: ");
  Serial.print(ch4Value);

  delay(500);
}
// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue) {
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
