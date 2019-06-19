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
pinMode(8,OUTPUT);
digitalWrite(8,LOW);
pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 //current=millis();
//Serial.println(current);
for(int i=0;i<1024;i++)
{
   analogWrite(panel,i);
   Serial.println(i);
   delay(2);
}
for(int i=1024;i>0;i--)
{
   analogWrite(panel,i);
   Serial.println(i);
   delay(2);
}
}
   


