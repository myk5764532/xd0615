#include <MsTimer2.h> 
volatile int pinInterrupt=2;
volatile byte tick = 0;
void myfunc()
{
  tick = 0;
}
void onTimer()
{
  Serial.println(tick);
  digitalWrite(3,(tick)&0x1);
  digitalWrite(4,(tick>>1)&0x1);
  digitalWrite(5,(tick>>2)&0x1);
  digitalWrite(6,(tick>>3)&0x1);
  tick++;
  if(tick>9)
    tick = 0;
}
void setup()
{
  
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(pinInterrupt), myfunc,CHANGE);
  MsTimer2::set(1000,onTimer);
  MsTimer2::start(); 
}
 
void loop()
{
  
}