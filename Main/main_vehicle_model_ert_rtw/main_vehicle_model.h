/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model.h
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

#ifndef RTW_HEADER_main_vehicle_model_h_
#define RTW_HEADER_main_vehicle_model_h_
#ifndef main_vehicle_model_COMMON_INCLUDES_
#define main_vehicle_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_AnalogOut.h"
#include "MW_AnalogIn.h"
#endif                                 /* main_vehicle_model_COMMON_INCLUDES_ */

#include "main_vehicle_model_types.h"
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
  real_T ACT2_DUTY_ROUNDED;            /* '<Root>/Round1' */
  real_T enc_angle;                    /* '<S1>/Gain' */
  real_T steer_ang_errdeg;             /* '<Root>/Subtract' */
  real_T ACT1_DUTY_ROUNDED;            /* '<Root>/Round2' */
  real_T Divide;                       /* '<S2>/Divide' */
  real_T Divide_e;                     /* '<S3>/Divide' */
  real_T In1;                          /* '<S9>/In1' */
  real_T In1_g;                        /* '<S8>/In1' */
  real_T In1_g2;                       /* '<S7>/In1' */
  real_T In1_g20;                      /* '<S6>/In1' */
  real_T BRAKE_PRESSURE;               /* '<Root>/PRES_DUCER' */
  real_T enc_count;                    /* '<S1>/MATLAB Function' */
  boolean_T WHL_F2;                    /* '<Root>/WHL_F2' */
  boolean_T WHL_F1;                    /* '<Root>/WHL_F1' */
  boolean_T new_A;                     /* '<S1>/MATLAB Function' */
  boolean_T new_B;                     /* '<S1>/MATLAB Function' */
} B_main_vehicle_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_main_vehicle_T obj; /* '<Root>/PRES_DUCER' */
  mbed_DigitalRead_main_vehicle_T obj_k;/* '<Root>/enc_ch_B' */
  mbed_DigitalRead_main_vehicle_T obj_f;/* '<Root>/enc_ch_A' */
  mbed_DigitalRead_main_vehicle_T obj_j;/* '<Root>/WHL_F2' */
  mbed_DigitalRead_main_vehicle_T obj_n;/* '<Root>/WHL_F1' */
  mbed_DigitalWrite_main_vehicl_T obj_i;/* '<Root>/Digital Write2' */
  mbed_DigitalWrite_main_vehicl_T obj_m;/* '<Root>/Digital Write1' */
  mbed_DigitalWrite_main_vehicl_T obj_jb;/* '<Root>/Digital Write' */
  mbed_DigitalWrite_main_vehicl_T obj_l;/* '<Root>/DRIVE RELAY EN PIN' */
  mbed_DigitalWrite_main_vehicl_T obj_nh;/* '<Root>/ACTUATOR 2 DIR PIN' */
  mbed_DigitalWrite_main_vehicl_T obj_ff;/* '<Root>/ACTUATOR 1 DIR PIN1' */
  mbed_DigitalWrite_main_vehicl_T obj_nv;/* '<Root>/ACT RELAY EN PIN' */
  mbed_PWMOutput_main_vehicle_m_T obj_iw;/* '<Root>/ACTUATOR 2 PWM PIN' */
  mbed_PWMOutput_main_vehicle_m_T obj_ib;/* '<Root>/ACTUATOR 1 PWM PIN1' */
  mbed_AnalogOutput_main_vehicl_T obj_h;/* '<Root>/DRIVE MOTOR ANALOG PIN' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  real_T UnitDelay_DSTATE_k;           /* '<S3>/Unit Delay' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S3>/Triggered Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S3>/If Action Subsystem' */
  int8_T TriggeredSubsystem_SubsysRanB_c;/* '<S2>/Triggered Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_h;/* '<S2>/If Action Subsystem' */
  uint8_T is_active_c1_main_vehicle_model;/* '<Root>/conv_to_dir_pin' */
  uint8_T is_active_c2_main_vehicle_model;/* '<S1>/MATLAB Function' */
  boolean_T Memory1_PreviousInput;     /* '<S1>/Memory1' */
  boolean_T Memory_PreviousInput;      /* '<S1>/Memory' */
} DW_main_vehicle_model_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S3>/Triggered Subsystem' */
  ZCSigState TriggeredSubsystem_Trig_ZCE_m;/* '<S2>/Triggered Subsystem' */
} PrevZCX_main_vehicle_model_T;

