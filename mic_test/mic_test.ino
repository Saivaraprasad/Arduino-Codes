int a;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  pinMode(10,INPUT);
  
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

a=digitalRead(10);
Serial.println(a);
}
