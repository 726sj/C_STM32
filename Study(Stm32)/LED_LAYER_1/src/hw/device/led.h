/*
 * led.h
 *
 *  Created on: Jun 17, 2024
 *      Author: Work
 */

#ifndef DEVICE_LED_H_
#define DEVICE_LED_H_

#include "hw.h"

typedef struct{
   GPIO_TypeDef   *GPIOx; // port
   uint16_t      GPIO_Pin; // pin number
   GPIO_PinState   On_State;
   GPIO_PinState    Off_State;
}LED_TBL; // led_table

void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);

void ledRightShift(uint8_t ch);
void ledLeftShift(uint8_t ch);

#endif /* DEVICE_LED_H_ */
