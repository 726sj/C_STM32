/*
 * delay_us.c
 *
 *  Created on: Jun 14, 2024
 *      Author: Work
 */

#include "delay_us.h"

void delay_us(uint16_t us){
	__HAL_TIM_SET_COUNTER(&htim10, 0);
	while((__HAL_TIM_GET_COUNTER(&htim10)) < us);
}
