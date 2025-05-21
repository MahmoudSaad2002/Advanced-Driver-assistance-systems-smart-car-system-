# 🚗 Smart Car Control System - Final AVR Project

This project is the final training project developed as part of the ITI Embedded Systems course. It simulates a smart automotive system built using AVR microcontrollers. The system is divided into two main ECUs:

- **Security ECU**
- **Control ECU**

## 🔐 Security ECU

The Security ECU handles system access and verification through a keypad-based password system.

### Features:

- Uses a keypad to enter a 4-digit password.
- Compares entered password to stored values in EEPROM (`1`, `2`, `3`, `4`).
- Feedback:
  - ✅ Correct password: Green LED turns ON for 700ms, then servo rotates to +90°, returns after 1s.
  - ❌ Incorrect password: Red LED blinks for 700ms.
- Sends the character `'A'` through UART to the Control ECU upon correct password.
- Uses **Timer0 in overflow mode** for timing control.

## 🧠 Control ECU

The Control ECU activates and manages all car subsystems after receiving permission from the Security ECU.

### Inputs:

- 3 Push buttons:
  - Button 1 → SL (Speed Limiter)
  - Button 2 → Gearbox state (D, N, P, R)
  - Button 3 → CCS (Cruise Control)

### Subsystems:

1. **🚨 Brake Assistant System (BAS):**
   - Enabled only if gearbox is in 'D'.
   - Reads distance using an ultrasonic sensor:
     - > 10 cm: BAS OFF
     - 5–10 cm: BAS LED toggles every 100 ms
     - ≤ 5 cm: BAS ON
   - LCD displays: `BAS: ON` or `BAS: OFF`

2. **⏩ Speed Limiter (SL):**
   - Toggle with SL button (only in 'D' mode).
   - LED and LCD reflect current status.

3. **🛣️ Cruise Control System (CCS):**
   - Toggle with CCS button (only in 'D' mode).
   - Deactivates if gas potentiometer is touched.
   - LED and LCD reflect current status.

4. **📏 Kilometer Counter:**
   - Increments depending on gas potentiometer level.
   - Displayed on LCD.

5. **👁️‍🗨️ Drive Monitoring System:**
   - Active only in 'D'.
   - Monitors user activity via **Timer2 overflow**:
     - If no input for 5s → buzzer toggles every 100 ms.

## 📦 Project Structure


## 🛠 Technologies Used

- **AVR Microcontrollers**
- **C Language**
- **Atmel Studio / AVR Studio**
- EEPROM, Timers, UART, Servo Motor, LEDs, LCD, Keypad, Buzzer


**Under the guidance of:**
- Eng. Mohamed Ramadan  
- Eng. Ahmed Samy

## 🧪 How to Run

1. Open `Project_avr.pdsprj` in AVR Studio.
2. Build the project to generate `.hex` file.
3. Flash the `.hex` file to your microcontroller using `AVRDUDE` or equivalent.
4. Connect the hardware (Keypad, Servo, LCD, Sensors) as per design.

## 📃 License

This project is for academic and learning purposes. You are free to modify or expand upon it.
