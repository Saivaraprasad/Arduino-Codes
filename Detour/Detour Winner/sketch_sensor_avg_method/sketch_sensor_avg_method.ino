#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5
#define front_sens 6
#define left_sens 11
int left1;
int left2;
int left3;
int left4;
int right1;
int right2;
int right3;
int right4;
int lc=0;
int sc=1;
float Kp=0.55, Kd=0.055;   
float P=0, D=0, PD_value=0;  
float left_motor_speed=0, right_motor_speed=0;
float previous_P=0;
int left=0;
int right=0;
int pos;
int setpoint=3500;
long sensors_average=0;
int sensors_sum=0;
//int max_speed=180;
void setup()
{
  //
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  //
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);
  //Serial.begin(9600);
}
void loop()
{   
    left4=digitalRead(A0); 
    left3=digitalRead(A1); 
    left2=digitalRead(A2); 
    left1=digitalRead(7); 
    right1=digitalRead(2); 
    right2=digitalRead(A3); 
    right3=digitalRead(A4); 
    right4=digitalRead(A5);
    if(left4==0)   
    {
     left=0;
    }
    if(right4==0)
    {
     right=0;
    }
    if((left4!=0)&&(left3!=0)&&(left2!=0)&&(left1!=0)&&(right1!=0)&&(right2!=0)&&(right3!=0)&&(right4!=0))
    {
      if((left>600)&&(right<600))  
      {
          left1=digitalRead(7); 
          right1=digitalRead(2); 
          while((right1!=0)&&(left1!=0))
	  {
	    right_turn();
	    left1=digitalRead(7); 
            right1=digitalRead(2); 
          }
          
      }
      else if((left<600)&&(right>600)) 
      {
	    left1=digitalRead(7); 
            right1=digitalRead(2); 
            
            while((left1!=0)&&(right1!=0))
	    {
	     left_turn();
	     left1=digitalRead(7); 
             right1=digitalRead(2); 
            }
            
       }
    }
    
    PD_loop(160);
    left=left+1;
    right=right+1;
     if(left>20000)
     {
       left=1000;
     }
     if(right>20000)
     {
       right=1000;
     }
}
void PD_loop(int base_speed)
{   
    //sensor & error
    sensors_average=(((left4)*0)+((left3)*1000)+((left2)*2000)+((left1)*3000)+((right1)*4000)+((right2)*5000)+((right3)*6000)+((right4)*7000));
    sensors_sum=((left4)+(left3)+(left2)+(left1)+(right1)+(right2)+(right3)+(right4));
    pos=(sensors_average/sensors_sum);
    //PD_calculation
    P = setpoint - pos;
    D = P - previous_P;
    
    PD_value = (Kp*P) + (Kd*D);
    previous_P = P;
    //motor drive
    left_motor_speed = base_speed+PD_value;
    right_motor_speed = base_speed-PD_value;
   if(left_motor_speed>=255)   
   {    
	left_motor_speed=255;
   }
   if(left_motor_speed<=0)
   {    
	left_motor_speed=0;
   }
   if(right_motor_speed>=255)
   {
    right_motor_speed=255;
   }
   if(right_motor_speed<=0)
   {
    right_motor_speed=0;
   }
   analogWrite(left_pwm, left_motor_speed);
   analogWrite(right_pwm, right_motor_speed);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   
   /*Serial.print(left_motor_speed);
   Serial.print(" , ");
   Serial.print(right_motor_speed);
   Serial.print("\n");
   */ 
}
void right_turn()
{
   analogWrite(left_pwm, 120);
   analogWrite(right_pwm, 120);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void left_turn()
{
   analogWrite(left_pwm, 120);
   analogWrite(right_pwm, 120);
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
  analogWrite(left_pwm, 85);
   analogWrite(right_pwm, 85);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}

