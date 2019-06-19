#define lmp 10
#define lmn 11
#define rmp 8
#define rmn 9

#define d0 2
#define d1 3
#define d2 4
#define d3 5
#define dv 6

int data;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(lmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(d0,INPUT);
  pinMode(d1,INPUT);
  pinMode(d2,INPUT);
  pinMode(d3,INPUT);
  pinMode(dv,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
forward();
}

forward()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmnp,LOW);
}

backward()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(lmnp,HIGH);
}

sharpright()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmnp,HIGH);
}

sharpleft()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmnp,LOW);
}

left()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmnp,LOW);
}

right()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmnp,LOW);
}

stops()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmnp,LOW);
}


