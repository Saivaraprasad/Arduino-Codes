#define redn 8
#define redp 9
#define bluen 10
#define bluep 11
#define pir 2


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(pir,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(pir)==HIGH)
 {
  redon();
  blueoff();
  Serial.println(digitalRead(pir));
 }
else
{
  blueon();
  redoff();
}

}

void redon()
  {
  digitalWrite(redn,LOW);
  digitalWrite(redp,HIGH);
 
  }
  void redoff()
  {
  digitalWrite(redn,LOW);
  digitalWrite(redp,LOW);
  
  }
  void blueon()
  {
  digitalWrite(bluen,LOW);
  digitalWrite(bluep,HIGH);
  
  }
  void blueoff()
  {
  digitalWrite(bluen,LOW);
  digitalWrite(bluep,LOW);
  }
