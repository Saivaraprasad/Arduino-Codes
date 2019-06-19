#include <VirtualWire.h>
//#include <VirtualWire_Config.h>

#include <Wire.h>


char *cordinates[4];
char *camera;

//int Lx = 0;,
int Ly = 0;
int Rx = 0;
int Ry = 0;
int Lx;
void setup() 
{
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(4000);// speed of data transfer Kbps
Serial.begin(9600);
}


void loop()
{
   reads();
//   if(controller!=-1 && camera!=-1)
   sends();
}


void reads()
{
   Lx=analogRead(A0);
   Ly=analogRead(A1);
   Rx=analogRead(A2);
   Ry=analogRead(A3);

 //Data monitoring
 
   Serial.print(Lx);
   Serial.print("  |   ");
   Serial.print(Ly);
   Serial.print("  |   ");
   Serial.print(Rx);
   Serial.print("  |   ");
   Serial.println(Ry);

   cordinates[0] = Lx;
   cordinates[1] = Ly;
   cordinates[2] = Rx;
   cordinates[3] = Ry;
   
 /* if(a<10)
 // Serial.println(0);
   controller="0";
  else if(a>1000)
   //Serial.println(1); 
   controller="1";
  else if(b<10)
   
   controller="2";
    //Serial.println(2);
  else if(b>1000)
   controller="3";
    //Serial.println(3);
  else
   controller="-1";
    //Serial.println(-1);
   
  if(c<10)
   camera="4";
    //Serial.println(4);
  else if(c>1000)
   camera="5";
    //Serial.println(5);
  else if(d<10)
   camera="6";
    //Serial.println(6);
  else if(d>1000)
   camera="7";
    //Serial.println(7);
  else
   camera="-1";
  //Serial.println(8); */
}

void sends()
{
vw_send((uint8_t *)cordinates[], strlen(cordinates));
vw_wait_tx(); // Wait until the whole message is gone
vw_send((uint8_t *)camera, strlen(camera));
vw_wait_tx(); // Wait until the whole message is gone

}
