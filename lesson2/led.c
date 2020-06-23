void setup()
{
  for(int i=4;i<7;i++)
  pinMode(2*i+1, OUTPUT);
}

void loop() 
{
  for(int i=4;i<7;i++)
  {
  digitalWrite(2*i+1, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(2*i+1, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  }
}