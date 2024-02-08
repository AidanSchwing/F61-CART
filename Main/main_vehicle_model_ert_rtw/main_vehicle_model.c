/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_vehicle_model.c
 *
 * Code generated for Simulink model 'main_vehicle_model'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb  7 20:55:20 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "main_vehicle_model.h"
#include "main_vehicle_model_types.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "main_vehicle_model_private.h"

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

/* Forward declaration for local functions */
static void icm20948_accel_gyro_temp_change(e_sensors_internal_icm20948_a_T *obj,
  real_T bankNo);
static e_sensors_internal_icm20948_a_T *icm20948_accel_gyro_temp_icm209
  (e_sensors_internal_icm20948_a_T *obj, f_codertarget_mbed_internal_M_T
   *varargin_1);
static void main_vehicle_m_SystemCore_setup(sensors_raspberrypi_ICM20948B_T *obj);
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
  if ((main_vehicle_model_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    main_vehicle_model_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void icm20948_accel_gyro_temp_change(e_sensors_internal_icm20948_a_T *obj,
  real_T bankNo)
{
  f_matlabshared_devicedrivers__T *obj_1;
  f_matlabshared_sensors_coder__T *obj_0;
  if (obj->UserBank != bankNo) {
    switch ((int32_T)bankNo) {
     case 0:
      main_vehicle_model_B.orValue = 0U;
      break;

     case 1:
      main_vehicle_model_B.orValue = 16U;
      break;

     case 2:
      main_vehicle_model_B.orValue = 32U;
      break;

     case 3:
      main_vehicle_model_B.orValue = 48U;
      break;

     default:
      main_vehicle_model_B.orValue = 0U;
      break;
    }

    obj_0 = obj->Device;
    obj_1 = obj_0->InterfaceObj;
    main_vehicle_model_B.slaveAddress = obj_0->DeviceAddress;

    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    main_vehicle_model_B.b_value = 0U;
    main_vehicle_model_B.b_status_p = 127U;

    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    main_vehicle_model_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
      main_vehicle_model_B.slaveAddress, &main_vehicle_model_B.b_status_p, 1U,
      true, false);
    if (main_vehicle_model_B.b_status_p == 0) {
      /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
      MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.slaveAddress,
                        &main_vehicle_model_B.b_value, 1U, false, true);
    }

    obj_0 = obj->Device;
    obj_1 = obj_0->InterfaceObj;
    main_vehicle_model_B.slaveAddress = obj_0->DeviceAddress;

    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    main_vehicle_model_B.b_data_c[0] = 127U;
    main_vehicle_model_B.b_data_c[1] = (uint8_T)((main_vehicle_model_B.b_value &
      207) | main_vehicle_model_B.orValue);
    MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.slaveAddress,
                       &main_vehicle_model_B.b_data_c[0], 2U, false, false);
    obj->UserBank = bankNo;
  }
}

