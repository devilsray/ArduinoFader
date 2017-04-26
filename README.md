# Fader

Simple helper library which can be used to dim/fade some leds on arduino.

## Pros:

* no logic for managing timings and brightness regulation state
* default values are given, simple initialize with pin and then set brightness or brightness percent

## Cons:

* when _sleep_ is used in main class, then the regulation process is broken during this time

## Usage:

### Initialization

__Initialize with pin 3__
Fader fader(3);

__Initialize with full options__
Fader fader(4, 40, 200, 2, 3);

__Used parameters:__
* Pin
* Regulation interval (40 is my favorite)
* Max brightness to use. Depends on arduino model. Mostly 255 is possible. Default is 200 to save leds
* This values defines the value which will be added during the dim up process
* This values defines the value which will be added during the dim down process
