#define left_pwm 10
#define right_pwm 3 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5
const int  buttonPin = 11;    
const int ledPin = 13;       

int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;     

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

float Kp=105, Kd=150;   
float error=0, P=0, D=0, PID_value=0;
float initial_motor_speed_l=255;  
float initial_motor_speed_r=255;  
float left_motor_speed=0, right_motor_speed=0;
float previous_error=0;

char path[100] = "";
unsigned char path_length = 0; // the length of the path
void setup()
{
  //
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,INPUT);
  pinMode(6,INPUT);
  //pinMode(buttonPin,INPUT);
  //
  pinMode(right_pwm,OUTPUT);
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(left_pwm,OUTPUT);
  pinMode(ledPin,OUTPUT);
  //
  }

void loop()
{
  readSensors();
  //follow_line();
  MazeSolve();
}
void follow_line()
{
  
    readSensors();
  
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
   analogWrite(left_pwm, left_motor_speed);
   analogWrite(right_pwm, right_motor_speed);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH); 
  
  if((left3!=0)&&(left2!=0)&&(left1!=0)&&(right1!=0)&&(right2!=0)&&(right3!=0))
  {
    return;
  }
  else if((left4==0)||(right4==0))
  {
    return;
  }
  
 
}
void turn(char dir)
{
  switch(dir)
  {
    case 'L':
    readSensors();
    while(left2!=0)
    {
      left_turn();
      readSensors();
    }
    break;
    case 'R':
    readSensors();
    while((right2!=0))
    {
      right_turn();
      readSensors();
    }
    break;
    case 'B':
    readSensors();
    while((left1!=0)&&(right1!=0))
    {
      left_turn();
      readSensors();
    }
    break;
    case 'S':
    break;
  }
}
char select_turn(unsigned char found_left, unsigned char found_straight, unsigned char found_right)
{
  if(found_left)
    return 'L';
  else if(found_straight)
    return 'S';
  else if(found_right)
    return 'R';
  else
    return 'B';
} 
void simplify_path()
{
  // only simplify the path if the second-to-last turn was a 'B'
  if(path_length < 3 || path[path_length-2] != 'B')
    return;

  int total_angle = 0;
  int i;
  for(i=1;i<=3;i++)
  {
    switch(path[path_length-i])
    {
      case 'R':
        total_angle += 90;
	break;
      case 'L':
	total_angle += 270;
	break;
      case 'B':
	total_angle += 180;
	break;
    }
  }
  total_angle = total_angle % 360;
  switch(total_angle)
  {
    case 0:
	path[path_length - 3] = 'S';
	break;
    case 90:
	path[path_length - 3] = 'R';
	break;
    case 180:
	path[path_length - 3] = 'B';
	break;
    case 270:
	path[path_length - 3] = 'L';
	break;
  }
  path_length -= 2;
} 
void MazeSolve()
{
  // Loop until we have solved the maze.
  while(1)
  {
    follow_line();

    forward();
    delay(25); 
   
    unsigned char found_left=0;
    unsigned char found_straight=0;
    unsigned char found_right=0;
    readSensors();
    
    if(left4==0)
    {
      found_left=1;
    }
    if(right4==0)
    {
      found_right=1;
    }
    forward();
    delay(150);
    readSensors();
    if ((left3!=0)||(left2!=0)||(left1!=0)||(right1!=0)||(right2!=0)||(right3!=0))
    {
      found_straight=1;
    }
    if ((left3==0)&&(left2==0)&&(left1==0)&&(right1==0)&&(right2==0)&&(right3==0))
    {
      break;
    }
    unsigned char dir = select_turn(found_left, found_straight, found_right);

    // Make the turn indicated by the path.
    turn(dir);

    // Store the intersection in the path variable.
    path[path_length] = dir;
    path_length ++;

    // Simplify the learned path.
    simplify_path();
  }
  while(1)
  {
    digitalWrite(13,HIGH);
    brake();
    readSensors();
    while((left3==0)&&(left2==0)&&(left1==0)&&(right1==0)&&(right2==0)&&(right3==0))
    {
      readSensors();
      //delay();
    }
    while(1)
    {
      readSensors();
       while((left3==0)||(left2==0)||(left1==0)||(right1==0)||(right2==0)||(right3==0))
       {
         break;
         delay(50);
       }
    }
    delay(2000);
    int i;
    for(i=0;i<path_length;i++)
    {
      // SECOND MAIN LOOP BODY  
      follow_line();
      forward();
      delay(80);
      turn(path[i]);
    }
    follow_line();
    forward();
    delay(150);
      
  }
}
    
void readSensors()
{
    left4=digitalRead(A0); 
    left3=digitalRead(A1); 
    left2=digitalRead(A2); 
    left1=digitalRead(6); 
    right1=digitalRead(2); 
    right2=digitalRead(A3); 
    right3=digitalRead(A4); 
    right4=digitalRead(A5); 
    
}
void right_turn()
{
   analogWrite(left_pwm, 65);
   analogWrite(right_pwm, 65);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW);
}
void left_turn()
{
   analogWrite(left_pwm, 65);
   analogWrite(right_pwm, 65);
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
