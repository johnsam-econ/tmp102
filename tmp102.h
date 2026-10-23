#include <stdint.h>

/* Masks for extracting temperature data in each operating mode */
#define NORMAL_MASK                 (0x0FFF)  // 12-bit temperature data mask
#define EXTENDED_MASK               (0x1FFF)  // 13-bit temperature data mask

/* Temperature conversion resolution in degrees Celsius per bit */
#define RESOLUTION                  (0.0625f)

/* Number of right shifts needed to extract temperature data */
#define TEMP_NORMAL_DATA_SHIFT      (4)       // Normal mode: bits 15–4
#define TEMP_EXTENDED_DATA_SHIFT    (3)       // Extended mode: bits 15–3

/* Sign-bit positions after shifting the temperature data */
#define TEMP_NORMAL_SIGN_BIT        (11)      // Normal mode: bit 11
#define TEMP_EXTENDED_SIGN_BIT      (12)      // Extended mode: bit 12

/* Values representing a set or cleared bit */
#define TEMP_BIT_SET                (1)
#define TEMP_BIT_CLEAR              (0)

/* Temperature register operating-mode indicators */
#define TEMP_NORMAL_MODE            (0)
#define TEMP_EXTENDED_MODE          (1)

/* TMP102 internal register addresses */
#define TMP102_REG_TEMP              (0x00)   // Temperature register
#define TMP102_REG_CONFIG            (0x01)   // Configuration register
#define TMP102_REG_TLOW              (0x02)   // Low-temperature threshold register
#define TMP102_REG_THIGH             (0x03)   // High-temperature threshold register

/* 7-bit I2C device addresses based on the ADD0 pin connection */
#define TMP102_ADDR_A0_GND           (0x48)   // ADD0 connected to GND
#define TMP102_ADDR_A0_VPLUS         (0x49)   // ADD0 connected to V+
#define TMP102_ADDR_A0_SDA           (0x4A)   // ADD0 connected to SDA
#define TMP102_ADDR_A0_SCL           (0x4B)   // ADD0 connected to SCL

/* Convert a raw 16-bit temperature register value to degrees Celsius */
float tmp102_raw_to_celsius(uint16_t reg);