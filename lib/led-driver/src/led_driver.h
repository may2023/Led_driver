#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#include <stdint.h>
#include <common_header.h>

class Led{
    
    public:
        error_type_t init();
        error_type_t turn_on();
        error_type_t turn_off();
        error_type_t deinit();
        //constructor use to initalize the data member
        Led(uint8_t pin);
        bool activate;

    private:
        uint8_t led_pin;
        int status;
   
    
};    
#endif