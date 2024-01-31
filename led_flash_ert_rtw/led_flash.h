/*
 * led_flash.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "led_flash".
 *
 * Model version              : 1.15
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Jan 30 17:15:05 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_led_flash_h_
#define RTW_HEADER_led_flash_h_
#ifndef led_flash_COMMON_INCLUDES_
#define led_flash_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#endif                                 /* led_flash_COMMON_INCLUDES_ */

#include "led_flash_types.h"
#include <string.h>
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
  real_T IMUACCEL[3];                  /* '<Root>/ICM20948 IMU Sensor' */
  uint32_T pinname;
  MW_AnalogIn_TriggerSource_Type trigger_val;
  MW_I2C_Mode_Type modename;
  MW_I2C_Mode_Type modename_m;
  real_T AnalogInput3;                 /* '<Root>/Analog Input3' */
  real_T AnalogInput2;                 /* '<Root>/Analog Input2' */
  real_T PRESSURE;                     /* '<Root>/Analog Input' */
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  uint8_T b_data[2];
  uint8_T b_data_c[2];
  uint8_T b_data_k[2];
  uint8_T val;
  uint8_T i2cModule;
  uint8_T b_status;
  uint8_T val_c;
  uint8_T i2cModule_b;
  uint8_T b_status_p;
  uint8_T orValue;
  uint8_T b_value;
  uint8_T slaveAddress;
  uint8_T b_status_c;
  boolean_T digital;                   /* '<Root>/Digital Read2' */
  boolean_T DigitalRead;               /* '<Root>/Digital Read' */
} B_led_flash_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  sensors_raspberrypi_ICM20948B_T obj; /* '<Root>/ICM20948 IMU Sensor' */
  mbed_AnalogInput_led_flash_T obj_b;  /* '<Root>/Analog Input3' */
  mbed_AnalogInput_led_flash_T obj_g;  /* '<Root>/Analog Input2' */
  mbed_AnalogInput_led_flash_T obj_h;  /* '<Root>/Analog Input' */
  mbed_DigitalRead_led_flash_T obj_l;  /* '<Root>/Digital Read2' */
  mbed_DigitalRead_led_flash_T obj_d;  /* '<Root>/Digital Read' */
  mbed_DigitalWrite_led_flash_T obj_bo;/* '<Root>/Digital Write2' */
  mbed_DigitalWrite_led_flash_T obj_j; /* '<Root>/Digital Write1' */
  mbed_DigitalWrite_led_flash_T obj_p; /* '<Root>/Digital Write' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  boolean_T objisempty;                /* '<Root>/ICM20948 IMU Sensor' */
  boolean_T objisempty_m;              /* '<Root>/Digital Write2' */
  boolean_T objisempty_a;              /* '<Root>/Digital Write1' */
  boolean_T objisempty_n;              /* '<Root>/Digital Write' */
  boolean_T objisempty_p;              /* '<Root>/Digital Read2' */
  boolean_T objisempty_ag;             /* '<Root>/Digital Read' */
  boolean_T objisempty_az;             /* '<Root>/Analog Input3' */
  boolean_T objisempty_c;              /* '<Root>/Analog Input2' */
  boolean_T objisempty_g;              /* '<Root>/Analog Input' */
} DW_led_flash_T;

/* Parameters (default storage) */
struct P_led_flash_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T AnalogInput3_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input3'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T DigitalRead2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Digital Read2'
                                        */
  real_T ICM20948IMUSensor_SampleTime; /* Expression: -1
                                        * Referenced by: '<Root>/ICM20948 IMU Sensor'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_led_flash_T {
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
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_led_flash_T led_flash_P;

/* Block signals (default storage) */
extern B_led_flash_T led_flash_B;

/* Block states (default storage) */
extern DW_led_flash_T led_flash_DW;

/* Model entry point functions */
extern void led_flash_initialize(void);
extern void led_flash_step(void);
extern void led_flash_terminate(void);

/* Real-time Model object */
extern RT_MODEL_led_flash_T *const led_flash_M;
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
 * '<Root>' : 'led_flash'
 */
#endif                                 /* RTW_HEADER_led_flash_h_ */
