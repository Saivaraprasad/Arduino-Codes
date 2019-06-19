#define lmp 8
#define lmn 9
#define rmp 12
#define rmn 13
void setup()
{
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  left();

}
 void backward()
  {
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  Serial.println("Backward");
  }    
  void stops()
  {
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  Serial.println("Stopped");
  }
void forward()
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  Serial.println("Forward");
}

void left()
{
   digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
   digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  Serial.println("Right");
  
}

void right()
{
   digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  Serial.println("Left");
}


