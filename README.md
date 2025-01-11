# RFID Access Control System

This project is an RFID-based access control system using an Arduino, an MFRC522 RFID reader, and a servo motor to manage access. It grants access to authorized cards and denies it to others. Visual and sound feedback is provided via LEDs and a buzzer.

## Features
- Reads RFID cards/tags.
- Grants access to authorized cards by rotating a servo motor.
- Denies access to unauthorized cards with LED and buzzer feedback.
- Easy to customize for additional cards or actions.

## Components Required
- Arduino (e.g., Uno, Mega, Nano)
- MFRC522 RFID Module
- Servo Motor
- LEDs (Green and Red)
- Buzzer
- Connecting Wires
- Breadboard (optional)

## Circuit Diagram

- Connect the MFRC522 module to the Arduino:
  - **SDA** -> Pin 10
  - **SCK** -> Pin 13
  - **MOSI** -> Pin 11
  - **MISO** -> Pin 12
  - **RST** -> Pin 9
  - **VCC** -> 3.3V
  - **GND** -> GND

- Connect the servo motor:
  - Signal -> Pin 7
  - VCC -> 5V
  - GND -> GND

- Connect LEDs:
  - Green LED -> Pin 4
  - Red LED -> Pin 5

- Connect the buzzer:
  - Signal -> Pin 2

## Usage

1. Power on the Arduino.
2. Place an RFID card/tag near the reader.
3. The system will:
   - Grant access if the card's UID matches the pre-authorized UID.
   - Deny access if the card's UID does not match.
4. Monitor the serial output for debugging or UID capture.

## Customization

To add more authorized cards, modify this section in the code:
```cpp
if (content == "73DE3529") {
    // Add more UIDs by extending the condition or using an array.
}
```

You can add multiple authorized UIDs or load them from an external storage (like an EEPROM

## Contributing
Feel free to submit issues or pull requests to improve this project.

