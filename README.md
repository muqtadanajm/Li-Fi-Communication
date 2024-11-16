# Li-Fi Communication Project

## Project Description
The Li-Fi Communication Project aims to transmit data through light using Li-Fi technology. Data is sent via an LED and received using an LDR sensor. The project displays specific messages on an LCD screen upon receiving the data.

---

## Components Used
### Hardware:
- Arduino UNO board
- Keypad (4x4)
- LED
- LDR sensor
- LCD screen with I2C interface
- 18650 batteries with holder
- Resistors and connecting wires

### Software:
- Arduino IDE
- Libraries:
  - [Keypad](https://github.com/Chris--A/Keypad)
  - [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)

---

## How It Works
### Transmitter:
- A Keypad is used to select a specific message.
- Messages are transmitted using an LED via Li-Fi.

### Receiver:
- An LDR sensor is used to receive the data.
- The received data is decoded and displayed on an LCD screen.

---

## Circuit Diagrams
### Transmitter Circuit:
![Li-Fi Transmitter](./li-fi%20transmitter.png)

### Receiver Circuit:
![Li-Fi Receiver](./li-fi%20resever.png)

---

## How to Run
1. **Setup**:
   - Connect the transmitter circuit as shown in the diagram.
   - Similarly, connect the receiver circuit.

2. **Upload Code**:
   - Use Arduino IDE to upload the transmitter and receiver code to the respective Arduino boards.

3. **Operation**:
   - Press a button on the Keypad to send a predefined message.
   - The receiver decodes the message and displays it on the LCD.

---

## Future Improvements
- Adding error detection and correction for better reliability.
- Extending the range of the communication system.
- Implementing multiple message types and languages.

---

## License
The code is prohibited from being used for commercial purposes or sold, as it is open source.

## Created By
Created by: [Muqtada Najm](https://github.com/muqtadanajm)