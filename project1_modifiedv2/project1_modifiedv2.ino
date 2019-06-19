#define lmp 2
#define lmn 3
#define rmp 4
#define rmn 5
#define tl 6
#define el 7
#define tr 8
#define er 9
#define tf 10
#define ef 11
int durationa,durationb,durationc,cml,cmr,cmf;
int t=500;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(tl,OUTPUT);
  pinMode(tr,OUTPUT);
  pinMode(tf,OUTPUT);
  pinMode(el,INPUT);
  pinMode(er,INPUT);
  pinMode(ef,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  
  

}

void loop() 
{
  // put your main code here, to run repeatedly:
 digitalWrite(tr,LOW);
 delayMicroseconds(2);
 digitalWrite(tr,HIGH);
 delayMicroseconds(5);
 digitalWrite(tr,LOW);
 durationb=pulseIn(er,HIGH);
 cmr=durationb/29/2; 

  digitalWrite(tl,LOW);
  delayMicroseconds(2);
  digitalWrite(tl,HIGH);
  delayMicroseconds(5);
  digitalWrite(tl,LOW);
  durationa=pulseIn(el,HIGH);
  cml=durationa/29/2;
  
  
  digitalWrite(tf,LOW);
  delayMicroseconds(2);
  digitalWrite(tf,HIGH);
  delayMicroseconds(5);
  digitalWrite(tf,LOW);
  durationc=pulseIn(ef,HIGH);
  cmf=durationc/29/2;

  if(cml<5)

  {
    right();
     delay(t);
    forward();
  }
  

 else if(cmr<5)
  {
    left();
    delay(t);
    forward();
  }

  else if(cmf<=10)
  {
   stops();
    
  }
  else
 {
  forward();
 }
}

 void forward()
  {
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  }    
  void stops()
  {
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  }
void backward()
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
}

void left()
{
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
}

void right()
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
}


