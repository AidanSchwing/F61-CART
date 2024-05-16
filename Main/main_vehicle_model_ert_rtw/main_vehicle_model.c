/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model.c
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May 16 12:43:07 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "main_vehicle_model.h"
#include "main_vehicle_model_private.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <math.h>

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
  if ((main_vehicle_model_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.5s, 0.0s] */
    main_vehicle_model_M->Timing.TaskCounters.TID[2] = 0;
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
  ZCEventType zcEvent;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/ACT RELAY PIN' incorporates:
   *  Constant: '<Root>/Actuator Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.ActuatorRelay_Value != 0.0);

  /* MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN' incorporates:
   *  Constant: '<Root>/ACT1_DIR'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_e.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.ACT1_DIR_Value != 0.0);

  /* Rounding: '<Root>/Round' incorporates:
   *  Constant: '<Root>/ACT1_DUTY'
   */
  main_vehicle_model_B.ACT1_DUTY_ROUNDED = rt_roundd_snf
    (main_vehicle_model_P.ACT1_DUTY_Value);

  /* MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN' */
  MW_PWM_SetDutyCycle(main_vehicle_model_DW.obj_ef.MW_PWM_HANDLE,
                      main_vehicle_model_B.ACT1_DUTY_ROUNDED);

  /* MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN' incorporates:
   *  Constant: '<Root>/ACT2_DIR'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.ACT2_DIR_Value != 0.0);

  /* Rounding: '<Root>/Round1' incorporates:
   *  Constant: '<Root>/ACT2_DUTY'
   */
  main_vehicle_model_B.ACT2_DUTY_ROUNDED = rt_roundd_snf
    (main_vehicle_model_P.ACT2_DUTY_Value);

  /* MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN' */
  MW_PWM_SetDutyCycle(main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE,
                      main_vehicle_model_B.ACT2_DUTY_ROUNDED);

  /* MATLABSystem: '<Root>/DRIVE MTR ANALOG PIN' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_AnalogOut_Write(main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE, (real32_T)
                     main_vehicle_model_P.Constant_Value);

  /* MATLABSystem: '<Root>/DRIVE RELAY PIN' incorporates:
   *  Constant: '<Root>/Drive Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.DriveRelay_Value != 0.0);

  /* MATLABSystem: '<Root>/WHLSPD DIGITAL PIN' */
  if (main_vehicle_model_DW.obj.SampleTime !=
      main_vehicle_model_P.WHLSPDDIGITALPIN_SampleTime) {
    main_vehicle_model_DW.obj.SampleTime =
      main_vehicle_model_P.WHLSPDDIGITALPIN_SampleTime;
  }

  /* MATLABSystem: '<Root>/WHLSPD DIGITAL PIN' */
  main_vehicle_model_B.WHEELSPEEDTOGGLE = MW_digitalIO_read
    (main_vehicle_model_DW.obj.MW_DIGITALIO_HANDLE);

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &main_vehicle_model_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     ((real_T)main_vehicle_model_B.WHEELSPEEDTOGGLE -
                      main_vehicle_model_P.Constant_Value_i));
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S3>/In1' incorporates:
     *  Clock: '<S1>/Clock'
     */
    main_vehicle_model_B.In1 = main_vehicle_model_M->Timing.t[0];
    main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */
  /* Sum: '<S1>/Sum' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Sum = main_vehicle_model_B.In1 - main_vehicle_model_DW.UnitDelay_DSTATE;

  /* If: '<S1>/If' */
  if (rtb_Sum > 0.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/In1' */
    main_vehicle_model_B.In1_g = rtb_Sum;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Update for If: '<S1>/If' */
    srUpdateBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem' */
  }

  /* End of If: '<S1>/If' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE = main_vehicle_model_B.In1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  main_vehicle_model_M->Timing.t[0] =
    ((time_T)(++main_vehicle_model_M->Timing.clockTick0)) *
    main_vehicle_model_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_vehicle_model_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void main_vehicle_model_step2(void)    /* Sample time: [0.5s, 0.0s] */
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
  MW_digitalIO_write(main_vehicle_model_DW.obj_j.MW_DIGITALIO_HANDLE,
                     rtb_PulseGenerator != 0.0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_m.MW_DIGITALIO_HANDLE,
                     rtb_PulseGenerator != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_i.MW_DIGITALIO_HANDLE,
                     rtb_PulseGenerator != 0.0);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_vehicle_model_M->Timing.clockTick2++;
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
  rtmSetTFinal(main_vehicle_model_M, 999.0);
  main_vehicle_model_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  main_vehicle_model_M->Sizes.checksums[0] = (1520848253U);
  main_vehicle_model_M->Sizes.checksums[1] = (1383666511U);
  main_vehicle_model_M->Sizes.checksums[2] = (2629879578U);
  main_vehicle_model_M->Sizes.checksums[3] = (334405797U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
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
    systemRan[11] = (sysRanDType *)
      &main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[13] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(main_vehicle_model_M->extModeInfo,
      &main_vehicle_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(main_vehicle_model_M->extModeInfo,
                        main_vehicle_model_M->Sizes.checksums);
    rteiSetTPtr(main_vehicle_model_M->extModeInfo, rtmGetTPtr
                (main_vehicle_model_M));
  }

  main_vehicle_model_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE =
    main_vehicle_model_P.UnitDelay_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S2>/In1' incorporates:
   *  Outport: '<S2>/Out1'
   */
  main_vehicle_model_B.In1_g = main_vehicle_model_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S3>/In1' incorporates:
   *  Outport: '<S3>/Out1'
   */
  main_vehicle_model_B.In1 = main_vehicle_model_P.Out1_Y0_b;

  /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */

  /* Start for MATLABSystem: '<Root>/ACT RELAY PIN' */
  main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_nv.isInitialized = 1;
  main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D8, 1);
  main_vehicle_model_DW.obj_nv.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN' */
  main_vehicle_model_DW.obj_e.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_e.isInitialized = 1;
  main_vehicle_model_DW.obj_e.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D2, 1);
  main_vehicle_model_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN' */
  main_vehicle_model_DW.obj_ef.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_ef.isInitialized = 1;
  main_vehicle_model_DW.obj_ef.MW_PWM_HANDLE = MW_PWM_Open(D3, 20000.0, 50.0);
  MW_PWM_Start(main_vehicle_model_DW.obj_ef.MW_PWM_HANDLE);
  main_vehicle_model_DW.obj_ef.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN' */
  main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_n.isInitialized = 1;
  main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D7, 1);
  main_vehicle_model_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN' */
  main_vehicle_model_DW.obj_iw.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_iw.isInitialized = 1;
  main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE = MW_PWM_Open(D11, 20000.0, 50.0);
  MW_PWM_Start(main_vehicle_model_DW.obj_iw.MW_PWM_HANDLE);
  main_vehicle_model_DW.obj_iw.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/DRIVE MTR ANALOG PIN' */
  main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_h.isInitialized = 1;
  main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE = MW_AnalogOut_Open(D13);
  main_vehicle_model_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/DRIVE RELAY PIN' */
  main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_l.isInitialized = 1;
  main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D9, 1);
  main_vehicle_model_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/WHLSPD DIGITAL PIN' */
  main_vehicle_model_DW.obj.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj.SampleTime =
    main_vehicle_model_P.WHLSPDDIGITALPIN_SampleTime;
  main_vehicle_model_DW.obj.isInitialized = 1;
  main_vehicle_model_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A0, 0);
  main_vehicle_model_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  main_vehicle_model_DW.obj_j.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_j.isInitialized = 1;
  main_vehicle_model_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(PB_7, 1);
  main_vehicle_model_DW.obj_j.isSetupComplete = true;

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
  /* Terminate for MATLABSystem: '<Root>/ACT RELAY PIN' */
  if (!main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_nv.isInitialized == 1) &&
        main_vehicle_model_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACT RELAY PIN' */

  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN' */
  if (!main_vehicle_model_DW.obj_e.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_e.isInitialized == 1) &&
        main_vehicle_model_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN' */

  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN' */
  if (!main_vehicle_model_DW.obj_ef.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_ef.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_ef.isInitialized == 1) &&
        main_vehicle_model_DW.obj_ef.isSetupComplete) {
      MW_PWM_Stop(main_vehicle_model_DW.obj_ef.MW_PWM_HANDLE);
      MW_PWM_Close(main_vehicle_model_DW.obj_ef.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN' */
  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN' */
  if (!main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_n.isInitialized == 1) &&
        main_vehicle_model_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE);
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
  /* Terminate for MATLABSystem: '<Root>/DRIVE MTR ANALOG PIN' */
  if (!main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_h.isInitialized == 1) &&
        main_vehicle_model_DW.obj_h.isSetupComplete) {
      MW_AnalogOut_Close(main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/DRIVE MTR ANALOG PIN' */

  /* Terminate for MATLABSystem: '<Root>/DRIVE RELAY PIN' */
  if (!main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_l.isInitialized == 1) &&
        main_vehicle_model_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/DRIVE RELAY PIN' */

  /* Terminate for MATLABSystem: '<Root>/WHLSPD DIGITAL PIN' */
  if (!main_vehicle_model_DW.obj.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj.isInitialized == 1) &&
        main_vehicle_model_DW.obj.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/WHLSPD DIGITAL PIN' */
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!main_vehicle_model_DW.obj_j.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_j.isInitialized == 1) &&
        main_vehicle_model_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_j.MW_DIGITALIO_HANDLE);
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
