#define d0 8
#define d1 9
#define d2 10
#define d3 11
#define dv 12

int data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(d0,INPUT);
  pinMode(d1,INPUT);
  pinMode(d2,INPUT);
  pinMode(d3,INPUT);
  pinMode(dv,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //if(digitalRead(dv)==HIGH)
  //{
   data=0;
   if(digitalRead(d0)==HIGH)
   data=data+1;
   if(digitalRead(d1)==HIGH)
   data=data+2;
   if(digitalRead(d2)==HIGH)
   data=data+4;
   if(digitalRead(d3)==HIGH)
   data=data+8;
   
    Serial.println(data);
//  }
 
}
