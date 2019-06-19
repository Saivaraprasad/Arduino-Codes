#define r1 2
#define r2 3
#define r3 4
#define r4 5

#define panel 6
#define LED 12

int t=10;
int tp = 200;
int v1,v2,v3,v4;
int data=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(r1,INPUT);
pinMode(r2,INPUT);
pinMode(r3,INPUT);
pinMode(r4,INPUT);

pinMode(panel,OUTPUT);
pinMode(LED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(panel,HIGH);
  delay(t);
  digitalWrite(panel,LOW);
  delay(t);

 v1 = analogRead(r1);
 Serial.print("470 Ohm:");
            Serial.print(v1);
            //Serial.print("  ||  ");

 v2 = analogRead(r2);
                //  Serial.print("  ____1K Ohm:  ");
                  //               Serial.print(v2);
                    //               Serial.print("  ||  ");

 v3 = analogRead(r3); 
                      //                      Serial.print(" ____82K Ohm: ");
                        //                                   Serial.print(v3);
                          //                                    Serial.print("  ||  ");

 v4 = analogRead(r4);
                            //                                       Serial.print(" ____1M Ohm:  ");
                              //                                                 Serial.println(v4);

if(data<tp)
 {
  Serial.println("                                                                                                                                                    Touch not detected");
  //Serial.println(data);
  digitalWrite(LED,LOW);
 }

 if(data>tp)
 {
  Serial.println("                                                                                                                                                    Touch detected");
  Serial.println(data);
  digitalWrite(LED,HIGH);
 }
}
