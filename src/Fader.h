#ifndef FADER_H
#define FADER_H

#include "Arduino.h"

class Fader
{
public:
  Fader(const int _pin, const int _processIntervalMillis = 40, const float _maxBrightness = 255, const float _stepsUpPerProcess = 1, const float _stepsDownPerProcess = 1, const int channel = 0);
  void setLevel(const float _level);
  void setPercent(const float _percent);
  void loop();
  bool isLevelReached();

protected:
  int pin;
  int processIntervalMillis;
  float maxBrightness;
  float stepsUpPerProcess;
  float stepsDownPerProcess;
  float lightCurrentLevel;
  float lightTargetLevel;
  int channel;
  unsigned long nextLightProcess;
};
#endif