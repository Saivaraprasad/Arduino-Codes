#define disply_time 1000

#define lmp 
#define lmn 
#define rmp 
#define rmn 

#define tf 
#define ef 

#include <LiquidCrystal.h>
LiquidCrystal lcd(11,12,5,4,3,2);

int duration,cm;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

 // Serial.begin(9600);
 
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  
   pinMode(tf,OUTPUT);
   pinMode(ef,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //disply
  lcd.print("Hello,");
  lcd.setCursor(2,1);
  lcd.print("I am a robot");
  delay(disply_time);
  lcd.clear();

//Ultrasonic data
  digitalWrite(tf,LOW);
  delayMicroseconds(2);
  digitalWrite(tf,HIGH);
  delayMicroseconds(5);
  digitalWrite(tf,LOW);
  
  duration = pulseIn(ef,HIGH);
  cm = duration/29/2;
 // Serial.println(cm);
}

/*
void forward()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void backward()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
}

void sharpleft()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
}

void sharpright()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void left()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,LOW);
}

void right()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void stops()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,LOW);
}

void blinks()
{
digitalWrite(13,HIGH);
delay(250);
digitalWrite(13,LOW);
delay(250);
  
}
*/
