#define Thermistor_Pin A0
#define R1_fixed 10000.0
#define A 1.009249522e-03
#define B 2.378405444e-04
#define C 2.019202697e-07
//define our function prototype
float readTempC(const int TPin, const float R1);
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
  //find T, first do log(R2) since it is needed twice
  float logR2 = log(R2);
  float Tkelvin = (1.0 / (A + B*logR2 + C*pow(logR2,3)));
  //print some debug parts to help us see if this is working...
  Serial.print("log(r2): \t");
  Serial.print(logR2);
  Serial.print("\tpow(logR2,3): \t");
  Serial.println(pow(logR2,3));
  
  Serial.print("Temperature: "); 
  Serial.print(Tkelvin);
  Serial.println(" K"); 
  float Tcel = Tkelvin - 273.15;
  Serial.print("Temperature: "); 
  Serial.print(Tcel);
  Serial.println(" °C"); 
  Serial.print("Function Temperature: "); 
  Serial.print(readTempC(Thermistor_Pin,R1_fixed));
  Serial.println(" °C"); 
  delay(1000);
}
//put the reading process in a function
float readTempC(const int TPin, const float R1)
{
  //read digital value
  int digValue = analogRead(TPin);
  //find R2
  float R2 = R1 * ((1024.0/digValue) - 1.0);
  //save logR2 because it is slow and used twice
  float logR2 = log(R2);
  //find the temp in K
  float Tkelvin = (1.0 / (A + B*logR2 + C*pow(logR2,3)));
  //convert to C
  float Tcel = Tkelvin - 273.15;
  //give back solution
  return Tcel;
}