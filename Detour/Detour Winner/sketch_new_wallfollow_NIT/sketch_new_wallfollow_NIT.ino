#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5
int LWS, RWS, FS;
float wall_Kp=10, wall_Kd=0, wall_set_point=0;
int wall_error, wall_P, wall_D, wall_prev_error, wall_PID_value;
int left_thres; 
int right_thres;
int wall_right_motor_speed, wall_left_motor_speed;
int wall_initial_motor_speed=80;

void setup()
{
  Serial.begin(9600);
  //wall
  pinMode(A4,INPUT); //left wall sensor
  pinMode(A5,INPUT); //right wall sensor
  pinMode(12,INPUT); //front sensor
  //motor 
  pinMode(right_pwm,OUTPUT);
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(left_pwm,OUTPUT);
}
void loop()
{
  LWS = analogRead(A4);
  RWS = analogRead(A5);
  while((LWS<500)&&(RWS>800)&&(FS!=0))
  {
    brake();
    delay(5000);
    //delay(5);
    //FS=digitalRead(12);
    LWS = analogRead(A4);
    RWS = analogRead(A5);
    FS=digitalRead(12);
    right_wall_follow();
  }
  left_wall_follow();
  
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
void forward_front_wall()
{
  analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
void forward()
{
   analogWrite(left_pwm, 150);
   analogWrite(right_pwm, 150);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
void right_turn()
{
  //digitalWrite(ledPin2,HIGH);
   analogWrite(left_pwm, 50);
   analogWrite(right_pwm, 50);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void left_turn()
{
  //digitalWrite(ledPin1,HIGH);
   analogWrite(left_pwm, 50);
   analogWrite(right_pwm, 50);
   digitalWrite(left_1,LOW);
   digitalWrite(left_2,HIGH);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}	
void left_wall_follow()
{
  while(LWS>980)
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 0);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<979)&&(LWS>974))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 20);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<973)&&(LWS>965))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 40);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<964)&&(LWS>960))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 60);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<960)&&(LWS>949))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<949)&&(LWS>942))
  {
    analogWrite(left_pwm, 60);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<942)&&(LWS>936))
  {
    analogWrite(left_pwm, 40);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<936)&&(LWS>930))
  {
    analogWrite(left_pwm, 20);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((LWS<936)&&(LWS>915))
  {
    analogWrite(left_pwm, 0);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
   
  }
 
}
void right_wall_follow()
{
  while(RWS>980)
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 0);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<979)&&(RWS>974))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 20);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<973)&&(RWS>965))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 40);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<964)&&(RWS>960))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 60);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<960)&&(RWS>949))
  {
    analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<949)&&(RWS>942))
  {
    analogWrite(left_pwm, 60);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<942)&&(RWS>936))
  {
    analogWrite(left_pwm, 40);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<936)&&(RWS>930))
  {
    analogWrite(left_pwm, 20);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
  }
  while((RWS<936)&&(RWS>915))
  {
    analogWrite(left_pwm, 0);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   LWS = analogRead(A4);
   
  }
}
