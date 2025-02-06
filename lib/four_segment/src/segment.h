#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include <common_header.h>
#include <stdint.h>

class Segment{
    private:
        uint8_t* led_pins;
        bool activate;

    public:
        
        error_type_t blink();
        error_type_t led_init();
        error_type_t led_deinit();
        //constructor use to initalize the data member
        Segment(uint8_t pins[4]);
        ~Segment(){
            delete(led_pins);
        }


};
#endif