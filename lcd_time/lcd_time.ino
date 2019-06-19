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
long previous_millis=0;

int hrs = 14;
int mins = 10;
int secs = 00;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);


 // Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  //disply
  
  lcd.print(hrs);
  lcd.print(" : ");
  lcd.print(mins);
  lcd.print(" : ");
  lcd.print(secs);
  
long current_millis= millis();



  if(current_millis - previous_millis >= 1000);
  {
    previous_millis=current_millis;
    secs= secs+1;
    if(secs>=60)
    {
        secs=0;
        mins=mins+1;
        if(mins>=60)
        {
          mins=0;
          hrs=hrs+1;
          if(hrs>=24)
          {
            hrs=0;
          }
        }
    }
  
    
  }

  
  lcd.clear();


}
