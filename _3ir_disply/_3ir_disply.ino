
#define lmp 8
#define lmn 9
#define rmp 10
#define rmn 11
#define trigger 4
#define echo 5
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

int duration,cm,ir;
int a,b,c,d,e;
int l=300,w=500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(lmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  //declaration of ir sensors
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  
  

}

void loop(){

a=analogRead(ir1);
b=analogRead(ir2);
c=analogRead(ir3);
d=analogRead(ir4);
e=analogRead(ir5);


if (a>w&&b<l&&c>w)
{
Serial.println("forward");
delay(5);
}
else if(a<l&&b>w&&c>w)
{
  Serial.println("left");
  delay(5);

}
else if (a>w&&b>w&&c<l)
{
  Serial.println("right");
  delay(5);
 
}




  
}






void ultrasonic()
{
  // put your main code here, to run repeatedly:

 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(5);
 digitalWrite(trigger,LOW);
 duration=pulseIn(echo,HIGH);
 cm=duration/29/2;
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
