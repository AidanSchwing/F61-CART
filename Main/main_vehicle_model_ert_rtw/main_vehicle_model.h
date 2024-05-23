/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model.h
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.310
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May 23 16:02:48 2024
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

/* Block states (default storage) for system '<S4>/zero out speed' */
typedef struct {
  int32_T sfEvent;                     /* '<S4>/zero out speed' */
  uint8_T is_active_c6_main_vehicle_model;/* '<S4>/zero out speed' */
  boolean_T doneDoubleBufferReInit;    /* '<S4>/zero out speed' */
} DW_zerooutspeed_main_vehicle__T;

/* Block states (default storage) for system '<Root>/conv_to_dir_pin' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/conv_to_dir_pin' */
  uint8_T is_active_c1_main_vehicle_model;/* '<Root>/conv_to_dir_pin' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/conv_to_dir_pin' */
} DW_conv_to_dir_pin_main_vehic_T;

/* Block states (default storage) for system '<S62>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S62>/If Action Subsystem1' */
} DW_IfActionSubsystem1_main_ve_T;

/* Block states (default storage) for system '<S62>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S62>/MATLAB Function' */
  uint8_T is_active_c5_main_vehicle_model;/* '<S62>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S62>/MATLAB Function' */
} DW_MATLABFunction_main_vehicl_T;

/* Block signals (default storage) */
typedef struct {
  real_T Clock;                        /* '<S5>/Clock' */
  real_T Clock_a;                      /* '<S4>/Clock' */
  real_T braking;                      /* '<Root>/scale to % brake' */
  real_T brakeerr;                     /* '<Root>/Subtract2' */
  real_T ACT2_DUTY_ROUNDED;            /* '<Root>/Round3' */
  real_T TmpRTBAttime_deltatospeedInport;/* '<S4>/Clock' */
  real_T TmpRTBAttime_deltatospeedInpo_h;/* '<S5>/Clock' */
  real_T Inport;                       /* '<S66>/Inport' */
  real_T Divide;                       /* '<S68>/Divide' */
  real_T Inport_f;                     /* '<S62>/Inport' */
  real_T Divide_d;                     /* '<S64>/Divide' */
  real_T output;                       /* '<S5>/zero out speed' */
  real_T output_k;                     /* '<S4>/zero out speed' */
  real_T enc_count;                    /* '<S2>/Quadrature Decode' */
  boolean_T new_A;                     /* '<S2>/Quadrature Decode' */
  boolean_T new_B;                     /* '<S2>/Quadrature Decode' */
} B_main_vehicle_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  mbed_AnalogInput_main_vehicle_T obj; /* '<Root>/PRES_DUCER' */
  mbed_DigitalRead_main_vehicle_T obj_k;/* '<Root>/enc_ch_B' */
  mbed_DigitalRead_main_vehicle_T obj_f;/* '<Root>/enc_ch_A' */
  mbed_DigitalWrite_main_vehicl_T obj_i;/* '<Root>/Digital Write2' */
  mbed_DigitalWrite_main_vehicl_T obj_m;/* '<Root>/Digital Write1' */
  mbed_DigitalWrite_main_vehicl_T obj_j;/* '<Root>/Digital Write' */
  mbed_DigitalWrite_main_vehicl_T obj_l;/* '<Root>/DRIVE RELAY EN PIN' */
  mbed_DigitalWrite_main_vehicl_T obj_o;/* '<Root>/ACTUATOR 2 DIR PIN1' */
  mbed_DigitalWrite_main_vehicl_T obj_ff;/* '<Root>/ACTUATOR 1 DIR PIN1' */
  mbed_DigitalWrite_main_vehicl_T obj_n;/* '<Root>/ACT RELAY EN PIN' */
  mbed_PWMOutput_main_vehicle_m_T obj_lv;/* '<Root>/ACTUATOR 2 PWM PIN1' */
  mbed_PWMOutput_main_vehicle_m_T obj_ib;/* '<Root>/ACTUATOR 1 PWM PIN1' */
  mbed_AnalogOutput_main_vehicl_T obj_h;/* '<Root>/DRIVE MOTOR ANALOG PIN' */
  real_T UnitDelay_DSTATE;             /* '<S61>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S41>/Integrator' */
  real_T Filter_DSTATE;                /* '<S36>/Filter' */
  real_T Memory2_PreviousInput;        /* '<S2>/Memory2' */
  real_T Memory_PreviousInput;         /* '<S66>/Memory' */
  real_T Memory_PreviousInput_e;       /* '<S62>/Memory' */
  MW_Handle_Type wheelspeedintpin1_ExtIntHandle;/* '<Root>/wheelspeed int. pin1' */
  MW_Handle_Type wheelspeedintpin_ExtIntHandle;/* '<Root>/wheelspeed int. pin' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T time_deltatospeed_SubsysRanBC;/* '<S5>/time_delta to speed' */
  int8_T time_deltatospeed_SubsysRanBC_b;/* '<S4>/time_delta to speed' */
  uint8_T is_active_c2_main_vehicle_model;/* '<S2>/Quadrature Decode' */
  boolean_T Memory1_PreviousInput;     /* '<S2>/Memory1' */
  boolean_T Memory_PreviousInput_g;    /* '<S2>/Memory' */
  DW_MATLABFunction_main_vehicl_T sf_MATLABFunction_m;/* '<S66>/MATLAB Function' */
  DW_IfActionSubsystem1_main_ve_T IfActionSubsystem1_n;/* '<S66>/If Action Subsystem1' */
  DW_MATLABFunction_main_vehicl_T sf_MATLABFunction;/* '<S62>/MATLAB Function' */
  DW_IfActionSubsystem1_main_ve_T IfActionSubsystem1;/* '<S62>/If Action Subsystem1' */
  DW_conv_to_dir_pin_main_vehic_T sf_conv_to_dir_pin1;/* '<Root>/conv_to_dir_pin1' */
  DW_conv_to_dir_pin_main_vehic_T sf_conv_to_dir_pin;/* '<Root>/conv_to_dir_pin' */
  DW_zerooutspeed_main_vehicle__T sf_zerooutspeed_f;/* '<S5>/zero out speed' */
  DW_zerooutspeed_main_vehicle__T sf_zerooutspeed;/* '<S4>/zero out speed' */
} DW_main_vehicle_model_T;

