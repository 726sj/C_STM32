/*
 * ap.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Work
 */

#include "ap.h"
#include "led.h"

void apInit(void){

}

void apMain(void){
	LED_CONTROL led1 = {GPIOC, GPIO_PIN_9,200,LED_OFF,0};
	LED_CONTROL led2 = {GPIOB, GPIO_PIN_8,1000,LED_OFF,0};
	while(1){
		updateLED(&led1);
		updateLED(&led2);
	}
}
