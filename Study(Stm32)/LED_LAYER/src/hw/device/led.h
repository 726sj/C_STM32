/*
 * led.h
 *
 *  Created on: Jun 17, 2024
 *      Author: Work
 */

#ifndef HW_DEVICE_LED_H_
#define HW_DEVICE_LED_H_

#include "hw.h"

//LED 상태를 정의하는 열거형
typedef enum{
	LED_OFF,	//0
	LED_ON		//1
}LED_STATE;

typedef struct{
	GPIO_TypeDef	*GPIOx;		//LED가 연결된 GPIO포트
	uint16_t		GPIO_Pin;	//LED가 연결된 핀 번호
	uint32_t		interval;	//LED가 깜빡이는 시간(delay함수가 32비트)
	LED_STATE		state;		//LED의 현재 상태
	uint32_t		lastTick;	//LED가 마지막으로 변경된 시간 저장
}LED_CONTROL;

void updateLED(LED_CONTROL *led);
//LED상태를 업데이트 하는 함수

#endif /* HW_DEVICE_LED_H_ */
