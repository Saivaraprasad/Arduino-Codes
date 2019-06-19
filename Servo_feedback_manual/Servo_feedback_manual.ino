void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//analogRead(8);
Serial.println(analogRead(8));
}
