#define lmp 9
#define lmn 10
#define rmp 11
#define rmn 12



int data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(lmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(12,OUTPUT);
 
 

  pinMode(13,OUTPUT);

  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
 
    data = Serial.read()

    while(data == '2'){
    forward();
    }

    while(data == '4'){
    left();
    }

    while(data == '6'){
    right();
    }

    while(data == '8'){
    backward();
    }

    while(data == '0'){
   stops();
    }
    
    
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
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(lmn,HIGH);
  digitalWrite(lmp,LOW);
}

void sharpright()
{
  digitalWrite(rmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(lmp,HIGH);
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


