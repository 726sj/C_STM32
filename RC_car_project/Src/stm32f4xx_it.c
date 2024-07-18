#include "main.h"
#include "stm32f4xx_it.h"

/* Handles the Non maskable interrupt. */
void NMI_Handler(void)
{
  while (1)
  {
  }
}

/* Handles the Hard fault interrupt. */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/* Handles the Memory management fault. */
void MemManage_Handler(void)
{
  while (1)
  {
  }
}

/* Handles the Pre-fetch fault, memory access fault. */
void BusFault_Handler(void)
{
  while (1)
  {
  }
}

/* Handles the Undefined instruction or illegal state. */
void UsageFault_Handler(void)
{
  while (1)
  {
  }
}

/* Handles the System service call via SWI instruction. */
void SVC_Handler(void)
{
}

/* Handles the Debug monitor. */
void DebugMon_Handler(void)
{
}

/* Handles the Pendable request for system service. */
void PendSV_Handler(void)
{
}

/* Handles the System tick timer. */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/* Handles the TIM1 capture compare interrupt. */
void TIM1_CC_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim1);
}

/* Handles the TIM4 global interrupt. */
void TIM4_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim4);
}

/* Handles the TIM5 global interrupt. */
void TIM5_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim5);
}

/* Handles the USART6 global interrupt. */
void USART6_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart6);
}