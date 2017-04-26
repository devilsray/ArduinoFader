#include "Fader.h"

Fader::Fader(const int _pin,
             const int _processIntervalMillis,
             const float _maxBrightness,
             const float _stepsUpPerProcess,
             const float _stepsDownPerProcess)
    : pin(_pin),
      processIntervalMillis(_processIntervalMillis),
      maxBrightness(_maxBrightness),
      stepsUpPerProcess(_stepsUpPerProcess),
      stepsDownPerProcess(_stepsDownPerProcess)
{
  lightCurrentLevel = 0;
  lightTargetLevel = 0;
  pinMode(pin, OUTPUT);
}

void Fader::setLevel(const float _level)
{
  lightTargetLevel = _level;
}

void Fader::setPercent(const float _percent)
{
  lightTargetLevel = _percent / 100 * maxBrightness;
  #if defined DEBUG
      Serial.sprintf("Fader: target level %i", lightTargetLevel);
  #endif
}

bool Fader::isLevelReached()
{
  return lightCurrentLevel == lightTargetLevel;
}

void Fader::loop()
{
  if (nextLightProcess <= millis())
  {
    nextLightProcess = millis() + processIntervalMillis;
    if (lightTargetLevel == lightCurrentLevel)
    {
      return;
    }
    if (lightTargetLevel > lightCurrentLevel)
    {
      lightCurrentLevel += stepsUpPerProcess;
      if (lightCurrentLevel > lightTargetLevel)
        lightCurrentLevel = lightTargetLevel;
    }
    else
    {
      lightCurrentLevel -= stepsDownPerProcess;
      if (lightCurrentLevel < 0)
        lightCurrentLevel = 0;
    }
    #if defined DEBUG
        Serial.sprintf("Fader: level %i", lightCurrentLevel);
    #endif
    analogWrite(pin, lightCurrentLevel);
  }
}