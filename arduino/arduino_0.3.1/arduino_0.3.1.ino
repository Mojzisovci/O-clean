#define DHTPIN 38//missing pin
#define DHTTYPE DHT11

#define enginePin1 2 //is not used
#define enginePin2 3

#define distanceSensorTrigg1 22
#define distanceSensorEcho1 24
#define distanceSensorTrigg2 26
#define distanceSensorEcho2 28
#define distanceSensorTrigg3 30
#define distanceSensorEcho3 32
#define distanceSensorTrigg4 34
#define distanceSensorEcho4 36

#define servoPin1 10 //is not used
#define servoPin2 11
#define servoPin3 12
#define servoPin4 13

#define led1 7

#include<DHT.h>

DHT dht(DHTPIN, DHTTYPE);

int distance1;
int distance2;
int distance3;
int distance4;

int temp;
int humidity;
int sensorPonoruValue;

int nejvetsiSranec = 0;


void setup() 
{
  dht.begin();
  
  pinMode(enginePin1,OUTPUT);
  pinMode(enginePin2,OUTPUT);
  
  pinMode(led1, OUTPUT);
  
  pinMode(distanceSensorTrigg1,OUTPUT);
  pinMode(distanceSensorEcho1,INPUT);
  pinMode(distanceSensorTrigg2,OUTPUT);
  pinMode(distanceSensorEcho2,INPUT);
  pinMode(distanceSensorTrigg3,OUTPUT);
  pinMode(distanceSensorEcho3,INPUT);
  pinMode(distanceSensorTrigg4,OUTPUT); 
  pinMode(distanceSensorEcho4,INPUT);

  pinMode(A0,INPUT);

  Serial.begin(9600);
}

void loop()
{ 
  distance1 = getDistanceFromSensor(distanceSensorTrigg1,distanceSensorEcho1); //return distance
  distance2 = getDistanceFromSensor(distanceSensorTrigg2,distanceSensorEcho2);
  distance3 = getDistanceFromSensor(distanceSensorTrigg3,distanceSensorEcho3);
  distance4 = getDistanceFromSensor(distanceSensorTrigg4,distanceSensorEcho4);
  
  temp = dht.readTemperature(); //return temp
  humidity = dht.readHumidity(); //return humidity
  sensorPonoruValue = analogRead(A0); //return ponor

for(int a = 0; a < 256; a++)
{
  analogWrite(enginePin1, a);
  analogWrite(enginePin2, a);
  delay(10);
}  
for(int a = 255; a > 0; a--)
{
  analogWrite(enginePin1, a);
  analogWrite(enginePin2, a);
  delay(10);
}

  delay(10);
  Serial.println(distance1);
  Serial.println(distance2);
  Serial.println(distance3);
  Serial.println(distance4);
  Serial.println(temp);
  Serial.println(humidity);
  Serial.println(sensorPonoruValue);
  Serial.println("-------------------------------");
  
}

int getDistanceFromSensor(int pinSensorTrigg, int pinSensorEcho)
{
  float duration;
  float distance;
  digitalWrite(pinSensorTrigg, HIGH);
  delay(1);
  digitalWrite(pinSensorTrigg, LOW);
  duration = (float)pulseIn(pinSensorEcho,HIGH) / 1000; //duration in second
  distance = (343 * 100 * duration) / 2; //get distance in centimeters
  return distance;
}
