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

  pinMode(13,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(dv)==HIGH)
  {
    data=0;
   if(digitalRead(d0)==HIGH)
   data=data+1;
   if(digitalRead(d1)==HIGH)
   data=data+2;
   if(digitalRead(d2)==HIGH)
   data=data+4;
   if(digitalRead(d3)==HIGH)
   data=data+8;
   
  Serial.println(data);
  }
  
  
 switch(data)
{
 case 2 : forward(); break;
 case 5 : forward();  break;
 case 4 : sharpleft();  break; 
 case 6 : sharpright();  break;
 case 1 : left();  break;
 case 7 : left();   break;
 case 3 : right(); break;
 case 9 : right();  break;
 case 8 : backward(); blinks(); break;
 case 0 : stops(); blinks();  break;
 case 10: stops();  blinks(); break;
 case 11: blinks();  break; 
 default : stops();    break;
}
  
}
void forward()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void backward()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
}

void sharpleft()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
}

void sharpright()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void left()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,LOW);
}

void right()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void stops()
{
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,LOW);
}

void blinks()
{
digitalWrite(13,HIGH);
delay(250);
digitalWrite(13,LOW);
delay(250);
  
}

