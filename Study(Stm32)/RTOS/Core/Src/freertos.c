#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId_t LED1Handle;
const osThreadAttr_t LED1_attributes = {
  .name = "LED1",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

osThreadId_t LED2Handle;
const osThreadAttr_t LED2_attributes = {
  .name = "LED2",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

void StartDefaultTask(void *argument);
void StartTask02(void *argument);
void StartTask03(void *argument);

void MX_FREERTOS_Init(void);

void MX_FREERTOS_Init(void) {
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
  LED1Handle = osThreadNew(StartTask02, NULL, &LED1_attributes);
  LED2Handle = osThreadNew(StartTask03, NULL, &LED2_attributes);
}

void StartDefaultTask(void *argument) {
  for(;;) {
    osDelay(1);
  }
}

void StartTask02(void *argument) {
  for(;;) {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_11);
    osDelay(200);
  }
}

void StartTask03(void *argument) {
  for(;;) {
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
    osDelay(600);
  }
}
