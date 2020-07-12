#include <LegoSensorAdapter.h>
LegoSensor Lego_sensor;

void setup() {
  Lego_sensor.begin();
  
}

void loop() {
  Serial.println(Lego_sensor.readData(0x10));
}
