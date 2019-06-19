#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5
int LS=0, RS=0, FS=0;
void setup()
{
  pinMode(7,INPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  //
  pinMode(right_pwm,OUTPUT);
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(left_pwm,OUTPUT);
}
void loop()
{
  forward();
  delay(500);
  //right_turn();
  //delay(550);
  //left_turn();
  //delay(525);
  brake();
  delay(3000);
}
void right_turn()
{
  //digitalWrite(ledPin2,HIGH);
   analogWrite(left_pwm, 100);
   analogWrite(right_pwm, 100);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void left_turn()
{
  //digitalWrite(ledPin1,HIGH);
   analogWrite(left_pwm, 100);
   analogWrite(right_pwm, 100);
   digitalWrite(left_1,LOW);
   digitalWrite(left_2,HIGH);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}	
void brake()
{
   analogWrite(left_pwm, 0);
   analogWrite(right_pwm, 0);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,HIGH);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,HIGH);
}
void forward()
{
   analogWrite(left_pwm, 100);
   analogWrite(right_pwm, 100);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
