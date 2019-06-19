#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5    
const int ledPin = 13;  

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

float Kp=110, Kd=150;   //kp=140,kd=170
float error=0, P=0, D=0, PID_value=0;
float initial_motor_speed_l=255;  
float initial_motor_speed_r=255;  
float left_motor_speed=0, right_motor_speed=0;
float previous_error=0;

int left=0;
int right=0;

void setup()
{
  //line sensors
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(2,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(11,INPUT);
  //motors
  pinMode(right_pwm,OUTPUT);
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(left_pwm,OUTPUT);
  //LED
  pinMode(ledPin,OUTPUT);
}
void loop()
{
    left4=digitalRead(A0); 
    left3=digitalRead(A1); 
    left2=digitalRead(A2); 
    left1=digitalRead(A3); 
    right1=digitalRead(2); 
    right2=digitalRead(6); 
    right3=digitalRead(7); 
    right4=digitalRead(11); 
    
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
      if((left>650)&&(right<650))  
      {
        brake();
        delay(25);
        right2=digitalRead(6);
        while(right2!=0)
        {
          line_right_turn();
          right2=digitalRead(6);
        }
        brake();
        delay(25);
      }
      else if((left<650)&&(right>650)) 
      {
        brake();
        delay(25);
        left2=digitalRead(A2);
        while(left2!=0)
        {
          line_left_turn();
          left2=digitalRead(A2);
        }
        brake();
        delay(25);
      }
       else if((left<200)&&(right<200)) //either stop at last T section or left from circle
       {
         
            left1=digitalRead(A3); 
            right1=digitalRead(2); 
            while((left1!=0)&&(right1!=0))
	    {
             line_left_turn();
	     //brake();
             //digitalWrite(13,HIGH);
             left1=digitalRead(A3); 
             right1=digitalRead(2); 
            }
       }
       
      }
      /*else if((left4==0)&&(left3==0)&&(left2==0)&&(left1==0)&&(right1==0)&&(right2==0)&&(right3==0)&&(right4==0))
     {
       brake();
       delay(500);
       digitalWrite(13,HIGH);
       delay(500);
       digitalWrite(13,LOW);
       delay(500);
       digitalWrite(13,HIGH);
       delay(500);
       digitalWrite(13,LOW);
       delay(500);
       digitalWrite(13,HIGH);
       delay(500);
       digitalWrite(13,LOW);
       delay(500);
     }
     */
     /*else if((left4!=0)&&(left3!=0)&&(right3!=0)&&(right4!=0)&&((left2=0)||(left1==0)||(right1==0)||(right2==0)))
     {
       if((left<400)&&(right>400))
       {
         left2=digitalRead(A2);
        while(left2!=0)
        {
          line_left_turn();
          left2=digitalRead(A2);
        }
       }
       //turn_left (for exiting circular loop)
     }
     */
     line_pid();
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
void line_pid()
{   
    if((left1==lc)&&(right1==lc))   
   {   
	error=0;   
   }
   else if((left1!=lc)&&(right1==lc)&&(right2!=lc)) 			
   {   
	error=0.5; 
   }
   else if((right1==lc)&&(right2==lc))  
   {   
	error=1;   
   }
   else if((right2==lc)&&(right3!=lc))   		
   {   
	error=1.5; 
   }
   else if((right2==lc)&&(right3==lc))  
   {   
	error=2;   
   }
   else if((right3==lc)&&(right4!=lc))  	
   {   
	error=2.5; 
   }
   else if((right3==lc)&&(right4==lc))  
   {   
	error=3;
   }
   else if((right4==lc)&&(right3!=lc))  		
   {   
	error=3.5; 
   }
   else if((left2!=lc)&&(left1==lc)&&(right1!=lc))   		
   {   
	error=-0.5;
   }
   else if((left1==lc)&&(left2==lc))  
   {   
	error=-1;  
   }
   else if((left2==lc)&&(left3!=lc))   	
   {   
	error=-1.5;
   }
   else if((left2==lc)&&(left3==lc))  
   {   
	error=-2;  
   }
    else if((left3==lc)&&(left4!=lc))  		
   {   
	error=-2.5;
   }
    else if((left3==lc)&&(left4==lc))   
   {   
	error=-3;
   }
    else if((left4==lc)&&(left3!=lc))   
   {   
	error=-3.5; 
   }
   P = error;
   D = previous_error-error;
   PID_value = (Kp*P) + (Kd*D);
   previous_error=error;
   left_motor_speed = initial_motor_speed_l+PID_value;
   right_motor_speed = initial_motor_speed_r-PID_value;
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
  /* Serial.print(left_motor_speed);
   Serial.print(",");
   Serial.print(right_motor_speed);
   Serial.print("\n");
  */ 
   analogWrite(left_pwm, left_motor_speed);
   analogWrite(right_pwm, right_motor_speed);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   
}
void line_right_turn()
{
   analogWrite(left_pwm, 120);
   analogWrite(right_pwm, 120);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void line_left_turn()
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
void line_forward()
{
   analogWrite(left_pwm, 240);
   analogWrite(right_pwm, 240);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
