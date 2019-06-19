
#define lmp 8
#define lmn 9
#define rmp 10
#define rmn 11
#define trigger 4
#define echo 5
#define ir1 13
#define ir2 7
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
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  
  

}

void loop(){

a=digitalRead(ir1);
b=digitalRead(ir2);
//c=analogRead(ir3);
//d=analogRead(ir4);
//e=analogRead(ir5);
Serial.print(a);
Serial.print("       |          ");
Serial.println(b);
//Serial.print("       |          ");
//Serial.println(c);

//delay(100);
 
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
