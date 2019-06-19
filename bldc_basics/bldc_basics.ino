#include<Servo.h>
Servo bldc;
int max=2000;
int min =1000;
int data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  bldc.attach(9);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  bldc.writeMicroseconds(1500);
 
  
  

  

}
