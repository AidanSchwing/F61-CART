/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model.h
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue May 21 12:49:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_main_vehicle_model_h_
#define RTW_HEADER_main_vehicle_model_h_
#ifndef main_vehicle_model_COMMON_INCLUDES_
#define main_vehicle_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_InterruptIn.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_AnalogOut.h"
#include "MW_AnalogIn.h"
#endif                                 /* main_vehicle_model_COMMON_INCLUDES_ */

#include "main_vehicle_model_types.h"
#include "MW_SVD.h"
#include "rt_zcfcn.h"
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ACT1_DUTY_ROUNDED;            /* '<Root>/Round' */
  real_T ACT2_DUTY_ROUNDED;            /* '<Root>/Round1' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T TmpRTBAtAddOutport1;          /* '<Root>/Add' */
  real_T TmpRTBAtFunctionCallSubsystemIn;/* '<Root>/Add1' */
  real_T In1;                          /* '<S6>/In1' */
  real_T In1_g;                        /* '<S5>/In1' */
  real_T enc_count;                    /* '<S1>/MATLAB Function' */
  real_T FixPtSum1;                    /* '<S7>/FixPt Sum1' */
  boolean_T CHAN_B;                    /* '<Root>/ENC_B1' */
  boolean_T ENC_A;                     /* '<Root>/ENC_A1' */
  boolean_T WHL_F2;                    /* '<Root>/WHL_F2' */
  boolean_T WHL_F1;                    /* '<Root>/WHL_F1' */
  boolean_T CHAN_B_p;                  /* '<Root>/ENC_B1' */
  boolean_T ENC_A_b;                   /* '<Root>/ENC_A1' */
} B_main_vehicle_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_DigitalRead_main_vehicle_T obj; /* '<Root>/WHL_F2' */
  mbed_DigitalRead_main_vehicle_T obj_n;/* '<Root>/WHL_F1' */
  mbed_DigitalRead_main_vehicle_T obj_e;/* '<Root>/ENC_B1' */
  mbed_DigitalRead_main_vehicle_T obj_eu;/* '<Root>/ENC_A1' */
  mbed_AnalogInput_main_vehicle_T obj_g;/* '<Root>/PRES_DUCER' */
  mbed_DigitalWrite_main_vehicl_T obj_i;/* '<Root>/Digital Write2' */
  mbed_DigitalWrite_main_vehicl_T obj_m;/* '<Root>/Digital Write1' */
  mbed_DigitalWrite_main_vehicl_T obj_j;/* '<Root>/Digital Write' */
  mbed_DigitalWrite_main_vehicl_T obj_l;/* '<Root>/DRIVE RELAY PIN' */
  mbed_DigitalWrite_main_vehicl_T obj_nh;/* '<Root>/ACTUATOR 2 DIR PIN' */
  mbed_DigitalWrite_main_vehicl_T obj_ej;/* '<Root>/ACTUATOR 1 DIR PIN' */
  mbed_DigitalWrite_main_vehicl_T obj_nv;/* '<Root>/ACT RELAY PIN' */
  mbed_PWMOutput_main_vehicle_m_T obj_iw;/* '<Root>/ACTUATOR 2 PWM PIN' */
  mbed_PWMOutput_main_vehicle_m_T obj_ef;/* '<Root>/ACTUATOR 1 PWM PIN' */
  mbed_AnalogOutput_main_vehicl_T obj_h;/* '<Root>/DRIVE MTR ANALOG PIN' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  MW_Handle_Type ExternalInterrupt_ExtIntHandle;/* '<Root>/External Interrupt' */
  MW_Handle_Type ExternalInterrupt1_ExtIntHandle;/* '<Root>/External Interrupt1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S2>/Triggered Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S2>/If Action Subsystem' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T Subsystem1_SubsysRanBC;       /* '<Root>/Subsystem1' */
  uint8_T is_active_c2_main_vehicle_model;/* '<S1>/MATLAB Function' */
} DW_main_vehicle_model_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S2>/Triggered Subsystem' */
} PrevZCX_main_vehicle_model_T;

/* Parameters (default storage) */
struct P_main_vehicle_model_T_ {
  real_T ENC_A1_SampleTime;            /* Expression: -1
                                        * Referenced by: '<Root>/ENC_A1'
                                        */
  real_T ENC_B1_SampleTime;            /* Expression: -1
                                        * Referenced by: '<Root>/ENC_B1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S3>/Out1'
                                        */
  real_T FixPtConstant_Value;          /* Expression: 1
                                        * Referenced by: '<S7>/FixPt Constant'
                                        */
  real_T count_fcn_Y0;                 /* Computed Parameter: count_fcn_Y0
                                        * Referenced by: '<S1>/count_fcn'
                                        */
  real_T PRES_DUCER_SampleTime;        /* Expression: -1
                                        * Referenced by: '<Root>/PRES_DUCER'
                                        */
  real_T Out1_Y0_d;                    /* Computed Parameter: Out1_Y0_d
                                        * Referenced by: '<S5>/Out1'
                                        */
  real_T Out1_Y0_b;                    /* Computed Parameter: Out1_Y0_b
                                        * Referenced by: '<S6>/Out1'
                                        */
  real_T WHL_F1_SampleTime;            /* Expression: -1
                                        * Referenced by: '<Root>/WHL_F1'
                                        */
  real_T WHL_F2_SampleTime;            /* Expression: -1
                                        * Referenced by: '<Root>/WHL_F2'
                                        */
  real_T ActuatorRelay_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/Actuator Relay'
                                        */
  real_T ACT1_DIR_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/ACT1_DIR'
                                        */
  real_T ACT1_DUTY_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/ACT1_DUTY'
                                        */
  real_T ACT2_DIR_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/ACT2_DIR'
                                        */
  real_T ACT2_DUTY_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/ACT2_DUTY'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DriveRelay_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Drive Relay'
                                        */
  real_T Constant_Value_i;             /* Expression: .5
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_main_vehicle_model_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint32_T clockTick4;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

/* Block parameters (default storage) */
extern P_main_vehicle_model_T main_vehicle_model_P;

/* Block signals (default storage) */
extern B_main_vehicle_model_T main_vehicle_model_B;

/* Block states (default storage) */
extern DW_main_vehicle_model_T main_vehicle_model_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_main_vehicle_model_T main_vehicle_model_PrevZCX;

/* External function called from main */
extern void main_vehicle_model_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void main_vehicle_model_initialize(void);
extern void main_vehicle_model_step0(void);
extern void main_vehicle_model_step2(void);
extern void main_vehicle_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_main_vehicle_model_T *const main_vehicle_model_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Divide' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S7>/FixPt Gateway In' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'main_vehicle_model'
 * '<S1>'   : 'main_vehicle_model/Function-Call Subsystem'
 * '<S2>'   : 'main_vehicle_model/Subsystem'
 * '<S3>'   : 'main_vehicle_model/Subsystem1'
 * '<S4>'   : 'main_vehicle_model/Function-Call Subsystem/MATLAB Function'
 * '<S5>'   : 'main_vehicle_model/Subsystem/If Action Subsystem'
 * '<S6>'   : 'main_vehicle_model/Subsystem/Triggered Subsystem'
 * '<S7>'   : 'main_vehicle_model/Subsystem1/Increment Stored Integer'
 */
#endif                                 /* RTW_HEADER_main_vehicle_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
