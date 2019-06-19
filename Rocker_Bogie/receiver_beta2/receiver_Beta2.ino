

#include <VirtualWire.h>
#include <VirtualWire_Config.h>


int tilt_angle=0;
#define l1 4
#define l2 5
#define r1 6
#define r2 7
#define pan1 8
#define pan2 9
#define rollPin A0



void setup()
{
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(12);
vw_setup(4000); // Bits per sec

Serial.begin(9600);
//servoroll.attach(A0);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(r1,OUTPUT);
pinMode(r2,OUTPUT);
pinMode(pan1,OUTPUT);
pinMode(pan2,OUTPUT);
vw_rx_start();
}


void loop()
{
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    Serial.println("a");
    Serial.println(buf[0]);
  if(buf[0]=='1')
  {
  //Serial.println(buf[0])
  backward();
  }
  else if(buf[0]=='0')
  {
  //Serial.println(buf[0]);
  forward();
  }
  else if(buf[0]=='2')
  {
 // Serial.println(buf[0]);
  left(); 
  }
  else if(buf[0]=='3')
  {
 // Serial.println(buf[0]);
  right();
  }
  else if(buf[0]=='4')
  {
 // Serial.println(buf[0]);
  tiltup();
  }
  else if(buf[0]=='5')
  {
  //Serial.println(buf[0]);
  tiltdown();
  }
  else if(buf[0]=='6')  
  {
  //Serial.println(buf[0]);
  panright();
  }
  else if(buf[0]=='7')
  {
 // Serial.println(buf[0]);
  panleft();
  }

  }
}


void tiltup()
{
   /*tilt_angle=tilt_angle+1;                                 
   servoroll.write(tilt_angle);                 //command to rotate the servo to the specified angle
   delay(50);    */                   
  
}

void tiltdown()
{
   /*tilt_angle=tilt_angle-1;                                 
   servoroll.write(tilt_angle);                 //command to rotate the servo to the specified angle
   delay(50);*/
}
  
void forward()
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);

}

void backward()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  
}

void left()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);

}

void right()
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}

void panleft()
{
  digitalWrite(pan1,HIGH);
  digitalWrite(pan2,LOW);
}


void panright()
{
  digitalWrite(pan1,LOW);
  digitalWrite(pan2,HIGH);
}

