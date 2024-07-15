/*
 * hw.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Work
 */

#include "hw.h"

void delay(uint32_t ms){
	HAL_Delay(ms);
}

uint32_t millis(){
	return HAL_GetTick();
}
