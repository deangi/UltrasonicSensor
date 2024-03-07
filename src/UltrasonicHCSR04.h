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
// V1.0 Feb 29, 2024
//
#include <Arduino.h>
class UltrasonicHCSR04 
{
  public:
    UltrasonicHCSR04(uint8_t trigpin, uint8_t echopin);
    float measureDistanceInches();
	float measureDistanceCM() { return 2.54*measureDistanceInches(); }
    void setSpeedOfSoundFPS(float fps);
  private:
    uint8_t trigPin;
    uint8_t echoPin;
    // nominal speed of sound in the air at 20ºC (68ºF) = 
	// 343 m/s
    // 1125.33 ft/sec
    // .001350396 in/us
    float speedOfSound; // inches per microsecond 
};
