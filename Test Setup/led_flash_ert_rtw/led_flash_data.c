/*
 * led_flash_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "led_flash".
 *
 * Model version              : 1.33
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Wed Feb  7 19:31:31 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "led_flash.h"

/* Block parameters (default storage) */
P_led_flash_T led_flash_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Digital Read2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/ICM20948 IMU Sensor'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S2>/Out1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0_a
   * Referenced by: '<S3>/Out1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Actuator Relay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: .5
   * Referenced by: '<S1>/Constant'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Pulse Generator'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0
};
