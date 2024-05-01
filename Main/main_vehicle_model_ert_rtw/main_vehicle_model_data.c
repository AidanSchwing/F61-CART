/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model_data.c
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Apr 30 16:45:10 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "main_vehicle_model.h"

/* Block parameters (default storage) */
P_main_vehicle_model_T main_vehicle_model_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Digital Read'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Digital Read3'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/ICM20948 IMU Sensor'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S11>/Out1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0_b
   * Referenced by: '<S12>/Out1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/WHLSPD DIGITAL PIN'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Actuator Relay'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/ACT1_DIR'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/ACT1_DUTY'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/ACT2_DIR'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/ACT2_DUTY'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Drive Relay'
   */
  1.0,

  /* Expression: .5
   * Referenced by: '<S2>/Constant'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay'
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
  0.0,

  /* Computed Parameter: ResetMode_Value
   * Referenced by: '<S1>/ResetMode'
   */
  1,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S9>/Constant'
   */
  4000U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
