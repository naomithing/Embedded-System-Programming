//Student Name: Naomi Thing
//Student ID: 2332244
//Project Name: Speed Detector
//Date: 2023/05/20

int sen1 = A0;
int sen2 = A3;
int ledPin = 9;
unsigned long t1 = 0;
unsigned long t2 = 0;
int velocity;
int real_velocity;
float timeFirst;
float timeScnd;
float diff;
float speedConst = 7.5; //Speed Conversion constant in centimeter(cm)

void setup()
{
  Serial.begin(9600);
  pinMode(sen1, INPUT);
  pinMode(sen2, INPUT);
  analogWrite(11, LOW);
  analogWrite(10, HIGH);
}

void loop()
{
  //Checks if an object passed from left to right
  if (analogRead(sen1) < 500 && analogRead(sen2) > 500)
  {
    timeFirst = millis();//records time for first trigger
    digitalWrite(ledPin, LOW);
    delay(30);
  }
  //Checks if an object passed from right to left
  if (analogRead(sen2) > 500 && analogRead(sen1) < 500)
  {
    timeScnd = millis();//records time for second trigger
    diff = timeScnd - timeFirst;
    velocity = int(speedConst * diff);//calculates the velocity
    real_velocity = int((velocity * 360) / 100);//converts the calculated velocity to km/hr
    delay(30);
    digitalWrite(ledPin, HIGH);
    Serial.print("The velocity is: ");
    Serial.print(real_velocity);
    Serial.println("km/hr.");
    delay(500);
  }
}
