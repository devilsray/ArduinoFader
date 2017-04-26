#include <Fader.h>

// An led has to be connected to this pin. Every pin should work, but better use pwm pins and don't forget the resistor 
#define LIGHT_PIN 3   

// Led pin, change brightness every 40 milliseconds (my best working value), max value is 200, 2 steps up, 3 steps down
Fader fader(LIGHT_PIN, 40, 200, 2, 3);

bool isOn = true;

void setup()
{
    fader.setPercent(100);
}

void loop()
{
    fader.loop(); // fader will switch brightness if necessary
    if (fader.isLevelReached()) 
    {
        fader.setPercent(isOn ? 0 : 100); // change do on / off
        isOn = !isOn;
    }
}