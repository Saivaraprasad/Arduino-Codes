#define lmp 12
#define lmn 2
#define rmp 3
#define rmn 4
#define tf 9
#define ef 10
int durationc,cmf;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
   pinMode(tf,OUTPUT);
   pinMode(ef,INPUT);
   pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
 forward();

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
  Serial.println(cmf);

  if(cmf<10)

  {
    stops();
  }
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
