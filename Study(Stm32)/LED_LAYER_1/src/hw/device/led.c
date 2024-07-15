/*
 * led.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Work
 */

#include "led.h"

LED_TBL led_arr[8]=
   {
      {GPIOC, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},
      {GPIOB, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},
      {GPIOB, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},
      {GPIOA, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},
      {GPIOA, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
      {GPIOA, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
      {GPIOB, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
      {GPIOC, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET}
   };

void ledOn(uint8_t ch)
{
   HAL_GPIO_WritePin(led_arr[ch].GPIOx, led_arr[ch].GPIO_Pin, led_arr[ch].On_State);
}

void ledOff(uint8_t ch)
{
   HAL_GPIO_WritePin(led_arr[ch].GPIOx, led_arr[ch].GPIO_Pin, led_arr[ch].Off_State);
}

void ledToggle(uint8_t ch)
{
   HAL_GPIO_TogglePin(led_arr[ch].GPIOx, led_arr[ch].GPIO_Pin);
}
void ledRightShift(uint8_t delay_value){
	for(uint8_t i = 0; i < 7; i++){
		ledOn(i);
		delay(delay_value);
		ledOff(i);
	}
}

void ledLeftShift(uint8_t delay_value){
	for(uint8_t i = 7; i > 0; i--){
		ledOn(i);
		delay(delay_value);
		ledOff(i);
	}
}
