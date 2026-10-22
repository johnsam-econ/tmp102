#include <stdint.h>

#define NORMAL_MASK                 (0x0FFF)
#define EXTENDED_MASK               (0x1FFF)
#define RESOLUTION                  (0.0625f)
#define TEMP_NORMAL_DATA_SHIFT      (4)
#define TEMP_EXTENDED_DATA_SHIFT    (3)
#define TEMP_NORMAL_SIGN_BIT        (11)
#define TEMP_EXTENDED_SIGN_BIT      (12)
#define TEMP_BIT_SET                (1)
#define TEMP_BIT_CLEAR              (0)
#define TEMP_NORMAL_MODE            (0)
#define TEMP_EXTENDED_MODE          (1)


float tmp102_raw_to_celsius(uint16_t reg);