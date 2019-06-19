#define Liftp 4
#define Liftn 2
#define Lift_PWM 3
#define Up_Contact 9
#define Down_Contact 8
#define Broom_Pin 5
#define Bucket_Pin 6


#define Sweep_in_Angle 20
#define Sweep_out_Angle 130
#define Dump_Angle  150
#define Collect_Angle 30

#include<Servo.h>

 Servo Broom;
 Servo Bucket;

 int LIFT_UP_SPEED = 100;
 int LIFT_DOWN_SPEED = 50;

 int data=0;
 unsigned long Last_Timer =0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Liftp,OUTPUT);
  pinMode(Liftn,OUTPUT);
  pinMode(Lift_PWM,OUTPUT);

  Broom.attach(Broom_Pin);
  Bucket.attach(Bucket_Pin);

  Broom.write(Sweep_out_Angle);
  delay(500);
  Bucket.write(Collect_Angle);
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//
// Lift_up(100);
// delay(2000);
// Lift_down(100);
// delay(2000);
//Dump();
//Serial.println("Dumping");
//delay(2000);
//Collect();
//Serial.println("Collectinng");
//delay(2000);

//Sweep_in();
//Serial.println("in");
//delay(2000);
//Sweep_out();
//Serial.println("Out");
//delay(2000);
if(Serial.available())
{
data = Serial.read();
}

if(data=='8')
{
  Lift_up(LIFT_UP_SPEED);
}

if(data== '2')
{
  Lift_down(LIFT_DOWN_SPEED);
 
}

if(data== '4')
{
  Sweep_in();
}

if(data== '6')
{
  Sweep_out();
}

if(data== '1')
{
  Collect();
}

 if(data== '3')
 {
  Dump();
 }
if(data == '5')
{
  Sequence();
}

 else
 {
  stops();
 }
 
Serial.print("      ");
Serial.print(digitalRead(Up_Contact));
Serial.print("      ");
Serial.print(digitalRead(Down_Contact));
Serial.print("      ");
Serial.print(data);

data=0;
Serial.println("  ");
}


void brake()
{
  Serial.print("Brake");
    digitalWrite(Liftp,HIGH);
    digitalWrite(Liftn,HIGH);
}
void stops()
{
   Serial.print("Stopped");
    digitalWrite(Liftp,LOW);
    digitalWrite(Liftn,LOW);
}

int Lift_up(int i)
{

  Last_Timer = millis();
  while(!digitalRead(Up_Contact))
  {
    Serial.println("Lift Up");
    digitalWrite(Liftp,HIGH);
    digitalWrite(Liftn,LOW);
    analogWrite(Lift_PWM,i);
  unsigned long Timer =millis();
  if(Timer - Last_Timer > 2000)
  Lift_up(200);
  }
  delay(100);
  
  
}

int Lift_down(int i)
{
   while(!digitalRead(Down_Contact))
   {
  Serial.println("Lifting Down");
    digitalWrite(Liftp,LOW);
    digitalWrite(Liftn,HIGH);
    analogWrite(Lift_PWM,i);
   }
  stops();
  brake();
  delay(25);
    digitalWrite(Liftp,HIGH);
    digitalWrite(Liftn,LOW);
    analogWrite(Lift_PWM,60);
    delay(50);
  
  
}

 void Sweep_in()
 {
  
  for(int i=Sweep_out_Angle; i>=Sweep_in_Angle; i--)
  {
    Broom.write(i);
    Serial.println("sweeping in");
    delay(25);
  }
 }

  void Sweep_out()
 {
  for(int i=Sweep_in_Angle; i<=Sweep_out_Angle; i++)
  {
    Broom.write(i);
    Serial.println("Sweeping out");
    delay(25);
  }
 }

void Collect()
 {
  
  int i;
  for(i=Dump_Angle; i>=Collect_Angle; i--)
  {
    Bucket.write(i);
    Serial.println("Collecting");
    delay(25);
  }
 }

 void Dump()
 {
  
  for(int i=Collect_Angle; i<=Dump_Angle; i++)
  {
    Bucket.write(i);
    Serial.println("Dumping");
    delay(25);
 }
 }

void Sequence()
{
  Serial.println(" SEQUENCE INITIATED  ");
  
  Sweep_in();
  Sweep_out();
  Sweep_in();
  Sweep_out();

  Lift_up(LIFT_UP_SPEED);
  delay(100);
  
  Dump();
  Collect();
  delay(100);

  Lift_down(LIFT_DOWN_SPEED);
  
}

