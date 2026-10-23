# TMP102 Cheatsheet

## 1. I2C Device Addresses

The 7-bit I2C address depends on the ADD0 pin connection.

| ADD0 Connection | Address (Hex) | Address (Binary) |
|---|---|---|
| GND | `0x48` | `1001000` |
| V+ | `0x49` | `1001001` |
| SDA | `0x4A` | `1001010` |
| SCL | `0x4B` | `1001011` |

## 2. Register Map

| Register | Address | Description |
|---|---|---|
| Temperature | `0x00` | Stores temperature data |
| Configuration | `0x01` | Controls device operation |
| TLOW | `0x02` | Low-temperature threshold |
| THIGH | `0x03` | High-temperature threshold |

**Note:** The I2C device address selects the TMP102 device, while the register address selects an internal register.

## 3. Temperature Data Format

The temperature register is 16 bits wide.

| Mode | Temperature Bits | Data Shift | Mask | Sign Bit |
|---|---|---|---|---|
| Normal | 12 bits | 4 | `0x0FFF` | 11 |
| Extended | 13 bits | 3 | `0x1FFF` | 12 |

- Bit 0 of the raw temperature register indicates the data format:
  - `0`: Normal mode
  - `1`: Extended mode
- The temperature data is represented using two's complement.
- The temperature resolution is `0.0625°C` per count.

## 4. Temperature Conversion

### Step 1: Identify the mode

Check bit 0 of the raw temperature register.

### Step 2: Extract the temperature data

- Normal mode: shift right by 4 bits.
- Extended mode: shift right by 3 bits.

### Step 3: Interpret the signed value

Check the sign bit after shifting:

- Normal mode: bit 11.
- Extended mode: bit 12.

For a negative value, obtain its magnitude using two's complement.

### Step 4: Convert to Celsius

\[
T(°C) = \text{signed temperature count} \times 0.0625
\]

## 5. Useful Bit Operations

| Operation | Purpose |
|---|---|
| `reg >> n` | Shift data right by `n` bits |
| `reg & mask` | Extract selected bits |
| `~reg` | Invert all bits |
| `1U << n` | Generate a mask for bit `n` |

Example bit_mask macro:

```c
#define BIT_MASK(bit) (1U << (bit))
```

Usage:

```c
reg & BIT_MASK(TEMP_NORMAL_SIGN_BIT)
```

## 6. Conversion Test Vectors (Normal Mode)

| Raw Register | Expected Temperature |
|---|---:|
| `0x7FF0` | `127.9375°C` |
| `0x1900` | `25.0°C` |
| `0x0000` | `0.0°C` |
| `0xFFC0` | `-0.25°C` |
| `0xE700` | `-25.0°C` |
| `0xC900` | `-55.0°C` |
