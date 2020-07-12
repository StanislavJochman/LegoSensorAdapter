#include <LegoSensorAdapter.h>
LegoSensor Lego_sensor;

void setup() {
  Lego_sensor.begin();

}

void loop() {
  Lego_sensor.listDevices();
  delay(2000);
}
