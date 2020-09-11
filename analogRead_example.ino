#define A2DPin A0
#define R1_fixed 10000.0
void setup() 
{
  //setup the serial port for debug info...
  Serial.begin(115200);
  Serial.println("Analog read...");
}
void loop() 
{
  //read the digital value 0-1023
  int digValue = analogRead(A2DPin);
  
  float failure = digValue / 1024;//THIS WILL NOT WORK!!!!
  //The compiler only sees int values to the right of =
  //So 0/1024 in int land = 0 always
  
  //instead, make the constant value a FLOAT
  //by adding decimal place after
  float maybe = digValue / 1024.0;
  
  //better yet, typecast it and make the int a float
  float works = (float)digValue;
  works = works / 1024.0;
    
  Serial.print("fails: ");
  Serial.println(failure);
  
  Serial.print("maybe: ");
  Serial.println(maybe);
  
  Serial.print("works: ");
  Serial.println(works);
  delay(1000);
}
