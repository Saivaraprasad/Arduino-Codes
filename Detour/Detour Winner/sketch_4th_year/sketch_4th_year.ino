#define x_input A0
#define y_input A1
#define z_input A2
const int  buttonPin = 11;   
const int ledPin = 6;      

int buttonPushCounter = 0;   
int buttonState = 0;         
int lastButtonState = 0;  

float x=0;
float y=0;
float z=0;
float zero_level_x = 1204;
float zero_level_y = 1200;
float zero_level_z = 1440;
float sensitivity = 300;
float operating_voltage_level=3300;

void setup()
{
  pinMode(x_input,INPUT);
  pinMode(y_input,INPUT);
  pinMode(z_input,INPUT);
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH) 
    {
     buttonPushCounter++;
     delay(100);
    } 
    //delay(10);
  }
  lastButtonState = buttonState;
  if (buttonPushCounter % 2 != 0) 
  {
    digitalWrite(ledPin, HIGH);
    data_acquisition();
  } 
  else 
  {
  digitalWrite(ledPin, LOW);

  }
}
void data_acquisition()
{
  x = ((((operating_voltage_level/1023)*analogRead(x_input))-zero_level_x)/sensitivity);
  y = ((((operating_voltage_level/1023)*analogRead(y_input))-zero_level_y)/sensitivity);
  z = ((((operating_voltage_level/1023)*analogRead(z_input))-zero_level_z)/sensitivity); 
  Serial.print("x_reading - ");
  Serial.print(x);
  Serial.print(" , ");
  Serial.print("y_reading - ");
  Serial.print(y);
  Serial.print(" , ");
  Serial.print("z_reading - ");
  Serial.print(z);
  Serial.print("\n");
 delay(1);
}
