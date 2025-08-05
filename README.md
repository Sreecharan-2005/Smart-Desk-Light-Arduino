# Smart Desk Light (Arduino Project)

This project simulates a smart desk lamp that:

- Automatically adjusts brightness based on surrounding light using an **LDR**
- Lets the user override with a **manual mode** using a **button**
- Uses a **potentiometer** to set brightness manually
- Displays live sensor data using the **Serial Monitor**
- Uses `millis()` for non-blocking data printing

---

## 🔧 Components Used
- Arduino Uno
- LED
- LDR (Light Dependent Resistor)
- 10kΩ Resistor (for LDR voltage divider)
- Potentiometer (connected to A1)
- Pushbutton (connected to D2) + 10kΩ pull-down resistor
- Breadboard + Wires

---

## 🔗 Tinkercad Circuit

https://www.tinkercad.com/things/0cboD31RAL0-day-14

---

## 📄 Code Features
- PWM brightness control via `analogWrite()`
- Mode toggling using button + debounce logic
- Live data print using `Serial.print()` and `millis()` timing

---

## 🧠 Author Notes
This is part of my 14-day Arduino learning challenge.  
Capstone project built entirely in Tinkercad.
