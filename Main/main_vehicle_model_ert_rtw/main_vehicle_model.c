/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model.c
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

#include "main_vehicle_model.h"
#include "rtwtypes.h"
#include "main_vehicle_model_private.h"
#include <math.h>
#include "xcp.h"
#include "ext_mode.h"

/* Named constants for MATLAB Function: '<S4>/zero out speed' */
#define main_vehicle_model_CALL_EVENT  (-1)

/* Named constants for MATLAB Function: '<Root>/conv_to_dir_pin' */
#define main_vehicle_model_CALL_EVENT_g (-1)

/* Named constants for MATLAB Function: '<S62>/MATLAB Function' */
#define main_vehicle_model_CALL_EVENT_a (-1)

/* Block signals (default storage) */
B_main_vehicle_model_T main_vehicle_model_B;

/* Block states (default storage) */
DW_main_vehicle_model_T main_vehicle_model_DW;

/* Real-time model */
static RT_MODEL_main_vehicle_model_T main_vehicle_model_M_;
RT_MODEL_main_vehicle_model_T *const main_vehicle_model_M =
  &main_vehicle_model_M_;
static void rate_monotonic_scheduler(void);

/* Callback for Hardware Interrupt Block: '<Root>/wheelspeed int. pin' */
void ExtIntPinD1ForRisingEdge(void)
{
  if (1 == runModel) {
    /* Call the system: <S4>/time_delta to speed */
    {
      /* Reset subsysRan breadcrumbs */
      srClearBC
        (main_vehicle_model_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(main_vehicle_model_DW.time_deltatospeed_SubsysRanBC_b);

      /* RateTransition generated from: '<S4>/time_delta to speed' */
      main_vehicle_model_B.TmpRTBAttime_deltatospeedInport =
        main_vehicle_model_B.Clock_a;

      /* S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin' */

      /* Output and update for function-call system: '<S4>/time_delta to speed' */
      {
        real_T time_diff_i;

        /* Asynchronous task (with no priority assigned)
         * reads absolute time */
        switch (main_vehicle_model_M->Timing.rtmDbBufWriteBuf5) {
         case 0:
          main_vehicle_model_M->Timing.rtmDbBufReadBuf5 = 1;
          break;

         case 1:
          main_vehicle_model_M->Timing.rtmDbBufReadBuf5 = 0;
          break;

         default:
          main_vehicle_model_M->Timing.rtmDbBufReadBuf5 =
            main_vehicle_model_M->Timing.rtmDbBufLastBufWr5;
          break;
        }

        main_vehicle_model_M->Timing.clockTick5 =
          main_vehicle_model_M->Timing.rtmDbBufClockTick5
          [main_vehicle_model_M->Timing.rtmDbBufReadBuf5];
        main_vehicle_model_M->Timing.clockTickH5 =
          main_vehicle_model_M->Timing.rtmDbBufClockTickH5
          [main_vehicle_model_M->Timing.rtmDbBufReadBuf5];
        main_vehicle_model_M->Timing.rtmDbBufReadBuf5 = 0xFF;

        /* SignalConversion generated from: '<S62>/Inport' */
        main_vehicle_model_B.Inport_f =
          main_vehicle_model_B.TmpRTBAttime_deltatospeedInport;

        /* Update for Memory: '<S62>/Memory' incorporates:
         *  MATLAB Function: '<S62>/MATLAB Function'
         */
        main_vehicle_MATLABFunction(main_vehicle_model_B.Inport_f, &time_diff_i,
          &main_vehicle_model_DW.Memory_PreviousInput_e,
          &main_vehicle_model_DW.sf_MATLABFunction);

        /* If: '<S62>/If1' */
        if (time_diff_i > 0.0) {
          /* Outputs for IfAction SubSystem: '<S62>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S64>/Action Port'
           */
          main_veh_IfActionSubsystem1(time_diff_i,
            &main_vehicle_model_B.Divide_d,
            &main_vehicle_model_P.IfActionSubsystem1);

          /* End of Outputs for SubSystem: '<S62>/If Action Subsystem1' */
        }

        /* End of If: '<S62>/If1' */
        main_vehicle_model_DW.time_deltatospeed_SubsysRanBC_b = 4;
      }

      /* End of Outputs for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin' */
    }

    extmodeEvent(5,(((main_vehicle_model_M->Timing.clockTick5+
                      main_vehicle_model_M->Timing.clockTickH5* 4294967296.0)) *
                    1.0E-5));
  }
}

/* Callback for Hardware Interrupt Block: '<Root>/wheelspeed int. pin2' */
void ExtIntPinD0ForRisingEdge(void)
{
  if (1 == runModel) {
    /* Call the system: <S5>/time_delta to speed */
    {
      /* Reset subsysRan breadcrumbs */
      srClearBC(main_vehicle_model_DW.time_deltatospeed_SubsysRanBC);

      /* RateTransition generated from: '<S5>/time_delta to speed' */
      main_vehicle_model_B.TmpRTBAttime_deltatospeedInpo_h =
        main_vehicle_model_B.Clock;

      /* S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin2' */

      /* Output and update for function-call system: '<S5>/time_delta to speed' */
      {
        real_T time_diff;

        /* Asynchronous task (with no priority assigned)
         * reads absolute time */
        switch (main_vehicle_model_M->Timing.rtmDbBufWriteBuf6) {
         case 0:
          main_vehicle_model_M->Timing.rtmDbBufReadBuf6 = 1;
          break;

         case 1:
          main_vehicle_model_M->Timing.rtmDbBufReadBuf6 = 0;
          break;

         default:
          main_vehicle_model_M->Timing.rtmDbBufReadBuf6 =
            main_vehicle_model_M->Timing.rtmDbBufLastBufWr6;
          break;
        }

        main_vehicle_model_M->Timing.clockTick6 =
          main_vehicle_model_M->Timing.rtmDbBufClockTick6
          [main_vehicle_model_M->Timing.rtmDbBufReadBuf6];
        main_vehicle_model_M->Timing.clockTickH6 =
          main_vehicle_model_M->Timing.rtmDbBufClockTickH6
          [main_vehicle_model_M->Timing.rtmDbBufReadBuf6];
        main_vehicle_model_M->Timing.rtmDbBufReadBuf6 = 0xFF;

        /* SignalConversion generated from: '<S66>/Inport' */
        main_vehicle_model_B.Inport =
          main_vehicle_model_B.TmpRTBAttime_deltatospeedInpo_h;

        /* Update for Memory: '<S66>/Memory' incorporates:
         *  MATLAB Function: '<S66>/MATLAB Function'
         */
        main_vehicle_MATLABFunction(main_vehicle_model_B.Inport, &time_diff,
          &main_vehicle_model_DW.Memory_PreviousInput,
          &main_vehicle_model_DW.sf_MATLABFunction_h);

        /* If: '<S66>/If1' */
        if (time_diff > 0.0) {
          /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S68>/Action Port'
           */
          main_veh_IfActionSubsystem1(time_diff, &main_vehicle_model_B.Divide,
            &main_vehicle_model_P.IfActionSubsystem1_i);

          /* End of Outputs for SubSystem: '<S66>/If Action Subsystem1' */
        }

        /* End of If: '<S66>/If1' */
        main_vehicle_model_DW.time_deltatospeed_SubsysRanBC = 4;
      }

      /* End of Outputs for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin2' */
    }

    extmodeEvent(6,(((main_vehicle_model_M->Timing.clockTick6+
                      main_vehicle_model_M->Timing.clockTickH6* 4294967296.0)) *
                    1.0E-5));
  }
}

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
  eventFlags[4] = ((boolean_T)rtmStepTask(main_vehicle_model_M, 4));
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
  if ((main_vehicle_model_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.001s, 0.0s] */
    main_vehicle_model_M->Timing.TaskCounters.TID[2] = 0;
  }

  (main_vehicle_model_M->Timing.TaskCounters.TID[3])++;
  if ((main_vehicle_model_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [0.01s, 0.0s] */
    main_vehicle_model_M->Timing.TaskCounters.TID[3] = 0;
  }

  (main_vehicle_model_M->Timing.TaskCounters.TID[4])++;
  if ((main_vehicle_model_M->Timing.TaskCounters.TID[4]) > 24999) {/* Sample time: [0.25s, 0.0s] */
    main_vehicle_model_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S4>/zero out speed'
 *    '<S5>/zero out speed'
 */
void main_vehi_zerooutspeed_Init(DW_zerooutspeed_main_vehicle__T *localDW)
{
  localDW->sfEvent = main_vehicle_model_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S4>/zero out speed'
 *    '<S5>/zero out speed'
 */
void main_vehicle_m_zerooutspeed(real_T rtu_signal, real_T rtu_timeStamp, real_T
  rtu_currentTime, real_T *rty_output, DW_zerooutspeed_main_vehicle__T *localDW)
{
  localDW->sfEvent = main_vehicle_model_CALL_EVENT;
  if (rtu_currentTime - rtu_timeStamp > 0.16666666666666666) {
    *rty_output = 0.0;
  } else {
    *rty_output = rtu_signal;
  }
}

/*
 * System initialize for atomic system:
 *    '<Root>/conv_to_dir_pin'
 *    '<Root>/conv_to_dir_pin1'
 */
void main_v_conv_to_dir_pin_Init(DW_conv_to_dir_pin_main_vehic_T *localDW)
{
  localDW->sfEvent = main_vehicle_model_CALL_EVENT_g;
}

/*
 * Output and update for atomic system:
 *    '<Root>/conv_to_dir_pin'
 *    '<Root>/conv_to_dir_pin1'
 */
void main_vehicl_conv_to_dir_pin(real_T rtu_err, real_T *rty_dir,
  DW_conv_to_dir_pin_main_vehic_T *localDW)
{
  localDW->sfEvent = main_vehicle_model_CALL_EVENT_g;
  *rty_dir = -1.0;
  if (rtu_err >= 0.0) {
    *rty_dir = 0.0;
  } else if (rtu_err < 0.0) {
    *rty_dir = 1.0;
  }
}

/*
 * System initialize for action system:
 *    '<S62>/If Action Subsystem1'
 *    '<S66>/If Action Subsystem1'
 */
void mai_IfActionSubsystem1_Init(real_T *rty_Wheelspeed,
  P_IfActionSubsystem1_main_veh_T *localP)
{
  /* SystemInitialize for Outport: '<S64>/Wheelspeed' */
  *rty_Wheelspeed = localP->Wheelspeed_Y0;
}

/*
 * Output and update for action system:
 *    '<S62>/If Action Subsystem1'
 *    '<S66>/If Action Subsystem1'
 */
void main_veh_IfActionSubsystem1(real_T rtu_time_diff, real_T *rty_Wheelspeed,
  P_IfActionSubsystem1_main_veh_T *localP)
{
  /* Product: '<S64>/Divide' incorporates:
   *  Constant: '<S64>/count to radial speed'
   */
  *rty_Wheelspeed = localP->counttoradialspeed_Value / rtu_time_diff;
}

/*
 * System initialize for atomic system:
 *    '<S62>/MATLAB Function'
 *    '<S66>/MATLAB Function'
 */
void main_ve_MATLABFunction_Init(DW_MATLABFunction_main_vehicl_T *localDW)
{
  localDW->sfEvent = main_vehicle_model_CALL_EVENT_a;
}

/*
 * System reset for atomic system:
 *    '<S62>/MATLAB Function'
 *    '<S66>/MATLAB Function'
 */
void main_v_MATLABFunction_Reset(DW_MATLABFunction_main_vehicl_T *localDW)
{
  localDW->doneDoubleBufferReInit = false;
  localDW->sfEvent = main_vehicle_model_CALL_EVENT_a;
}

/*
 * Output and update for atomic system:
 *    '<S62>/MATLAB Function'
 *    '<S66>/MATLAB Function'
 */
void main_vehicle_MATLABFunction(real_T rtu_new_time, real_T *rty_time_diff,
  real_T *rty_prev_time, DW_MATLABFunction_main_vehicl_T *localDW)
{
  localDW->sfEvent = main_vehicle_model_CALL_EVENT_a;
  *rty_time_diff = rtu_new_time - *rty_prev_time;
  *rty_prev_time = rtu_new_time;
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
  real_T dir_g;
  real_T rtb_steer_ang_errdeg;
  static const int8_T b[16] = { 0, 1, -1, 2, -1, 0, 2, 1, 1, 2, 0, -1, 2, -1, 1,
    0 };

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

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

  /* MATLAB Function: '<S2>/Quadrature Decode' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  MATLABSystem: '<Root>/enc_ch_A'
   *  MATLABSystem: '<Root>/enc_ch_B'
   *  Memory: '<S2>/Memory'
   *  Memory: '<S2>/Memory1'
   *  Memory: '<S2>/Memory2'
   *  Sum: '<S2>/Add1'
   *  Sum: '<S2>/Add2'
   *  Sum: '<S2>/Add4'
   */
  main_vehicle_model_B.enc_count = (real_T)b[(int32_T)
    ((((main_vehicle_model_P.Constant2_Value + (real_T)
        main_vehicle_model_DW.Memory1_PreviousInput) * 2.0 +
       (main_vehicle_model_P.Constant4_Value + (real_T)
        main_vehicle_model_DW.Memory_PreviousInput_g)) * 4.0 + ((real_T)
       main_vehicle_model_B.new_A * 2.0 + (real_T)main_vehicle_model_B.new_B)) +
     1.0) - 1] + (main_vehicle_model_P.Constant3_Value +
                  main_vehicle_model_DW.Memory2_PreviousInput);

  /* Saturate: '<Root>/software angle limit' incorporates:
   *  Constant: '<Root>/ANGLE SETPOINT'
   */
  if (main_vehicle_model_P.ANGLESETPOINT_Value >
      main_vehicle_model_P.softwareanglelimit_UpperSat) {
    rtb_steer_ang_errdeg = main_vehicle_model_P.softwareanglelimit_UpperSat;
  } else if (main_vehicle_model_P.ANGLESETPOINT_Value <
             main_vehicle_model_P.softwareanglelimit_LowerSat) {
    rtb_steer_ang_errdeg = main_vehicle_model_P.softwareanglelimit_LowerSat;
  } else {
    rtb_steer_ang_errdeg = main_vehicle_model_P.ANGLESETPOINT_Value;
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Gain: '<S2>/Gain'
   *  Saturate: '<Root>/software angle limit'
   */
  rtb_steer_ang_errdeg -= main_vehicle_model_P.Gain_Gain *
    main_vehicle_model_B.enc_count;

  /* MATLAB Function: '<Root>/conv_to_dir_pin' */
  main_vehicl_conv_to_dir_pin(rtb_steer_ang_errdeg, &dir_g,
    &main_vehicle_model_DW.sf_conv_to_dir_pin);

  /* MATLABSystem: '<Root>/ACTUATOR 1 DIR PIN1' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_ff.MW_DIGITALIO_HANDLE, dir_g !=
                     0.0);

  /* Gain: '<Root>/Kp' incorporates:
   *  Abs: '<Root>/Abs'
   */
  rtb_steer_ang_errdeg = main_vehicle_model_P.Kp_Gain * fabs
    (rtb_steer_ang_errdeg);

  /* Saturate: '<Root>/pwm_saturation' */
  if (rtb_steer_ang_errdeg > main_vehicle_model_P.pwm_saturation_UpperSat) {
    rtb_steer_ang_errdeg = main_vehicle_model_P.pwm_saturation_UpperSat;
  } else if (rtb_steer_ang_errdeg < main_vehicle_model_P.pwm_saturation_LowerSat)
  {
    rtb_steer_ang_errdeg = main_vehicle_model_P.pwm_saturation_LowerSat;
  }

  /* MATLABSystem: '<Root>/ACTUATOR 1 PWM PIN1' incorporates:
   *  Rounding: '<Root>/Round2'
   *  Saturate: '<Root>/pwm_saturation'
   */
  MW_PWM_SetDutyCycle(main_vehicle_model_DW.obj_ib.MW_PWM_HANDLE, rt_roundd_snf
                      (rtb_steer_ang_errdeg));

  /* MATLABSystem: '<Root>/DRIVE RELAY EN PIN' incorporates:
   *  Constant: '<Root>/Drive Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.DriveRelay_Value != 0.0);

  /* Clock: '<S5>/Clock' incorporates:
   *  Clock: '<S4>/Clock'
   */
  rtb_steer_ang_errdeg = main_vehicle_model_M->Timing.t[0];

  /* Clock: '<S5>/Clock' */
  main_vehicle_model_B.Clock = rtb_steer_ang_errdeg;

  /* MATLAB Function: '<S5>/zero out speed' incorporates:
   *  RateTransition generated from: '<S5>/time_delta to speed'
   * */
  main_vehicle_m_zerooutspeed(main_vehicle_model_B.Divide,
    main_vehicle_model_B.Inport, main_vehicle_model_B.Clock, &dir_g,
    &main_vehicle_model_DW.sf_zerooutspeed_a);

  /* Sum: '<S75>/Add1' incorporates:
   *  Constant: '<S75>/Filter_Constant'
   *  Constant: '<S75>/One'
   *  Product: '<S75>/Product'
   *  Product: '<S75>/Product1'
   *  UnitDelay: '<S75>/Unit Delay'
   */
  main_vehicle_model_B.Add1 = dir_g * main_vehicle_model_P.Filter_Constant_Value
    + main_vehicle_model_P.One_Value * main_vehicle_model_DW.UnitDelay_DSTATE;

  /* Gain: '<Root>/Gain' */
  main_vehicle_model_B.wheelspeedRfiltered = main_vehicle_model_P.Gain_Gain_p *
    main_vehicle_model_B.Add1;

  /* Clock: '<S4>/Clock' */
  main_vehicle_model_B.Clock_a = rtb_steer_ang_errdeg;

  /* MATLAB Function: '<S4>/zero out speed' incorporates:
   *  RateTransition generated from: '<S4>/time_delta to speed'
   * */
  main_vehicle_m_zerooutspeed(main_vehicle_model_B.Divide_d,
    main_vehicle_model_B.Inport_f, main_vehicle_model_B.Clock_a,
    &rtb_steer_ang_errdeg, &main_vehicle_model_DW.sf_zerooutspeed);

  /* Sum: '<S72>/Add1' incorporates:
   *  Constant: '<S72>/Filter_Constant'
   *  Constant: '<S72>/One'
   *  Product: '<S72>/Product'
   *  Product: '<S72>/Product1'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  main_vehicle_model_B.Add1_h = rtb_steer_ang_errdeg *
    main_vehicle_model_P.Filter_Constant_Value_b +
    main_vehicle_model_P.One_Value_j * main_vehicle_model_DW.UnitDelay_DSTATE_b;

  /* Update for Memory: '<S2>/Memory2' */
  main_vehicle_model_DW.Memory2_PreviousInput = main_vehicle_model_B.enc_count;

  /* Update for Memory: '<S2>/Memory1' */
  main_vehicle_model_DW.Memory1_PreviousInput = main_vehicle_model_B.new_A;

  /* Update for Memory: '<S2>/Memory' */
  main_vehicle_model_DW.Memory_PreviousInput_g = main_vehicle_model_B.new_B;

  /* Update for UnitDelay: '<S75>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE = main_vehicle_model_B.Add1;

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE_b = main_vehicle_model_B.Add1_h;

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
  switch (main_vehicle_model_M->Timing.rtmDbBufReadBuf5) {
   case 0:
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf5 = 1;
    break;

   case 1:
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf5 = 0;
    break;

   default:
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf5 =
      !main_vehicle_model_M->Timing.rtmDbBufLastBufWr5;
    break;
  }

  main_vehicle_model_M->Timing.rtmDbBufClockTick5
    [main_vehicle_model_M->Timing.rtmDbBufWriteBuf5] =
    main_vehicle_model_M->Timing.clockTick0;
  main_vehicle_model_M->Timing.rtmDbBufClockTickH5
    [main_vehicle_model_M->Timing.rtmDbBufWriteBuf5] =
    main_vehicle_model_M->Timing.clockTickH0;
  main_vehicle_model_M->Timing.rtmDbBufLastBufWr5 =
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf5;
  main_vehicle_model_M->Timing.rtmDbBufWriteBuf5 = 0xFF;
  switch (main_vehicle_model_M->Timing.rtmDbBufReadBuf6) {
   case 0:
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf6 = 1;
    break;

   case 1:
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf6 = 0;
    break;

   default:
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf6 =
      !main_vehicle_model_M->Timing.rtmDbBufLastBufWr6;
    break;
  }

  main_vehicle_model_M->Timing.rtmDbBufClockTick6
    [main_vehicle_model_M->Timing.rtmDbBufWriteBuf6] =
    main_vehicle_model_M->Timing.clockTick0;
  main_vehicle_model_M->Timing.rtmDbBufClockTickH6
    [main_vehicle_model_M->Timing.rtmDbBufWriteBuf6] =
    main_vehicle_model_M->Timing.clockTickH0;
  main_vehicle_model_M->Timing.rtmDbBufLastBufWr6 =
    main_vehicle_model_M->Timing.rtmDbBufWriteBuf6;
  main_vehicle_model_M->Timing.rtmDbBufWriteBuf6 = 0xFF;

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
void main_vehicle_model_step2(void)    /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  real_T dir;
  real_T u0;

  /* MATLABSystem: '<Root>/PRES_DUCER' */
  if (main_vehicle_model_DW.obj.SampleTime !=
      main_vehicle_model_P.PRES_DUCER_SampleTime) {
    main_vehicle_model_DW.obj.SampleTime =
      main_vehicle_model_P.PRES_DUCER_SampleTime;
  }

  MW_AnalogIn_Start(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE,
    &dir, 7);

  /* Sum: '<S61>/Add1' incorporates:
   *  Constant: '<S61>/Filter_Constant'
   *  Constant: '<S61>/One'
   *  MATLABSystem: '<Root>/PRES_DUCER'
   *  Product: '<S61>/Product'
   *  Product: '<S61>/Product1'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  main_vehicle_model_DW.UnitDelay_DSTATE_g = dir *
    main_vehicle_model_P.Filter_Constant_Value_e +
    main_vehicle_model_P.One_Value_a * main_vehicle_model_DW.UnitDelay_DSTATE_g;

  /* Gain: '<Root>/scale to % brake' incorporates:
   *  Constant: '<Root>/Brake Calib. Bias'
   *  Sum: '<Root>/Subtract1'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  main_vehicle_model_B.braking = (main_vehicle_model_DW.UnitDelay_DSTATE_g -
    main_vehicle_model_P.BrakeCalibBias_Value) *
    main_vehicle_model_P.scaletobrake_Gain;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Constant: '<Root>/brake % set point'
   */
  if (main_vehicle_model_P.brakesetpoint_Value >
      main_vehicle_model_P.Saturation_UpperSat) {
    dir = main_vehicle_model_P.Saturation_UpperSat;
  } else if (main_vehicle_model_P.brakesetpoint_Value <
             main_vehicle_model_P.Saturation_LowerSat) {
    dir = main_vehicle_model_P.Saturation_LowerSat;
  } else {
    dir = main_vehicle_model_P.brakesetpoint_Value;
  }

  /* Sum: '<Root>/Subtract2' incorporates:
   *  Saturate: '<Root>/Saturation'
   */
  main_vehicle_model_B.brakeerr = dir - main_vehicle_model_B.braking;

  /* MATLAB Function: '<Root>/conv_to_dir_pin1' */
  main_vehicl_conv_to_dir_pin(main_vehicle_model_B.brakeerr, &dir,
    &main_vehicle_model_DW.sf_conv_to_dir_pin1);

  /* MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN1' */
  MW_digitalIO_write(main_vehicle_model_DW.obj_o.MW_DIGITALIO_HANDLE, dir != 0.0);

  /* Abs: '<Root>/Abs1' */
  dir = fabs(main_vehicle_model_B.brakeerr);

  /* Gain: '<S44>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S36>/Filter'
   *  Gain: '<S35>/Derivative Gain'
   *  Sum: '<S36>/SumD'
   */
  rtb_FilterCoefficient = (main_vehicle_model_P.DiscretePIDController_D * dir -
    main_vehicle_model_DW.Filter_DSTATE) *
    main_vehicle_model_P.DiscretePIDController_N;

  /* Sum: '<S50>/Sum' incorporates:
   *  DiscreteIntegrator: '<S41>/Integrator'
   *  Gain: '<S46>/Proportional Gain'
   */
  u0 = (main_vehicle_model_P.DiscretePIDController_P * dir +
        main_vehicle_model_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Saturate: '<Root>/pwm_sat' */
  if (u0 > main_vehicle_model_P.pwm_sat_UpperSat) {
    u0 = main_vehicle_model_P.pwm_sat_UpperSat;
  } else if (u0 < main_vehicle_model_P.pwm_sat_LowerSat) {
    u0 = main_vehicle_model_P.pwm_sat_LowerSat;
  }

  /* Rounding: '<Root>/Round3' incorporates:
   *  Saturate: '<Root>/pwm_sat'
   */
  main_vehicle_model_B.ACT2_DUTY_ROUNDED = rt_roundd_snf(u0);

  /* MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN1' */
  MW_PWM_SetDutyCycle(main_vehicle_model_DW.obj_lv.MW_PWM_HANDLE,
                      main_vehicle_model_B.ACT2_DUTY_ROUNDED);

  /* Gain: '<S38>/Integral Gain' */
  rtb_IntegralGain = main_vehicle_model_P.DiscretePIDController_I * dir;

  /* Update for DiscreteIntegrator: '<S41>/Integrator' */
  main_vehicle_model_DW.Integrator_DSTATE +=
    main_vehicle_model_P.Integrator_gainval * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S36>/Filter' */
  main_vehicle_model_DW.Filter_DSTATE += main_vehicle_model_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_vehicle_model_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void main_vehicle_model_step3(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* MATLABSystem: '<Root>/ACT RELAY EN PIN' incorporates:
   *  Constant: '<Root>/Actuator Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.ActuatorRelay_Value != 0.0);

  /* MATLABSystem: '<Root>/DRIVE MOTOR ANALOG PIN' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_AnalogOut_Write(main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE, (real32_T)
                     main_vehicle_model_P.Constant_Value);

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_vehicle_model_M->Timing.clockTick3++;
}

/* Model step function for TID4 */
void main_vehicle_model_step4(void)    /* Sample time: [0.25s, 0.0s] */
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
  /* The "clockTick4" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.25, which is the step size
   * of the task. Size of "clockTick4" ensures timer will not overflow during the
   * application lifespan selected.
   */
  main_vehicle_model_M->Timing.clockTick4++;
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
  main_vehicle_model_M->Sizes.checksums[0] = (2124790350U);
  main_vehicle_model_M->Sizes.checksums[1] = (3220657178U);
  main_vehicle_model_M->Sizes.checksums[2] = (3736258195U);
  main_vehicle_model_M->Sizes.checksums[3] = (2322877114U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[25];
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
      &main_vehicle_model_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &main_vehicle_model_DW.time_deltatospeed_SubsysRanBC_b;
    systemRan[15] = (sysRanDType *)
      &main_vehicle_model_DW.time_deltatospeed_SubsysRanBC_b;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)
      &main_vehicle_model_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &main_vehicle_model_DW.time_deltatospeed_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &main_vehicle_model_DW.time_deltatospeed_SubsysRanBC;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(main_vehicle_model_M->extModeInfo,
      &main_vehicle_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(main_vehicle_model_M->extModeInfo,
                        main_vehicle_model_M->Sizes.checksums);
    rteiSetTPtr(main_vehicle_model_M->extModeInfo, rtmGetTPtr
                (main_vehicle_model_M));
  }

  main_vehicle_model_M->Timing.rtmDbBufReadBuf5 = 0xFF;
  main_vehicle_model_M->Timing.rtmDbBufWriteBuf5 = 0xFF;
  main_vehicle_model_M->Timing.rtmDbBufLastBufWr5 = 0;
  main_vehicle_model_M->Timing.rtmDbBufReadBuf6 = 0xFF;
  main_vehicle_model_M->Timing.rtmDbBufWriteBuf6 = 0xFF;
  main_vehicle_model_M->Timing.rtmDbBufLastBufWr6 = 0;

  /* InitializeConditions for Memory: '<S2>/Memory2' */
  main_vehicle_model_DW.Memory2_PreviousInput =
    main_vehicle_model_P.Memory2_InitialCondition;

  /* InitializeConditions for Memory: '<S2>/Memory1' */
  main_vehicle_model_DW.Memory1_PreviousInput =
    main_vehicle_model_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  main_vehicle_model_DW.Memory_PreviousInput_g =
    main_vehicle_model_P.Memory_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S75>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE =
    main_vehicle_model_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S72>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE_b =
    main_vehicle_model_P.UnitDelay_InitialCondition_n;

  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
  main_vehicle_model_DW.UnitDelay_DSTATE_g =
    main_vehicle_model_P.UnitDelay_InitialCondition_i;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  main_vehicle_model_DW.Integrator_DSTATE =
    main_vehicle_model_P.DiscretePIDController_Initial_k;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Filter' */
  main_vehicle_model_DW.Filter_DSTATE =
    main_vehicle_model_P.DiscretePIDController_InitialCo;

  /* SystemInitialize for MATLAB Function: '<Root>/conv_to_dir_pin' */
  main_v_conv_to_dir_pin_Init(&main_vehicle_model_DW.sf_conv_to_dir_pin);

  /* SystemInitialize for MATLAB Function: '<Root>/conv_to_dir_pin1' */
  main_v_conv_to_dir_pin_Init(&main_vehicle_model_DW.sf_conv_to_dir_pin1);

  /* SystemInitialize for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin2' incorporates:
   *  SubSystem: '<S5>/time_delta to speed'
   */

  /* System initialize for function-call system: '<S5>/time_delta to speed' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (main_vehicle_model_M->Timing.rtmDbBufWriteBuf6) {
   case 0:
    main_vehicle_model_M->Timing.rtmDbBufReadBuf6 = 1;
    break;

   case 1:
    main_vehicle_model_M->Timing.rtmDbBufReadBuf6 = 0;
    break;

   default:
    main_vehicle_model_M->Timing.rtmDbBufReadBuf6 =
      main_vehicle_model_M->Timing.rtmDbBufLastBufWr6;
    break;
  }

  main_vehicle_model_M->Timing.clockTick6 =
    main_vehicle_model_M->Timing.rtmDbBufClockTick6
    [main_vehicle_model_M->Timing.rtmDbBufReadBuf6];
  main_vehicle_model_M->Timing.clockTickH6 =
    main_vehicle_model_M->Timing.rtmDbBufClockTickH6
    [main_vehicle_model_M->Timing.rtmDbBufReadBuf6];
  main_vehicle_model_M->Timing.rtmDbBufReadBuf6 = 0xFF;

  /* InitializeConditions for Memory: '<S66>/Memory' */
  main_vehicle_model_DW.Memory_PreviousInput =
    main_vehicle_model_P.Memory_InitialCondition_f;

  /* SystemInitialize for IfAction SubSystem: '<S66>/If Action Subsystem1' */
  mai_IfActionSubsystem1_Init(&main_vehicle_model_B.Divide,
    &main_vehicle_model_P.IfActionSubsystem1_i);

  /* End of SystemInitialize for SubSystem: '<S66>/If Action Subsystem1' */

  /* SystemInitialize for MATLAB Function: '<S66>/MATLAB Function' */
  main_ve_MATLABFunction_Init(&main_vehicle_model_DW.sf_MATLABFunction_h);

  /* SystemInitialize for SignalConversion generated from: '<S66>/Inport' incorporates:
   *  Outport: '<S66>/Outport'
   */
  main_vehicle_model_B.Inport = main_vehicle_model_P.Outport_Y0_i;
  main_vehicle_model_DW.wheelspeedintpin2_ExtIntHandle = MW_InterruptIn_Open(D0,
    MW_PULL_DOWN);

  /* Register for rising edge callback function */
  MW_InterruptIn_RisingEvent
    (main_vehicle_model_DW.wheelspeedintpin2_ExtIntHandle,
     &ExtIntPinD0ForRisingEdge);

  /* End of SystemInitialize for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin2' */

  /* SystemInitialize for MATLAB Function: '<S5>/zero out speed' */
  main_vehi_zerooutspeed_Init(&main_vehicle_model_DW.sf_zerooutspeed_a);

  /* SystemInitialize for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin' incorporates:
   *  SubSystem: '<S4>/time_delta to speed'
   */

  /* System initialize for function-call system: '<S4>/time_delta to speed' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (main_vehicle_model_M->Timing.rtmDbBufWriteBuf5) {
   case 0:
    main_vehicle_model_M->Timing.rtmDbBufReadBuf5 = 1;
    break;

   case 1:
    main_vehicle_model_M->Timing.rtmDbBufReadBuf5 = 0;
    break;

   default:
    main_vehicle_model_M->Timing.rtmDbBufReadBuf5 =
      main_vehicle_model_M->Timing.rtmDbBufLastBufWr5;
    break;
  }

  main_vehicle_model_M->Timing.clockTick5 =
    main_vehicle_model_M->Timing.rtmDbBufClockTick5
    [main_vehicle_model_M->Timing.rtmDbBufReadBuf5];
  main_vehicle_model_M->Timing.clockTickH5 =
    main_vehicle_model_M->Timing.rtmDbBufClockTickH5
    [main_vehicle_model_M->Timing.rtmDbBufReadBuf5];
  main_vehicle_model_M->Timing.rtmDbBufReadBuf5 = 0xFF;

  /* InitializeConditions for Memory: '<S62>/Memory' */
  main_vehicle_model_DW.Memory_PreviousInput_e =
    main_vehicle_model_P.Memory_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S62>/If Action Subsystem1' */
  mai_IfActionSubsystem1_Init(&main_vehicle_model_B.Divide_d,
    &main_vehicle_model_P.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S62>/If Action Subsystem1' */

  /* SystemInitialize for MATLAB Function: '<S62>/MATLAB Function' */
  main_ve_MATLABFunction_Init(&main_vehicle_model_DW.sf_MATLABFunction);

  /* SystemInitialize for SignalConversion generated from: '<S62>/Inport' incorporates:
   *  Outport: '<S62>/Outport'
   */
  main_vehicle_model_B.Inport_f = main_vehicle_model_P.Outport_Y0;
  main_vehicle_model_DW.wheelspeedintpin_ExtIntHandle = MW_InterruptIn_Open(D1,
    MW_PULL_DOWN);

  /* Register for rising edge callback function */
  MW_InterruptIn_RisingEvent(main_vehicle_model_DW.wheelspeedintpin_ExtIntHandle,
    &ExtIntPinD1ForRisingEdge);

  /* End of SystemInitialize for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin' */

  /* SystemInitialize for MATLAB Function: '<S4>/zero out speed' */
  main_vehi_zerooutspeed_Init(&main_vehicle_model_DW.sf_zerooutspeed);

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
  main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(D12);
  MW_AnalogIn_SetTriggerSource(main_vehicle_model_DW.obj.MW_ANALOGIN_HANDLE,
    MW_ANALOGIN_SOFTWARE_TRIGGER, 0U);
  main_vehicle_model_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN1' */
  main_vehicle_model_DW.obj_o.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_o.isInitialized = 1;
  main_vehicle_model_DW.obj_o.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D7, 1);
  main_vehicle_model_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN1' */
  main_vehicle_model_DW.obj_lv.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_lv.isInitialized = 1;
  main_vehicle_model_DW.obj_lv.MW_PWM_HANDLE = MW_PWM_Open(D11, 20000.0, 50.0);
  MW_PWM_Start(main_vehicle_model_DW.obj_lv.MW_PWM_HANDLE);
  main_vehicle_model_DW.obj_lv.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/ACT RELAY EN PIN' */
  main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_n.isInitialized = 1;
  main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A1, 1);
  main_vehicle_model_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/DRIVE MOTOR ANALOG PIN' */
  main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_h.isInitialized = 1;
  main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE = MW_AnalogOut_Open(D13);
  main_vehicle_model_DW.obj_h.isSetupComplete = true;

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

  /* Terminate for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin2' */
  MW_InterruptIn_Close(main_vehicle_model_DW.wheelspeedintpin2_ExtIntHandle);

  /* End of Terminate for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin2' */
  /* Terminate for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin' */
  MW_InterruptIn_Close(main_vehicle_model_DW.wheelspeedintpin_ExtIntHandle);

  /* End of Terminate for S-Function (mbedInterruptIn_sfcn): '<Root>/wheelspeed int. pin' */
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

  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN1' */
  if (!main_vehicle_model_DW.obj_o.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_o.isInitialized == 1) &&
        main_vehicle_model_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 2 DIR PIN1' */
  /* Terminate for MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN1' */
  if (!main_vehicle_model_DW.obj_lv.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_lv.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_lv.isInitialized == 1) &&
        main_vehicle_model_DW.obj_lv.isSetupComplete) {
      MW_PWM_Stop(main_vehicle_model_DW.obj_lv.MW_PWM_HANDLE);
      MW_PWM_Close(main_vehicle_model_DW.obj_lv.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ACTUATOR 2 PWM PIN1' */
  /* Terminate for MATLABSystem: '<Root>/ACT RELAY EN PIN' */
  if (!main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_n.isInitialized == 1) &&
        main_vehicle_model_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE);
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
