#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_

#include "delay_us.h"
#include "gpio.h"

extern uint16_t distance_L;
extern uint16_t distance_R;
extern uint16_t distance_F;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HC_SR04_1(void);
void HC_SR04_2(void);
void HC_SR04_3(void);

#endif /* INC_ULTRASONIC_H_ */