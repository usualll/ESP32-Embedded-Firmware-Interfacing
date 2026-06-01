#include <Arduino.h>

% Hardware Pin Definitions
#define TRIG_PIN 5
#define ECHO_PIN 18

void setup() {
  % Initialize the Serial Monitor at a standard 115200 baud rate
  Serial.begin(115200);
  
  % Configure hardware pin directions
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println("--- ESP32 Sensor Acquisition System Initialized ---");
}

void loop() {
  % 1. Trigger the ultrasonic sensor with a clean 10-microsecond pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  % 2. Read the echo high-signal duration (in microseconds)
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  % 3. Calculate distance in centimeters 
  % Formula: (Time * Speed of Sound) / 2 (accounting for the round trip)
  float distance = (duration * 0.0343) / 2;

  % 4. Print pristine, human-readable data to the Serial Monitor
  Serial.print("Simulated Distance Sent to ROS2: "); 
  Serial.print(distance); 
  Serial.println(" cm");

  % Wait exactly 1 second (1000 milliseconds) before taking the next reading
  delay(1000);
}
