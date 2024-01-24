/*
 * led_flash.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "led_flash".
 *
 * Model version              : 1.3
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Jan 23 21:09:35 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "led_flash.h"
#include "rtwtypes.h"
#include <string.h>

/* Block states (default storage) */
DW_led_flash_T led_flash_DW;

/* Real-time model */
static RT_MODEL_led_flash_T led_flash_M_;
RT_MODEL_led_flash_T *const led_flash_M = &led_flash_M_;

/* Model step function */
void led_flash_step(void)
{
  real_T rtb_PulseGenerator;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (led_flash_DW.obj.SampleTime != led_flash_P.AnalogInput_SampleTime) {
    led_flash_DW.obj.SampleTime = led_flash_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(led_flash_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(led_flash_DW.obj.MW_ANALOGIN_HANDLE,
    &rtb_PulseGenerator, 7);

  /* End of MATLABSystem: '<Root>/Analog Input' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (led_flash_DW.clockTickCounter <
                        led_flash_P.PulseGenerator_Duty) &&
    (led_flash_DW.clockTickCounter >= 0) ? led_flash_P.PulseGenerator_Amp : 0.0;
  if (led_flash_DW.clockTickCounter >= led_flash_P.PulseGenerator_Period - 1.0)
  {
    led_flash_DW.clockTickCounter = 0;
  } else {
    led_flash_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(led_flash_DW.obj_p.MW_DIGITALIO_HANDLE, rtb_PulseGenerator
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(led_flash_DW.obj_j.MW_DIGITALIO_HANDLE, rtb_PulseGenerator
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(led_flash_DW.obj_b.MW_DIGITALIO_HANDLE, false);
}

/* Model initialize function */
void led_flash_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(led_flash_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&led_flash_DW, 0,
                sizeof(DW_led_flash_T));

  {
    MW_AnalogIn_TriggerSource_Type trigger_val;
    uint32_T pinname;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    led_flash_DW.obj.matlabCodegenIsDeleted = false;
    led_flash_DW.objisempty_g = true;
    led_flash_DW.obj.SampleTime = led_flash_P.AnalogInput_SampleTime;
    led_flash_DW.obj.isInitialized = 1;
    pinname = A0;
    led_flash_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(pinname);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(led_flash_DW.obj.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    led_flash_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    led_flash_DW.obj_p.matlabCodegenIsDeleted = false;
    led_flash_DW.objisempty_n = true;
    led_flash_DW.obj_p.isInitialized = 1;
    pinname = PB_7;
    led_flash_DW.obj_p.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    led_flash_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    led_flash_DW.obj_j.matlabCodegenIsDeleted = false;
    led_flash_DW.objisempty_a = true;
    led_flash_DW.obj_j.isInitialized = 1;
    pinname = PB_14;
    led_flash_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    led_flash_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    led_flash_DW.obj_b.matlabCodegenIsDeleted = false;
    led_flash_DW.objisempty = true;
    led_flash_DW.obj_b.isInitialized = 1;
    pinname = PB_0;
    led_flash_DW.obj_b.MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    led_flash_DW.obj_b.isSetupComplete = true;
  }

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  led_flash_DW.clockTickCounter = 0;
}

/* Model terminate function */
void led_flash_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!led_flash_DW.obj.matlabCodegenIsDeleted) {
    led_flash_DW.obj.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj.isInitialized == 1) &&
        led_flash_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(led_flash_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(led_flash_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!led_flash_DW.obj_p.matlabCodegenIsDeleted) {
    led_flash_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_p.isInitialized == 1) &&
        led_flash_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!led_flash_DW.obj_j.matlabCodegenIsDeleted) {
    led_flash_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_j.isInitialized == 1) &&
        led_flash_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!led_flash_DW.obj_b.matlabCodegenIsDeleted) {
    led_flash_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_b.isInitialized == 1) &&
        led_flash_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */
}
