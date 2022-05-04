# PWM relay
PWMrelay - a library for generating a low-frequency PWM signal for relays (for PID controllers, etc.)
- PWM period setting
- Signal setting 0-255 (8 bits)
- Support low and high level relay
- Non-blocking call, does not use timers (except the system one), works on millis()

### Compatibility
Compatible with all Arduino platforms (using Arduino functions)

### Documentation
The library has [extended documentation](https://alexgyver.ru/PWMrelay/)

## Content
- [Install](#install)
- [Initialization](#init)
- [Usage](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found by the name **PWMrelay** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download Library](https://github.com/GyverLibs/PWMrelay/archive/refs/heads/main.zip) .zip archive for manual installation:
    - Unzip and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unzip and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/*
    - (Arduino IDE) automatic installation from .zip: *Sketch/Include library/Add .ZIP library…* and specify the downloaded archive
- Read more detailed instructions for installing libraries [here](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1 %D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Initialization
```cpp
PWM relay(pin);
```

<a id="usage"></a>
## Usage
```cpp
PWMrelay(int pin, bool dir = false, int period = 1000); // pin, relay level HIGH/LOW, period
void tick(); // tick, call as often as possible, controls the relay itself
void setPWM(byte duty); // set the PWM value, 0-255. With a value of 0 and 255, the tick is inactive!
byte getPWM(); // returns the PWM value
void setPeriod(int period); // set the PWM period to milliseconds. (default 1000ms == 1s)
int getPeriod(); // get period
void setLevel(bool level); // set set relay level (HIGH/LOW)
```

<a id="example"></a>
## Example
See **examples** for other examples!
```cpp
#include "PWMrelay.h"
PWM relay(13); // relay on pin 13

// or so
// PWM relay(13, HIGH); // high level relay on pin 13
// PWM relay(13, HIGH, 2000); // high level relay on pin 13, period 2 seconds

void setup() {
  Serial.begin(9600);
  
  relay.setLevel(HIGH); // you can change the level of the relay (HIGH/LOW)
  
  relay.setPeriod(1000); // you can change the period, milliseconds

  relay.setPWM(20); // set PWM signal 0-255
}

void loop() {
  // call in the loop, this function controls the relay itself
  relay.tick();
}
```

<a id="versions"></a>
## Versions
- v1.2 - minor compatibility bugs fixed

<a id="feedback"></a>
## Bugs and feedback
When you find bugs, create an **Issue**, or better, immediately write to the mail [alex@alexgyver.ru](mailto:alex@alexgyver.ru)
The library is open for revision and your **Pull Request**'s!