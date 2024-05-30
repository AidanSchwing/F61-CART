/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model_data.c
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

/* Block parameters (default storage) */
P_main_vehicle_model_T main_vehicle_model_P = {
  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S35>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S38>/Integral Gain'
   */
  0.1,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S36>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_Initial_k
   * Referenced by: '<S41>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by: '<S44>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S46>/Proportional Gain'
   */
  10.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/PRES_DUCER'
   */
  0.001,

  /* Expression: 0.00001
   * Referenced by: '<Root>/enc_ch_A'
   */
  1.0E-5,

  /* Expression: 0.00001
   * Referenced by: '<Root>/enc_ch_B'
   */
  1.0E-5,

  /* Computed Parameter: Outport_Y0
   * Referenced by: '<S62>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S62>/Memory'
   */
  0.0,

  /* Computed Parameter: Outport_Y0_i
   * Referenced by: '<S66>/Outport'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S66>/Memory'
   */
  0.0,

  /* Expression: 0.175438596491226
   * Referenced by: '<Root>/ANGLE SETPOINT'
   */
  0.175438596491226,

  /* Expression: 33
   * Referenced by: '<Root>/software angle limit'
   */
  33.0,

  /* Expression: -33
   * Referenced by: '<Root>/software angle limit'
   */
  -33.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant4'
   */
  0.0,

  /* Expression: 1/(500*4) * 360
   * Referenced by: '<S2>/Gain'
   */
  0.18,

  /* Expression: 10
   * Referenced by: '<Root>/Kp'
   */
  10.0,

  /* Expression: 100
   * Referenced by: '<Root>/pwm_saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/pwm_saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Drive Relay'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S75>/Filter_Constant'
   */
  0.1,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S75>/One'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S75>/Unit Delay'
   */
  0.0,

  /* Expression: 1/6
   * Referenced by: '<Root>/Gain'
   */
  0.16666666666666666,

  /* Expression: Filter_constant
   * Referenced by: '<S72>/Filter_Constant'
   */
  0.1,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S72>/One'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S72>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/brake % set point'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: Filter_constant
   * Referenced by: '<S61>/Filter_Constant'
   */
  0.01,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S61>/One'
   */
  0.99,

  /* Expression: 0
   * Referenced by: '<S61>/Unit Delay'
   */
  0.0,

  /* Expression: 0.18
   * Referenced by: '<Root>/Brake Calib. Bias'
   */
  0.18,

  /* Expression: 100/(0.42)
   * Referenced by: '<Root>/scale to % brake'
   */
  238.0952380952381,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S41>/Integrator'
   */
  0.001,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S36>/Filter'
   */
  0.001,

  /* Expression: 100
   * Referenced by: '<Root>/pwm_sat'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/pwm_sat'
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
   * Referenced by: '<S2>/Memory1'
   */
  false,

  /* Computed Parameter: Memory_InitialCondition_l
   * Referenced by: '<S2>/Memory'
   */
  false,

  /* Start of '<S66>/If Action Subsystem1' */
  {
    /* Computed Parameter: Wheelspeed_Y0
     * Referenced by: '<S68>/Wheelspeed'
     */
    0.0,

    /* Expression: 50/360*2*pi
     * Referenced by: '<S68>/count to radial speed'
     */
    0.87266462599716477
  }
  ,

  /* End of '<S66>/If Action Subsystem1' */

  /* Start of '<S62>/If Action Subsystem1' */
  {
    /* Computed Parameter: Wheelspeed_Y0
     * Referenced by: '<S64>/Wheelspeed'
     */
    0.0,

    /* Expression: 22/360*2*pi
     * Referenced by: '<S64>/count to radial speed'
     */
    0.38397243543875248
  }
  /* End of '<S62>/If Action Subsystem1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
