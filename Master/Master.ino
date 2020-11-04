#include <Wire.h>

//define constants
  //the address of the slaves in the communication mechanism 
  //the address of the slave that turns the led on 
const int ledSlaveId = 1;
  //the address of the slave that gets the distance
  //to the object through the sensor
const int sensorSlaveId = 2;

//defines variables
  //the distance between the sensor and the object
  //received from sensor slave through i2c
int distance = 0;

void setup()
{
  //join i2c bus
  Wire.begin();
}

void loop()
{
  //request an int from the sensor slave
  Wire.requestFrom(sensorSlaveId, sizeof(int));
  //read the distance
  distance = Wire.read();

  //start communication with led slave
  Wire.beginTransmission(ledSlaveId); 
  //transmit distance to the led slave
  Wire.write(distance); 
  //stop communication with led slave
  Wire.endTransmission(); 
}
