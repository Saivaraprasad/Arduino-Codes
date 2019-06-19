#define lmp 12
#define lmn 2
#define rmp 3
#define rmn 4


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);  

}

void loop() {
  // put your main code here, to run repeatedly:
  
 digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);


}
