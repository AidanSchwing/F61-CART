/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: expo_proj.h
 *
 * Code generated for Simulink model 'expo_proj'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue May 21 12:39:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_expo_proj_h_
#define RTW_HEADER_expo_proj_h_
#ifndef expo_proj_COMMON_INCLUDES_
#define expo_proj_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "main.h"
#endif                                 /* expo_proj_COMMON_INCLUDES_ */

#include "expo_proj_types.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T ENC_CNT;                    /* '<Root>/Encoder' */
} B_expo_proj_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_expo_proj_T;

/* Parameters (default storage) */
struct P_expo_proj_T_ {
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
struct tag_RTM_expo_proj_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_expo_proj_T expo_proj_P;

/* Block signals (default storage) */
extern B_expo_proj_T expo_proj_B;

/* Block states (default storage) */
extern DW_expo_proj_T expo_proj_DW;

/* Model entry point functions */
extern void expo_proj_initialize(void);
extern void expo_proj_step(void);
extern void expo_proj_terminate(void);

/* Real-time Model object */
extern RT_MODEL_expo_proj_T *const expo_proj_M;
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
 * '<Root>' : 'expo_proj'
 * '<S1>'   : 'expo_proj/Digital Port Write1'
 * '<S2>'   : 'expo_proj/Digital Port Write2'
 * '<S3>'   : 'expo_proj/Digital Port Write3'
 * '<S4>'   : 'expo_proj/Digital Port Write1/ECSoC'
 * '<S5>'   : 'expo_proj/Digital Port Write1/ECSoC/ECSimCodegen'
 * '<S6>'   : 'expo_proj/Digital Port Write2/ECSoC'
 * '<S7>'   : 'expo_proj/Digital Port Write2/ECSoC/ECSimCodegen'
 * '<S8>'   : 'expo_proj/Digital Port Write3/ECSoC'
 * '<S9>'   : 'expo_proj/Digital Port Write3/ECSoC/ECSimCodegen'
 */
#endif                                 /* RTW_HEADER_expo_proj_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
