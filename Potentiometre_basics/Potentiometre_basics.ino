int data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  data=analogRead(A0);
  Serial.println(data);

}
