#include <Servo.h>

#define SENSOR_PIN A0 // Arduino pin connected to sound sensor's pin
#define SERVO_PIN 3   // Arduino pin connected to servo motor's pin

Servo servo;  // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastSoundState;     // the previous state of sound sensor
int currentSoundState;  // the current state of sound sensor

void setup() {
  Serial.begin(9600);          // initialize serial
  pinMode(SENSOR_PIN, INPUT);  // set arduino pin to input mode
  servo.attach(SERVO_PIN);     // attaches the servo on pin 9 to the servo object

  servo.write(angle);
  currentSoundState = digitalRead(SENSOR_PIN);
}

void loop() {
  lastSoundState = currentSoundState;           // save the last state
  currentSoundState = digitalRead(SENSOR_PIN);  // read new state

  if (lastSoundState == HIGH && currentSoundState == LOW) {  // state change: HIGH -> LOW
    Serial.println("The sound has been detected");

    // change angle of servo motor
    if (angle == 0)
      angle = 270;
    else if (angle == 270)
      angle = 0;

    // control servo motor arccoding to the angle
    servo.write(angle);
    delay(2000);
  }
}