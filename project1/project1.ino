#define lmp 12
#define lmn 2
#define rmp 3
#define rmn 4
#define tl 5
#define el 6
#define tr 7
#define er 8
#define tf 10
#define ef 9
int durationa,durationb,durationc,cml,cmr,cmf;

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
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  
  

}

void loop() 
{
  // put your main code here, to run repeatedly:

  forward();

}

 void backward()
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
void forward()
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

void Ultrasonicleft()
{
digitalWrite(tl,LOW);
delayMicroseconds(2);
digitalWrite(tl,HIGH);
delayMicroseconds(5);
digitalWrite(tl,LOW);
durationa=pulseIn(el,HIGH);
cml=durationa/29/2;
Serial.print ("left distance: ");
Serial.print(cml);
Serial.println(" centimetres.");

  if(cml<10)

  {
    right();
    forward();
  }
}

void Ultrasonicright()
{
  digitalWrite(tr,LOW);
delayMicroseconds(2);
digitalWrite(tr,HIGH);
delayMicroseconds(5);
digitalWrite(tr,LOW);
durationb=pulseIn(er,HIGH);
cmr=durationb/29/2;
Serial.print ("right distance:");
Serial.print(cmr);
Serial.println("centimetres.");
  if(cmr<10)

  {
    left();
    forward();
  }
  
}

void Ultrasonicfront()
{
  digitalWrite(tf,LOW);
  delayMicroseconds(2);
  digitalWrite(tf,HIGH);
  delayMicroseconds(5);
  digitalWrite(tf,LOW);
  durationc=pulseIn(ef,HIGH);
  cmf=durationc/29/2;
  Serial.print ("front distance:");
Serial.println(cmf);
Serial.println("centimetres.");

  if(cmf<10)

  {
    stops();
  }
  
}
  


