int data;
int lift=1000;
int push=1000;
int mini=1000;
int maxi=2000;
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
  data=Serial.read();
 Serial.print("                                                                                                                                              \t           recieved : ");
Serial.println(data);

if(data=='2')
{
  if(lift!=maxi)
  {
    lift=lift+100;
    Serial.println(lift);
    //delay(50);
    
  }
}

if(data=='8')
{
  if(lift!=mini)
  {
    lift=lift-100;
    Serial.println(lift);
    delay(50);
  }
}

}
}
