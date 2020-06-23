#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("READY!");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Please Enter: ");
  Serial.begin(9600);
}

void loop() {
  String str = Serial.readString();
  String str1 = "";
  if((str.length()<=16)&&(str.length()>0))
  {
    lcd.setCursor(0, 0);
    lcd.print("               ");
    lcd.setCursor(0, 0);
    lcd.print(str);
  }
  else if(str.length()>16)
  {
    lcd.setCursor(0, 0);
    lcd.print("               ");
    lcd.setCursor(0, 0);
    lcd.print("Input Error!");
  }
} 