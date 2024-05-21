/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model_data.c
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.220
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue May 21 16:05:15 2024
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
   * Referenced by: '<Root>/PRES_DUCER'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S6>/Out1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0_b
   * Referenced by: '<S7>/Out1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/WHL_F2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/WHL_F1'
   */
  -1.0,

  /* Expression: 0.00001
   * Referenced by: '<Root>/enc_A'
   */
  1.0E-5,

  /* Expression: 0.00001
   * Referenced by: '<Root>/enc_B'
   */
  1.0E-5,

  /* Computed Parameter: Out1_Y0_by
   * Referenced by: '<S3>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/FixPt Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/ACT2_DIR'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/ACT2_DUTY'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<Root>/ANGLE SETPOINT'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant4'
   */
  0.0,

  /* Expression: 1/(500*4) * 360
   * Referenced by: '<S1>/Gain'
   */
  0.18,

  /* Expression: 10
   * Referenced by: '<Root>/Kp'
   */
  10.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
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

  /* Expression: 0
   * Referenced by: '<Root>/Actuator Relay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  2.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Memory1_InitialCondition
   * Referenced by: '<S1>/Memory1'
   */
  false,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S1>/Memory'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
