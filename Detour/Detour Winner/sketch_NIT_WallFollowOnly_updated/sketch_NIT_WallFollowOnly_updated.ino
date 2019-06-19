#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5
int LWS, RWS, FS;
float wall_Kp=0.05, wall_Kd=0.05, wall_set_point=0;
int wall_error, wall_P, wall_D, wall_prev_error, wall_PID_value;
int left_thres; 
int right_thres;
int wall_right_motor_speed, wall_left_motor_speed;
int wall_initial_motor_speed=150;

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
  FS=digitalRead(12);
  //FS = digitalRead(12);
  wall_follow();
  /*Serial.print(LWS);
  Serial.print(",");
  Serial.print(RWS);
  Serial.println(" ");
  */
  if(LWS<350)
  {
    brake();
    delay(5);
    FS=digitalRead(12);
    while(FS!=1)
    {
      forward_front_wall();
      FS=digitalRead(12);
    }
    brake();
    delay(100);
    left_turn();
    delay(950);
    brake();
    delay(100);
    forward();
    delay(150);
   }
  else if(RWS<350)
  {
    brake();
    delay(5);
    FS=digitalRead(12);
    while(FS!=1)
    {
      forward_front_wall();
      FS=digitalRead(12);
    }
    brake();
    delay(100);
    right_turn();
    delay(1300);
    brake();
    delay(100);
    forward();
    delay(150);
   }
   if((RWS<350)&&(RWS<350)&&(FS==1))
   {
    left_turn(); 
   }
}
void wall_follow()
{
  //Serial.println(wall_error);
  wall_error=LWS-RWS;
  wall_P = wall_error;
  wall_D = wall_prev_error - wall_error;
  wall_PID_value = (wall_Kp*wall_P) + (wall_Kd*wall_D);
  wall_prev_error = wall_error;
   
   wall_left_motor_speed = wall_initial_motor_speed+wall_PID_value;
   wall_right_motor_speed = wall_initial_motor_speed-wall_PID_value;
   if(wall_left_motor_speed>=255)   
   {    
	wall_left_motor_speed=255;
   }
   if(wall_left_motor_speed<=0)
   {    
	wall_left_motor_speed=0;
   }
   if(wall_right_motor_speed>=255)
   {
    wall_right_motor_speed=255;
   }
   if(wall_right_motor_speed<=0)
   {
    wall_right_motor_speed=0;
   }
   /*Serial.print(wall_left_motor_speed);
   Serial.print(",");
   Serial.print(wall_right_motor_speed);
   Serial.print("\n");
  */
  analogWrite(left_pwm, wall_left_motor_speed);
   analogWrite(right_pwm, wall_right_motor_speed);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
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

