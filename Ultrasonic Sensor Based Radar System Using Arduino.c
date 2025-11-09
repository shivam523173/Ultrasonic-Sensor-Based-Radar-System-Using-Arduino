// Ultrasonic Sensor–Based Radar System Using Arduino

#include <Servo.h>  // Include the Servo library

// Ultrasonic Sensor pins
const int trigPin = 10;
const int echoPin = 11;

// Servo
const int servoPin = 12;
Servo myServo;

// Sweep limits
const int SERVO_MIN = 15;   // degrees
const int SERVO_MAX = 165;  // degrees

// Globals
unsigned long duration;
int distanceCm;

// Forward declaration
int calculateDistance();

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  myServo.attach(servoPin);
  myServo.write(SERVO_MIN);
  delay(300);
}

void loop() {
  // Sweep forward
  for (int angle = SERVO_MIN; angle <= SERVO_MAX; angle++) {
    myServo.write(angle);
    delay(30);

    distanceCm = calculateDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distanceCm);
    Serial.print(".");
  }

  // Sweep backward
  for (int angle = SERVO_MAX; angle >= SERVO_MIN; angle--) {
    myServo.write(angle);
    delay(30);

    distanceCm = calculateDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distanceCm);
    Serial.print(".");
  }
}

// Measure distance in centimeters
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000UL);

  if (duration == 0) return -1;  // Out of range

  long cm = (duration * 34L) / 2000L;

  if (cm < 0) cm = 0;
  if (cm > 400) cm = 400;

  return (int)cm;
}
