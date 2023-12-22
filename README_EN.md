This is an automatic translation, may be incorrect in some places. See sources and examples!

# Pwmrelay
PWMRELAY - a library for generating a low -frequency PWM signal for relay (for PID regulators, etc.)
- Setting up the Shim period
- Signal settings 0-255 (8 bits)
- Support for low and high -level relay
- a non -closing call, does not use timers (except for systemic), works on Millis ()

## compatibility
Compatible with all arduino platforms (used arduino functions)

### Documentation
There is [expanded documentation] to the library (https://alexgyver.ru/pwmrelay/)

## Content
- [installation] (# Install)
- [initialization] (#init)
- [use] (#usage)
- [Example] (# Example)
- [versions] (#varsions)
- [bugs and feedback] (#fedback)

<a id="install"> </a>
## Installation
- The library can be found according to the name ** pwmreli ** and installed through the library manager in:
    - Arduino ide
    - Arduino ide v2
    - Platformio
- [download the library] (https://github.com/gyverlibs/pwmrelay/archive/refs/heads/main.zip) .Zip archive for manual installation:
    - unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
    - unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
    - unpack and put in *documents/arduino/libraries/ *
    - (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!


<a id="init"> </a>
## initialization
`` `CPP
PWMRELAY RELAY (PIN);
`` `

<a id="usage"> </a>
## Usage
`` `CPP
PWMRELAY (Int, Bool Dir = FALSE, Int Period = 1000);// PIN, relay level high/low, period
VOID Tick ();// tick, call as often as possible, the relay itself controls
VOID setpwm (byte duty);// Set the PWM value, 0-255.With a value of 0 and 255, the tick is inactive!
Byte getpwm ();// Returns the size of Shim
VOID setperiod (intration);// Install the PWIM period in milliseck.(in silence. 1000ms == 1C)
Intperiod ();// Get a period
VOID Setlevel (Bool Level);// Install the level of relay (High/Low)
`` `

<a id="EXAMPLE"> </a>
## Example
The rest of the examples look at ** Examples **!
`` `CPP
#include "Pwmrelay.h"
PWMRELAY RELAY (13);// Relay on 13 pin

// or so
// Pwmrelay Relay (13, High);// high -level relay on 13 pine
// PWMRELAY RELAY (13, High, 2000);// high -level relay 13 pin, period 2 seconds

VOID setup () {
  Serial.Begin (9600);
  
  Relay.Setlevel (High);// you can change the level of relay (high/low)
  
  Relay.Setperiod (1000);// You can change the period, milliseconds

  Relay.setpwm (20);// set the signal Shim 0-255
}

VOID loop () {
  // Call in lCranberries, this function itself controls the relay
  Relay.tick ();
}
`` `

<a id="versions"> </a>
## versions
- V1.2 - Small errors with compatibility are fixed

<a id="feedback"> </a>
## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!


When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- whether the built -in examples work correctly, in which the functions and designs are used, leading to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code