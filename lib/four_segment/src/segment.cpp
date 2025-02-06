#include <iostream>
#include<segment.h>
#include<Arduino.h>


Segment::Segment(uint8_t pins[4]){
    led_pins= (uint8_t*)malloc(4* sizeof(uint8_t));
    for (uint8_t i = 0; i < 4; i++)
    {
        led_pins[i] = pins[i];
    }
    

}

 error_type_t Segment::led_init(){
    if (led_pins == 0)return error_type_t::ERROR_INVALID_PIN_NUMBER;
    for (uint8_t i = 0; i < 4; i++)
    {
        pinMode(led_pins[i],OUTPUT);
    }
    activate = true;
    return error_type_t::ERROR_OK;

 }

 error_type_t Segment::blink(){
    if (!activate)return error_type_t::ERROR_INVALIDE_STATE;
    for (uint8_t i = 0; i < 4; i++)
    {
        digitalWrite(led_pins[i], HIGH);
        delay(1000);
        digitalWrite(led_pins[i],LOW);
        delay(1000);

    }
    return error_type_t::ERROR_OK;  
 }

 error_type_t Segment::led_deinit(){
    activate = false;
    return error_type_t::ERROR_OK;
 }