/* Parameters (default storage) */
struct P_main_vehicle_model_T_ {
  real_T PRES_DUCER_SampleTime;        /* Expression: -1
                                        * Referenced by: '<Root>/PRES_DUCER'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S6>/Out1'
                                        */
  real_T Out1_Y0_b;                    /* Computed Parameter: Out1_Y0_b
                                        * Referenced by: '<S7>/Out1'
                                        */
  real_T Out1_Y0_i;                    /* Computed Parameter: Out1_Y0_i
                                        * Referenced by: '<S8>/Out1'
                                        */
  real_T Out1_Y0_c;                    /* Computed Parameter: Out1_Y0_c
                                        * Referenced by: '<S9>/Out1'
                                        */
  real_T WHL_F1_SampleTime;            /* Expression: -1
                                        * Referenced by: '<Root>/WHL_F1'
                                        */
  real_T WHL_F2_SampleTime;            /* Expression: -1
                                        * Referenced by: '<Root>/WHL_F2'
                                        */
  real_T enc_ch_A_SampleTime;          /* Expression: 0.00001
                                        * Referenced by: '<Root>/enc_ch_A'
                                        */
  real_T enc_ch_B_SampleTime;          /* Expression: 0.00001
                                        * Referenced by: '<Root>/enc_ch_B'
                                        */
  real_T ACT2_DIR_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/ACT2_DIR'
                                        */
  real_T ACT2_DUTY_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/ACT2_DUTY'
                                        */
  real_T ANGLESETPOINT_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/ANGLE SETPOINT'
                                        */
  real_T softwareanglelimit_UpperSat;  /* Expression: 33
                                        * Referenced by: '<Root>/software angle limit'
                                        */
  real_T softwareanglelimit_LowerSat;  /* Expression: -33
                                        * Referenced by: '<Root>/software angle limit'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/(500*4) * 360
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Kp_Gain;                      /* Expression: 10
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T pwm_saturation_UpperSat;      /* Expression: 100
                                        * Referenced by: '<Root>/pwm_saturation'
                                        */
  real_T pwm_saturation_LowerSat;      /* Expression: 0
                                        * Referenced by: '<Root>/pwm_saturation'
                                        */
  real_T DriveRelay_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Drive Relay'
                                        */
  real_T Constant1_Value;              /* Expression: 9/360*2*pi
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: .5
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T Constant1_Value_b;            /* Expression: 9/360*2*pi
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: .5
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T UnitDelay_InitialCondition_l; /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  real_T ActuatorRelay_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/Actuator Relay'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
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
  boolean_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S1>/Memory1'
                                  */
  boolean_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S1>/Memory'
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    struct {
      uint16_T TID[4];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
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
extern void main_vehicle_model_step3(void);
extern void main_vehicle_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_main_vehicle_model_T *const main_vehicle_model_M;
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
 * '<Root>' : 'main_vehicle_model'
 * '<S1>'   : 'main_vehicle_model/ENCODER COUNT'
 * '<S2>'   : 'main_vehicle_model/Subsystem'
 * '<S3>'   : 'main_vehicle_model/Subsystem2'
 * '<S4>'   : 'main_vehicle_model/conv_to_dir_pin'
 * '<S5>'   : 'main_vehicle_model/ENCODER COUNT/MATLAB Function'
 * '<S6>'   : 'main_vehicle_model/Subsystem/If Action Subsystem'
 * '<S7>'   : 'main_vehicle_model/Subsystem/Triggered Subsystem'
 * '<S8>'   : 'main_vehicle_model/Subsystem2/If Action Subsystem'
 * '<S9>'   : 'main_vehicle_model/Subsystem2/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_main_vehicle_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
