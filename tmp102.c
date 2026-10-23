#include <stdint.h>
#include "tmp102.h"

/*
 * Convert the raw 16-bit temperature register value into degrees Celsius.
 * The temperature format depends on the operating mode indicated by bit 0.
 */
float tmp102_raw_to_celsius(uint16_t reg){

    /* Check bit 0 to determine whether the register uses extended mode. */
    if(reg&TEMP_EXTENDED_MODE){

        /* Extract the 13-bit temperature value in extended mode. */
        reg = reg>>TEMP_EXTENDED_DATA_SHIFT;

        /* Check whether the sign bit indicates a negative temperature. */
        if(reg&BIT_MASK(TEMP_EXTENDED_SIGN_BIT)){

            /* Convert the negative two's complement value to its magnitude. */
            reg = (~reg)&EXTENDED_MASK;
            reg +=TEMP_BIT_SET;

            /* Return the temperature as a negative Celsius value. */
            return reg*(-RESOLUTION);
        }
        else {
            /* Convert the positive temperature to Celsius. */
            return reg*(RESOLUTION);
        }
    }
    else{

        /* Extract the 12-bit temperature value in normal mode. */
        reg = reg>>TEMP_NORMAL_DATA_SHIFT;

        /* Check whether the sign bit indicates a negative temperature. */
        if(reg&BIT_MASK(TEMP_NORMAL_SIGN_BIT)){

            /* Convert the negative two's complement value to its magnitude. */
            reg = (~reg)&NORMAL_MASK;
            reg +=TEMP_BIT_SET;

            /* Return the temperature as a negative Celsius value. */
            return reg*(-RESOLUTION);
        }
        else {
            /* Convert the positive temperature to Celsius. */
            return reg*(RESOLUTION);
        }
    }
}