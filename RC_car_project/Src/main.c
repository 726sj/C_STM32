#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

uint8_t rxData[1];

void SystemClock_Config(void);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart ->Instance == USART6){
		HAL_UART_Receive_IT(&huart6, rxData, sizeof(rxData));
		HAL_UART_Transmit_IT(&huart6, rxData, sizeof(rxData));
	}
}

int main(void)
{
    uint8_t dutyValue = 0;

    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_TIM3_Init();
    MX_USART6_UART_Init();
    MX_TIM2_Init();

    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

    HAL_UART_Receive_IT(&huart6, rxData, sizeof(rxData));

    while (1)
    {
        if(rxData[0] == 'a' || rxData[0] == 'b' || rxData[0] == 'c' || rxData[0] == 'd' ||
           rxData[0] == 'e' || rxData[0] == 'f'){
            dutyValue = rxData[0];
            switch (dutyValue) {
                case 'a':    // GO!
                    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 1);
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0);
                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
                    TIM3->CCR1 = 700;
                    TIM2->CCR1 = 700;
                    break;
                case 'b':    //BACK..
                    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1);
                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
                    TIM3->CCR1 = 700;
                    TIM2->CCR1 = 700;
                    break;
                case 'c':    //LEFT
                    TIM3->CCR1 = 700;
                    TIM2->CCR1 = 0;
                    break;
                case 'd':    //RIGHT
                    TIM3->CCR1 = 0;
                    TIM2->CCR1 = 700;
                    break;
                case 'e':    //TURN
                    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, 0);
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1);
                    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
                    TIM3->CCR1 = 700;
                    TIM2->CCR1 = 700;
                    break;
                case 'f':    //parking
                    TIM3->CCR1 = 0;
                    TIM2->CCR1 = 0;
                    break;
                default:
                    break;
            }
        }
    }
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 4;
    RCC_OscInitStruct.PLL.PLLN = 100;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 4;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
    {
        Error_Handler();
    }
}

void Error_Handler(void)
{
    __disable_irq();
    while (1)
    {
    }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