/* Parameters for system: '<S62>/If Action Subsystem1' */
struct P_IfActionSubsystem1_main_veh_T_ {
  real_T Wheelspeed_Y0;                /* Computed Parameter: Wheelspeed_Y0
                                        * Referenced by: '<S64>/Wheelspeed'
                                        */
  real_T counttoradialspeed_Value;     /* Expression: 22/360*2*pi
                                        * Referenced by: '<S64>/count to radial speed'
                                        */
};

/* Parameters (default storage) */
struct P_main_vehicle_model_T_ {
  real_T DiscretePIDController_D;     /* Mask Parameter: DiscretePIDController_D
                                       * Referenced by: '<S35>/Derivative Gain'
                                       */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S38>/Integral Gain'
                                       */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S36>/Filter'
                               */
  real_T DiscretePIDController_Initial_k;
                              /* Mask Parameter: DiscretePIDController_Initial_k
                               * Referenced by: '<S41>/Integrator'
                               */
  real_T DiscretePIDController_N;     /* Mask Parameter: DiscretePIDController_N
                                       * Referenced by: '<S44>/Filter Coefficient'
                                       */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S46>/Proportional Gain'
                                       */
  real_T PRES_DUCER_SampleTime;        /* Expression: 0.001
                                        * Referenced by: '<Root>/PRES_DUCER'
                                        */
  real_T enc_ch_A_SampleTime;          /* Expression: 0.00001
                                        * Referenced by: '<Root>/enc_ch_A'
                                        */
  real_T enc_ch_B_SampleTime;          /* Expression: 0.00001
                                        * Referenced by: '<Root>/enc_ch_B'
                                        */
  real_T Outport_Y0;                   /* Computed Parameter: Outport_Y0
                                        * Referenced by: '<S62>/Outport'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S62>/Memory'
                                        */
  real_T Outport_Y0_m;                 /* Computed Parameter: Outport_Y0_m
                                        * Referenced by: '<S66>/Outport'
                                        */
  real_T Memory_InitialCondition_m;    /* Expression: 0
                                        * Referenced by: '<S66>/Memory'
                                        */
  real_T ANGLESETPOINT_Value;          /* Expression: -0.2786377708978343
                                        * Referenced by: '<Root>/ANGLE SETPOINT'
                                        */
  real_T softwareanglelimit_UpperSat;  /* Expression: 33
                                        * Referenced by: '<Root>/software angle limit'
                                        */
  real_T softwareanglelimit_LowerSat;  /* Expression: -33
                                        * Referenced by: '<Root>/software angle limit'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S2>/Memory2'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/(500*4) * 360
                                        * Referenced by: '<S2>/Gain'
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
  real_T brakesetpoint_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/brake % set point'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Filter_Constant_Value;        /* Expression: Filter_constant
                                        * Referenced by: '<S61>/Filter_Constant'
                                        */
  real_T One_Value;                    /* Expression: 1 - Filter_constant
                                        * Referenced by: '<S61>/One'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S61>/Unit Delay'
                                        */
  real_T BrakeCalibBias_Value;         /* Expression: 0.18
                                        * Referenced by: '<Root>/Brake Calib. Bias'
                                        */
  real_T scaletobrake_Gain;            /* Expression: 100/(0.42)
                                        * Referenced by: '<Root>/scale to % brake'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S36>/Filter'
                                        */
  real_T pwm_sat_UpperSat;             /* Expression: 100
                                        * Referenced by: '<Root>/pwm_sat'
                                        */
  real_T pwm_sat_LowerSat;             /* Expression: 0
                                        * Referenced by: '<Root>/pwm_sat'
                                        */
  real_T ActuatorRelay_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/Actuator Relay'
                                        */
  real_T Constant_Value;               /* Expression: 0
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
                                  * Referenced by: '<S2>/Memory1'
                                  */
  boolean_T Memory_InitialCondition_l;
                                /* Computed Parameter: Memory_InitialCondition_l
                                 * Referenced by: '<S2>/Memory'
                                 */
  P_IfActionSubsystem1_main_veh_T IfActionSubsystem1_n;/* '<S66>/If Action Subsystem1' */
  P_IfActionSubsystem1_main_veh_T IfActionSubsystem1;/* '<S62>/If Action Subsystem1' */
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
    uint32_T clockTick4;
    uint32_T clockTick5;
    uint32_T clockTickH5;
    uint8_T rtmDbBufReadBuf5;
    uint8_T rtmDbBufWriteBuf5;
    boolean_T rtmDbBufLastBufWr5;
    uint32_T rtmDbBufClockTick5[2];
    uint32_T rtmDbBufClockTickH5[2];
    uint32_T clockTick6;
    uint32_T clockTickH6;
    uint8_T rtmDbBufReadBuf6;
    uint8_T rtmDbBufWriteBuf6;
    boolean_T rtmDbBufLastBufWr6;
    uint32_T rtmDbBufClockTick6[2];
    uint32_T rtmDbBufClockTickH6[2];
    struct {
      uint16_T TID[5];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[7];
  } Timing;
};

