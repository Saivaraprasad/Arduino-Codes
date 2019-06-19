#include<Servo.h>
Servo bldc;
int maxi=2000;
int mini =1000;
int data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  bldc.attach(9);
  pinMode(A0,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  data=analogRead(A0);
  Serial.print(data);
  Serial.print(" ----->   ");
  data=map(data,0,1023,mini,maxi);
  bldc.writeMicroseconds(data);
  Serial.println(data);
  
  

  

}
