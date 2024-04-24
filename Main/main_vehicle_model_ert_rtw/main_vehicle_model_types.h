/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model_types.h
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Apr 23 15:37:12 2024
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

/* Custom Type definition for MATLABSystem: '<Root>/PWM Output1' */
#include "MW_SVD.h"
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

#ifndef struct_tag_45NO01sr76bOLMYCTk1zwH
#define struct_tag_45NO01sr76bOLMYCTk1zwH

struct tag_45NO01sr76bOLMYCTk1zwH
{
  real_T currentTime;
};

#endif                                 /* struct_tag_45NO01sr76bOLMYCTk1zwH */

#ifndef typedef_f_codertarget_mbed_internal_M_T
#define typedef_f_codertarget_mbed_internal_M_T

typedef struct tag_45NO01sr76bOLMYCTk1zwH f_codertarget_mbed_internal_M_T;

#endif                             /* typedef_f_codertarget_mbed_internal_M_T */

#ifndef struct_tag_aKWq6a6RxmYGQum8qfKjlF
#define struct_tag_aKWq6a6RxmYGQum8qfKjlF

struct tag_aKWq6a6RxmYGQum8qfKjlF
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_aKWq6a6RxmYGQum8qfKjlF */

#ifndef typedef_f_matlabshared_devicedrivers__T
#define typedef_f_matlabshared_devicedrivers__T

typedef struct tag_aKWq6a6RxmYGQum8qfKjlF f_matlabshared_devicedrivers__T;

#endif                             /* typedef_f_matlabshared_devicedrivers__T */

#ifndef struct_tag_MYJ770bjSLi75gskT6UTJF
#define struct_tag_MYJ770bjSLi75gskT6UTJF

struct tag_MYJ770bjSLi75gskT6UTJF
{
  uint8_T Bus;
  uint8_T DeviceAddress;
  f_matlabshared_devicedrivers__T *InterfaceObj;
  f_matlabshared_devicedrivers__T _pobj0;
};

#endif                                 /* struct_tag_MYJ770bjSLi75gskT6UTJF */

#ifndef typedef_f_matlabshared_sensors_coder__T
#define typedef_f_matlabshared_sensors_coder__T

typedef struct tag_MYJ770bjSLi75gskT6UTJF f_matlabshared_sensors_coder__T;

#endif                             /* typedef_f_matlabshared_sensors_coder__T */

#ifndef struct_tag_muda4i2FAYG3EuGictkYcG
#define struct_tag_muda4i2FAYG3EuGictkYcG

struct tag_muda4i2FAYG3EuGictkYcG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  f_codertarget_mbed_internal_M_T *Parent;
  f_matlabshared_sensors_coder__T *Device;
  real_T UserBank;
  f_matlabshared_sensors_coder__T _pobj0;
};

#endif                                 /* struct_tag_muda4i2FAYG3EuGictkYcG */

#ifndef typedef_e_sensors_internal_icm20948_a_T
#define typedef_e_sensors_internal_icm20948_a_T

typedef struct tag_muda4i2FAYG3EuGictkYcG e_sensors_internal_icm20948_a_T;

#endif                             /* typedef_e_sensors_internal_icm20948_a_T */

#ifndef struct_tag_eFI6gcYu2CWgNWChW3jiGC
#define struct_tag_eFI6gcYu2CWgNWChW3jiGC

struct tag_eFI6gcYu2CWgNWChW3jiGC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  f_codertarget_mbed_internal_M_T *Parent;
  f_matlabshared_sensors_coder__T *Device;
  f_matlabshared_sensors_coder__T _pobj0;
};

#endif                                 /* struct_tag_eFI6gcYu2CWgNWChW3jiGC */

#ifndef typedef_b_sensors_internal_ak09916_ma_T
#define typedef_b_sensors_internal_ak09916_ma_T

typedef struct tag_eFI6gcYu2CWgNWChW3jiGC b_sensors_internal_ak09916_ma_T;

#endif                             /* typedef_b_sensors_internal_ak09916_ma_T */

#ifndef struct_tag_LBGcLZTtGRb7kSFgx384e
#define struct_tag_LBGcLZTtGRb7kSFgx384e

struct tag_LBGcLZTtGRb7kSFgx384e
{
  e_sensors_internal_icm20948_a_T *f1;
  b_sensors_internal_ak09916_ma_T *f2;
};

#endif                                 /* struct_tag_LBGcLZTtGRb7kSFgx384e */

