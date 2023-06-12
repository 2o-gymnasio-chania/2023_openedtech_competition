
int buzzer = 3;
int ir1=A0;
int ir2=A1;
unsigned long time_start, time_counter;
const int object_distance=200;
void setup ()
{
  pinMode (buzzer, OUTPUT) ;
  time_start=millis();
  digitalWrite (buzzer, HIGH);
}
void loop ()
{
  if (analogRead(ir1)>object_distance || analogRead(ir2)>object_distance)
  {
    time_counter=millis();
    if (time_counter-time_start>=2000)
    {
      digitalWrite (buzzer, LOW);
      delay (500) ;
      digitalWrite (buzzer, HIGH);
      delay (1000) ;
    }
  }
  else
  {
    time_start=millis();
    digitalWrite (buzzer, HIGH);
  }
}
