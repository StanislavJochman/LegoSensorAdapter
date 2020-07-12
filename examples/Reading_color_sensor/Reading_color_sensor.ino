#include <LegoSensorAdapter.h>
LegoSensor Lego_sensor;

void setup() {
  Lego_sensor.begin();
  
}

void loop() {
  Lego_sensor.setMode(0x10,"LightR");
  Serial.print("Red Light: ");
  Serial.println(Lego_sensor.readData(0x10));
  delay(500);
  Lego_sensor.setMode(0x10,"LightB");
  Serial.print("Blue Light: ");
  Serial.println(Lego_sensor.readData(0x10));
  delay(500);
  Lego_sensor.setMode(0x10,"Color");
  Serial.print("Color: ");
  Serial.println(Lego_sensor.readData(0x10));
  delay(500);
  Lego_sensor.setMode(0x10,"Off");
  Serial.println("Sensor Off");
  delay(500);
}