#ifndef typedef_dc_cell_main_vehicle_model_T
#define typedef_dc_cell_main_vehicle_model_T

typedef struct tag_LBGcLZTtGRb7kSFgx384e dc_cell_main_vehicle_model_T;

#endif                                /* typedef_dc_cell_main_vehicle_model_T */

#ifndef struct_tag_vAdOa5udNO5g0UB6E8cPDB
#define struct_tag_vAdOa5udNO5g0UB6E8cPDB

struct tag_vAdOa5udNO5g0UB6E8cPDB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  f_codertarget_mbed_internal_M_T *Parent;
  dc_cell_main_vehicle_model_T SensorObjects;
  b_sensors_internal_ak09916_ma_T _pobj0;
  e_sensors_internal_icm20948_a_T _pobj1;
};

#endif                                 /* struct_tag_vAdOa5udNO5g0UB6E8cPDB */

#ifndef typedef_b_icm20948_main_vehicle_model_T
#define typedef_b_icm20948_main_vehicle_model_T

typedef struct tag_vAdOa5udNO5g0UB6E8cPDB b_icm20948_main_vehicle_model_T;

#endif                             /* typedef_b_icm20948_main_vehicle_model_T */

#ifndef struct_tag_As8gYj3mjzMic4nXDF1rQG
#define struct_tag_As8gYj3mjzMic4nXDF1rQG

struct tag_As8gYj3mjzMic4nXDF1rQG
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_As8gYj3mjzMic4nXDF1rQG */

#ifndef typedef_h_matlabshared_sensors_simuli_T
#define typedef_h_matlabshared_sensors_simuli_T

typedef struct tag_As8gYj3mjzMic4nXDF1rQG h_matlabshared_sensors_simuli_T;

#endif                             /* typedef_h_matlabshared_sensors_simuli_T */

#ifndef struct_tag_emaM8BrQJAuATZkkqWHyXF
#define struct_tag_emaM8BrQJAuATZkkqWHyXF

struct tag_emaM8BrQJAuATZkkqWHyXF
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_emaM8BrQJAuATZkkqWHyXF */

#ifndef typedef_i_matlabshared_sensors_simuli_T
#define typedef_i_matlabshared_sensors_simuli_T

typedef struct tag_emaM8BrQJAuATZkkqWHyXF i_matlabshared_sensors_simuli_T;

#endif                             /* typedef_i_matlabshared_sensors_simuli_T */

#ifndef struct_tag_n1EGzm0lQI5HNFCanDcWuD
#define struct_tag_n1EGzm0lQI5HNFCanDcWuD

struct tag_n1EGzm0lQI5HNFCanDcWuD
{
  h_matlabshared_sensors_simuli_T *f1;
  i_matlabshared_sensors_simuli_T *f2;
};

#endif                                 /* struct_tag_n1EGzm0lQI5HNFCanDcWuD */

#ifndef typedef_ec_cell_main_vehicle_model_T
#define typedef_ec_cell_main_vehicle_model_T

typedef struct tag_n1EGzm0lQI5HNFCanDcWuD ec_cell_main_vehicle_model_T;

#endif                                /* typedef_ec_cell_main_vehicle_model_T */

#ifndef struct_tag_SOZSojNkdsyIbJ9UrSNKSE
#define struct_tag_SOZSojNkdsyIbJ9UrSNKSE

struct tag_SOZSojNkdsyIbJ9UrSNKSE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  f_codertarget_mbed_internal_M_T *HwUtilityObject;
  b_icm20948_main_vehicle_model_T *SensorObject;
  ec_cell_main_vehicle_model_T OutputModules;
  boolean_T __OutputModules_AssignmentSentinel;
  i_matlabshared_sensors_simuli_T _pobj0;
  h_matlabshared_sensors_simuli_T _pobj1;
  b_icm20948_main_vehicle_model_T _pobj2;
  f_codertarget_mbed_internal_M_T _pobj3;
};

#endif                                 /* struct_tag_SOZSojNkdsyIbJ9UrSNKSE */

#ifndef typedef_sensors_raspberrypi_ICM20948B_T
#define typedef_sensors_raspberrypi_ICM20948B_T

typedef struct tag_SOZSojNkdsyIbJ9UrSNKSE sensors_raspberrypi_ICM20948B_T;

#endif                             /* typedef_sensors_raspberrypi_ICM20948B_T */

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
