/*
 * stepper.c
 *
 *  Created on: Jun 26, 2024
 *      Author: Work
 */

#include "stepper.h"

void stepMotor(uint8_t step){
	HAL_GPIO_WritePin(IN1_GPIO_PORT, IN1_PIN, HALF_STEP_SEQ[step][0]);
	HAL_GPIO_WritePin(IN2_GPIO_PORT, IN2_PIN, HALF_STEP_SEQ[step][1]);
	HAL_GPIO_WritePin(IN3_GPIO_PORT, IN3_PIN, HALF_STEP_SEQ[step][2]);
	HAL_GPIO_WritePin(IN4_GPIO_PORT, IN4_PIN, HALF_STEP_SEQ[step][3]);
}
void rotateStep(uint16_t steps, uint8_t direction){
	for(uint16_t i = 0; i < steps; ++i){
		uint8_t step;
		if(direction == DIR_CW){
			step = i % 8;
		}
		else if(direction == DIR_CCW){
			step = (8 - (i % 8)) % 8;	//반시계
		}
		stepMotor(step);

		delay_us(400);	//스텝간 딜레이
	}
}
void rotateDegree(uint16_t degree, uint8_t direction){
	uint16_t steps = (uint16_t)(((uint32_t)degree * STEP_PER_REVOLUTIN) / 360);

	rotateStep(steps, direction);
}
