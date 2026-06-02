This is an automatic translation and may be incorrect in some places. See the source README and examples for authoritative information.

[![latest](https://img.shields.io/github/v/release/GyverLibs/PWMrelay.svg?color=brightgreen)](https://github.com/GyverLibs/PWMrelay/releases/latest/download/PWMrelay.zip)
[![PIO](https://badges.registry.platformio.org/packages/gyverlibs/library/PWMrelay.svg)](https://registry.platformio.org/libraries/gyverlibs/PWMrelay)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD%24%E2%82%AC%20%D0%9F%D0%BE%D0%B4%D0%B4%D0%B5%D1%80%D0%B6%D0%B0%D1%82%D1%8C-%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/PWMrelay?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# PWMrelay
PWMrelay - a library for generating a low-frequency PWM signal for relays (for PID regulators, etc.)
- Setting up the PWM period
- Signal setting 0-255 (8 bits)
- Low and high level relay support
- Non-blocking call, does not use timers (except system) and runs on millis()

### Compatibility
Compatible with all Arduino platforms (Arduino features are used)

### Documentation.
There's a library[extended documentation](https://alexgyver.ru/PWMrelay/)

## Contents
- [Installation](#install)
- [Initialization](#init)
- [Use of use](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found under the name **PWMrelay** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download the library](https://github.com/GyverLibs/PWMrelay/archive/refs/heads/main.zip).zip archive for manual installation:
    - Unpack and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unpack and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/ *
    - (Arduino IDE) Automatic installation from .zip: *Sketch/Connect library/Add .ZIP library...* and specify downloaded archive
- Read more detailed instructions for installing libraries[here](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: new versions fix errors and bugs, as well as optimize and add new features.
- Through the library manager IDE: find the library as when installing and click "Update"
- Manually: **Delete the folder with the old version** and then put the new one in its place. “Replacement” can not be done: sometimes new versions delete files that will remain when replaced and can lead to errors!

<a id="init"></a>
## Initialization
```cpp
PWMrelay relay(пин);
```

<a id="usage"></a>
## Use of use
```cpp
PWMrelay(int pin, bool dir = false, int period = 1000);	// PIN, HIGH/LOW relay level, period
void tick();					// tic, call as often as possible, controls the relay
void setPWM(byte duty);			// set the PWM value, 0-255. At 0 and 255, the tick is inactive.
byte getPWM();					// returns
void setPeriod(int period);		// set the PWM period to a millisecond. (silence). 1000ms = = 1c)
int getPeriod();				// period
void setLevel(bool level);		// set the relay level (HIGH/LOW)
```

<a id="example"></a>
## Example
For more examples see **examples**!
```cpp
#include "PWMrelay.h"
PWMrelay relay(13); // relay

// so
// PWMrelay relay(13, HIGH) // high-level relay at 13 pins
// PWMrelay relay(13, HIGH, 2000) // High level relay at 13 pins, period 2 seconds

void setup() {
  Serial.begin(9600);
  
  relay.setLevel(HIGH);   // Relay level can be changed (HIGH/LOW)
  
  relay.setPeriod(1000);  // You can change the period, milliseconds.

  relay.setPWM(20);       // set the PHY 0-255 signal
}

void loop() {
  // call in the magnifier, this function itself controls the relay
  relay.tick();   
}
```

<a id="versions"></a>
## Versions
- v1.2 - minor errors with compatibility are corrected

<a id="feedback"></a>
## Bugs and feedback
If you find bugs, create **Issue**, or better write to the mail immediately.[alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
The library is open for revision and your **Pull Requests*!

When reporting bugs or incorrect work of the library, it is necessary to specify:
- Library version
- What is used by the IC
- SDK version (for ESP)
- Arduino IDE version
- Are embedded examples that use features and designs that cause bugs in your code working correctly?
- What code was downloaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed. Not a canvas of a thousand lines, but a minimum code.
