/*design of mech system-4th year*/
#define left_pwm 10
#define right_pwm 6 
#define left_1 8
#define left_2 9
#define right_1 4
#define right_2 5

#include <IRremote.h>
int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;
int reading = 0;
int lastreading = 0;
void setup()
{
   
  irrecv.enableIRIn(); 
  pinMode(right_pwm,OUTPUT);
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(left_pwm,OUTPUT);
  
}
void loop() 
{
   if (irrecv.decode(&results)) 
  {
     reading=results.value;
    if(reading!=lastreading)
    {
    
      if(reading==0x240C)
    {
      s_open();
      delay(1000);
      s_off();
      delay(100);
      r_open();
      delay(850);
      r_off();
      delay(100);
     }
    else if(reading==0x640C)
    {
      r_close();
      delay(1200); 
      s_close();
      delay(1100);
      s_off();
      delay(100);
      r_off();
      delay(100);
     }
    }
    lastreading=reading;
    irrecv.resume(); 
  }
}
void s_open()
{
  analogWrite(left_pwm, 80);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,LOW);
}
void s_close()
{
  analogWrite(left_pwm, 100);
   digitalWrite(left_1,LOW);
   digitalWrite(left_2,HIGH);
   }
void s_off()
{
  analogWrite(left_pwm, 0);
   digitalWrite(left_1,HIGH);
   digitalWrite(left_2,HIGH);
   }
void r_open()
{
  analogWrite(right_pwm, 120);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,LOW); 
}
void r_close()
{
  analogWrite(right_pwm, 120);
   digitalWrite(right_1,LOW);
   digitalWrite(right_2,HIGH);
   
}
void r_off()
{
   analogWrite(right_pwm, 0);
   digitalWrite(right_1,HIGH);
   digitalWrite(right_2,HIGH);
}
