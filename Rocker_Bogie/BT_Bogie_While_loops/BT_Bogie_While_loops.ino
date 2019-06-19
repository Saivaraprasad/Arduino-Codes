#include<Servo.h>

#define lmp 4 //White
#define lmn 5 //Black
#define rmp 6 //Blue
#define rmn 7 //Red
#define Servopin 11 //header
#define rollp 8 //Pan motor
#define rolln 9
#define RF 12
#define BT_State 13
#define t 200 // delay in loops

Servo pitch;

int State = 0; //Bluetooth state
int data = 0;  //Bluetooth Data

//Global variables
int Tilt_angle =30;
int Min_tilt = 10;
int Max_tilt = 60;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

  //Motors
  pinMode(lmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  
  pinMode(rollp,OUTPUT);
  pinMode(rolln,OUTPUT);

  pinMode(RF,INPUT); 
  pinMode(BT_State,INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    
     data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);

     while(data == 2)
     {
      forward();
      data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
     }

    while(data == 8)
    {
      backward();
      data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
    }

    while(data == 4)
    {
      left();
       data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
    }

    while(data == 6)
    {
      right();
       data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
    }

    while( data == 1)
    {
      panleft();
       data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
    }

    while( data == 3)
    {
      panright();
       data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
    }

    while( data == 7)
    {
      tiltdown();
       data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
    }

    while( data == 9)
    {
      tiltdown();
       data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
    }

    //Halt all actions in case of emergency

     if( data == 0);
     {
      halt();
       data = Serial.read();
     data = data - 48; //Converts ASCII to Number
     Serial.println("Data Received");
     Serial.println(data);
     delay(t);
     }
     
}
}


// Funtion Definitions

void forward()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void backward()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
}

void sharpleft()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void sharpright()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
}

void left()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
}

void right()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void stops()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,LOW);
}


void panleft()
{
  digitalWrite(rollp,HIGH);
  digitalWrite(rolln,LOW);
}

void panright()
{
  digitalWrite(rollp,LOW);
  digitalWrite(rolln,HIGH);  
}

void stoppan()
{
  digitalWrite(rollp,LOW);
  digitalWrite(rolln,LOW);
}

void tiltdown()
{
 Tilt_angle = Tilt_angle - 1;
 Serial.println("Tilt decreased");
 if(Tilt_angle < Min_tilt)
 {
 Tilt_angle = Min_tilt;
 
 Serial.println("Min tilt");
 }
 pitch.write(Tilt_angle);
 
 delay(10);

}

void tiltup()
{
 Tilt_angle = Tilt_angle + 1;
 Serial.println("Tilt Increased");
 if(Tilt_angle > Max_tilt)
 {
 Tilt_angle = Max_tilt;
 
 Serial.println("Max tilt");
 }
 pitch.write(Tilt_angle);
 
 delay(10);
}


void blinks()
{
digitalWrite(13,HIGH);
delay(250);
digitalWrite(13,LOW);
delay(250);
  
}

void halt()
{
  stops();
  stoppan();
  Serial.println(" ALL ACTIONS ARE HALTED      PRESS ANY KEY TO CONTINUE ");
}