static e_sensors_internal_icm20948_a_T *icm20948_accel_gyro_temp_icm209
  (e_sensors_internal_icm20948_a_T *obj, f_codertarget_mbed_internal_M_T
   *varargin_1)
{
  e_sensors_internal_icm20948_a_T *b_obj;
  f_matlabshared_devicedrivers__T *obj_1;
  f_matlabshared_sensors_coder__T *obj_0;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  b_obj = obj;
  obj->isInitialized = 0;
  obj->Parent = varargin_1;
  obj->_pobj0.Bus = 0U;
  obj->_pobj0.DeviceAddress = 105U;
  obj->_pobj0._pobj0.MW_I2C_HANDLE = NULL;
  obj->_pobj0.InterfaceObj = &obj->_pobj0._pobj0;
  obj_1 = obj->_pobj0.InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj->_pobj0.Bus;
  obj_1->MW_I2C_HANDLE = MW_I2C_Open(main_vehicle_model_B.i2cModule_c,
    MW_I2C_MASTER);
  obj->Device = &obj->_pobj0;
  obj->UserBank = -1.0;
  icm20948_accel_gyro_temp_change(obj, 0.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;
  main_vehicle_model_B.b_status_b = 0U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.b_status_b, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 6U;
  main_vehicle_model_B.b_data_m[1] = 128U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 6U;
  main_vehicle_model_B.b_data_m[1] = 1U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 7U;
  main_vehicle_model_B.b_data_m[1] = 0U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 15U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 15U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)(main_vehicle_model_B.val_k | 2);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 9U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 9U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)(main_vehicle_model_B.val_k | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 20U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 20U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)((main_vehicle_model_B.val_k & 254)
    | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 1U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 1U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)((main_vehicle_model_B.val_k & 254)
    | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 20U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 20U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)(main_vehicle_model_B.val_k & 249);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 16U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 16U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)(main_vehicle_model_B.val_k & 248);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 17U;
  main_vehicle_model_B.b_data_m[1] = 0U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 20U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 20U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)((main_vehicle_model_B.val_k & 199)
    | 32);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 1U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 1U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)(main_vehicle_model_B.val_k & 249);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 0U;
  main_vehicle_model_B.b_data_m[1] = 0U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 1U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 1U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)((main_vehicle_model_B.val_k & 199)
    | 32);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val_k = 0U;
  main_vehicle_model_B.b_status_b = 83U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status_b = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule_c, &main_vehicle_model_B.b_status_b, 1U, true,
    false);
  if (main_vehicle_model_B.b_status_b == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                      &main_vehicle_model_B.val_k, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule_c = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data_m[0] = 83U;
  main_vehicle_model_B.b_data_m[1] = (uint8_T)((main_vehicle_model_B.val_k & 248)
    | 4);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule_c,
                     &main_vehicle_model_B.b_data_m[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 0.0);
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void main_vehicle_m_SystemCore_setup(sensors_raspberrypi_ICM20948B_T *obj)
{
  e_sensors_internal_icm20948_a_T *accelGyro;
  f_codertarget_mbed_internal_M_T *varargin_1;
  f_matlabshared_devicedrivers__T *obj_1;
  f_matlabshared_sensors_coder__T *obj_0;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj->isInitialized = 1;
  obj->_pobj3.currentTime = -1.0;
  obj->HwUtilityObject = &obj->_pobj3;
  varargin_1 = obj->HwUtilityObject;
  obj->_pobj2.isInitialized = 0;
  obj->_pobj2.Parent = varargin_1;
  accelGyro = icm20948_accel_gyro_temp_icm209(&obj->_pobj2._pobj1, varargin_1);
  obj->_pobj2._pobj0.isInitialized = 0;
  obj->_pobj2._pobj0.Parent = varargin_1;
  obj->_pobj2._pobj0._pobj0.Bus = 0U;
  obj->_pobj2._pobj0._pobj0.DeviceAddress = 12U;
  obj->_pobj2._pobj0._pobj0._pobj0.MW_I2C_HANDLE = NULL;
  obj->_pobj2._pobj0._pobj0.InterfaceObj = &obj->_pobj2._pobj0._pobj0._pobj0;
  obj_1 = obj->_pobj2._pobj0._pobj0.InterfaceObj;
  main_vehicle_model_B.i2cModule = obj->_pobj2._pobj0._pobj0.Bus;
  obj_1->MW_I2C_HANDLE = MW_I2C_Open(main_vehicle_model_B.i2cModule,
    MW_I2C_MASTER);
  obj->_pobj2._pobj0.Device = &obj->_pobj2._pobj0._pobj0;
  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule = obj_0->DeviceAddress;
  main_vehicle_model_B.b_status = 1U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule, &main_vehicle_model_B.b_status, 1U, true,
    false);
  if (main_vehicle_model_B.b_status == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule,
                      &main_vehicle_model_B.b_status, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val = 0U;
  main_vehicle_model_B.b_status = 50U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule, &main_vehicle_model_B.b_status, 1U, true,
    false);
  if (main_vehicle_model_B.b_status == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule,
                      &main_vehicle_model_B.val, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data[0] = 50U;
  main_vehicle_model_B.b_data[1] = (uint8_T)(main_vehicle_model_B.val | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule,
                     &main_vehicle_model_B.b_data[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.val = 0U;
  main_vehicle_model_B.b_status = 49U;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    main_vehicle_model_B.i2cModule, &main_vehicle_model_B.b_status, 1U, true,
    false);
  if (main_vehicle_model_B.b_status == 0) {
    /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule,
                      &main_vehicle_model_B.val, 1U, false, true);
  }

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  main_vehicle_model_B.i2cModule = obj_0->DeviceAddress;

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.b_data[0] = 49U;
  main_vehicle_model_B.b_data[1] = (uint8_T)((main_vehicle_model_B.val & 224) |
    8);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, main_vehicle_model_B.i2cModule,
                     &main_vehicle_model_B.b_data[0], 2U, false, false);
  wait_ms(10U);
  obj->_pobj2._pobj0.matlabCodegenIsDeleted = false;
  obj->_pobj2.SensorObjects.f1 = accelGyro;
  obj->_pobj2.SensorObjects.f2 = &obj->_pobj2._pobj0;
  obj->_pobj2.matlabCodegenIsDeleted = false;
  obj->SensorObject = &obj->_pobj2;
  obj->OutputModules.f1 = &obj->_pobj1;
  obj->OutputModules.f2 = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function for TID0 */
void main_vehicle_model_step0(void)    /* Sample time: [0.0s, 0.0s] */
{
  e_sensors_internal_icm20948_a_T *obj;
  f_matlabshared_devicedrivers__T *obj_1;
  f_matlabshared_sensors_coder__T *obj_0;
  int32_T i;
  uint8_T tempData[6];
  uint8_T b_output[2];
  uint8_T b_status;
  uint8_T slaveAddress;
  ZCEventType zcEvent;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  if (main_vehicle_model_DW.obj.SampleTime !=
      main_vehicle_model_P.ICM20948IMUSensor_SampleTime) {
    main_vehicle_model_DW.obj.SampleTime =
      main_vehicle_model_P.ICM20948IMUSensor_SampleTime;
  }

  if (main_vehicle_model_DW.obj.TunablePropsChanged) {
    main_vehicle_model_DW.obj.TunablePropsChanged = false;
  }

  obj = main_vehicle_model_DW.obj.SensorObject->SensorObjects.f1;
  icm20948_accel_gyro_temp_change(obj, 0.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  slaveAddress = obj_0->DeviceAddress;
  for (i = 0; i < 6; i++) {
    tempData[i] = 0U;
  }

  b_status = 45U;
  b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, slaveAddress, &tempData[0], 6U,
                      false, true);
  }

  obj = main_vehicle_model_DW.obj.SensorObject->SensorObjects.f1;
  icm20948_accel_gyro_temp_change(obj, 0.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  slaveAddress = obj_0->DeviceAddress;
  b_status = 57U;
  b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, slaveAddress, &b_output[0], 2U,
                      false, true);
  }

  /* MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_B.IMUACCEL[0] = (real_T)((int16_T)(tempData[0] << 8) |
    tempData[1]) * 0.00059814453125;
  main_vehicle_model_B.IMUACCEL[1] = (real_T)((int16_T)(tempData[2] << 8) |
    tempData[3]) * 0.00059814453125;
  main_vehicle_model_B.IMUACCEL[2] = (real_T)((int16_T)(tempData[4] << 8) |
    tempData[5]) * 0.00059814453125;

  /* MATLABSystem: '<Root>/Digital Write3' incorporates:
   *  Constant: '<Root>/Actuator Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.ActuatorRelay_Value != 0.0);

  /* MATLABSystem: '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_AnalogOut_Write(main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE, (real32_T)
                     main_vehicle_model_P.Constant_Value);

  /* MATLABSystem: '<Root>/Digital Read2' */
  if (main_vehicle_model_DW.obj_n.SampleTime !=
      main_vehicle_model_P.DigitalRead2_SampleTime) {
    main_vehicle_model_DW.obj_n.SampleTime =
      main_vehicle_model_P.DigitalRead2_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read2' */
  main_vehicle_model_B.DigitalRead2 = MW_digitalIO_read
    (main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &main_vehicle_model_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     ((real_T)main_vehicle_model_B.DigitalRead2 -
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
  main_vehicle_model_B.Sum = main_vehicle_model_B.In1 -
    main_vehicle_model_DW.UnitDelay_DSTATE;

  /* If: '<S1>/If' */
  if (main_vehicle_model_B.Sum > 0.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/In1' */
    main_vehicle_model_B.In1_g = main_vehicle_model_B.Sum;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Update for If: '<S1>/If' */
    srUpdateBC(main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem' */
  }

  /* End of If: '<S1>/If' */
  /* MATLABSystem: '<Root>/Digital Write4' incorporates:
   *  Constant: '<Root>/Drive Relay'
   */
  MW_digitalIO_write(main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE,
                     main_vehicle_model_P.DriveRelay_Value != 0.0);

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
void main_vehicle_model_step2(void)    /* Sample time: [0.1s, 0.0s] */
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
   * been executed. The resolution of this integer timer is 0.1, which is the step size
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
  main_vehicle_model_M->Sizes.checksums[0] = (865313027U);
  main_vehicle_model_M->Sizes.checksums[1] = (2781223436U);
  main_vehicle_model_M->Sizes.checksums[2] = (4069583706U);
  main_vehicle_model_M->Sizes.checksums[3] = (380231828U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
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
    systemRan[9] = (sysRanDType *)
      &main_vehicle_model_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &main_vehicle_model_DW.TriggeredSubsystem_SubsysRanBC;
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

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  main_vehicle_model_DW.obj._pobj2._pobj1.matlabCodegenIsDeleted = true;
  main_vehicle_model_DW.obj._pobj2._pobj0.matlabCodegenIsDeleted = true;
  main_vehicle_model_DW.obj._pobj2.matlabCodegenIsDeleted = true;
  main_vehicle_model_DW.obj.isInitialized = 0;
  main_vehicle_model_DW.obj.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj.SampleTime =
    main_vehicle_model_P.ICM20948IMUSensor_SampleTime;
  main_vehicle_m_SystemCore_setup(&main_vehicle_model_DW.obj);

  /* Start for MATLABSystem: '<Root>/Digital Write3' */
  main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_nv.isInitialized = 1;
  main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D8, 1);
  main_vehicle_model_DW.obj_nv.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Output' */
  main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_h.isInitialized = 1;
  main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE = MW_AnalogOut_Open(D13);
  main_vehicle_model_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read2' */
  main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_n.SampleTime =
    main_vehicle_model_P.DigitalRead2_SampleTime;
  main_vehicle_model_DW.obj_n.isInitialized = 1;
  main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(A1, 0);
  main_vehicle_model_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write4' */
  main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted = false;
  main_vehicle_model_DW.obj_l.isInitialized = 1;
  main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(D9, 1);
  main_vehicle_model_DW.obj_l.isSetupComplete = true;

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
  b_icm20948_main_vehicle_model_T *obj;
  b_sensors_internal_ak09916_ma_T *obj_0;
  e_sensors_internal_icm20948_a_T *obj_1;

  /* Terminate for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  if (!main_vehicle_model_DW.obj.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj.matlabCodegenIsDeleted = true;
  }

  obj = &main_vehicle_model_DW.obj._pobj2;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  obj_0 = &main_vehicle_model_DW.obj._pobj2._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }

  obj_1 = &main_vehicle_model_DW.obj._pobj2._pobj1;
  if (!obj_1->matlabCodegenIsDeleted) {
    obj_1->matlabCodegenIsDeleted = true;
    if (obj_1->isInitialized == 1) {
      obj_1->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_nv.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_nv.isInitialized == 1) &&
        main_vehicle_model_DW.obj_nv.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_nv.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Analog Output' */
  if (!main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_h.isInitialized == 1) &&
        main_vehicle_model_DW.obj_h.isSetupComplete) {
      MW_AnalogOut_Close(main_vehicle_model_DW.obj_h.MW_ANALOGOUT_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read2' */
  if (!main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_n.isInitialized == 1) &&
        main_vehicle_model_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read2' */
  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  if (!main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted) {
    main_vehicle_model_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((main_vehicle_model_DW.obj_l.isInitialized == 1) &&
        main_vehicle_model_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(main_vehicle_model_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write4' */

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
