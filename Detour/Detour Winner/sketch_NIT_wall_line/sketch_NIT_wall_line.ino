
#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5
const int ledPin = 13;
//
int LWS, RWS, FS;
//
int left1;
int left2;
int left3;
int left4;
int right1;
int right2;
int right3;
int right4;
//
int lc=0;
int sc=1;
//
float wall_Kp=0.052, wall_Kd=0.05;
float wall_error=0, wall_P=0, wall_D=0, wall_PID_value=0;
float wall_initial_motor_speed=100;
float wall_right_motor_speed=0, wall_left_motor_speed=0;
float wall_prev_error=0;
//
float line_Kp=110, line_Kd=150;   //kp=140,kd=170
float line_error=0, line_P=0, line_D=0, line_PID_value=0;
float line_initial_motor_speed_l=255;  
float line_initial_motor_speed_r=255;  
float line_left_motor_speed=0, line_right_motor_speed=0;
float line_previous_error=0;
//
int left=0;
int right=0;
//
int count=0;
void setup()
{
  //Serial.begin(9600);
  //line sensors
  pinMode(A0,INPUT); //left4
  pinMode(A1,INPUT); //left3
  pinMode(A2,INPUT); //left2
  pinMode(A3,INPUT); //left1
  pinMode(2,INPUT);  //right1
  pinMode(6,INPUT);  //right2
  pinMode(7,INPUT);  //right3
  pinMode(11,INPUT); //right4
  //wall
  pinMode(A4,INPUT); //left wall sensor
  pinMode(A5,INPUT); //right wall sensor
  pinMode(12,INPUT); //front sensor
  //motors
  pinMode(right_pwm,OUTPUT);
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(left_pwm,OUTPUT);
  //LED
  pinMode(ledPin,OUTPUT);
  count++;
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
    if((left4==0)&&(left3==0)&&(left2==0)&&(left1==0)&&(right1==0)&&(right2==0)&&(right3==0)&&(right4==0))
     { 
       /*
       line_forward();
       delay(100);
       left4=digitalRead(A0); 
      left3=digitalRead(A1); 
     left2=digitalRead(A2); 
     left1=digitalRead(A3); 
     right1=digitalRead(2); 
     right2=digitalRead(6); 
     right3=digitalRead(7); 
     right4=digitalRead(11);
      if((left2==0)||(left1==0)||(right1==0||(right2==0))
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
       count++;
      }
      */
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
       line_forward();
       delay(150);
       count++;
    }
    if(count==1)
    {
    left4=digitalRead(A0); 
    left3=digitalRead(A1); 
    left2=digitalRead(A2); 
    left1=digitalRead(A3); 
    right1=digitalRead(2); 
    right2=digitalRead(6); 
    right3=digitalRead(7); 
    right4=digitalRead(11);
    wall_follow();
    }
    else if(count>1)
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
    /*if(((left4==0)||(left3==0)||(left2==0)||(left1==0)||(right1==0)||(right2==0)||(right3==0)||(right4==0))&&(digitalRead(12)==1))
    {
      //path block encountered while line following 
    }
    */
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
            digitalWrite(13,LOW);
            left1=digitalRead(A3); 
            right1=digitalRead(2); 
            while((left1!=0)&&(right1!=0))
	    {
	     line_left_turn();
             left1=digitalRead(A3); 
             right1=digitalRead(2); 
            }
       }
      
     }
     /*else if(((left4!=0)&&(left3!=0)&&(right3!=0)&&(right4!=0))&&((left2==0)||(left1==0)||(right1==0)||(right2==0)))
     {
       //left T section has occured while circle following
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
	line_error=0;   
   }
   else if((left1!=lc)&&(right1==lc)&&(right2!=lc)) 			
   {   
	line_error=0.5; 
   }
   else if((right1==lc)&&(right2==lc))  
   {   
	line_error=1;   
   }
   else if((right2==lc)&&(right3!=lc))   		
   {   
	line_error=1.5; 
   }
   else if((right2==lc)&&(right3==lc))  
   {   
	line_error=2;   
   }
   else if((right3==lc)&&(right4!=lc))  	
   {   
	line_error=2.5; 
   }
   else if((right3==lc)&&(right4==lc))  
   {   
	line_error=3;
   }
   else if((right4==lc)&&(right3!=lc))  		
   {   
	line_error=3.5; 
   }
   else if((left2!=lc)&&(left1==lc)&&(right1!=lc))   		
   {   
	line_error=-0.5;
   }
   else if((left1==lc)&&(left2==lc))  
   {   
	line_error=-1;  
   }
   else if((left2==lc)&&(left3!=lc))   	
   {   
	line_error=-1.5;
   }
   else if((left2==lc)&&(left3==lc))  
   {   
	line_error=-2;  
   }
    else if((left3==lc)&&(left4!=lc))  		
   {   
	line_error=-2.5;
   }
    else if((left3==lc)&&(left4==lc))   
   {   
	line_error=-3;
   }
    else if((left4==lc)&&(left3!=lc))   
   {   
	line_error=-3.5; 
   }
   line_P = line_error;
   line_D = line_previous_error-line_error;
   line_PID_value = (line_Kp*line_P) + (line_Kd*line_D);
   line_previous_error=line_error;
   line_left_motor_speed = line_initial_motor_speed_l+line_PID_value;
   line_right_motor_speed = line_initial_motor_speed_r-line_PID_value;
   if(line_left_motor_speed>=255)   
   {    
	line_left_motor_speed=255;
   }
   if(line_left_motor_speed<=0)
   {    
	line_left_motor_speed=0;
   }
   if(line_right_motor_speed>=255)
   {
        line_right_motor_speed=255;
   }
   if(line_right_motor_speed<=0)
   {
        line_right_motor_speed=0;
   }
  /* Serial.print(line_left_motor_speed);
   Serial.print(",");
   Serial.print(line_right_motor_speed);
   Serial.print("\n");
  */ 
   analogWrite(left_pwm, line_left_motor_speed);
   analogWrite(right_pwm, line_right_motor_speed);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
