// include I2C library
#include <Wire.h>

//define constants
  //the address of the slave in the communication mechanism 
const int slaveId = 1;
  //the distance considered "close enough" to turn the led on 
  //~50cm
const int closeDistanceThreshold = 50;
  //the pin of the led
const int ledPin = 13;
  //the value required to turn the led on
int turnLedOn = 255;
  //the value required to turn the led off
int turnLedOff = 0;

//define variables
  //the distance between the sensor and the object
  //received from the master 
int distance = 0;
 
void setup()
{
  //set the pin of the led for output
  pinMode(ledPin, OUTPUT);
  //join i2c bus with assigned address 
  Wire.begin(slaveId);
  //when sent, receive the data in the 
  //receiveEvent function
  Wire.onReceive(receiveEvent);
}

void loop()
{
  //compare the distance with the "too close" threshold
  if (distance < closeDistanceThreshold)
  {
    //if distance < threshold, turn the led on 
    analogWrite(ledPin, turnLedOn);
  }
  else 
  {
    //else turn the led off
    analogWrite(ledPin, turnLedOff);
  }
}

void receiveEvent(int bytes) {
  //read I2C received distance
  distance = Wire.read(); 
}
