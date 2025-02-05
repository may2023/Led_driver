#include <Arduino.h>
#include <led_driver.h>
#include <common_header.h>
// put function declarations here:

Led led1(19);
error_type_t err;
void setup()
{
  // Your setup code here
  Serial.begin(9600);
  err = led1.init();
  if(err != error_type_t::ERROR_OK){
    exit(1);
  }

}

void loop()
{
  // put your main code here, to run repeatedly:
  err= led1.turn_on();
  if (err!= error_type_t::ERROR_OK)
  {
    exit(1);
  }
  delay(1000);
  err = led1.turn_off();
   if (err!= error_type_t::ERROR_OK)
  {
    exit(1);
  }
  
  delay(2000);
}
