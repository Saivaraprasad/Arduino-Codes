#include<Servo.h>
Servo esc;

int maxi=2000;
int mini=1000;
int thrust = mini;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  esc.attach(9);

  esc.writeMicroseconds(maxi);
   delay(1000);
    esc.writeMicroseconds(mini);
   delay(1000);
   

}

void loop() {
  // put your main code here, to run repeatedly:
   
   if(Serial.read() == '2')
   {
    thrust= thrust +100;
    Serial.println(thrust);
   }
   if(Serial.read() == '8')
   {
    thrust = thrust -100;
    Serial.print(thrust);
    
   }
   if(Serial.read() == 'x')
   {
      thrust=mini;
      Serial.println("Action Ceased");
      
   }
   
   
   esc.writeMicroseconds(thrust);
}