/* Block parameters (default storage) */
extern P_main_vehicle_model_T main_vehicle_model_P;

/* Block signals (default storage) */
extern B_main_vehicle_model_T main_vehicle_model_B;

/* Block states (default storage) */
extern DW_main_vehicle_model_T main_vehicle_model_DW;

/* External function called from main */
extern void main_vehicle_model_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void main_vehicle_model_initialize(void);
extern void main_vehicle_model_step0(void);
extern void main_vehicle_model_step2(void);
extern void main_vehicle_model_step3(void);
extern void main_vehicle_model_step4(void);
extern void main_vehicle_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_main_vehicle_model_T *const main_vehicle_model_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Add1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Filter_Constant' : Unused code path elimination
 * Block '<S72>/One' : Unused code path elimination
 * Block '<S72>/Product' : Unused code path elimination
 * Block '<S72>/Product1' : Unused code path elimination
 * Block '<S72>/Unit Delay' : Unused code path elimination
 * Block '<S75>/Add1' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Filter_Constant' : Unused code path elimination
 * Block '<S75>/One' : Unused code path elimination
 * Block '<S75>/Product' : Unused code path elimination
 * Block '<S75>/Product1' : Unused code path elimination
 * Block '<S75>/Unit Delay' : Unused code path elimination
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
 * '<S1>'   : 'main_vehicle_model/Discrete PID Controller'
 * '<S2>'   : 'main_vehicle_model/ENCODER COUNT'
 * '<S3>'   : 'main_vehicle_model/IIR Filter'
 * '<S4>'   : 'main_vehicle_model/calc wheelspeed'
 * '<S5>'   : 'main_vehicle_model/calc wheelspeed1'
 * '<S6>'   : 'main_vehicle_model/conv_to_dir_pin'
 * '<S7>'   : 'main_vehicle_model/conv_to_dir_pin1'
 * '<S8>'   : 'main_vehicle_model/wheelspeed low pass'
 * '<S9>'   : 'main_vehicle_model/wheelspeed low pass1'
 * '<S10>'  : 'main_vehicle_model/Discrete PID Controller/Anti-windup'
 * '<S11>'  : 'main_vehicle_model/Discrete PID Controller/D Gain'
 * '<S12>'  : 'main_vehicle_model/Discrete PID Controller/Filter'
 * '<S13>'  : 'main_vehicle_model/Discrete PID Controller/Filter ICs'
 * '<S14>'  : 'main_vehicle_model/Discrete PID Controller/I Gain'
 * '<S15>'  : 'main_vehicle_model/Discrete PID Controller/Ideal P Gain'
 * '<S16>'  : 'main_vehicle_model/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'main_vehicle_model/Discrete PID Controller/Integrator'
 * '<S18>'  : 'main_vehicle_model/Discrete PID Controller/Integrator ICs'
 * '<S19>'  : 'main_vehicle_model/Discrete PID Controller/N Copy'
 * '<S20>'  : 'main_vehicle_model/Discrete PID Controller/N Gain'
 * '<S21>'  : 'main_vehicle_model/Discrete PID Controller/P Copy'
 * '<S22>'  : 'main_vehicle_model/Discrete PID Controller/Parallel P Gain'
 * '<S23>'  : 'main_vehicle_model/Discrete PID Controller/Reset Signal'
 * '<S24>'  : 'main_vehicle_model/Discrete PID Controller/Saturation'
 * '<S25>'  : 'main_vehicle_model/Discrete PID Controller/Saturation Fdbk'
 * '<S26>'  : 'main_vehicle_model/Discrete PID Controller/Sum'
 * '<S27>'  : 'main_vehicle_model/Discrete PID Controller/Sum Fdbk'
 * '<S28>'  : 'main_vehicle_model/Discrete PID Controller/Tracking Mode'
 * '<S29>'  : 'main_vehicle_model/Discrete PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'main_vehicle_model/Discrete PID Controller/Tsamp - Integral'
 * '<S31>'  : 'main_vehicle_model/Discrete PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'main_vehicle_model/Discrete PID Controller/postSat Signal'
 * '<S33>'  : 'main_vehicle_model/Discrete PID Controller/preSat Signal'
 * '<S34>'  : 'main_vehicle_model/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S35>'  : 'main_vehicle_model/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S36>'  : 'main_vehicle_model/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S37>'  : 'main_vehicle_model/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S38>'  : 'main_vehicle_model/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S39>'  : 'main_vehicle_model/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'main_vehicle_model/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'main_vehicle_model/Discrete PID Controller/Integrator/Discrete'
 * '<S42>'  : 'main_vehicle_model/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'main_vehicle_model/Discrete PID Controller/N Copy/Disabled'
 * '<S44>'  : 'main_vehicle_model/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S45>'  : 'main_vehicle_model/Discrete PID Controller/P Copy/Disabled'
 * '<S46>'  : 'main_vehicle_model/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'main_vehicle_model/Discrete PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'main_vehicle_model/Discrete PID Controller/Saturation/Passthrough'
 * '<S49>'  : 'main_vehicle_model/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'main_vehicle_model/Discrete PID Controller/Sum/Sum_PID'
 * '<S51>'  : 'main_vehicle_model/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'main_vehicle_model/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'main_vehicle_model/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'main_vehicle_model/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'main_vehicle_model/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'main_vehicle_model/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'main_vehicle_model/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'main_vehicle_model/ENCODER COUNT/Quadrature Decode'
 * '<S59>'  : 'main_vehicle_model/IIR Filter/IIR Filter'
 * '<S60>'  : 'main_vehicle_model/IIR Filter/IIR Filter/Low-pass'
 * '<S61>'  : 'main_vehicle_model/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S62>'  : 'main_vehicle_model/calc wheelspeed/time_delta to speed'
 * '<S63>'  : 'main_vehicle_model/calc wheelspeed/zero out speed'
 * '<S64>'  : 'main_vehicle_model/calc wheelspeed/time_delta to speed/If Action Subsystem1'
 * '<S65>'  : 'main_vehicle_model/calc wheelspeed/time_delta to speed/MATLAB Function'
 * '<S66>'  : 'main_vehicle_model/calc wheelspeed1/time_delta to speed'
 * '<S67>'  : 'main_vehicle_model/calc wheelspeed1/zero out speed'
 * '<S68>'  : 'main_vehicle_model/calc wheelspeed1/time_delta to speed/If Action Subsystem1'
 * '<S69>'  : 'main_vehicle_model/calc wheelspeed1/time_delta to speed/MATLAB Function'
 * '<S70>'  : 'main_vehicle_model/wheelspeed low pass/IIR Filter'
 * '<S71>'  : 'main_vehicle_model/wheelspeed low pass/IIR Filter/Low-pass'
 * '<S72>'  : 'main_vehicle_model/wheelspeed low pass/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S73>'  : 'main_vehicle_model/wheelspeed low pass1/IIR Filter'
 * '<S74>'  : 'main_vehicle_model/wheelspeed low pass1/IIR Filter/Low-pass'
 * '<S75>'  : 'main_vehicle_model/wheelspeed low pass1/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* RTW_HEADER_main_vehicle_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
