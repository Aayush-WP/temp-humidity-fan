# Adaptive Temperature & Humidity Controlled Laptop Cooling Pad

A DIY Arduino-based cooling pad that automatically adjusts fan speed based on ambient temperature and humidity using a DHT11 sensor. The project demonstrates real-time environment sensing and PWM-based actuator control — ideal for laptop thermal management or small IoT control systems.

## 🔧 Project Objective

To develop a smart cooling system that dynamically adjusts fan speed to enhance cooling efficiency when needed and conserve energy otherwise.

## 📚 Core Concepts

- **Temperature & Humidity Sensing**: Using the DHT11 sensor to monitor ambient environmental conditions.
- **PWM Fan Speed Control**: Modulating fan speed via PWM signals based on temperature thresholds.
- **Control Logic**: A simple feedback-based control system implemented on an Arduino Uno.
- **Visual Feedback**: Live temperature and fan status displayed on a 16x2 I2C LCD.

## 🛠️ Hardware Used

- Arduino Uno (ATmega328P)
- 2 x 12V Brushless DC Fans (2-wire)
- DHT11 Temperature and Humidity Sensor
- I2C 16x2 LCD Display
- 2N2222 NPN Transistor
- 1K Ohm Resistor
- Breadboard and jumper wires

## 💻 Software & Libraries

- Arduino IDE
- `DHT11.h` for sensor interfacing
- `Wire.h` and `LiquidCrystal_I2C.h` for I2C LCD display

## 🧠 System Overview

The Arduino reads temperature and humidity from the DHT11 sensor every 2 seconds. Based on temperature thresholds, it adjusts the speed of two cooling fans using PWM signals. The LCD displays the current temperature and fan status in real-time.

### 🔁 Fan Control Logic

| Temperature Range | Fan Speed     | Status            |
|-------------------|----------------|--------------------|
| < 20°C            | 0%             | Fan OFF            |
| 20°C - 24°C       | ~20% (PWM 51)  | Low Cooling        |
| 24°C - 26°C       | ~40% (PWM 102) | Moderate Cooling   |
| 26°C - 28°C       | ~60% (PWM 153) | Efficient Cooling  |
| 28°C - 30°C       | ~80% (PWM 204) | High Cooling       |
| > 30°C            | 100% (PWM 255) | Max Cooling        |

## 🖼️ Project Images
![Circuit_Diagram](https://github.com/user-attachments/assets/2627b02c-6fa9-4060-ae3a-addf00250424)
![Circuit_Diagram](https://github.com/user-attachments/assets/2843c5bf-654d-401b-babe-4dc801b7e4f3)



https://github.com/user-attachments/assets/2a96c803-cfcc-4e78-aa1a-d85267187380


