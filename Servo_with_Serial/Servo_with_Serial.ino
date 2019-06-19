#include <Servo.h>
int t=1000;
int data;
int angle(90);

Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9); 

}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(angle);
 if(Serial.available())
 {
   data= Serial.read();
   Serial.print("                                                                                                                                                Recieved Data: "); 
   Serial.println(data);  
 
 
 if(data == 'r')
 {
  angle=angle+10;
  Serial.print(angle);
 }

 if(data == 'l')
 {
  angle=angle-10;
  Serial.print(angle);
 }

 }
 
 myservo.write(angle);
 
}

