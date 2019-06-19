#include <Servo.h>

Servo liftm;
Servo pushm;
Servo rudder;

#define state 2

int data;
int t=400;

int lift = 1000;
int push = 1000;
int angle = 90;

int minpush = 1000;
int minlift = 1000;
int minangle = 20;


int maxlift = 2000;
int maxpush = 2000;
int maxangle = 160;

int pushstep = 100;
int liftstep = 100;
int anglestep = 35;

const int straightangle = 90;
const int stablelift = 1300;
const int stablepush = 1300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  liftm.attach(9);
  pushm.attach(10);
  rudder.attach(11);

  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);

  
 // pinMode(A0,INPUT);
  
    liftm.writeMicroseconds(maxlift);
    pushm.writeMicroseconds(maxpush);
   // rudder.write(90);
   delay(1000);
   
   liftm.writeMicroseconds(minlift);
    pushm.writeMicroseconds(minpush);
    delay(1000); 

}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.print("initial lift");
  //Serial.println(lift);
  
/*if(digitalRead(state)==0)
{
  Serial.print("                                                                                                       Bluetooth not connected         Calibration Mode");
  data=analogRead(A0);
  Serial.print(data);
  Serial.print(" ----->   ");
  data=map(data,0,1023,mini,maxi);
  liftm.writeMicroseconds(data);
  Serial.println(data);
}*/
  
if(Serial.available())
{
  //Serial.print("                                                                                                           Bluetooth Connected");
  data=Serial.read();
 Serial.print("                                                                                                                                              \t           recieved : ");
Serial.println(data);


//Lift controls

if(data=='u')
{
  
    lift=lift+liftstep;
    if( lift > maxlift)
    {
      lift = maxlift;
    }
    Serial.println(lift);

}



if(data=='d')
{
    lift=lift-liftstep;
    if( lift < minlift)
    {
      lift = minlift;
    }
    Serial.println(lift);
}




// Propeller Controls

  if(data == '2')
  {
    
    push = push + pushstep;
    if( push > maxpush)
    {
      push = maxpush;
    }
    Serial.println(push);  
      
  }
  
  if(data == '8')
  {
    
    push = push - pushstep;
    if(push < minpush)
    {
      push = minpush;
    }
    Serial.println(push); 
      
  }





//Rudder Controls
 if(data == 'r')
 {
  angle=angle+anglestep;
  if( angle >=maxangle)
  {
    angle=maxangle;
  }
  Serial.print(angle);
 }

 if(data == 'l')
 {
  angle=angle-anglestep;
  
  if(angle <= minangle)
  {
    angle=minangle;
  }
  Serial.print(angle);
 }

  
  
  
 //Race Mode 
  if( data == 'R')
  {
    racemode();
    Serial.println("Entered Racemode");
    Serial.print("   Lift:     ");
    Serial.println(lift);
    Serial.print("   push:     ");
    Serial.println(push);
  }

//Cease
  if( data == 'x')
  {
    cease();
    Serial.println("Actions Ceased");
    Serial.print("   Lift:     ");
    Serial.println(lift);
    Serial.print("   push:     ");
    Serial.println(push);
  }

 //Straight Rudder
 if( data == 's')
 {
  rudder.write(straightangle);
 }


 //Hover
 if( data == 'h')
 {
  hover();
 }
  


if (data == 't')
{
  if(liftstep ==100)
  {
    liftstep=50;
  }
  else
  {
    liftstep=100;
  }
}

if (data == 'p')
{
  if(pushstep ==100)
  {
    pushstep=50;
  }
  else
  {
    pushstep=100;
  }
}

if (data == 'a')
{
  anglestep=anglestep+10;
  if(anglestep ==60)
  {
    anglestep=60;
  }
  
  }
  if( data =='b')
  {
    anglestep = anglestep-10;
    if(anglestep==10)
    {
      anglestep=10;
    }
  } 
  if (data == '<')
  {
    liftm.writeMicroseconds(minlift);
    pushm.writeMicroseconds(minpush);
    delay(1000);
  }
  
  if (data == '>')
  {
   liftm.writeMicroseconds(maxlift);
    pushm.writeMicroseconds(maxpush);
   delay(1000);
  }
}

liftm.writeMicroseconds(lift);
pushm.writeMicroseconds(push);
rudder.write(angle);
//delay(t);
//rudder.write(90);

}


void racemode()
{

lift=1600;
push=1600;
  
}

void cease()
{

 lift = minlift;
 push = minpush;
  
}



void hover()
{
  rudder.write(straightangle);
  liftm.writeMicroseconds(stablelift);
  pushm.writeMicroseconds(stablepush);
}

