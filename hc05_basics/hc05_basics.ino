int data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {

if(Serial.available())
{
  data=Serial.read();
  data = data - 48; // To change ASCII to number
  switch(data)
  {
    case 1: forward();
            break;
    case 2: reverse();
            break;
    case 3: left();
            break;
    case 4: right();
    break;
    default: stops();
  }
  Serial.print("--        --");
  Serial.println(data);  
}

//blueon();
//redon();
//delay(500);
//blueoff();
//redoff();
//delay(500);

/*if(Serial.available()!=0)
{
  blueon();
}

}
*/
}

void blueon()
{
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  
}

void redon()
{
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  
}

void blueoff()
{
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  
}

void redoff()
{
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  
}

