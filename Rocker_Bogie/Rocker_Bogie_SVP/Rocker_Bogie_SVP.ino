#include <Servo.h>

//#include <VirtualWire.h>
//#include<Servo.h>

#define lmp 4 //White
#define lmn 5 //Black
#define rmp 6 //Blue
#define rmn 7 //Red
#define Servopin 11 //header
#define rollp 8 //Pan motor
#define rolln 9
#define RF 12
#define BT_State 13

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
  
  //pitch.attach(Servopin);

  //RF Setup
 /* vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000); // Bits per sec
  vw_rx_start(); */
}

void loop() {
  // put your main code here, to run repeatedly:
  State = digitalRead(BT_State);
  //Serial.print("                                                  ");
  //Serial.print(State);


//RF part

/*while(!State)  //If no blutooth found operate via RF remote
 {

  State = digitalRead(BT_State);
  //Serial.println("Bluetooth  Disconnected"); 
  //Serial.println("RF MODE");

   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;

   if (vw_get_message(buf, &buflen)) // Non-blocking
  {
   
     buf[0]=buf[0]-48; //Converts from ASCII to Number
     
    // Serial.println("If Loop");
     /*Serial.print("       |         ");
     Serial.print(buflen);
     Serial.print("                ");
     Serial.print(buf[0]);
     Serial.print("                ");
     Serial.print(buf[1]);
     Serial.print("               ");
     Serial.println(buf[3]);
     */

     //Decisions
   /*   if(buf[0]==0)
  {
  Serial.println("backward");
  backward();
  }
  
  else if(buf[0]==1)
  {
  Serial.println("forward");
  forward();
  }
  
  else if(buf[0]==3)
  {
  Serial.println("left");
  left(); 
  }
  
  else if(buf[0]==2)
  {
  Serial.println("right");
  right();
  }
  
  else if(buf[0]==5)
  {
  Serial.println("tilt up");
  tiltup();
  }
  
  else if(buf[0]==4)
  {
  Serial.println("tilt down");
  tiltdown();
  }
  
  else if(buf[0]==6)  
  {
  Serial.println("pan right");
  panright();
  }
  
  else if(buf[0]==7)
  {
  Serial.println("pan left");
  panleft();
  }

  delay(30);
  

  }

 stops();
 stoppan();
// delay(25);
 //Serial.println("Halted");
  
} //End of RF while


   //Bluetooth part
  

  //Bluetooth connected and switch to bluetooth mode
  while(State)
  {*/
  if(Serial.available())
  {
     data = Serial.read();
     data = data - 48; //Converts ASCII to Number
  }
 // Serial.print("Data");
     Serial.println(data);
    if(data == 1)
    {
      panleft();
      Serial.println("Panning Left");
    }
    if(data == 3)
    {
      panright();
      Serial.println("Panning Right");
    }

    if(data == 7)
    {
      tiltdown();
      Serial.println("Tilting Down");
    }

    if(data == 9)
    {
      tiltup();
      Serial.println("Tilting Up");
    }
    
    if(data == 2){
    forward();
    Serial.println("Forward");
    }

   else if(data == 4){
    left();
    Serial.println("Left");
    }

    else if(data == 6){
    right();
    Serial.println("Right");
    }

    else if(data == 8){
    backward();
    Serial.println("backward");
    }

    else if(data == 0){
   stops();
   Serial.println("Stopped");
    }

else
stops();

//data = 0;
    stops();
    stoppan();
   // delay(25);
    //Serial.println("Halted");
  
  } 

 
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


