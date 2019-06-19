#define d0 2
#define d1 3
#define d2 4
#define d3 5
#define dv 6

int data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(d0,INPUT);
  pinMode(d1,INPUT);
  pinMode(d2,INPUT);
  pinMode(d3,INPUT);
  pinMode(dv,INPUT);

  pinMode(13,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(digitalRead(dv)==HIGH)
  {
 Serial.print(" DTMF TEST     Dv -- ");
 Serial.print(digitalRead(dv));
 Serial.print("   || D0 -- "); 
 Serial.print(digitalRead(d0));
 Serial.print("   || D1 -- ");
 Serial.print(digitalRead(d1));
 Serial.print("   || D2 -- ");
 Serial.print(digitalRead(d2));
 Serial.print("   || D3 -- "); 
 Serial.println(digitalRead(d3)); 
 
}

}
