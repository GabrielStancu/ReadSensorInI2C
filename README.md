# ReadSensorInI2C

The sensor slave gets the distance between the ultrasonic wave sensor and an object. The distance is sent through I2C to the master circuit, which is sent to the other slave, that turns the led on if the distance is smaller than a given threshold. 

Made with Arduino. The circuit scheme can be seen in the attached image file.
