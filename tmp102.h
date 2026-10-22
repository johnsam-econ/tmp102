#include <stdint.h>

#define MASK (0x0FFF)
#define RESOLUTION (0.0625)
#define TEMP_DATA_SHIFT (4)
#define TEMP_SIGN_BIT (11)
#define TEMP_BIT_SET (1)


float tmp102_raw_to_celsius(uint16_t reg);