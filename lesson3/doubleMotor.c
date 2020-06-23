char ch = ' ';
void setup()
{
  Serial.begin(9600);
  Serial.println("ok!");
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
    ch = Serial.read();
    switch(ch)
    {
      case 'f':
      	digitalWrite(13,HIGH);
      	digitalWrite(12,LOW);
      	digitalWrite(7,LOW);
      	digitalWrite(4,HIGH);
    	break;
      case 'b':
      	digitalWrite(12,HIGH);
      	digitalWrite(13,LOW);
      	digitalWrite(4,LOW);
      	digitalWrite(7,HIGH);
     	break;
      case 'r':
      	digitalWrite(13,HIGH);
      	digitalWrite(12,LOW);
      	digitalWrite(4,LOW);
      	digitalWrite(7,LOW);
        break;
      case 'l':
      	digitalWrite(12,LOW);
      	digitalWrite(13,LOW);
      	digitalWrite(7,LOW);
      	digitalWrite(4,HIGH);
        break;
      case 's':
      	digitalWrite(13,LOW);
      	digitalWrite(12,LOW);
      	digitalWrite(7,LOW);
      	digitalWrite(4,LOW);
        break;
      default:
      	break; 
    }
  }
}