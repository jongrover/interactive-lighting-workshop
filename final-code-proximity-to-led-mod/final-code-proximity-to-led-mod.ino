/* Title: Proximity to RGB LED version 1.0
 * Author: Jonathan Grover <hello@jonathangrover.com>
 * Date: 6/16/2021
 * Hardware wiring:
 * SHARP IR Proximity Sensor GP2Y0A41SK0F (4-30CM): yellow to A0, black to GND, red to 5V
 * Grove – Chainable RGB LED: yellow to pin 7, white to pin 8, red to 5V, black to GND
 */

#include <ChainableLED.h>
#include <Smoothed.h>

#define NUM_LEDS 2

Smoothed <float> mySensor;
ChainableLED leds(7, 8, NUM_LEDS);

float hue = 0.0;
float saturation = 1.0;
float brightness = 0.0;
float min_sense_val = 20.0;
float max_sense_val = 575.0;
float sense_threshold = 40.0;
float min_brightness = 0.0;
float max_brightness = 1.0;
float fade_amount = 0.05;
int fade_time = 50;
int sensor_pin = A0;
boolean up = true;

void setup() {
  Serial.begin(9600);
  mySensor.begin(SMOOTHED_AVERAGE, 20);
  mySensor.clear();
}

void loop() {
  
  float value = analogRead(sensor_pin);
  mySensor.add(value);
  float average = mySensor.get();
  if (average < sense_threshold) {
    for (byte i=0; i<NUM_LEDS; i++) {
      leds.setColorRGB(i, 255, 0, 0);
    }
  } else {
    for (byte i=0; i<NUM_LEDS; i++) {
      leds.setColorRGB(i, 0, 255, 0);
    }
  }
  Serial.println(brightness);
    
  if (up) {
    hue+= fade_amount;
  } else {
    hue-= fade_amount;
  }
  if (hue>=1.0 && up) {
    up = false;
  } else if (hue<=0.0 && !up) {
    up = true;
  }
  
  delay(fade_time);
}
