# OneWireReader

A simple Arduino firmware project that reads OneWire device IDs (such as Dallas DS1990A iButtons or RFID cards) and outputs them both to the serial console and as keyboard input to the host computer.

## Overview

This project transforms an Arduino-compatible board into a OneWire RFID reader that can:
- Read ROM IDs from OneWire devices like DS1990A iButtons
- Display the device ID in hexadecimal format via serial console
- Automatically type the device ID on the computer as if from a keyboard
- Continuously scan for new devices with proper reset handling

Perfect for access control systems, attendance tracking, or any application requiring OneWire device identification.

## Hardware Requirements

### Required Components
- **SparkFun Pro Micro 16MHz** (or compatible Arduino Leonardo-style board with USB HID capability)
- **OneWire device reader circuit** (DS1990A holder, etc.)
- **4.7kΩ resistor** (pull-up resistor for OneWire bus)
- **Jumper wires** for connections

### Wiring Diagram

```
Arduino Pro Micro          OneWire Reader
     Pin 10  ────────────── Data line (with 4.7kΩ pull-up to VCC)
      VCC   ────────────── VCC (5V or 3.3V)
      GND   ────────────── GND
```

**Important:** The OneWire data line requires a 4.7kΩ pull-up resistor connected between the data line and VCC.

## Software Requirements

### Development Environment
- [PlatformIO](https://platformio.org/) (recommended) or Arduino IDE
- USB cable for programming and power

### Dependencies
The following libraries are automatically installed by PlatformIO:
- `OneWire` - For OneWire communication protocol
- `Keyboard` - For USB HID keyboard emulation

## Installation & Setup

### Method 1: PlatformIO (Recommended)

1. **Install PlatformIO**
   ```bash
   pip install platformio
   ```

2. **Clone the repository**
   ```bash
   git clone https://github.com/arturo393/OneWireReader.git
   cd OneWireReader
   ```

3. **Build and upload**
   ```bash
   platformio run --target upload
   ```

### Method 2: Arduino IDE

1. **Install required libraries**
   - Open Arduino IDE
   - Go to Tools → Manage Libraries
   - Install "OneWire" by Jim Studt

2. **Select board**
   - Board: "Arduino Leonardo" or "SparkFun Pro Micro"
   - Port: Select your device's COM port

3. **Upload the code**
   - Open `src/main.cpp` in Arduino IDE
   - Click Upload

## Usage

### Basic Operation

1. **Connect hardware** according to the wiring diagram
2. **Upload firmware** to your Arduino board
3. **Open serial monitor** (optional, for debugging)
   - Baud rate: 9600
4. **Present OneWire device** to the reader

### Output Format

When a OneWire device is detected:
- **Serial console**: `ROM = 01234567890ABCEF`
- **Keyboard output**: The same hex ID is typed automatically, followed by Enter

The device continuously scans for new OneWire devices with a 250ms delay between scans.

### Example Output

```
ROM = 01a2b3c4d5e6f708
ROM = 09f8e7d6c5b4a321
No more addresses.

ROM = 01a2b3c4d5e6f708
```

## Troubleshooting

### Common Issues

**No devices detected**
- Verify 4.7kΩ pull-up resistor is connected
- Check wiring connections
- Ensure OneWire device is making proper contact

**Keyboard input not working**
- Verify you're using a Leonardo-compatible board (Pro Micro, Leonardo, Micro)
- Check that the Keyboard library is properly installed
- Some systems may require driver installation for HID devices

**Incorrect output format**
- Recent firmware uses `%02x` formatting for consistent 2-digit hex output
- Older versions may show inconsistent formatting

**Build errors**
- Ensure all dependencies are installed
- Check that the correct board is selected
- Verify PlatformIO or Arduino IDE is up to date

## Configuration

### Customizing Pin Assignment

To change the OneWire pin from the default pin 10:

```cpp
OneWire ds(YOUR_PIN_NUMBER);  // Change 10 to your desired pin
```

### Adjusting Scan Timing

Modify the delay in the main loop:

```cpp
delay(250);  // Change to your preferred scan interval (milliseconds)
```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Built on the Arduino platform
- Uses the OneWire library by Jim Studt
- Developed for SparkFun Pro Micro hardware
- Inspired by OneWire device identification needs

## Version History

See [CHANGELOG.md](CHANGELOG.md) for a detailed history of changes and improvements.
