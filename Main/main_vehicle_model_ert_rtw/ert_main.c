/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 29 23:24:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "main_vehicle_model.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[5] = { 0, 0, 0, 0, 0 };

boolean_T need2runFlags[5] = { 0, 0, 0, 0, 0 };

void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;
  boolean_T eventFlags[5];
  int_T i;

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
  main_vehicle_model_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  currentTime = (extmodeSimulationTime_T) main_vehicle_model_M->Timing.t[0];
  main_vehicle_model_step0();

  /* Get model outputs here */

  /* Trigger External Mode event */
  extmodeEvent(1, currentTime);
  __disable_irq();
  isRateRunning[0]--;
  for (i = 1; i < 5; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 2; i < 5; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;
      __enable_irq();

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 2 :
        currentTime = (extmodeSimulationTime_T)
          ((main_vehicle_model_M->Timing.clockTick2) * 0.001);
        main_vehicle_model_step2();

        /* Get model outputs here */

        /* Trigger External Mode event */
        extmodeEvent(2, currentTime);
        break;

       case 3 :
        currentTime = (extmodeSimulationTime_T)
          ((main_vehicle_model_M->Timing.clockTick3) * 0.01);
        main_vehicle_model_step3();

        /* Get model outputs here */

        /* Trigger External Mode event */
        extmodeEvent(3, currentTime);
        break;

       case 4 :
        currentTime = (extmodeSimulationTime_T)
          ((main_vehicle_model_M->Timing.clockTick4) * 0.25);
        main_vehicle_model_step4();

        /* Get model outputs here */

        /* Trigger External Mode event */
        extmodeEvent(4, currentTime);
        break;

       default :
        break;
      }

      __disable_irq();
      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 1.0E-5;
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
  rtmSetErrorStatus(main_vehicle_model_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  main_vehicle_model_initialize();
  __disable_irq();
  __enable_irq();

  /* External Mode initialization */
  errorCode = extmodeInit(main_vehicle_model_M->extModeInfo, &rtmGetTFinal
    (main_vehicle_model_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(main_vehicle_model_M, true);
    }
  }

  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel = !extmodeSimulationComplete() && !extmodeStopRequested() &&
    !rtmGetStopRequested(main_vehicle_model_M);
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
                      !rtmGetStopRequested(main_vehicle_model_M));
    runModel = !(stopRequested);
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  main_vehicle_model_terminate();

  /* External Mode reset */
  extmodeReset();
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
