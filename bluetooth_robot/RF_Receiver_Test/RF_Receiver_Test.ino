#include <SoftwareSerial.h>

#define RF 12

SoftwareSerial RFserial(12,A0);
 int data=0;
void setup() {
  // put your setup code here, to run once:
  RFserial.begin(9600);
pinMode(RF,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
data = RFserial.read(.);
RFserial.println(data);

}
