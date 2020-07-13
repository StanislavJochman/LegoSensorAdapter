# Library for Lego adapter boards  #

This library allows you to connect Lego EV3 sensors to arduino using adapter board.
<p align="center">
  <img width="100%" alt= "Adapter board" src="https://github.com/StanislavJochman/LegoSensorAdapter/blob/master/sensor%20Board.png">
</p>

For more information about this library please visit us at
http://.sk

---

## Libraries Functions

### listDevices()

#### Description

Lists all available I2C devices.

#### Syntax

`listDevices()`

---

### begin()

#### Description

Inicialisation function for setting up I2C and Serial port.


#### Syntax

`begin(long baudrate,int time)`

#### Parameters

baudrate: `300`, `1200`, `2400`, `4800`, `9600`, `19200`, `38400`, `57600`, `74880`, `115200` - sets baudrate of Serial port

time: `1` - `1000` - sets time of Serial timeout in ms

---

### setAddress()

#### Description

Functions that allows you to set I2C addresses of individual modules using Serial monitor.


#### Syntax

`setAddress()`

---

### setMode()

#### Description

Inicialisation function for setting up I2C and Serial port.


#### Syntax

`setMode(int address,String mode)`

#### Parameters

address: `0x04` - `0x77` - I2C address of module where mode will be set 

mode: `Off`, `LightB`, `LightR`, `Color` - sets the mode of operation for sensors

##### Mode table

---

### readData()

#### Description

Reads the value from sensor.


#### Syntax

`readData(int address,String mode)`

#### Parameters

address: `0x04` - `0x77` - I2C address of module where mode will be set 

#### Returns

##### Button

| Value |     State     |
|:-----:|:-------------:|
|   1   |    Pressed    |
|   0   |  Not pressed  |

##### Color sensor

![Lego sensor colors](https://www.funcodeforkids.com/wp-content/uploads/Lego-Mindstorms-EV3-software-color-sensor-compare-color.jpg)

| Value | Color name |
|:-----:|:----------:|
|   0   |  No color  |
|   1   |    Black   |
|   2   |    Blue    |
|   3   |    Green   |
|   4   |   Yellow   |
|   5   |     Red    |
|   6   |    White   |
|   7   |    Brown   |



---


## License ##

Copyright © 2020 Stanislav Jochman. All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
