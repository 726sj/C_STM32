/*
 * led.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Work
 */

#include "led.h"

void updateLED(LED_CONTROL *led){
	uint32_t currTick = millis();		//HAL_GetTick() == millis()

	if(currTick - led -> lastTick >= led -> interval){
		//LED 상태를 변경 할꺼야
		if(led -> state == LED_OFF){
			HAL_GPIO_WritePin(led -> GPIOx, led -> GPIO_Pin, 1);	//LED 켜기
			led->state = LED_ON;
			led->lastTick = currTick;
		}
		else{
			HAL_GPIO_WritePin(led -> GPIOx, led -> GPIO_Pin, GPIO_PIN_RESET);
			led -> state = LED_OFF;
			led->lastTick = currTick;
		}
	}
}


