/*
 * led_flash.h
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

#ifndef RTW_HEADER_led_flash_h_
#define RTW_HEADER_led_flash_h_
#ifndef led_flash_COMMON_INCLUDES_
#define led_flash_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#endif                                 /* led_flash_COMMON_INCLUDES_ */

#include "led_flash_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_led_flash_T obj;    /* '<Root>/Analog Input' */
  mbed_DigitalWrite_led_flash_T obj_b; /* '<Root>/Digital Write2' */
  mbed_DigitalWrite_led_flash_T obj_j; /* '<Root>/Digital Write1' */
  mbed_DigitalWrite_led_flash_T obj_p; /* '<Root>/Digital Write' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  boolean_T objisempty;                /* '<Root>/Digital Write2' */
  boolean_T objisempty_a;              /* '<Root>/Digital Write1' */
  boolean_T objisempty_n;              /* '<Root>/Digital Write' */
  boolean_T objisempty_g;              /* '<Root>/Analog Input' */
} DW_led_flash_T;

/* Parameters (default storage) */
struct P_led_flash_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_led_flash_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_led_flash_T led_flash_P;

/* Block states (default storage) */
extern DW_led_flash_T led_flash_DW;

/* Model entry point functions */
extern void led_flash_initialize(void);
extern void led_flash_step(void);
extern void led_flash_terminate(void);

/* Real-time Model object */
extern RT_MODEL_led_flash_T *const led_flash_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'led_flash'
 */
#endif                                 /* RTW_HEADER_led_flash_h_ */
