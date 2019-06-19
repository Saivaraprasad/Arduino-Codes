#include <Servo.h>
int t=1000;

Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 myservo.attach(6); 

}

void loop() {
  // put your main code here, to run repeatedly:

 for(int i=0; i<180; i++)
 {
 myservo.write(i);
 Serial.println(i);
 delay(10);
 }

 for(int i=180; i>0; i--)
 {
 myservo.write(i);
 Serial.println(i);
 delay(10);
 }
 
}
