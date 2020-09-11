#define Thermistor_Pin A0
#define R1_fixed 10000.0
void setup() 
{
  //setup the serial port for debug info...
  Serial.begin(115200);
  Serial.println("Start...");
}
void loop() 
{
  //read the digital value 0-1023
  int digValue = analogRead(Thermistor_Pin);
  //convert to floating point
  float voltCalc = (float)digValue;
  //find the voltage ratio
  voltCalc = voltCalc/1024.0;
  Serial.print("Voltage input: ");
  Serial.print(voltCalc * 5.0);
  Serial.println(" V");
  //find R2...
  float R2 = R1_fixed * ((1024.0/digValue) - 1.0);
  Serial.print("R2: ");
  Serial.print(R2);
  Serial.println(" ohm");
  delay(1000);
}