void wall_follow()
{
  LWS = analogRead(A4);
  RWS = analogRead(A5);
  wall_pid();
  if((LWS<350)&&(left>400)&&(right>400))
  {
    brake();
    delay(5);
    FS=digitalRead(12);
    left4=digitalRead(A0); 
     left3=digitalRead(A1); 
     left2=digitalRead(A2); 
     left1=digitalRead(A3); 
     right1=digitalRead(2); 
     right2=digitalRead(6); 
     right3=digitalRead(7); 
     right4=digitalRead(11);
    while(FS!=1)
    {
      forward_front_wall();
      FS=digitalRead(12);
      left4=digitalRead(A0); 
      left3=digitalRead(A1); 
      left2=digitalRead(A2); 
      left1=digitalRead(A3); 
      right1=digitalRead(2); 
      right2=digitalRead(6); 
      right3=digitalRead(7); 
      right4=digitalRead(11);
    }
    brake();
    delay(100);
    wall_left_turn();
    delay(1000); //check this delay
    brake();
    delay(100);
    wall_forward();
    delay(200); //check this delay
   }
  else if((RWS<350)&&(left>400)&&(right>400))
  {
    brake();
    delay(5);
    FS=digitalRead(12);
    left4=digitalRead(A0); 
     left3=digitalRead(A1); 
     left2=digitalRead(A2); 
     left1=digitalRead(A3); 
     right1=digitalRead(2); 
     right2=digitalRead(6); 
     right3=digitalRead(7); 
     right4=digitalRead(11);
    while(FS!=1)
    {
      forward_front_wall();
      FS=digitalRead(12);
      left4=digitalRead(A0); 
     left3=digitalRead(A1); 
     left2=digitalRead(A2); 
     left1=digitalRead(A3); 
     right1=digitalRead(2); 
     right2=digitalRead(6); 
     right3=digitalRead(7); 
     right4=digitalRead(11);
    }
    brake();
    delay(100);
    wall_right_turn();
    delay(1125); //check this delay
    brake();
    delay(100);
    wall_forward();
    delay(150); //check this delay
   }
}
void wall_pid()
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
void forward_front_wall()
{
  analogWrite(left_pwm, 80);
   analogWrite(right_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
void wall_forward()
{
   analogWrite(left_pwm, 150);
   analogWrite(right_pwm, 150);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}
void wall_right_turn()
{
   analogWrite(left_pwm, 50);
   analogWrite(right_pwm, 50);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void wall_left_turn()
{
   analogWrite(left_pwm, 50);
   analogWrite(right_pwm, 50);
   digitalWrite(left_1,LOW);
   digitalWrite(left_2,HIGH);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
}	
void line_right_turn()
{
   analogWrite(left_pwm, 140);
   analogWrite(right_pwm, 140);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void line_left_turn()
{
  analogWrite(left_pwm, 140);
   analogWrite(right_pwm, 140);
   digitalWrite(left_1,LOW);
   digitalWrite(left_2,HIGH);
   digitalWrite(right_1,LOW);
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
void brake()
{
   analogWrite(left_pwm, 0);
   analogWrite(right_pwm, 0);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,HIGH);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,HIGH);
}

