#define left_pwm 5
#define right_pwm 6 
#define left_1 4
#define left_2 7
#define right_1 3
#define right_2 2
//#define front_sens 6
//#define left_sens 11
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
float Kp=44, Kd=40;   
float error=0, P=0, D=0, PID_value=0;
float initial_motor_speed_l=145;  
float initial_motor_speed_r=145;  
float left_motor_speed=0, right_motor_speed=0;
float previous_error=0;
int left=0;
int right=0;
void setup()
{
  //
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
 
  //
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
}
void loop()
{
     line_follow();
       
}
void pid()
{   
    if((left1==lc)&&(right1==lc))   
   {   
	error=0;   
   }
   else if(right1==lc) 			
   {   
	error=0.5; 
   }
   else if((right1==lc)&&(right2==lc))  
   {   
	error=1;   
   }
   else if(right2==lc)   		
   {   
	error=1.5; 
   }
   else if((right2==lc)&&(right3==lc))  
   {   
	error=2;   
   }
   else if(right3==lc)  	
   {   
	error=2.5; 
   }
   else if((right3==lc)&&(right4==lc))  
   {   
	error=3;
   }
   else if(right4==lc)  		
   {   
	error=3.5; 
   }
   else if(left1==lc)   		
   {   
	error=-0.5;
   }
   else if((left1==lc)&&(left2==lc))  
   {   
	error=-1;  
   }
   else if(left2==lc)   	
   {   
	error=-1.5;
   }
   else if((left2==lc)&&(left3==lc))  
   {   
	error=-2;  
   }
   else if(left3==lc)  		
   {   
	error=-2.5;
   }
   else if((left3==lc)&&(left4==lc))   
   {   
	error=-3;
   }
   else if(left4==lc)   
   {   
	error=-3.5; 
   }
   
   P = error;
   D = previous_error-error;
   PID_value = (Kp*P) + (Kd*D);
   previous_error=error;
   left_motor_speed = initial_motor_speed_l-PID_value;
   right_motor_speed = initial_motor_speed_r+PID_value;
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
}
void line_follow()
{
    left4=digitalRead(A0); 
    left3=digitalRead(A1); 
    left2=digitalRead(A2); 
    left1=digitalRead(8); 
    right1=digitalRead(9); 
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
      if((left>900)&&(right<900))  
      {
          left1=digitalRead(8); 
       right1=digitalRead(9); 
      while((right1!=0)&&(left1!=0))
	  {
	    right_turn();
	    left1=digitalRead(8); 
             right1=digitalRead(9); 
          }
          
      }
      else if((left<900)&&(right>900)) 
      {
	    left1=digitalRead(8); 
           right1=digitalRead(9); 
    
            while((left1!=0)&&(right1!=0))
	    {
	     left_turn();
	     left1=digitalRead(8); 
          right1=digitalRead(9); 
       }
            
       }
       /*else if((left<200)&&(right<200))
       {
            left1=digitalRead(8); 
    right1=digitalRead(9); 
    while((left1!=0)&&(right1!=0))
	    {
	     brake();
	     left1=digitalRead(8); 
    right1=digitalRead(9); 
    }
       }
       */
       
     }
     pid();
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
void left_turn()
{
   analogWrite(left_pwm, 140);
   analogWrite(right_pwm, 140);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void right_turn()
{
   analogWrite(left_pwm, 140);
   analogWrite(right_pwm, 140);
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

