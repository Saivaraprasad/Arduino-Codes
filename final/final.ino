const int lm1=9;
const int lm2=10;
const int rm1=11;
const int rm2=12;
const int li=2;
const int mi=3;
const int ri=4;
const int tf=5;
const int ef=6;
const int tl=3;
const int el=4;
const int tr=7;
const int er=8;
int count=1;
int duration=0;
int distance=0; 
void setup() 
{
pinMode(lm1,OUTPUT);//left+
pinMode(lm2,OUTPUT);//left-
pinMode(rm1,OUTPUT);//rgt+
pinMode(rm2,OUTPUT);//rgt-
pinMode(li,INPUT);//left lower ir
pinMode(mi,INPUT);//middle lower ir
pinMode(ri,INPUT);//right middle ir
pinMode(ef,INPUT);//left upp ir
pinMode(el,INPUT);//right upp ir
pinMode(er,INPUT);//trigg
pinMode(tf,OUTPUT);
pinMode(tr,OUTPUT);
pinMode(tl,OUTPUT);//echo
Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() 
{   if(digitalRead(li)==1&&digitalRead(mi)==1&&digitalRead(ri)==1&&dl<30)
    { 
      wallfollow();
    }
    if(d1>50)
    {
      linefollow();
    }
    if(df<11)
    {
      obstacle();
    }
}
void wallfollow()
{ if(dl>4&&dr>4&&df>8)
  forward();
  else if(dl<4&&dr>4&&df>8)
  softright();
  else if(dl>4&&dr<4&&df>8)
  softleft();
  else if(dl>4&&dr>20&&df<5)
  sharpright();
  else if(dl>20&&dr>4&&df<5)
  sharpleft();
}
void linefollow()
{ if(digitalRead(li)==1&&digitalRead(mi)==1&&digitalRead(ri)==1)
  checkpoint();
  else if(digitalRead(li)==1&&digitalRead(mi)==0&&digitalRead(ri)==1)
  forward();
  else if(digitalRead(li)==0&&digitalRead(mi)==1&&digitalRead(ri)==1)
  softleft();
  else if(digitalRead(li)==1&&digitalRead(mi)==1&&digitalRead(ri)==0)
  softright();
  else if(digitalRead(li)==0&&digitalRead(mi)==0&&digitalRead(ri)==1)
  sharpleft();
  else if(digitalRead(li)==1&&digitalRead(mi)==0&&digitalRead(ri)==0)
  sharpright();
  else if(digitalRead(li)==0&&digitalRead(mi)==0&&digitalRead(ri)==0)
  forward();
}
void obstacle()
{stops();
 delay(1000);
 sharpright();
 delay(2000);
 backward();
 delay(2000);
 forward();
 delay(2000);
 sharpleft();
 delay(2000);
 forward();
}
void sharpleft()
{
  digitalWrite(lm1 , LOW);
    digitalWrite(lm2 , HIGH);
    digitalWrite(rm1 , HIGH);
    digitalWrite(rm2 , LOW);
}
void sharpright()
{
  digitalWrite(lm1 , HIGH);
    digitalWrite(lm2 , LOW);
    digitalWrite(rm1 , LOW);
    digitalWrite(rm2 , HIGH);
}
void softleft()
{
  digitalWrite(lm1,LOW);
 
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}
void softright()
{
  digitalWrite(lm1 , HIGH);
    digitalWrite(lm2 , LOW);
    digitalWrite(rm1 , LOW);
    digitalWrite(rm2 , LOW);
}
void forward()
{
  digitalWrite(lm1 , HIGH);
    digitalWrite(lm2 , LOW);
    digitalWrite(rm1 , HIGH);
    digitalWrite(rm2 , LOW);
}
void stops()
{
  digitalWrite(lm1 , LOW);
    digitalWrite(lm2 , LOW);
    digitalWrite(rm1 , LOW);
    digitalWrite(rm2 , LOW);
}
void backward()
{
  digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
}
void blinks()
{ digitalWrite(13,HIGH);
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
} // put your main code here, to run repeatedly:

void checkpoint()
{ 
  stops();
  blinks();
  forward();
}

