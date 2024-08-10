int trig=12;
int echo=11;

int red=7;
int blue=5;
int green=4;

int duration=0;
int cm=0;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red, OUTPUT); 
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  //Trigger to generate the ultrasonic sound wave
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo,HIGH); //Measure the time taken by the sound wave to reach the object and return to the sensor
  cm = duration*0.017; //distance = time duration for the sound to travel to the object and back to sensor * speed of sound (0.034 cm/us) / 2 (To account only one way trip of sound wave)
  
  if (cm < 25){
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    delay(300);
  }
  else if (cm >= 25 && cm < 50){
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    delay(300);
  }
  else if (cm >= 50 && cm < 100){
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    delay(300);
  }
  else{ // Make the led blink with red, blue, green when no object is detected or the object is more than 100 cm away from the sensor
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    delay(100);
  }
}
