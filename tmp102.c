#include <stdint.h>
#include "tmp102.h"

float tmp102_raw_to_celsius(uint16_t reg){
    reg = reg>>TEMP_DATA_SHIFT;
    if(reg&(TEMP_BIT_SET<<TEMP_SIGN_BIT)){
        reg = (~reg)&MASK;
        reg +=TEMP_BIT_SET;
        return reg*(-RESOLUTION);
    }
    else { return reg*(RESOLUTION);}
}