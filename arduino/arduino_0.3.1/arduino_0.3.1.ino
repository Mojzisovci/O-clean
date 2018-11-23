#include<DHT.h>


const int enginePin1 = 2; //is not used
const int enginePin2 = 3;

const int distanceSensorTrigg1 = 22;
const int distanceSensorEcho1 = 23;
const int distanceSensorTrigg2 = 24;
const int distanceSensorEcho2 = 25;
const int distanceSensorTrigg3 = 26;
const int distanceSensorEcho3 = 27;
const int distanceSensorTrigg4 = 28;
const int distanceSensorEcho4 = 29;

const int servoPin1 = 10; //is not used
const int servoPin2 = 11;
const int servoPin3 = 12;
const int servoPin4 = 13;

const int tempSensor = 30; //is not used



const int led1 = 7;



int distance1;
int distance2;
int distance3;
int distance4;




void setup() 
{
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
  
  pinMode(tempSensor, INPUT);
  
}

void loop() 
{
  distance1 = getDistanceFromSensor(distanceSensorTrigg1,distanceSensorEcho1);
  distance2 = getDistanceFromSensor(distanceSensorTrigg2,distanceSensorEcho2);
  distance3 = getDistanceFromSensor(distanceSensorTrigg3,distanceSensorEcho3);
  distance4 = getDistanceFromSensor(distanceSensorTrigg4,distanceSensorEcho4);
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

int getTemperature(int tempSensorPin)
{
  
}
