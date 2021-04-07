#define AIR1 D12//catch
#define AIR2 D13//pull

void setup() {
  // put your setup code here, to run once:
    pinMode(AIR1,OUTPUT);
    pinMode(AIR2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    shot(0,1);
    delay(3000);
    shot(1,1);
    delay(3000);
    shot(1,0);
    delay(3000);
    shot(0,0);
    delay(3000);
}

void air(bool a, int b)
{
  if(a)
  {
    digitalWrite(b,HIGH);
  }
  else 
  {
    digitalWrite(b,LOW);
  }
}

void shot(int a, int b)
{
    air(a,AIR1);
    air(b,AIR2);
}
