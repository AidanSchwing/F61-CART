#include "led_flash.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;
  boolean_T eventFlags[3];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  led_flash_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  currentTime = (extmodeSimulationTime_T) led_flash_M->Timing.t[0];
  led_flash_step0();

  /* Get model outputs here */

  /* Trigger External Mode event */
  extmodeEvent(1, currentTime);
  __disable_irq();
  isRateRunning[0]--;
  if (eventFlags[2]) {
    if (need2runFlags[2]++) {
      IsrOverrun = 1;
      need2runFlags[2]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[2]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[2]++;
    __enable_irq();

    /* Step the model for subrate "2" */
    switch (2)
    {
     case 2 :
      currentTime = (extmodeSimulationTime_T) (((led_flash_M->Timing.clockTick2+
        led_flash_M->Timing.clockTickH2* 4294967296.0)) * 0.1);
      led_flash_step2();

      /* Get model outputs here */

      /* Trigger External Mode event */
      extmodeEvent(2, currentTime);
      break;

     default :
      break;
    }

    __disable_irq();
    need2runFlags[2]--;
    isRateRunning[2]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.01;
  float systemClock = 216;
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;

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

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  led_flash_initialize();
  __disable_irq();
  __enable_irq();

  /* External Mode initialization */
  errorCode = extmodeInit(led_flash_M->extModeInfo, &rtmGetTFinal(led_flash_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(led_flash_M, true);
    }
  }

  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel = !extmodeSimulationComplete() && !extmodeStopRequested() &&
    !rtmGetStopRequested(led_flash_M);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    stopRequested = !(!extmodeSimulationComplete() && !extmodeStopRequested() &&
                      !rtmGetStopRequested(led_flash_M));
    runModel = !(stopRequested);
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  led_flash_terminate();

  /* External Mode reset */
  extmodeReset();
  __disable_irq();
  return 0;
}
