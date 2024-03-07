//--------------------------------------------------------
// Ultrasonic range finder sensor test
//
// Dean Gienger, Feb 29, 2024
//
// HC-SR04 ultrasonic range sensor
//
// 4 pins:
// VCC - 5V
// Trigger - input pulse to SR04 
// Output - output pulse from SR04 - width proportional to detected range
// GND - 0V
//
// Trigger - can accept 3.3V pulse from ESP32
// Output - 5V pulse must be reduced to 3.3 V for ESP32 input
//
// Credit: Rui Santos
//  Complete project details at https://RandomNerdTutorials.com/esp32-hc-sr04-ultrasonic-arduino/

#include "UltrasonicHCSR04.h"

const int trigPin = 5; // output
const int echoPin = 18; // input

UltrasonicHCSR04 distSensor(trigPin, echoPin);

void setup() 
{
  Serial.begin(115200); // Starts the serial communication
  Serial.println("\nHC-SR04 ultrasonic range sensor test\n");
}

void loop() 
{
  float distanceInch = distSensor.measureDistanceInches();
  Serial.println(distanceInch);
  delay(200);
}
