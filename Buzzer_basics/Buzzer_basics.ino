
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 
tone(2,300,300);
delay(400);
tone(2,800,300);
delay(400);
noTone(2);
}
