/*
Created by Stanislav Jochman
*/
#ifndef LegoSensorAdapter
#define LegoSensorAdapter
#include "Arduino.h"
//--------------------------------------------
//              Creating Class
//--------------------------------------------
class LegoSensor
{
// public variables
  public:
//constructor
    LegoSensor();
    void listDevices();
    void begin(long baudrate=9600,int time=10);
    void setAddress();
    void setMode(int address, String mode = "Off");
    int readData(int address);
// local variables
  private:
  int hstoi(String recv);
};
#endif
