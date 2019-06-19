

#include<EEPROM.h>
int a=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Memmory available:  ");
  Serial.println(EEPROM.length());
  Serial.println("Data entry Initialised");
  delay(1000);
  
 for(int i=0;i<250;i++)
 {
  
  EEPROM.write(a,i);
  a++;
  Serial.println(i);
  delay(10);
  if(a == EEPROM.length())
 a=0;
 }
 
 Serial.println("Succesfully written data to EEPROM");

 delay(100000);
 
}
