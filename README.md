# TMP102 Temperature Conversion

A C project for converting raw temperature register data from the TMP102
digital temperature sensor into degrees Celsius.

## Features

- Supports normal and extended temperature data formats.
- Handles positive and negative temperatures using two's complement.
- Provides macros for TMP102 I2C device addresses and register addresses.
- Includes a bit-mask generation macro for bit manipulation.
- Provides test cases for validating temperature conversion.

## Temperature Conversion

The TMP102 temperature register stores temperature data in a 16-bit register.

| Operating Mode | Data Width | Data Shift | Resolution |
|---|---:|---:|---:|
| Normal | 12 bits | 4 bits | 0.0625°C |
| Extended | 13 bits | 3 bits | 0.0625°C |

The conversion function is declared as:

```c
float tmp102_raw_to_celsius(uint16_t reg);
```

It accepts a raw temperature register value and returns the corresponding
temperature in degrees Celsius.

## I2C Device Addresses

The TMP102 supports four 7-bit I2C addresses, selected by the ADD0 pin.

| ADD0 Connection | Address |
|---|---|
| GND | `0x48` |
| V+ | `0x49` |
| SDA | `0x4A` |
| SCL | `0x4B` |

These addresses identify the device on the I2C bus. They are distinct from
the internal register addresses.

## Register Map

| Register | Address | Description |
|---|---|---|
| Temperature | `0x00` | Temperature data |
| Configuration | `0x01` | Device configuration |
| TLOW | `0x02` | Low-temperature threshold |
| THIGH | `0x03` | High-temperature threshold |

## Build and Test

The project uses a Makefile to simplify compilation and testing.

```bash
make
```

Run the project's test target with:

```bash
make test
```

Remove generated build artifacts with:

```bash
make clean
```

Refer to the Makefile for the exact targets supported by your current
project configuration.

## Project Structure

```text
.
├── tmp102.h
├── tmp102.c
├── Makefile
├── cheatsheet.md
└── README.md
```

The structure above describes the expected main files; adjust it if your
actual project contains additional directories or files.

## Documentation

See [cheatsheet.md](cheatsheet.md) for a quick reference covering:

- I2C device addresses and register addresses
- Temperature data formats
- Bit manipulation
- Temperature conversion
- Normal-mode test vectors

## Hardware

This project can test the raw-register conversion logic without a physical
TMP102 sensor by supplying known register values to the conversion function.

Actual I2C communication and hardware behavior require an appropriate
sensor and I2C interface.

## License

Add the applicable license information here if the project will be
distributed or shared publicly.
