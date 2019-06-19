int data;
int lift=1000;
int push=1000;
int mini=1000;
int maxi=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.print("initial lift");
  //Serial.println(lift);
if(Serial.available())
{
  while(Serial.read()== '2')
  {
    lift=lift+5;
    Serial.println(lift);
    delay(50);
  }

  while(Serial.read()=='8')
  {
    lift=lift-5;
    Serial.println(lift);
    delay(50);
  }

}
}
