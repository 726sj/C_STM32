#include "Ultrasonic.h"

#define TRIG_PORT	GPIOC
#define TRIG_PIN	GPIO_PIN_11

uint32_t IC_L_Value1 = 0;	//LEFT L
uint32_t IC_L_Value2 = 0;

uint32_t IC_R_Value1 = 0;	//RIGHT R
uint32_t IC_R_Value2 = 0;

uint32_t IC_F_Value1 = 0;	//FRONT F
uint32_t IC_F_Value2 = 0;

uint32_t echoTime_L = 0;
uint32_t echoTime_R = 0;
uint32_t echoTime_F = 0;

uint16_t captureFlag_L = 0;
uint16_t captureFlag_R = 0;
uint16_t captureFlag_F = 0;

uint16_t distance_L = 0;
uint16_t distance_R = 0;
uint16_t distance_F = 0;

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM1){
			if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1){
				if(captureFlag_F == 0){
					IC_F_Value1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
					captureFlag_F = 1;
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
				}
				else if(captureFlag_F == 1){
					IC_F_Value2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
					__HAL_TIM_SET_COUNTER(htim, 0);
					if(IC_F_Value2 > IC_F_Value1){
						echoTime_F = IC_F_Value2 - IC_F_Value1;
					}
					else if(IC_F_Value1 > IC_F_Value2){
						echoTime_F = (0xffffffff - IC_F_Value1) + IC_F_Value2;
					}
					distance_F = echoTime_F / 58;
					captureFlag_F = 0;
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
					__HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
				}
			}
		}
	if(htim->Instance == TIM4){
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1){
			if(captureFlag_L == 0){
				IC_L_Value1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
				captureFlag_L = 1;
				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
			}
			else if(captureFlag_L == 1){
				IC_L_Value2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
				__HAL_TIM_SET_COUNTER(htim, 0);
				if(IC_L_Value2 > IC_L_Value1){
					echoTime_L = IC_L_Value2 - IC_L_Value1;
				}
				else if(IC_L_Value1 > IC_L_Value2){
					echoTime_L = (0xffffffff - IC_L_Value1) + IC_L_Value2;
				}
				distance_L = echoTime_L / 58;
				captureFlag_L = 0;
				__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
				__HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
			}
		}
	}
	if(htim->Instance == TIM5){
			if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1){
				if(captureFlag_R == 0){
					IC_R_Value1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
					captureFlag_R = 1;
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
				}
				else if(captureFlag_R == 1){
					IC_R_Value2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
					__HAL_TIM_SET_COUNTER(htim, 0);
					if(IC_R_Value2 > IC_R_Value1){
						echoTime_R = IC_R_Value2 - IC_R_Value1;
					}
					else if(IC_R_Value1 > IC_R_Value2){
						echoTime_R = (0xffffffff - IC_R_Value1) + IC_R_Value2;
					}
					distance_R = echoTime_R / 58;
					captureFlag_R = 0;
					__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
					__HAL_TIM_DISABLE_IT(htim, TIM_IT_CC1);
				}
			}
		}

}

void HC_SR04_1(void){
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
}

void HC_SR04_2(void){
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim4, TIM_IT_CC1);
}

void HC_SR04_3(void){
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE_IT(&htim5, TIM_IT_CC1);
}