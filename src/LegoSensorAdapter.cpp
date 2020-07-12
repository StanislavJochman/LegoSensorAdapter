/*
Created by Stanislav Jochman
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include <SoftwareSerial.h>
#include <Wire.h>
#include <i2cdetect.h>
//--------------------------------------------
#include "Arduino.h"
#include "LegoSensorAdapter.h"
//--------------------------------------------
LegoSensor::LegoSensor(){}
//--------------------------------------------
//             Servo setup
//--------------------------------------------

void LegoSensor::listDevices(){
	i2cdetect();
}

void LegoSensor::begin(long baudrate,int time){
	Wire.begin();
	Serial.begin(baudrate);
	Serial.setTimeout(time);
}
void LegoSensor::setAddress(){
	Serial.println("To change address of module connect jumper Addr and press switch SW on module.");
	Serial.println("Wait for led Status to start blinking once a second.");
	Serial.println("Write new adress from 0x04 to 0x0F. 0X00 - 0X03 are reserved!!");
	String serialInput;
	int address = 0;
	while (address == 0){
		if (Serial.available() > 0) {
		serialInput = Serial.readString();
		serialInput = serialInput.substring(2);
		address = hstoi(serialInput);
		}
	}
	Wire.beginTransmission(0x03);
	Wire.write(address);
	Wire.write((address>>8));
	Wire.endTransmission();
	Serial.print("Address sucessfuly set to 0X");
	Serial.print(address,HEX);
	Serial.println(".");
	Serial.println("You can now press disconnect jumper Addr and press switch SW.");
	while (true) {}
}

int LegoSensor::hstoi(String recv){
  char c[recv.length() + 1];
  recv.toCharArray(c, recv.length() + 1);
  return strtol(c, NULL, 16);
}

/*
modes

0 - red light
1 - blue light
2 - color mode
3 - red light (not stable,not used)
4 - color mode (not stable,not used)
5 - off
*/

void LegoSensor::setMode(int address,String mode){
	if (address>0X77 || address<0x04){
    	#define I2C_error
  	}
	Wire.beginTransmission(address);
	//Sensor off
	if(mode == "Off"){
	  Wire.write(5);
	}
	//Light Blue
	else if(mode == "LightB"){
	  Wire.write(1);
	}
	//Light red
	else if(mode == "LightR"){
	  Wire.write(0);
	}
	//Color
	else{
	  Wire.write(2);
	}
	Wire.endTransmission();
}
int LegoSensor::readData(int address){
	if (address>0X77 || address<0x04){
    	
  	}
  	Wire.requestFrom(address,2);
  	int data = (Wire.read() | Wire.read() << 8);
  	return data;
}
