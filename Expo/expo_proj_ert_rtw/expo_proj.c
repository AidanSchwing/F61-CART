/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: expo_proj.c
 *
 * Code generated for Simulink model 'expo_proj'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue May 21 12:39:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "expo_proj.h"
#include "expo_proj_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "expo_proj_private.h"

/* Block signals (default storage) */
B_expo_proj_T expo_proj_B;

/* Block states (default storage) */
DW_expo_proj_T expo_proj_DW;

/* Real-time model */
static RT_MODEL_expo_proj_T expo_proj_M_;
RT_MODEL_expo_proj_T *const expo_proj_M = &expo_proj_M_;

/* Forward declaration for local functions */
static void expo_proj_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void expo_proj_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void expo_proj_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T c;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (expo_proj_DW.clockTickCounter <
                        expo_proj_P.PulseGenerator_Duty) &&
    (expo_proj_DW.clockTickCounter >= 0) ? expo_proj_P.PulseGenerator_Amp : 0.0;
  if (expo_proj_DW.clockTickCounter >= expo_proj_P.PulseGenerator_Period - 1.0)
  {
    expo_proj_DW.clockTickCounter = 0;
  } else {
    expo_proj_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S5>/Digital Port Write' */
  portNameLoc = GPIOB;
  c = (rtb_PulseGenerator != 0.0);
  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 1U);

  /* MATLABSystem: '<S7>/Digital Port Write' */
  portNameLoc = GPIOB;
  if (rtb_PulseGenerator != 0.0) {
    c = 16384;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 16384U);

  /* End of MATLABSystem: '<S7>/Digital Port Write' */

  /* MATLABSystem: '<S9>/Digital Port Write' */
  portNameLoc = GPIOB;
  if (rtb_PulseGenerator != 0.0) {
    c = 128;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 128U);

  /* End of MATLABSystem: '<S9>/Digital Port Write' */

  /* MATLABSystem: '<Root>/Encoder' */
  expo_proj_B.ENC_CNT = getTimerCounterValue(expo_proj_DW.obj.TimerHandle);

  {                                    /* Sample time: [0.5s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  expo_proj_M->Timing.taskTime0 =
    ((time_T)(++expo_proj_M->Timing.clockTick0)) * expo_proj_M->Timing.stepSize0;
}

/* Model initialize function */
void expo_proj_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(expo_proj_M, 999.0);
  expo_proj_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  expo_proj_M->Sizes.checksums[0] = (2739193167U);
  expo_proj_M->Sizes.checksums[1] = (3984357819U);
  expo_proj_M->Sizes.checksums[2] = (4282649153U);
  expo_proj_M->Sizes.checksums[3] = (2634880592U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    expo_proj_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(expo_proj_M->extModeInfo,
      &expo_proj_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(expo_proj_M->extModeInfo, expo_proj_M->Sizes.checksums);
    rteiSetTPtr(expo_proj_M->extModeInfo, rtmGetTPtr(expo_proj_M));
  }

  /* Start for MATLABSystem: '<Root>/Encoder' */
  expo_proj_DW.obj.isInitialized = 0;
  expo_proj_DW.obj.matlabCodegenIsDeleted = false;
  expo_proj_SystemCore_setup(&expo_proj_DW.obj);
}

/* Model terminate function */
void expo_proj_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!expo_proj_DW.obj.matlabCodegenIsDeleted) {
    expo_proj_DW.obj.matlabCodegenIsDeleted = true;
    if ((expo_proj_DW.obj.isInitialized == 1) &&
        expo_proj_DW.obj.isSetupComplete) {
      disableCounter(expo_proj_DW.obj.TimerHandle);
      disableTimerInterrupts(expo_proj_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(expo_proj_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(expo_proj_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
