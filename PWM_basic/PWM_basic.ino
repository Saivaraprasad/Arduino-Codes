#define motorp 2
#define motorn 4
#define motorpwm 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(motorp,OUTPUT);
pinMode(motorn,OUTPUT);
pinMode(motorpwm,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

   int i=125;
    
    digitalWrite(motorp,HIGH);
    digitalWrite(motorn,LOW);
    Serial.println(i);
    analogWrite(motorpwm,i);

    delay(1000);

     digitalWrite(motorp,LOW);
    digitalWrite(motorn,HIGH);
    Serial.println(i);
    analogWrite(motorpwm,i);

    delay(1000);

}
