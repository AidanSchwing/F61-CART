/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model_private.h
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

#ifndef RTW_HEADER_main_vehicle_model_private_h_
#define RTW_HEADER_main_vehicle_model_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "main_vehicle_model.h"
#include "main_vehicle_model_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
void ExtIntPinD0ForRisingEdge(void);
void ExtIntPinD1ForRisingEdge(void);
extern void main_vehi_zerooutspeed_Init(DW_zerooutspeed_main_vehicle__T *localDW);
extern void main_vehicle_m_zerooutspeed(real_T rtu_signal, real_T rtu_timeStamp,
  real_T rtu_currentTime, real_T *rty_output, DW_zerooutspeed_main_vehicle__T
  *localDW);
extern void main_v_conv_to_dir_pin_Init(DW_conv_to_dir_pin_main_vehic_T *localDW);
extern void main_vehicl_conv_to_dir_pin(real_T rtu_err, real_T *rty_dir,
  DW_conv_to_dir_pin_main_vehic_T *localDW);
extern void mai_IfActionSubsystem1_Init(real_T *rty_Wheelspeed,
  P_IfActionSubsystem1_main_veh_T *localP);
extern void main_veh_IfActionSubsystem1(real_T rtu_time_diff, real_T
  *rty_Wheelspeed, P_IfActionSubsystem1_main_veh_T *localP);
extern void main_ve_MATLABFunction_Init(DW_MATLABFunction_main_vehicl_T *localDW);
extern void main_v_MATLABFunction_Reset(DW_MATLABFunction_main_vehicl_T *localDW);
extern void main_vehicle_MATLABFunction(real_T rtu_new_time, real_T
  *rty_time_diff, real_T *rty_prev_time, DW_MATLABFunction_main_vehicl_T
  *localDW);

#endif                            /* RTW_HEADER_main_vehicle_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
