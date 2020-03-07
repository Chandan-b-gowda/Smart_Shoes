  #define trigPin1 A5
  #define echoPin1 A4

  #define trigPin2 A3
  #define echoPin2 A2

  #define buzzer 3
  #define vibrator1 5

  long duration;
  float distanceInch;
  int timer;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(vibrator1, OUTPUT);
}

void loop()

{
  long duration, distance;

  // Read distance for buzzer
  
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin1, HIGH);
  distanceInch = duration * 0.0133 /2;
  
  // Actuate Buzzer
  digitalWrite(buzzer, HIGH);
  delay(30);
  digitalWrite(buzzer, LOW);

  timer = distanceInch * 10;

  delay(timer);

  
 // Read distance for Vibrator 1
 
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(1); 
  digitalWrite(trigPin2, LOW);

  duration = pulseIn(echoPin2, HIGH);
  distance = (duration/2) / 29.1;
  // Actuate Vibrator1
  if (distance < 20)
  { 
    Serial.println(distance);
    digitalWrite(vibrator1,HIGH);
    Serial.println("Vibrator1 - HIGH");
  }
  else
  {
    Serial.println(distance);
    digitalWrite(vibrator1,LOW);
    Serial.println("vibrator 1 LOW");
  }
  delay(50);
}
