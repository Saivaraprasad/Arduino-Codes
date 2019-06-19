#define disply_time 1000
#define Rs 12
#define En 7
#define D4 8
#define D5 9
#define D6 10
#define D7 11
#define PIR 2
#define LED 13

#include <LiquidCrystal.h>
LiquidCrystal lcd(Rs, En, D4, D5, D6, D7);

int curr_state =0;
int prev_state =0;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
   pinMode(PIR,INPUT);
  
  
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:

  curr_state = digitalRead(PIR);
  digitalWrite(LED,curr_state); // Turns on LED according to the presense of humans
  Serial.print("The curreent state is: ");
  Serial.print(curr_state);
  Serial.print("    ");

  lcd.print("CS");
  lcd.print(curr_state);
  lcd.print(" ");

  if (prev_state != curr_state)
  {
    if(curr_state == HIGH)
    {
      count++;
      Serial.print("                                                                    Counter incremented");
    }
    else
    Serial.print("                                                                        State unchanged");
  }
  
 digitalWrite(LED,curr_state);
 
  lcd.print("Count ");
  lcd.print(count);
  Serial.print("The conter is:  ");
  Serial.println(count);
  
  prev_state = curr_state;
  
  lcd.setCursor(2,1);
  lcd.print("PS");
  lcd.print(prev_state);
  
  delay(50);
  lcd.clear();
}
