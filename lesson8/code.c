#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//初始化LCD，将rs, enable, d4, d5, d6, d7分别接到12，11，5，4，3，2号引脚上；

void setup() {
  lcd.begin(16, 2);//初始化LCD并指定16*2的尺寸；
  lcd.print("hello, world!");//将"hello, world!"打印到LCD上；
}

void loop() {
  lcd.setCursor(0, 1);//将指针调至第0行第1列；
  lcd.print(millis() / 1000);//显示LCD运行的时长；
}
 