unsigned long current =0;
unsigned long previous =0;

int period = 1000;
int state = LOW;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  current=millis();
Serial.println(current);
if(current - previous >= period)
{
  previous = current;
  if(state == LOW)
  {
    state = HIGH;
  }
  else
  {
    state = LOW;
  }
  Serial.print("                               ");
  Serial.println(state);
}
//delay(10);
}
