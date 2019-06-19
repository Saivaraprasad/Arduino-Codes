#include <SoftwareSerial.h>

#include<Servo.h>
int Tilt_angle=0;
SoftwareSerial blue(10,11);//rx,tx
#define Servopin 9 //header
int a;
Servo pitch;
  
void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
blue.begin(9600);
pitch.attach(Servopin);

}

void loop() 
{

  if(blue.available())
  {
    a=blue.read();
    Serial.print(a);
  // put your main code here, to run repeatedly:
  if(a==48)
  {
  Tilt_angle = Tilt_angle + 3;
  pitch.write(Tilt_angle);
  delay(50);
  }

  else if(a==49)
  {
  Tilt_angle = Tilt_angle - 3;
  pitch.write(Tilt_angle);
  delay(50);
  }
 }



}
