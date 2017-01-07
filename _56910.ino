
const int N1 = 9;  
const int N2 = 10;  
const int N3 = 5;  
const int N4 = 6;  
const int PWM_ENA = 7;
const int PWM_ENB = 8;
int RATE = 800;

void Forword()
{
  digitalWrite(N1,HIGH);
  digitalWrite(N2,LOW);
  digitalWrite(N3,HIGH);
  digitalWrite(N4,LOW);
}
void Backword()
{
  digitalWrite(N1,LOW);
  digitalWrite(N2,HIGH);
  digitalWrite(N3,LOW);
  digitalWrite(N4,HIGH);
}
void TurnLeft()
{
  digitalWrite(N1,LOW);
  digitalWrite(N2,HIGH);
  digitalWrite(N3,HIGH);
  digitalWrite(N4,LOW);
}
void TurnRight()
{
  digitalWrite(N1,HIGH);
  digitalWrite(N2,LOW);
  digitalWrite(N3,LOW);
  digitalWrite(N4,HIGH);
}
void Stop()
{
  digitalWrite(N1,LOW);
  digitalWrite(N2,LOW);
  digitalWrite(N3,LOW);
  digitalWrite(N4,LOW);
}
void PWM_PLUS(int rate )
{
   
    digitalWrite(PWM_ENA,HIGH);
     digitalWrite(PWM_ENB,HIGH);
    delayMicroseconds(RATE);
    digitalWrite(PWM_ENA,LOW);
    digitalWrite(PWM_ENB,LOW);
    delayMicroseconds(1000-RATE);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(N1,OUTPUT);
  pinMode(N2,OUTPUT);
  pinMode(N3,OUTPUT);
  pinMode(N4,OUTPUT);
  pinMode(PWM_ENA,OUTPUT);
  pinMode(PWM_ENB,OUTPUT);
  
  Forword();
}
void loop() {
  // put your main code here, to run repeatedly:
  PWM_PLUS(RATE);//调速函数，通过ENA输出PWM脉冲
  while(Serial.available()>0)
   {
     char c=Serial.read();
     
      if(c=='U')
        {
          Forword();
        }
      else if(c == 'D')
      {
        Backword();
      }
      else if(c == 'L')
      {
        TurnLeft();
      }
      else if(c == 'R')
      {
        TurnRight();
      }
      else if(c == 'S')
      {
        Stop();
      }
      else if(c == '3')
      {
        RATE=1000;
        PWM_PLUS(RATE);
      }
        else if(c == '2')
      {
        RATE=900;
        PWM_PLUS(RATE);
      }
        else if(c == '1')
      {
        RATE=800;
        PWM_PLUS(RATE);
      }
        else if(c == '0')
      {
        RATE=700;
        PWM_PLUS(RATE);
      }
   }
}
