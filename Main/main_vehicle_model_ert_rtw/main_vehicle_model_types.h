/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model_types.h
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.331
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 29 00:34:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_main_vehicle_model_types_h_
#define RTW_HEADER_main_vehicle_model_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/enc_ch_B' */
#include "MW_SVD.h"
#ifndef struct_tag_KxFW01GBdhqk5JOEHU3GlD
#define struct_tag_KxFW01GBdhqk5JOEHU3GlD

struct tag_KxFW01GBdhqk5JOEHU3GlD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_KxFW01GBdhqk5JOEHU3GlD */

#ifndef typedef_mbed_DigitalWrite_main_vehicl_T
#define typedef_mbed_DigitalWrite_main_vehicl_T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_main_vehicl_T;

#endif                             /* typedef_mbed_DigitalWrite_main_vehicl_T */

#ifndef struct_tag_UndvUYqhBVOhRRpUse3fWF
#define struct_tag_UndvUYqhBVOhRRpUse3fWF

struct tag_UndvUYqhBVOhRRpUse3fWF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_UndvUYqhBVOhRRpUse3fWF */

#ifndef typedef_mbed_PWMOutput_main_vehicle_m_T
#define typedef_mbed_PWMOutput_main_vehicle_m_T

typedef struct tag_UndvUYqhBVOhRRpUse3fWF mbed_PWMOutput_main_vehicle_m_T;

#endif                             /* typedef_mbed_PWMOutput_main_vehicle_m_T */

#ifndef struct_tag_LqyuMmJIWYfQ3MCRdlPEPB
#define struct_tag_LqyuMmJIWYfQ3MCRdlPEPB

struct tag_LqyuMmJIWYfQ3MCRdlPEPB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_ANALOGOUT_HANDLE;
};

#endif                                 /* struct_tag_LqyuMmJIWYfQ3MCRdlPEPB */

#ifndef typedef_mbed_AnalogOutput_main_vehicl_T
#define typedef_mbed_AnalogOutput_main_vehicl_T

typedef struct tag_LqyuMmJIWYfQ3MCRdlPEPB mbed_AnalogOutput_main_vehicl_T;

#endif                             /* typedef_mbed_AnalogOutput_main_vehicl_T */

#ifndef struct_tag_p5Oj7yF0nd6COoUgI0GAlG
#define struct_tag_p5Oj7yF0nd6COoUgI0GAlG

struct tag_p5Oj7yF0nd6COoUgI0GAlG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_p5Oj7yF0nd6COoUgI0GAlG */

#ifndef typedef_mbed_AnalogInput_main_vehicle_T
#define typedef_mbed_AnalogInput_main_vehicle_T

typedef struct tag_p5Oj7yF0nd6COoUgI0GAlG mbed_AnalogInput_main_vehicle_T;

#endif                             /* typedef_mbed_AnalogInput_main_vehicle_T */

#ifndef struct_tag_5FwKk6wA1XPbMoI1XCDeDF
#define struct_tag_5FwKk6wA1XPbMoI1XCDeDF

struct tag_5FwKk6wA1XPbMoI1XCDeDF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_5FwKk6wA1XPbMoI1XCDeDF */

#ifndef typedef_mbed_DigitalRead_main_vehicle_T
#define typedef_mbed_DigitalRead_main_vehicle_T

typedef struct tag_5FwKk6wA1XPbMoI1XCDeDF mbed_DigitalRead_main_vehicle_T;

#endif                             /* typedef_mbed_DigitalRead_main_vehicle_T */

/* Parameters for system: '<S62>/If Action Subsystem1' */
typedef struct P_IfActionSubsystem1_main_veh_T_ P_IfActionSubsystem1_main_veh_T;

/* Parameters (default storage) */
typedef struct P_main_vehicle_model_T_ P_main_vehicle_model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_main_vehicle_model_T RT_MODEL_main_vehicle_model_T;

#endif                              /* RTW_HEADER_main_vehicle_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
