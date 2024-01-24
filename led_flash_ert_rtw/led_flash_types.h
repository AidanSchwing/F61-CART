/*
 * led_flash_types.h
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

#ifndef RTW_HEADER_led_flash_types_h_
#define RTW_HEADER_led_flash_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/Digital Write2' */
#include "MW_SVD.h"
#ifndef struct_tag_p5Oj7yF0nd6COoUgI0GAlG
#define struct_tag_p5Oj7yF0nd6COoUgI0GAlG

struct tag_p5Oj7yF0nd6COoUgI0GAlG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_p5Oj7yF0nd6COoUgI0GAlG */

#ifndef typedef_mbed_AnalogInput_led_flash_T
#define typedef_mbed_AnalogInput_led_flash_T

typedef struct tag_p5Oj7yF0nd6COoUgI0GAlG mbed_AnalogInput_led_flash_T;

#endif                                /* typedef_mbed_AnalogInput_led_flash_T */

#ifndef struct_tag_KxFW01GBdhqk5JOEHU3GlD
#define struct_tag_KxFW01GBdhqk5JOEHU3GlD

struct tag_KxFW01GBdhqk5JOEHU3GlD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_KxFW01GBdhqk5JOEHU3GlD */

#ifndef typedef_mbed_DigitalWrite_led_flash_T
#define typedef_mbed_DigitalWrite_led_flash_T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_led_flash_T;

#endif                               /* typedef_mbed_DigitalWrite_led_flash_T */

/* Parameters (default storage) */
typedef struct P_led_flash_T_ P_led_flash_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_led_flash_T RT_MODEL_led_flash_T;

#endif                                 /* RTW_HEADER_led_flash_types_h_ */
