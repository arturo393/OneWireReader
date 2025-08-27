# Changelog

All notable changes to the OneWireReader project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Comprehensive README.md with installation, wiring, and usage instructions
- CONTRIBUTING.md with development guidelines and contribution workflow
- MIT LICENSE for open source distribution
- This CHANGELOG.md to track project evolution

### Changed
- Enhanced project documentation and structure

## [1.0.3] - 2025-06-09

### Changed
- Improved hex formatting using `%02x` for consistent 2-digit output
- Added unwanted VS Code extension recommendations to prevent conflicts

### Fixed
- Removed problematic zero-padding code that was causing formatting issues
- Better handling of single-digit hex values

### Technical
- Added Keyboard library dependency to platformio.ini
- Updated VS Code extensions.json with unwanted recommendations

## [1.0.2] - 2020-08-31

### Fixed
- **Breaking Change**: Fixed byte order by reversing array indexing (`addr[8-i]` instead of `addr[i]`)
- Corrected ROM address output to display in proper order

### Technical
- Changed loop indexing from `i = 0; i < 8` to `i = 1; i <= 8` for array reversal

## [1.0.1] - 2020-08-07

### Added
- Improved zero handling in hex output
- Added delay between device scans (500ms) for better performance

### Fixed
- Better formatting for addresses containing zero bytes
- Conditional zero padding for single-digit hex values

### Changed
- Modified hex formatting logic to handle edge cases
- Added proper spacing in Serial output

## [1.0.0] - 2020-08-07

### Added
- Initial OneWire RFID reader implementation
- Arduino framework support using PlatformIO
- SparkFun Pro Micro 16MHz board configuration
- OneWire library integration for device communication
- USB HID Keyboard emulation for automatic ID typing
- Serial console output for debugging
- Continuous device scanning with proper reset handling
- VS Code development environment configuration
- Travis CI configuration template (commented out)
- Standard PlatformIO project structure (include/, lib/, src/, test/ directories)

### Technical Features
- OneWire communication on configurable pin (default: pin 10)
- 4.7kΩ pull-up resistor requirement documented
- Hex output formatting for device ROM addresses
- Proper device search and reset cycle implementation
- USB HID integration for keyboard output
- Serial debugging at 9600 baud rate

### Development Infrastructure
- PlatformIO project configuration
- VS Code workspace setup with PlatformIO IDE extension
- Git repository initialization with appropriate .gitignore
- Project documentation structure

---

## Version Numbering

This project follows semantic versioning:
- **MAJOR** version for incompatible API changes
- **MINOR** version for backwards-compatible functionality additions
- **PATCH** version for backwards-compatible bug fixes

## Release Notes

### Hardware Compatibility
- **Supported**: SparkFun Pro Micro 16MHz, Arduino Leonardo, Arduino Micro
- **Required**: OneWire devices (DS1990A iButtons, etc.)
- **Dependencies**: 4.7kΩ pull-up resistor on OneWire data line

### Software Dependencies
- **PlatformIO**: Recommended build system
- **Arduino Framework**: Core platform
- **OneWire Library**: Device communication
- **Keyboard Library**: USB HID functionality

### Known Issues
- Some USB HID compatibility issues on older systems
- Requires Leonardo-compatible board for keyboard functionality
- OneWire timing sensitive to pull-up resistor value

### Migration Notes

#### From v1.0.2 to v1.0.3
- No breaking changes
- Improved output formatting automatically applied
- Remove any manual zero-padding code if customized

#### From v1.0.1 to v1.0.2
- **Breaking Change**: ROM address byte order changed
- Update any code that depends on specific byte positions
- Verify device ID databases use correct byte order

#### From v1.0.0 to v1.0.1
- No breaking changes
- Scan timing improved with added delays
- Better zero handling in output formatting