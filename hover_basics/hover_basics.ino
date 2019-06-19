#include <Servo.h>
Servo liftm;
Servo pushm;
#define state 2
int data;
int lift=1000;
int push=1000;
int mini=1000;
int maxi=2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  liftm.attach(9);
  pushm.attach(10);

  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);

  
  pinMode(A0,INPUT);
  
  liftm.writeMicroseconds(maxi);
   delay(1000);
    liftm.writeMicroseconds(mini);
   delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.print("initial lift");
  //Serial.println(lift);
  
/*if(digitalRead(state)==0)
{
  Serial.print("                                                                                                       Bluetooth not connected         Calibration Mode");
  data=analogRead(A0);
  Serial.print(data);
  Serial.print(" ----->   ");
  data=map(data,0,1023,mini,maxi);
  liftm.writeMicroseconds(data);
  Serial.println(data);
}*/
  
if(Serial.available())
{
  //Serial.print("                                                                                                           Bluetooth Connected");
  data=Serial.read();
 Serial.print("                                                                                                                                              \t           recieved : ");
Serial.println(data);

if(data=='2')
{
  if(lift!=maxi)
  {
    lift=lift+100;
    Serial.println(lift);
    //delay(50);
    
  }
}

if(data=='8')
{
  if(lift!=mini)
  {
    lift=lift-100;
    Serial.println(lift);
    delay(50);
  }
}

}

liftm.writeMicroseconds(lift);



}
