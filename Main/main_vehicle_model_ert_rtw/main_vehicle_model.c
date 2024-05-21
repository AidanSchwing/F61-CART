/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model.c
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.246
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue May 21 16:39:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "main_vehicle_model.h"
#include "main_vehicle_model_private.h"
#include <math.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Block signals (default storage) */
B_main_vehicle_model_T main_vehicle_model_B;

/* Block states (default storage) */
DW_main_vehicle_model_T main_vehicle_model_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_main_vehicle_model_T main_vehicle_model_PrevZCX;

/* Real-time model */
static RT_MODEL_main_vehicle_model_T main_vehicle_model_M_;
RT_MODEL_main_vehicle_model_T *const main_vehicle_model_M =
  &main_vehicle_model_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void main_vehicle_model_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(main_vehicle_model_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(main_vehicle_model_M, 3));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (main_vehicle_model_M->Timing.TaskCounters.TID[2])++;
  if ((main_vehicle_model_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.01s, 0.0s] */
    main_vehicle_model_M->Timing.TaskCounters.TID[2] = 0;
  }

  (main_vehicle_model_M->Timing.TaskCounters.TID[3])++;
  if ((main_vehicle_model_M->Timing.TaskCounters.TID[3]) > 49999) {/* Sample time: [0.5s, 0.0s] */
    main_vehicle_model_M->Timing.TaskCounters.TID[3] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void main_vehicle_model_step0(void)    /* Sample time: [0.0s, 0.0s] */
{
  real_T rtb_Sum;
  int32_T dir;
  ZCEventType zcEvent;
  static const int8_T b[16] = { 0, 1, -1, 2, -1, 0, 2, 1, 1, 2, 0, -1, 2, -1, 1,
    0 };

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.TriggeredSubsystem_SubsysRanB_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN' incorporates:
   *  Constant: '<Root>/ACT2_DIR'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_nh.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.ACT2_DIR_Value != 0.0);

  /* Rounding: '<Root>/Round1' incorporates:
   *  Constant: '<Root>/ACT2_DUTY'
   */
  main_vehicle_model_B.ACT2_DUTY_ROUNDED = rt_roundd_snf
    (main_vehicle_model_P.ACT2_DUTY_Value);

  /* MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN' */
  MW_PWM_SetDutyCycle(main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE,
                      main_vehicle_model_B.ACT2_DUTY_ROUNDED);

  /* MATLABSystem: '<Root>/enc_ch_A' */
  if (main_vehicle_model_DW.obj_f.SampleTime !=
      main_vehicle_model_P.enc_ch_A_SampleTime) {
    main_vehicle_model_DW.obj_f.SampleTime =
      main_vehicle_model_P.enc_ch_A_SampleTime;
  }

  main_vehicle_model_B.new_A = MW_digitalIO_read
    (main_vehicle_model_DW.obj_f.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/enc_ch_B' */
  if (main_vehicle_model_DW.obj_k.SampleTime !=
      main_vehicle_model_P.enc_ch_B_SampleTime) {
    main_vehicle_model_DW.obj_k.SampleTime =
      main_vehicle_model_P.enc_ch_B_SampleTime;
  }

  main_vehicle_model_B.new_B = MW_digitalIO_read
    (main_vehicle_model_DW.obj_k.MW_DIGITALIO_HANDLE);

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  MATLABSystem: '<Root>/enc_ch_A'
   *  MATLABSystem: '<Root>/enc_ch_B'
   *  Memory: '<S1>/Memory'
   *  Memory: '<S1>/Memory1'
   *  Memory: '<S1>/Memory2'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Add2'
   *  Sum: '<S1>/Add4'
   */
  main_vehicle_model_B.enc_count = (real_T)b[(int32_T)
    ((((main_vehicle_model_P.Constant2_Value + (real_T)
        main_vehicle_model_DW.Memory1_PreviousInput) * 2.0 +
       (main_vehicle_model_P.Constant4_Value + (real_T)
        main_vehicle_model_DW.Memory_PreviousInput)) * 4.0 + ((real_T)
       main_vehicle_model_B.new_A * 2.0 + (real_T)main_vehicle_model_B.new_B)) +
     1.0) - 1] + (main_vehicle_model_P.Constant3_Value +
                  main_vehicle_model_DW.Memory2_PreviousInput);

  /* Gain: '<S1>/Gain' */
  main_vehicle_model_B.enc_angle = main_vehicle_model_P.Gain_Gain *
    main_vehicle_model_B.enc_count;

  /* Saturate: '<Root>/software angle limit' incorporates:
   *  Constant: '<Root>/ANGLE SETPOINT'
   */
  if (main_vehicle_model_P.ANGLESETPOINT_Value >
      main_vehicle_model_P.softwareanglelimit_UpperSat) {
    rtb_Sum = main_vehicle_model_P.softwareanglelimit_UpperSat;
  } else if (main_vehicle_model_P.ANGLESETPOINT_Value <
             main_vehicle_model_P.softwareanglelimit_LowerSat) {
    rtb_Sum = main_vehicle_model_P.softwareanglelimit_LowerSat;
  } else {
    rtb_Sum = main_vehicle_model_P.ANGLESETPOINT_Value;
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Saturate: '<Root>/software angle limit'
   */
  main_vehicle_model_B.steer_ang_errdeg = rtb_Sum -
    main_vehicle_model_B.enc_angle;

  /* MATLAB Function: '<Root>/conv_to_dir_pin' */
  dir = -1;
  if (main_vehicle_model_B.steer_ang_errdeg >= 0.0) {
    dir = 0;
  } else if (main_vehicle_model_B.steer_ang_errdeg < 0.0) {
    dir = 1;
  }

  /* End of MATLAB Function: '<Root>/conv_to_dir_pin' */

  /* MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN1' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_ff.MW_DIGITALIO_HANDLE, dir != 0);

  /* Gain: '<Root>/Kp' incorporates:
   *  Abs: '<Root>/Abs'
   */
  rtb_Sum = main_vehicle_model_P.Kp_Gain * fabs
    (main_vehicle_model_B.steer_ang_errdeg);

  /* Saturate: '<Root>/pwm_saturation' */
  if (rtb_Sum > main_vehicle_model_P.pwm_saturation_UpperSat) {
    rtb_Sum = main_vehicle_model_P.pwm_saturation_UpperSat;
  } else if (rtb_Sum < main_vehicle_model_P.pwm_saturation_LowerSat) {
    rtb_Sum = main_vehicle_model_P.pwm_saturation_LowerSat;
  }

  /* Rounding: '<Root>/Round2' incorporates:
   *  Saturate: '<Root>/pwm_saturation'
   */
  main_vehicle_model_B.ACT1_DUTY_ROUNDED = rt_roundd_snf(rtb_Sum);

  /* MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN1' */
  MW_PWM_SetDutyCycle(main_vehicle_model_DW.obj_ib.MW_PWM_HANDLE,
                      main_vehicle_model_B.ACT1_DUTY_ROUNDED);

  /* MATLABSystem: '<Root>/DRIVE RELAY EN PIN' incorporates:
   *  Constant: '<Root>/Drive Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.DriveRelay_Value != 0.0);

  /* MATLABSystem: '<Root>/PRES_DUCER' */
  if (main_vehicle_model_DW.obj.SampleTime !=
      main_vehicle_model_P.PRES_DUCER_SampleTime) {
    main_vehicle_model_DW.obj.SampleTime =
      main_vehicle_model_P.PRES_DUCER_SampleTime;
  }

  MW_AnalogIn_Start(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/PRES_DUCER' */
  MW_AnalogInSingle_ReadResult(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE,
    &main_vehicle_model_B.BRAKE_PRESSURE, 7);

  /* MATLABSystem: '<Root>/WHL_F1' */
  if (main_vehicle_model_DW.obj_n.SampleTime !=
      main_vehicle_model_P.WHL_F1_SampleTime) {
    main_vehicle_model_DW.obj_n.SampleTime =
      main_vehicle_model_P.WHL_F1_SampleTime;
  }

  /* MATLABSystem: '<Root>/WHL_F1' */
  main_vehicle_model_B.WHL_F1 = MW_digitalIO_read
    (main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* Outputs for Triggered SubSystem: '<S2>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S7>/Trigger'
   */
  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &main_vehicle_model_PrevZCX.TriggeredSubsystem_Trig_ZCE_m,
                     ((real_T)main_vehicle_model_B.WHL_F1 -
                      main_vehicle_model_P.Constant_Value));
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S7>/In1' incorporates:
     *  Clock: '<S2>/Clock'
     */
    main_vehicle_model_B.In1_g2 = main_vehicle_model_M->Timing.t[0];
    main_vehicle_model_DW.TriggeredSubsystem_SubsysRanB_c = 4;
  }

  /* End of Outputs for SubSystem: '<S2>/Triggered Subsystem' */

  /* Sum: '<S2>/Sum' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Sum = main_vehicle_model_B.In1_g2 - main_vehicle_model_DW.UnitDelay_DSTATE;

  /* If: '<S2>/If' */
  if (rtb_Sum > 0.0) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* SignalConversion generated from: '<S6>/In1' */
    main_vehicle_model_B.In1_g20 = rtb_Sum;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Update for If: '<S2>/If' */
    srUpdateBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC_h);

    /* End of Update for SubSystem: '<S2>/If Action Subsystem' */
  }

  /* End of If: '<S2>/If' */

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  main_vehicle_model_B.Divide = main_vehicle_model_P.Constant1_Value /
    main_vehicle_model_B.In1_g20;

  /* MATLABSystem: '<Root>/WHL_F2' */
  if (main_vehicle_model_DW.obj_j.SampleTime !=
      main_vehicle_model_P.WHL_F2_SampleTime) {
    main_vehicle_model_DW.obj_j.SampleTime =
      main_vehicle_model_P.WHL_F2_SampleTime;
  }

  /* MATLABSystem: '<Root>/WHL_F2' */
  main_vehicle_model_B.WHL_F2 = MW_digitalIO_read
    (main_vehicle_model_DW.obj_j.MW_DIGITALIO_HANDLE);

  /* Outputs for Triggered SubSystem: '<S3>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S9>/Trigger'
   */
  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S3>/Constant'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &main_vehicle_model_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     ((real_T)main_vehicle_model_B.WHL_F2 -
                      main_vehicle_model_P.Constant_Value_l));
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S9>/In1' incorporates:
     *  Clock: '<S3>/Clock'
     */
    main_vehicle_model_B.In1 = main_vehicle_model_M->Timing.t[0];
    main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S3>/Triggered Subsystem' */

  /* Sum: '<S3>/Sum' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Sum = main_vehicle_model_B.In1 - main_vehicle_model_DW.UnitDelay_DSTATE_k;

  /* If: '<S3>/If' */
  if (rtb_Sum > 0.0) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* SignalConversion generated from: '<S8>/In1' */
    main_vehicle_model_B.In1_g = rtb_Sum;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Update for If: '<S3>/If' */
    srUpdateBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S3>/If Action Subsystem' */
  }

  /* End of If: '<S3>/If' */

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  main_vehicle_model_B.Divide_e = main_vehicle_model_P.Constant1_Value_b /
    main_vehicle_model_B.In1_g;

  /* Update for Memory: '<S1>/Memory2' */
  main_vehicle_model_DW.Memory2_PreviousInput = main_vehicle_model_B.enc_count;

  /* Update for Memory: '<S1>/Memory1' */
  main_vehicle_model_DW.Memory1_PreviousInput = main_vehicle_model_B.new_A;

  /* Update for Memory: '<S1>/Memory' */
  main_vehicle_model_DW.Memory_PreviousInput = main_vehicle_model_B.new_B;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE = main_vehicle_model_B.In1_g2;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE_k = main_vehicle_model_B.In1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++main_vehicle_model_M->Timing.clockTick0)) {
    ++main_vehicle_model_M->Timing.clockTickH0;
  }

  main_vehicle_model_M->Timing.t[0] = main_vehicle_model_M->Timing.clockTick0 *
    main_vehicle_model_M->Timing.stepSize0 +
    main_vehicle_model_M->Timing.clockTickH0 *
    main_vehicle_model_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  main_vehicle_model_M->Timing.clockTick1++;
  if (!main_vehicle_model_M->Timing.clockTick1) {
    main_vehicle_model_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void main_vehicle_model_step2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* MATLABSystem: '<Root>/ACT RELAY EN PIN' incorporates:
   *  Constant: '<Root>/Actuator Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.ActuatorRelay_Value != 0.0);

  /* MATLABSystem: '<Root>/DRIVE MOTOR ANALOG PIN' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_AnalogOut_Write(main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE, (real32_T)
                     main_vehicle_model_P.Constant_Value_e);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_vehicle_model_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void main_vehicle_model_step3(void)    /* Sample time: [0.5s, 0.0s] */
{
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (main_vehicle_model_DW.clockTickCounter <
                        main_vehicle_model_P.PulseGenerator_Duty) &&
    (main_vehicle_model_DW.clockTickCounter >= 0) ?
    main_vehicle_model_P.PulseGenerator_Amp : 0.0;
  if (main_vehicle_model_DW.clockTickCounter >=
      main_vehicle_model_P.PulseGenerator_Period - 1.0) {
    main_vehicle_model_DW.clockTickCounter = 0;
  } else {
    main_vehicle_model_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_jb.MW_DIGITALIO_HANDLE,
                     rtb_PulseGenerator != 0.0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_m.MW_DIGITALIO_HANDLE,
                     rtb_PulseGenerator != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_i.MW_DIGITALIO_HANDLE,
                     rtb_PulseGenerator != 0.0);

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_vehicle_model_M->Timing.clockTick3++;
}

/* Model initialize function */
void main_vehicle_model_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&main_vehicle_model_M->solverInfo,
                          &main_vehicle_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&main_vehicle_model_M->solverInfo, &rtmGetTPtr
                (main_vehicle_model_M));
    rtsiSetStepSizePtr(&main_vehicle_model_M->solverInfo,
                       &main_vehicle_model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&main_vehicle_model_M->solverInfo, (&rtmGetErrorStatus
      (main_vehicle_model_M)));
    rtsiSetRTModelPtr(&main_vehicle_model_M->solverInfo, main_vehicle_model_M);
  }

  rtsiSetSimTimeStep(&main_vehicle_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&main_vehicle_model_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(main_vehicle_model_M, &main_vehicle_model_M->Timing.tArray[0]);
  rtmSetTFinal(main_vehicle_model_M, 999.00000000000011);
  main_vehicle_model_M->Timing.stepSize0 = 1.0E-5;

  /* External mode info */
  main_vehicle_model_M->Sizes.checksums[0] = (1148247716U);
  main_vehicle_model_M->Sizes.checksums[1] = (2141615940U);
  main_vehicle_model_M->Sizes.checksums[2] = (638938084U);
  main_vehicle_model_M->Sizes.checksums[3] = (2373662299U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[22];
    main_vehicle_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC_h;
    systemRan[14] = (sysRanDType *)
      &main_vehicle_model_DW.TriggeredSubsystem_SubsysRanB_c;
    systemRan[15] = (sysRanDType *)
      &main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(main_vehicle_model_M->extModeInfo,
      &main_vehicle_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(main_vehicle_model_M->extModeInfo,
                        main_vehicle_model_M->Sizes.checksums);
    rteiSetTPtr(main_vehicle_model_M->extModeInfo, rtmGetTPtr
                (main_vehicle_model_M));
  }

  main_vehicle_model_PrevZCX.TriggeredSubsystem_Trig_ZCE_m = UNINITIALIZED_ZCSIG;
  main_vehicle_model_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S1>/Memory2' */
  main_vehicle_model_DW.Memory2_PreviousInput =
    main_vehicle_model_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  main_vehicle_model_DW.Memory1_PreviousInput =
    main_vehicle_model_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S1>/Memory' */
  main_vehicle_model_DW.Memory_PreviousInput =
    main_vehicle_model_P.Memory_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE =
    main_vehicle_model_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE_k =
    main_vehicle_model_P.UnitDelay_InitialCondition_l;

  /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
   *  Outport: '<S6>/Out1'
   */
  main_vehicle_model_B.In1_g20 = main_vehicle_model_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S2>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
   *  Outport: '<S7>/Out1'
   */
  main_vehicle_model_B.In1_g2 = main_vehicle_model_P.Out1_Y0_b;

  /* End of SystemInitialize for SubSystem: '<S2>/Triggered Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
   *  Outport: '<S8>/Out1'
   */
  main_vehicle_model_B.In1_g = main_vehicle_model_P.Out1_Y0_i;

  /* End of SystemInitialize for SubSystem: '<S3>/If Action Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S3>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
   *  Outport: '<S9>/Out1'
   */
  main_vehicle_model_B.In1 = main_vehicle_model_P.Out1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S3>/Triggered Subsystem' */

  /* Start for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN' */
  main_vehicle_model_DW.obj_nh.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_nh.isInitialized = 1;
  main_vehicle_model_DW.obj_nh.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D7, 1);
  main_vehicle_model_DW.obj_nh.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN' */
  main_vehicle_model_DW.obj_iw.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_iw.isInitialized = 1;
  main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE = MW_PWM_Open(D11, 20000.0, 50.0);
  MW_PWM_Start(main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE);
  main_vehicle_model_DW.obj_iw.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/enc_ch_A' */
  main_vehicle_model_DW.obj_f.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_f.SampleTime =
    main_vehicle_model_P.enc_ch_A_SampleTime;
  main_vehicle_model_DW.obj_f.isInitialized = 1;
  main_vehicle_model_DW.obj_f.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A4, 0);
  main_vehicle_model_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/enc_ch_B' */
  main_vehicle_model_DW.obj_k.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_k.SampleTime =
    main_vehicle_model_P.enc_ch_B_SampleTime;
  main_vehicle_model_DW.obj_k.isInitialized = 1;
  main_vehicle_model_DW.obj_k.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A5, 0);
  main_vehicle_model_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN1' */
  main_vehicle_model_DW.obj_ff.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_ff.isInitialized = 1;
  main_vehicle_model_DW.obj_ff.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D2, 1);
  main_vehicle_model_DW.obj_ff.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN1' */
  main_vehicle_model_DW.obj_ib.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_ib.isInitialized = 1;
  main_vehicle_model_DW.obj_ib.MW_PWM_HANDLE = MW_PWM_Open(D3, 20000.0, 0.0);
  MW_PWM_Start(main_vehicle_model_DW.obj_ib.MW_PWM_HANDLE);
  main_vehicle_model_DW.obj_ib.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/DRIVE RELAY EN PIN' */
  main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_l.isInitialized = 1;
  main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A0, 1);
  main_vehicle_model_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PRES_DUCER' */
  main_vehicle_model_DW.obj.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj.SampleTime =
    main_vehicle_model_P.PRES_DUCER_SampleTime;
  main_vehicle_model_DW.obj.isInitialized = 1;
  main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(D13);
  MW_AnalogIn_SetTriggerSource(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  main_vehicle_model_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/WHL_F1' */
  main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_n.SampleTime =
    main_vehicle_model_P.WHL_F1_SampleTime;
  main_vehicle_model_DW.obj_n.isInitialized = 1;
  main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D0, 0);
  main_vehicle_model_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/WHL_F2' */
  main_vehicle_model_DW.obj_j.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_j.SampleTime =
    main_vehicle_model_P.WHL_F2_SampleTime;
  main_vehicle_model_DW.obj_j.isInitialized = 1;
  main_vehicle_model_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D1, 0);
  main_vehicle_model_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACT RELAY EN PIN' */
  main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_nv.isInitialized = 1;
  main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A1, 1);
  main_vehicle_model_DW.obj_nv.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/DRIVE MOTOR ANALOG PIN' */
  main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_h.isInitialized = 1;
  main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE = MW_AnalogOut_Open(D13);
  main_vehicle_model_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  main_vehicle_model_DW.obj_jb.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_jb.isInitialized = 1;
  main_vehicle_model_DW.obj_jb.MW_DIGITALIO_HANDLE = MW_digitalIO_open(PB_7, 1);
  main_vehicle_model_DW.obj_jb.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  main_vehicle_model_DW.obj_m.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_m.isInitialized = 1;
  main_vehicle_model_DW.obj_m.MW_DIGITALIO_HANDLE = MW_digitalIO_open(PB_14, 1);
  main_vehicle_model_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write2' */
  main_vehicle_model_DW.obj_i.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_i.isInitialized = 1;
  main_vehicle_model_DW.obj_i.MW_DIGITALIO_HANDLE = MW_digitalIO_open(PB_0, 1);
  main_vehicle_model_DW.obj_i.isSetupComplete = true;
}

