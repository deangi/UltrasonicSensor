// Driver for HC-SR04 Ultrasonic Distance Sensor
// Has a trigger pin - which you pulse high for 10us
// Has an echo pin - which is high until the return pulse is detected
//
// If you send a trigger and measure the duration of the
// trigger pin, you get the round-trip time of the ultrasonic
// sound wave from the sensor to some object and back
//
// Has about a +/- 15 degree field of view horizontally
//
// Dean Gienger, February 29, 2024
//
// V1.0 Feb 29, 2024
//

#include "UltrasonicHCSR04.h"

UltrasonicHCSR04::UltrasonicHCSR04(uint8_t trigpin, uint8_t echopin)
{
  trigPin = trigpin;
  echoPin = echopin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(echoPin, LOW);
  speedOfSound = 1125.33*12.0/1000000.0; // inches per us, 1125.33 fps constant
}

void UltrasonicHCSR04::setSpeedOfSoundFPS(float fps)
{
  speedOfSound = fps * 12.0 / 1000000.0; // inches per microsecond
}

float UltrasonicHCSR04::measureDistanceInches()
{
  // send trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds, round trip
  long durationus = pulseIn(echoPin, HIGH) / 2; // microseconds one-way trip
  return speedOfSound * (float)durationus;
}
