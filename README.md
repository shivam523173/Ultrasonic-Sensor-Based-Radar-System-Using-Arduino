# Ultrasonic Sensor Based Radar System Using Arduino

This project simulates a radar scanning system using an ultrasonic sensor and a servo motor with Arduino. The servo rotates the sensor across a range of angles, while the ultrasonic module measures the distance to any object in its path. The distance and angle data are sent to the Serial Monitor, which can be visualized as a radar display using Processing or other visualization tools.

---

## 🎯 Features
- Scans environment across a set angle range
- Measures distance to objects using ultrasonic sensing
- Sends angle and distance data to Serial Monitor
- Can be visualized as a radar interface on a computer

---

## 🛠️ Components Used
| Component | Quantity |
|----------|----------|
| Arduino Uno / Nano / Mega | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| SG90 / MG90S Servo Motor | 1 |
| Jumper Wires | As needed |
| Breadboard | 1 |
| USB Cable | 1 |

---

## 🔧 Circuit Connections
| Ultrasonic Sensor | Arduino Pin |
|------------------|-------------|
| VCC              | 5V          |
| GND              | GND         |
| Trig             | 10          |
| Echo             | 11          |

| Servo Motor | Arduino Pin |
|-------------|-------------|
| Signal      | 12          |
| VCC         | 5V          |
| GND         | GND         |

---

## 💻 Output Format (Serial Monitor)
