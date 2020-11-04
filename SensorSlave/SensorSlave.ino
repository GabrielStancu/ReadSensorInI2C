//include I2C library
#include <Wire.h>

//define pins numbers
  //the pin on which the sound wave is sent towards the object:
const int trigPin = A1; 
  //the pin on which the rebounced frequency is received: 
const int echoPin = A0;

//define constants
  //the address of the slave in the communication mechanism 
const int sensorSlaveId = 2;
  //the constant we need to multiply the voltage to obtain the 
  //real distance. Determined experimentally.
const float scaleConstant = 0.0361/2;

//defines variables
  //the duration between sound wave send and receive
long duration;
  //the distance between the sensor and the object
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT); //sets the trigPin as an Output
  pinMode(echoPin, INPUT); //sets the echoPin as an Input
  Wire.begin(sensorSlaveId); //join the buss with address assigned
  Wire.onRequest(sendDistanceToMaster); 
    //when requested, send the distance to the master 
    //through the sendDistanceToMaster function
}

void loop()
{
  setTrigger(); //send the frequency wave in front of sensor
  computeDistance(); //compute the distance based on 
    //the time needed for wave to reach back
}

void setTrigger()
{
  //clear the trigPin:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //set the trigPin on HIGH state for 10 micro seconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}
  
void computeDistance()
{
  //read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  //calculate the distance
  distance= duration*scaleConstant;
}
  
void sendDistanceToMaster()
{
   //round the distance because we can only send integers 
   int roundedDistance = (int)(distance);
   //write the value on the bus
   Wire.write(roundedDistance);
}
