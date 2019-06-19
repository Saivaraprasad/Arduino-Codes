#define disply_time 1000
#define Rs 12
#define En 13
#define D4 8
#define D5 9
#define D6 10
#define D7 11


#include <LiquidCrystal.h>
LiquidCrystal lcd(Rs,En,D4,D5,D6,D7);

int duration,cm;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

 // Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  //disply
  lcd.print("Hello,");
  lcd.setCursor(2,1);
  lcd.print("I am a robot");
  delay(disply_time);
  lcd.clear();

}
