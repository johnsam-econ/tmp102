#include <stdint.h>
#include "tmp102.h"

float tmp102_raw_to_celsius(uint16_t reg){
    if(reg&TEMP_EXTENDED_MODE){
        reg = reg>>TEMP_EXTENDED_DATA_SHIFT;
        if(reg&(TEMP_BIT_SET<<TEMP_EXTENDED_SIGN_BIT)){
            reg = (~reg)&EXTENDED_MASK;
            reg +=TEMP_BIT_SET;
            return reg*(-RESOLUTION);
        }
        else { return reg*(RESOLUTION);}
    }
    else{
        reg = reg>>TEMP_NORMAL_DATA_SHIFT;
        if(reg&(TEMP_BIT_SET<<TEMP_NORMAL_SIGN_BIT)){
            reg = (~reg)&NORMAL_MASK;
            reg +=TEMP_BIT_SET;
            return reg*(-RESOLUTION);
        }
        else { return reg*(RESOLUTION);}
    }
}