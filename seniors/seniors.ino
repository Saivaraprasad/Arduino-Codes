#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
#define rmotor1 4
#define rmotor2 5
#define lmotor1 7
#define lmotor2 6
#define echopin 8
#define trigger 9
int flag=0;
int duration,cm;

void setup() 
{
Serial.begin(9600);
pinMode(trigger,OUTPUT);
pinMode(echopin,INPUT);
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(ir3,INPUT);
pinMode(ir4,INPUT);
pinMode(ir5,INPUT);
pinMode(rmotor1,OUTPUT);
pinMode(rmotor2,OUTPUT);
pinMode(lmotor1,OUTPUT);
pinMode(lmotor2,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
pinMode(2,OUTPUT);
digitalWrite(2,LOW);
pinMode(3,OUTPUT);
digitalWrite(3,HIGH);
 digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
   pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() 
{
  if(flag==0)
  {
    
    forward();
  wallfollow();
  if(analogRead(ir1)<400 && analogRead(ir3)<400 && analogRead(ir3)<400)
 { 
   delay(1000);
   stops();
   delay(1000);
   forward();
   flag=1;
 }
  }
  else if(flag==1)
  {
  linefollow();
 // ultrasonic();
  }
 
}

void linefollow()
{
 if(analogRead(ir1)>800 && analogRead(ir2)<400 && analogRead(ir3)>800)
 forward();
 if(analogRead(ir1)>800 && analogRead(ir2)>400 && analogRead(ir3)<400)
 left();
 if(analogRead(ir1)<400 && analogRead(ir2)>400 && analogRead(ir3)>800)
 right();
 if(analogRead(ir1)<400 && analogRead(ir3)<400 && analogRead(ir3)<400)
 { stops();
 delay(1000);
  while(analogRead(ir1)<400 || analogRead(ir2)<400 || analogRead(ir3)<400)
  forward();

 }
 else
 forward();
}

void wallfollow()
{
   if(analogRead(ir4)/30<analogRead(ir5)/30)
   while(analogRead(ir4)/30<analogRead(ir5)/30)
   softleft();
   else if(analogRead(ir4)/30 > analogRead(ir5)/30)
   while(analogRead(ir4)/30>analogRead(ir5)/30)
   softright();
   else
   forward();
}


void ultrasonic2()
{
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(5);
digitalWrite(trigger,LOW);
duration=pulseIn(echopin,HIGH);// put your main code here, to run repeatedly:
cm=duration/29/2;

 if(cm<=10)
  {
    stops();
    while(analogRead(ir4)<400)
    left();
    forward();
    delay(2000);
    backward();
    delay(2000);
    right();
    delay(2000);
  }

}
  
  void backward()
  {
  digitalWrite(lmotor1,LOW);
  digitalWrite(lmotor2,HIGH);
  digitalWrite(rmotor1,LOW);
  digitalWrite(rmotor2,HIGH);
  }    
  void stops()
  {
  digitalWrite(lmotor1,LOW);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor1,LOW);
  digitalWrite(rmotor2,LOW);
  }
void forward()
{
  digitalWrite(lmotor1,HIGH);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor1,HIGH);
  digitalWrite(rmotor2,LOW);
}

void left()
{
  digitalWrite(lmotor1,LOW);
  digitalWrite(lmotor2,HIGH);
  digitalWrite(rmotor1,HIGH);
  digitalWrite(rmotor2,LOW);
}

void right()
{
  digitalWrite(lmotor1,HIGH);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor1,LOW);
  digitalWrite(rmotor2,HIGH);
}

void softleft()
{
  digitalWrite(lmotor1,LOW);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor1,HIGH);
  digitalWrite(rmotor2,LOW);
}

void softright()
{
  digitalWrite(lmotor1,HIGH);
  digitalWrite(lmotor2,LOW);
  digitalWrite(rmotor1,LOW);
  digitalWrite(rmotor2,LOW);
}
