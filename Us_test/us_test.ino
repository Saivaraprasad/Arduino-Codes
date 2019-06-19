/*#define lmp 8
#define lmn 9
#define rmp 3
#define rmn 4 
*/
#define trigger 8
#define echo 9

int duration=0,cm=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

 /* pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT); */ 
  
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  
/*  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH); */
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(5);
 digitalWrite(trigger,LOW);
 
 duration=pulseIn(echo,HIGH);
 cm=duration/29/2;
 
 Serial.println(cm);
 delay(10);
}
 


