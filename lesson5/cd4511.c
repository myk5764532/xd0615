byte digit[100];
byte zero = 0;
void setup()
{
  pinMode(2, OUTPUT);//输入1
  pinMode(3, OUTPUT);//输入2
  pinMode(4, OUTPUT);//输入3
  pinMode(5, OUTPUT);//输入4
  pinMode(8, OUTPUT);//片选1
  pinMode(9, OUTPUT);//片选2
  pinMode(10, OUTPUT);//片选3
  pinMode(11, OUTPUT);//片选4
  
  pinMode(6,OUTPUT);//测试
  pinMode(7,OUTPUT);//消隐
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  Serial.begin(9600);
}

void loop()
{
    String dig = Serial.readString();
    if(dig.length()==1)
    {
      for(int i=8;i<11;i++)
      {
        digitalWrite(i,LOW);
        digitalWrite(2,zero&0x1);
        digitalWrite(3,(zero>>1)&0x1);
        digitalWrite(4,(zero>>2)&0x1);
        digitalWrite(5,(zero>>3)&0x1);
        digitalWrite(i,HIGH);
      }
      dig.getBytes(digit,2);
      digit[0]=digit[0]-'0';
      digitalWrite(11,LOW);
      digitalWrite(2,byte(digit[0])&0x1);
      digitalWrite(3,(byte(digit[0])>>1)&0x1);
      digitalWrite(4,(byte(digit[0])>>2)&0x1);
      digitalWrite(5,(byte(digit[0])>>3)&0x1);
      digitalWrite(11,HIGH);
  	  delay(10);
    }
    else if(dig.length()==4)
    {
      dig.getBytes(digit,dig.length()+1);
      for(int i=0;i<4;i++)
    	digit[i] -= '0';
      for(int i=8;i<12;i++)
      {
        digitalWrite(i,LOW);
        digitalWrite(2,byte(digit[i-8])&0x1);
        digitalWrite(3,(byte(digit[i-8])>>1)&0x1);
        digitalWrite(4,(byte(digit[i-8])>>2)&0x1);
        digitalWrite(5,(byte(digit[i-8])>>3)&0x1);
        digitalWrite(i,HIGH);
  	    delay(10);
      }
    }
  	else if(dig.length()>4)
  	{
      dig = "0000"+dig;
      dig.getBytes(digit,dig.length()+1);
      for(int i=0;i<dig.length();i++)
    	digit[i] -= '0';
      for(int i=0;i<dig.length()-3;i++)
      {
        for(int j=8;j<12;j++)
      	{
        	digitalWrite(j,LOW);
        	digitalWrite(2,byte(digit[j-8+i])&0x1);
        	digitalWrite(3,(byte(digit[j-8+i])>>1)&0x1);
        	digitalWrite(4,(byte(digit[j-8+i])>>2)&0x1);
        	digitalWrite(5,(byte(digit[j-8+i])>>3)&0x1);
        	digitalWrite(j,HIGH);
  	    	delay(500);
        }
      }
  	}
}