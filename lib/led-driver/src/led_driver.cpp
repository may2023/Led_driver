#include <iostream>
#include <led_driver.h>
#include <Arduino.h>

#define MAX_PIN 23


Led::Led(uint8_t pin):led_pin(pin){

}


error_type_t Led::init(){
    if (led_pin == 0||led_pin>MAX_PIN  )return error_type_t::ERROR_INVALID_PIN_NUMBER;
    pinMode(led_pin,OUTPUT);
    activate = true;
    return error_type_t::ERROR_OK;   
}

error_type_t Led::turn_on(){
    if (!activate)return error_type_t::ERROR_INVALIDE_STATE;
    status = HIGH;
    digitalWrite(led_pin,status);
    return error_type_t::ERROR_OK;   
}

error_type_t Led::turn_off(){
    if (!activate)return error_type_t::ERROR_INVALIDE_STATE;
    status= LOW;
    digitalWrite(led_pin,status);
    return error_type_t::ERROR_OK;
    
}

error_type_t Led::deinit(){
    activate = false;
    return error_type_t::ERROR_OK;
}


