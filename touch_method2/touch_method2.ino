#define r 2
#define panel 6
#define LED 12

int data;
int t=5;
int tp = 250;

unsigned long current =0;
unsigned long previous =0;
unsigned long previous2 =0;

int period = 12;
int period2 =100;
int state = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(2,INPUT);
pinMode(panel,OUTPUT);
pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 current=millis();
//Serial.println(current);
if(current - previous >= period)
{
  previous = current;
  if(state == LOW)
  {
    state = HIGH;
  }
  else
  {
    state = LOW;
  }
  //Serial.print("                               ");
  //Serial.print(state);
   digitalWrite(panel,state);
   Serial.println(state);
}
data = analogRead(r);
 // previous2 = current;
 //Serial.println(data);

/*if(data<tp)
 {
  Serial.println("                                        Touch not detected");
  Serial.println(data);
  digitalWrite(LED,LOW);
 }

 if(data>tp)
 {
  Serial.println("                                        Touch detected");
  Serial.println(data);
  digitalWrite(LED,HIGH);
 }*/
}
