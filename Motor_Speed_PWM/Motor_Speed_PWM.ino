#define lmp 8
#define lmn 9
#define L_EN 10

#define R_EN 11
#define rmp 12
#define rmn 13

#define L_Potentio A1
#define R_Potentio A3

int L_Speed=0,R_Speed=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(L_EN,INPUT);
  pinMode(R_EN,INPUT);
  pinMode(L_Potentio,INPUT);
  pinMode(R_Potentio,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  L_Speed = analogRead(L_Potentio);
  R_Speed = analogRead(R_Potentio);

  L_Speed = map(L_Speed, 0, 1023, 60, 255);
  R_Speed = map(R_Speed, 0, 1023, 60, 255);

  right(L_Speed,R_Speed);
}
int forward(int Speed)
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  
  analogWrite(L_EN,Speed);
  analogWrite(R_EN,Speed);
  
  Serial.print("Forward");
  Serial.print("   ");
  Serial.print("Speed= ");
  Serial.println(Speed);
  
}

 int backward(int Speed)
  {
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,LOW);
  analogWrite(L_EN,Speed);
  analogWrite(R_EN,Speed);
  
  Serial.print("Backward");
  Serial.print("   ");
  Serial.print("Speed= ");
  Serial.println(Speed);
  
  }    
  int stops()
  {
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  Serial.println("Stopped");
  }

int left(int L_Speed,int R_Speed)
{
   digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
   digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);

  analogWrite(L_EN,L_Speed);
  analogWrite(R_EN,L_Speed);
  
  Serial.print("Left");
  Serial.print("   ");
  Serial.print("L_Speed= ");
  Serial.print(L_Speed);
  Serial.print("   ");
  Serial.print("R_Speed= ");
  Serial.println(R_Speed);
  
}

int right(int L_Speed,int R_Speed)
{
   digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
 
  analogWrite(L_EN,L_Speed);
  analogWrite(R_EN,R_Speed);
  
  Serial.print("Left");
  Serial.print("   ");
  Serial.print("L_Speed= ");
  Serial.print(L_Speed);
  Serial.print("   ");
  Serial.print("R_Speed= ");
  Serial.println(R_Speed);
}

int Brake()
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,HIGH);
  Serial.println("Brake");
}

