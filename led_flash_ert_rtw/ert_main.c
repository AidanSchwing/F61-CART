#include "led_flash.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  led_flash_step();

  /* Get model outputs here */
  __disable_irq();
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.1;
  float systemClock = 216;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;
  (void)systemClock;
  HAL_Init();
  SystemCoreClockUpdate();
  stm32nucleof7xx_init_board();
  rtmSetErrorStatus(led_flash_M, 0);
  led_flash_initialize();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel = rtmGetErrorStatus(led_flash_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(led_flash_M) == (NULL));
  }

  /* Terminate model */
  led_flash_terminate();
  __disable_irq();
  return 0;
}
