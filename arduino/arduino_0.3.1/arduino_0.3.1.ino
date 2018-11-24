#define DHTPIN 38 
#define DHTTYPE DHT11 //temp sensor

#define enginePin1 2 //engine control
#define enginePin2 3

#define distanceSensorTrigg1 22 //distance sensor
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

#define led1 7 //is not used

#include<DHT.h>

DHT dht(DHTPIN, DHTTYPE);

int distance1;
int distance2;
int distance3;
int distance4;

int temp;
int humidity;
int sensorPonoruValue;

int collectorTimer = 0;

void setup() 
{
  dht.begin();
  
  pinMode(enginePin1,OUTPUT); //engine pin
  pinMode(enginePin2,OUTPUT);
  
  pinMode(led1, OUTPUT); //not used
  
  pinMode(distanceSensorTrigg1,OUTPUT);//distance sensor
  pinMode(distanceSensorEcho1,INPUT);
  pinMode(distanceSensorTrigg2,OUTPUT);
  pinMode(distanceSensorEcho2,INPUT);
  pinMode(distanceSensorTrigg3,OUTPUT);
  pinMode(distanceSensorEcho3,INPUT);
  pinMode(distanceSensorTrigg4,OUTPUT); 
  pinMode(distanceSensorEcho4,INPUT);

  pinMode(A0,INPUT); //ponor

  Serial.begin(9600);
  
  analogWrite(enginePin1, 250); //engine start
  analogWrite(enginePin2, 250);
}

void loop()
{ 
  analogWrite(enginePin1, 250); //engine work
  analogWrite(enginePin2, 250);
  
  distance1 = getDistanceFromSensor(distanceSensorTrigg1,distanceSensorEcho1); //return distance
  distance2 = getDistanceFromSensor(distanceSensorTrigg2,distanceSensorEcho2);
  distance3 = getDistanceFromSensor(distanceSensorTrigg3,distanceSensorEcho3);
  distance4 = getDistanceFromSensor(distanceSensorTrigg4,distanceSensorEcho4);
  
  temp = dht.readTemperature(); //return temp
  humidity = dht.readHumidity(); //return humidity
  sensorPonoruValue = analogRead(A0); //return ponor



  if(distance1 == min(min(distance1, distance2),min(distance3, distance4))&& distance1 > 10 && distance1 < 30)
  {
     //nejnizsi vykon levy motor
     analogWrite(enginePin1, 100);
  }
  else if(distance2 == min(min(distance1, distance2),min(distance3, distance4))&& distance2 > 10 && distance2 < 20)
  {
    //maly vykon levy motor
    analogWrite(enginePin1, 150);
    //collector on for 20 seconds
    collectorTimer = 0;
  }
  else if(distance3 == min(min(distance1, distance2),min(distance3, distance4))&& distance3 > 10 && distance3 < 30)
  {
    //nejnizsi vykon pravy motor
    analogWrite(enginePin2, 100);
  }
  else if(distance4 == min(min(distance1, distance2),min(distance3, distance4))&& distance4 > 10 && distance4 < 20)
  {
    //maly vykon pravy motor
    analogWrite(enginePin2, 150);
    //collector on for 20 seconds
    collectorTimer = 0;
  }
  delay(1);
  collectorTimer++;
  if(collectorTimer < 20000)//timer for 20 seconds = 20000 miliseconds
  {
    //turn on collector
  }
  
  
  
  Serial.println(distance1); //only to showing
  Serial.println(distance2);
  Serial.println(distance3);
  Serial.println(distance4);
  Serial.println(temp);
  Serial.println(humidity);
  Serial.println(sensorPonoruValue);
  Serial.println("-------------------------------");

}

int getDistanceFromSensor(int pinSensorTrigg, int pinSensorEcho) //return distance from sensor
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
