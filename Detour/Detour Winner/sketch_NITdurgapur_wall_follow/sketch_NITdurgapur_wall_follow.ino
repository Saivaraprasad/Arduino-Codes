#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5

int LWS, RWS, FS;
float wall_Kp=1, wall_Kd=0.01, wall_set_point=0;
int wall_error, wall_P, wall_D, wall_prev_error, wall_PID_value;
int left_thres; 
int right_thres;
int wall_right_motor_speed, wall_left_motor_speed;
int wall_initial_motor_speed=150;
void setup()
{
   //sensor inputs
   pinMode(A0,INPUT); //line sensor left4
   pinMode(A1,INPUT); //line sensor left3
   pinMode(A2,INPUT); //line sensor left2
   pinMode(A3,INPUT); //line sensor left1
   pinMode(6,INPUT); //line sensor right1
   pinMode(7,INPUT); //line sensor right2
   pinMode(11,INPUT); //line sensor right3
   pinMode(12,INPUT); //line sensor right4
   //wall sensors
   pinMode(A4,INPUT); //left wall sensor
   pinMode(A5,INPUT); //right wall sensor
   pinMode(2,INPUT); //front sensor
   //motors
   pinMode(3,OUTPUT); //tb66 pwm1
   pinMode(4,OUTPUT); //tb66 dig1
   pinMode(5,OUTPUT); //tb66 dig2
   pinMode(8,OUTPUT); //tb66 dig3
   pinMode(9,OUTPUT); //tb66 dig4
   pinMode(10,OUTPUT); //tb66 pwm 2
   //led
   pinMode(13,OUTPUT); //debugging led
}
void loop()
{
  follow_wall();
}
void follow_wall()
{
  FS=digitalRead(2);
  if(FS==1)
  {
    if((analogRead(A4)<left_thres)&&(analogRead(A5)>right_thres))//no left wall
    {
      brake();
      delay(100);
      forward();
      delay(10);
      wall_left_turn();
      delay(100);
      forward();
      delay(10);
    }
    else if((analogRead(A4)>left_thres)&&(analogRead(A5)<right_thres))//no right wall
    {
      brake();
      delay(100);
      forward();
      delay(10);
      wall_right_turn();
      delay(100);
      forward();
      delay(10);
    }
  }
  wall_pid();
}
void wall_pid()
{
  LWS = analogRead(A4);
  RWS = analogRead(A5);
  wall_error=LWS-RWS;
  wall_P = wall_error - wall_set_point;
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
   analogWrite(left_pwm, wall_left_motor_speed);
   analogWrite(right_pwm, wall_right_motor_speed);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   
}
void wall_right_turn()
{
  //digitalWrite(ledPin2,HIGH);
   analogWrite(left_pwm, 160);
   analogWrite(right_pwm, 160);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void wall_left_turn()
{
  //digitalWrite(ledPin1,HIGH);
   analogWrite(left_pwm, 160);
   analogWrite(right_pwm, 160);
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
   analogWrite(left_pwm, 240);
   analogWrite(right_pwm, 240);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
