#define lir 2
#define mir 9
#define rir 10

int l=1;
int m=1;
int r=1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(lir,INPUT);
  pinMode(mir,INPUT);
  pinMode(rir,INPUT);

  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  l=digitalRead(lir);
  m=digitalRead(mir);
  r=digitalRead(rir);

  Serial.print(l);
  Serial.print( "\t -- \t");
  Serial.print(m);
  Serial.print( "\t -- \t");
  Serial.println(r);
  
}