/* Model terminate function */
void main_vehicle_model_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN' */
  if (!main_vehicle_model_DW.obj_nh.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_nh.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_nh.isInitialized == 1) &&
        main_vehicle_model_DW.obj_nh.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_nh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN' */

  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN' */
  if (!main_vehicle_model_DW.obj_iw.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_iw.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_iw.isInitialized == 1) &&
        main_vehicle_model_DW.obj_iw.isSetupComplete) {
      MW_PWM_Stop(main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE);
      MW_PWM_Close(main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN' */
  /* Terminate for MATLABSystem: '<Root>/enc_ch_A' */
  if (!main_vehicle_model_DW.obj_f.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_f.isInitialized == 1) &&
        main_vehicle_model_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/enc_ch_A' */

  /* Terminate for MATLABSystem: '<Root>/enc_ch_B' */
  if (!main_vehicle_model_DW.obj_k.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_k.isInitialized == 1) &&
        main_vehicle_model_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/enc_ch_B' */

  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN1' */
  if (!main_vehicle_model_DW.obj_ff.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_ff.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_ff.isInitialized == 1) &&
        main_vehicle_model_DW.obj_ff.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_ff.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN1' */
  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN1' */
  if (!main_vehicle_model_DW.obj_ib.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_ib.isInitialized == 1) &&
        main_vehicle_model_DW.obj_ib.isSetupComplete) {
      MW_PWM_Stop(main_vehicle_model_DW.obj_ib.MW_PWM_HANDLE);
      MW_PWM_Close(main_vehicle_model_DW.obj_ib.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN1' */
  /* Terminate for MATLABSystem: '<Root>/DRIVE RELAY EN PIN' */
  if (!main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_l.isInitialized == 1) &&
        main_vehicle_model_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/DRIVE RELAY EN PIN' */

  /* Terminate for MATLABSystem: '<Root>/PRES_DUCER' */
  if (!main_vehicle_model_DW.obj.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj.isInitialized == 1) &&
        main_vehicle_model_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PRES_DUCER' */
  /* Terminate for MATLABSystem: '<Root>/WHL_F1' */
  if (!main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_n.isInitialized == 1) &&
        main_vehicle_model_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/WHL_F1' */
  /* Terminate for MATLABSystem: '<Root>/WHL_F2' */
  if (!main_vehicle_model_DW.obj_j.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_j.isInitialized == 1) &&
        main_vehicle_model_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/WHL_F2' */
  /* Terminate for MATLABSystem: '<Root>/ACT RELAY EN PIN' */
  if (!main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_nv.isInitialized == 1) &&
        main_vehicle_model_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACT RELAY EN PIN' */

  /* Terminate for MATLABSystem: '<Root>/DRIVE MOTOR ANALOG PIN' */
  if (!main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_h.isInitialized == 1) &&
        main_vehicle_model_DW.obj_h.isSetupComplete) {
      MW_AnalogOut_Close(main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/DRIVE MOTOR ANALOG PIN' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!main_vehicle_model_DW.obj_jb.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_jb.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_jb.isInitialized == 1) &&
        main_vehicle_model_DW.obj_jb.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_jb.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!main_vehicle_model_DW.obj_m.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_m.isInitialized == 1) &&
        main_vehicle_model_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!main_vehicle_model_DW.obj_i.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_i.isInitialized == 1) &&
        main_vehicle_model_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
