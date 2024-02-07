/*
 * led_flash.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "led_flash".
 *
 * Model version              : 1.30
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sun Feb  4 22:36:48 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "led_flash.h"
#include "led_flash_types.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "led_flash_private.h"
#include <string.h>

/* Block signals (default storage) */
B_led_flash_T led_flash_B;

/* Block states (default storage) */
DW_led_flash_T led_flash_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_led_flash_T led_flash_PrevZCX;

/* Real-time model */
static RT_MODEL_led_flash_T led_flash_M_;
RT_MODEL_led_flash_T *const led_flash_M = &led_flash_M_;

/* Forward declaration for local functions */
static void icm20948_accel_gyro_temp_change(e_sensors_internal_icm20948_a_T *obj,
  real_T bankNo);
static e_sensors_internal_icm20948_a_T *icm20948_accel_gyro_temp_icm209
  (e_sensors_internal_icm20948_a_T *obj, f_codertarget_mbed_internal_M_T
   *varargin_1);
static void led_flash_SystemCore_setup(sensors_raspberrypi_ICM20948B_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void led_flash_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(led_flash_M, 2));
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
  (led_flash_M->Timing.TaskCounters.TID[2])++;
  if ((led_flash_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    led_flash_M->Timing.TaskCounters.TID[2] = 0;
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
      led_flash_B.orValue = 0U;
      break;

     case 1:
      led_flash_B.orValue = 16U;
      break;

     case 2:
      led_flash_B.orValue = 32U;
      break;

     case 3:
      led_flash_B.orValue = 48U;
      break;

     default:
      led_flash_B.orValue = 0U;
      break;
    }

    obj_0 = obj->Device;
    obj_1 = obj_0->InterfaceObj;
    led_flash_B.slaveAddress = obj_0->DeviceAddress;
    led_flash_B.b_value = 0U;
    led_flash_B.b_status_c = 127U;
    led_flash_B.b_status_c = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
      led_flash_B.slaveAddress, &led_flash_B.b_status_c, 1U, true, false);
    if (led_flash_B.b_status_c == 0) {
      MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.slaveAddress,
                        &led_flash_B.b_value, 1U, false, true);
    }

    obj_0 = obj->Device;
    obj_1 = obj_0->InterfaceObj;
    led_flash_B.slaveAddress = obj_0->DeviceAddress;
    led_flash_B.b_data_k[0] = 127U;
    led_flash_B.b_data_k[1] = (uint8_T)((led_flash_B.b_value & 207) |
      led_flash_B.orValue);
    MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.slaveAddress,
                       &led_flash_B.b_data_k[0], 2U, false, false);
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
  b_obj = obj;
  obj->isInitialized = 0;
  obj->Parent = varargin_1;
  obj->_pobj0.Bus = 0U;
  obj->_pobj0.DeviceAddress = 105U;
  obj->_pobj0._pobj0.MW_I2C_HANDLE = NULL;
  obj->_pobj0.InterfaceObj = &obj->_pobj0._pobj0;
  obj_1 = obj->_pobj0.InterfaceObj;
  led_flash_B.i2cModule_b = obj->_pobj0.Bus;
  led_flash_B.modename_m = MW_I2C_MASTER;
  obj_1->MW_I2C_HANDLE = MW_I2C_Open(led_flash_B.i2cModule_b,
    led_flash_B.modename_m);
  obj->Device = &obj->_pobj0;
  obj->UserBank = -1.0;
  icm20948_accel_gyro_temp_change(obj, 0.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_status_p = 0U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.b_status_p, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 6U;
  led_flash_B.b_data_c[1] = 128U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 6U;
  led_flash_B.b_data_c[1] = 1U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 7U;
  led_flash_B.b_data_c[1] = 0U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 15U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 15U;
  led_flash_B.b_data_c[1] = (uint8_T)(led_flash_B.val_c | 2);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  wait_ms(10U);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 9U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 9U;
  led_flash_B.b_data_c[1] = (uint8_T)(led_flash_B.val_c | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 20U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 20U;
  led_flash_B.b_data_c[1] = (uint8_T)((led_flash_B.val_c & 254) | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 1U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 1U;
  led_flash_B.b_data_c[1] = (uint8_T)((led_flash_B.val_c & 254) | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 20U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 20U;
  led_flash_B.b_data_c[1] = (uint8_T)(led_flash_B.val_c & 249);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 16U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 16U;
  led_flash_B.b_data_c[1] = (uint8_T)(led_flash_B.val_c & 248);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 17U;
  led_flash_B.b_data_c[1] = 0U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 20U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 20U;
  led_flash_B.b_data_c[1] = (uint8_T)((led_flash_B.val_c & 199) | 32);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 1U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 1U;
  led_flash_B.b_data_c[1] = (uint8_T)(led_flash_B.val_c & 249);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 0U;
  led_flash_B.b_data_c[1] = 0U;
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 1U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 1U;
  led_flash_B.b_data_c[1] = (uint8_T)((led_flash_B.val_c & 199) | 32);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 2.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.val_c = 0U;
  led_flash_B.b_status_p = 83U;
  led_flash_B.b_status_p = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule_b, &led_flash_B.b_status_p, 1U, true, false);
  if (led_flash_B.b_status_p == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                      &led_flash_B.val_c, 1U, false, true);
  }

  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule_b = obj_0->DeviceAddress;
  led_flash_B.b_data_c[0] = 83U;
  led_flash_B.b_data_c[1] = (uint8_T)((led_flash_B.val_c & 248) | 4);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule_b,
                     &led_flash_B.b_data_c[0], 2U, false, false);
  wait_ms(10U);
  icm20948_accel_gyro_temp_change(obj, 0.0);
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void led_flash_SystemCore_setup(sensors_raspberrypi_ICM20948B_T *obj)
{
  e_sensors_internal_icm20948_a_T *accelGyro;
  f_codertarget_mbed_internal_M_T *varargin_1;
  f_matlabshared_devicedrivers__T *obj_1;
  f_matlabshared_sensors_coder__T *obj_0;
  obj->isSetupComplete = false;
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
  led_flash_B.i2cModule = obj->_pobj2._pobj0._pobj0.Bus;
  led_flash_B.modename = MW_I2C_MASTER;
  obj_1->MW_I2C_HANDLE = MW_I2C_Open(led_flash_B.i2cModule, led_flash_B.modename);
  obj->_pobj2._pobj0.Device = &obj->_pobj2._pobj0._pobj0;
  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule = obj_0->DeviceAddress;
  led_flash_B.b_status = 1U;
  led_flash_B.b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule, &led_flash_B.b_status, 1U, true, false);
  if (led_flash_B.b_status == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule,
                      &led_flash_B.b_status, 1U, false, true);
  }

  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule = obj_0->DeviceAddress;
  led_flash_B.val = 0U;
  led_flash_B.b_status = 50U;
  led_flash_B.b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule, &led_flash_B.b_status, 1U, true, false);
  if (led_flash_B.b_status == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule,
                      &led_flash_B.val, 1U, false, true);
  }

  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule = obj_0->DeviceAddress;
  led_flash_B.b_data[0] = 50U;
  led_flash_B.b_data[1] = (uint8_T)(led_flash_B.val | 1);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule,
                     &led_flash_B.b_data[0], 2U, false, false);
  wait_ms(10U);
  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule = obj_0->DeviceAddress;
  led_flash_B.val = 0U;
  led_flash_B.b_status = 49U;
  led_flash_B.b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE,
    led_flash_B.i2cModule, &led_flash_B.b_status, 1U, true, false);
  if (led_flash_B.b_status == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule,
                      &led_flash_B.val, 1U, false, true);
  }

  obj_0 = obj->_pobj2._pobj0.Device;
  obj_1 = obj_0->InterfaceObj;
  led_flash_B.i2cModule = obj_0->DeviceAddress;
  led_flash_B.b_data[0] = 49U;
  led_flash_B.b_data[1] = (uint8_T)((led_flash_B.val & 224) | 8);
  MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, led_flash_B.i2cModule,
                     &led_flash_B.b_data[0], 2U, false, false);
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
void led_flash_step0(void)             /* Sample time: [0.0s, 0.0s] */
{
  b_icm20948_led_flash_T *sensorObj_tmp;
  e_sensors_internal_icm20948_a_T *obj;
  f_matlabshared_devicedrivers__T *obj_1;
  f_matlabshared_sensors_coder__T *obj_0;
  int32_T i;
  uint8_T b_output[2];
  uint8_T b_status;
  uint8_T slaveAddress;
  ZCEventType zcEvent;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(led_flash_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(led_flash_DW.TriggeredSubsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  if (led_flash_DW.obj.SampleTime != led_flash_P.ICM20948IMUSensor_SampleTime) {
    led_flash_DW.obj.SampleTime = led_flash_P.ICM20948IMUSensor_SampleTime;
  }

  if (led_flash_DW.obj.TunablePropsChanged) {
    led_flash_DW.obj.TunablePropsChanged = false;
  }

  sensorObj_tmp = led_flash_DW.obj.SensorObject;
  obj = sensorObj_tmp->SensorObjects.f1;
  icm20948_accel_gyro_temp_change(obj, 0.0);
  obj_0 = obj->Device;
  obj_1 = obj_0->InterfaceObj;
  slaveAddress = obj_0->DeviceAddress;
  for (i = 0; i < 6; i++) {
    led_flash_B.tempData[i] = 0U;
  }

  b_status = 45U;
  b_status = MW_I2C_MasterWrite(obj_1->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    MW_I2C_MasterRead(obj_1->MW_I2C_HANDLE, slaveAddress, &led_flash_B.tempData
                      [0], 6U, false, true);
  }

  obj = sensorObj_tmp->SensorObjects.f1;
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
  led_flash_B.IMUACCEL[0] = (real_T)((int16_T)(led_flash_B.tempData[0] << 8) |
    led_flash_B.tempData[1]) * 0.00059814453125;
  led_flash_B.IMUACCEL[1] = (real_T)((int16_T)(led_flash_B.tempData[2] << 8) |
    led_flash_B.tempData[3]) * 0.00059814453125;
  led_flash_B.IMUACCEL[2] = (real_T)((int16_T)(led_flash_B.tempData[4] << 8) |
    led_flash_B.tempData[5]) * 0.00059814453125;

  /* MATLABSystem: '<Root>/Digital Write3' incorporates:
   *  Constant: '<Root>/Actuator Relay'
   */
  MW_digitalIO_write(led_flash_DW.obj_h.MW_DIGITALIO_HANDLE,
                     led_flash_P.ActuatorRelay_Value != 0.0);

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (led_flash_DW.obj_g.SampleTime != led_flash_P.AnalogInput2_SampleTime) {
    led_flash_DW.obj_g.SampleTime = led_flash_P.AnalogInput2_SampleTime;
  }

  MW_AnalogIn_Start(led_flash_DW.obj_g.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input2' */
  MW_AnalogInSingle_ReadResult(led_flash_DW.obj_g.MW_ANALOGIN_HANDLE,
    &led_flash_B.AnalogInput2, 7);

  /* MATLABSystem: '<Root>/Analog Input3' */
  if (led_flash_DW.obj_b.SampleTime != led_flash_P.AnalogInput3_SampleTime) {
    led_flash_DW.obj_b.SampleTime = led_flash_P.AnalogInput3_SampleTime;
  }

  MW_AnalogIn_Start(led_flash_DW.obj_b.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input3' */
  MW_AnalogInSingle_ReadResult(led_flash_DW.obj_b.MW_ANALOGIN_HANDLE,
    &led_flash_B.AnalogInput3, 7);

  /* MATLABSystem: '<Root>/Analog Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_AnalogOut_Write(led_flash_DW.obj_dc.MW_ANALOGOUT_HANDLE, (real32_T)
                     led_flash_P.Constant_Value);

  /* MATLABSystem: '<Root>/Digital Read' */
  if (led_flash_DW.obj_d.SampleTime != led_flash_P.DigitalRead_SampleTime) {
    led_flash_DW.obj_d.SampleTime = led_flash_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read' */
  led_flash_B.DigitalRead = MW_digitalIO_read
    (led_flash_DW.obj_d.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<Root>/Digital Read2' */
  if (led_flash_DW.obj_l.SampleTime != led_flash_P.DigitalRead2_SampleTime) {
    led_flash_DW.obj_l.SampleTime = led_flash_P.DigitalRead2_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read2' */
  led_flash_B.DigitalRead2 = MW_digitalIO_read
    (led_flash_DW.obj_l.MW_DIGITALIO_HANDLE);

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  led_flash_B.Sum1 = (real_T)led_flash_B.DigitalRead2 -
    led_flash_P.Constant_Value_l;

  /* Clock: '<S1>/Clock' */
  led_flash_B.Clock = led_flash_M->Timing.t[0];

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &led_flash_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (led_flash_B.Sum1));
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S3>/In1' */
    led_flash_B.In1 = led_flash_B.Clock;
    led_flash_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */
  /* Sum: '<S1>/Sum' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  led_flash_B.Sum = led_flash_B.In1 - led_flash_DW.UnitDelay_DSTATE;

  /* If: '<S1>/If' */
  if (led_flash_B.Sum > 0.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/In1' */
    led_flash_B.In1_g = led_flash_B.Sum;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Update for If: '<S1>/If' */
    srUpdateBC(led_flash_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S1>/If Action Subsystem' */
  }

  /* End of If: '<S1>/If' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  led_flash_DW.UnitDelay_DSTATE = led_flash_B.In1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++led_flash_M->Timing.clockTick0)) {
    ++led_flash_M->Timing.clockTickH0;
  }

  led_flash_M->Timing.t[0] = led_flash_M->Timing.clockTick0 *
    led_flash_M->Timing.stepSize0 + led_flash_M->Timing.clockTickH0 *
    led_flash_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  led_flash_M->Timing.clockTick1++;
  if (!led_flash_M->Timing.clockTick1) {
    led_flash_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void led_flash_step2(void)             /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (led_flash_DW.clockTickCounter <
                        led_flash_P.PulseGenerator_Duty) &&
    (led_flash_DW.clockTickCounter >= 0) ? led_flash_P.PulseGenerator_Amp : 0.0;
  if (led_flash_DW.clockTickCounter >= led_flash_P.PulseGenerator_Period - 1.0)
  {
    led_flash_DW.clockTickCounter = 0;
  } else {
    led_flash_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(led_flash_DW.obj_p.MW_DIGITALIO_HANDLE, rtb_PulseGenerator
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(led_flash_DW.obj_j.MW_DIGITALIO_HANDLE, rtb_PulseGenerator
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(led_flash_DW.obj_bo.MW_DIGITALIO_HANDLE, rtb_PulseGenerator
                     != 0.0);

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  led_flash_M->Timing.clockTick2++;
  if (!led_flash_M->Timing.clockTick2) {
    led_flash_M->Timing.clockTickH2++;
  }
}

/* Model initialize function */
void led_flash_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)led_flash_M, 0,
                sizeof(RT_MODEL_led_flash_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&led_flash_M->solverInfo,
                          &led_flash_M->Timing.simTimeStep);
    rtsiSetTPtr(&led_flash_M->solverInfo, &rtmGetTPtr(led_flash_M));
    rtsiSetStepSizePtr(&led_flash_M->solverInfo, &led_flash_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&led_flash_M->solverInfo, (&rtmGetErrorStatus
      (led_flash_M)));
    rtsiSetRTModelPtr(&led_flash_M->solverInfo, led_flash_M);
  }

  rtsiSetSimTimeStep(&led_flash_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&led_flash_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(led_flash_M, &led_flash_M->Timing.tArray[0]);
  rtmSetTFinal(led_flash_M, 999.0);
  led_flash_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  led_flash_M->Sizes.checksums[0] = (860026892U);
  led_flash_M->Sizes.checksums[1] = (1960378016U);
  led_flash_M->Sizes.checksums[2] = (2422031873U);
  led_flash_M->Sizes.checksums[3] = (1134758426U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    led_flash_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[11] = (sysRanDType *)&led_flash_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&led_flash_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(led_flash_M->extModeInfo,
      &led_flash_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(led_flash_M->extModeInfo, led_flash_M->Sizes.checksums);
    rteiSetTPtr(led_flash_M->extModeInfo, rtmGetTPtr(led_flash_M));
  }

  /* block I/O */
  (void) memset(((void *) &led_flash_B), 0,
                sizeof(B_led_flash_T));

  /* states (dwork) */
  (void) memset((void *)&led_flash_DW, 0,
                sizeof(DW_led_flash_T));

  /* Start for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  led_flash_DW.obj._pobj2._pobj1.matlabCodegenIsDeleted = true;
  led_flash_DW.obj._pobj2._pobj0.matlabCodegenIsDeleted = true;
  led_flash_DW.obj._pobj2.matlabCodegenIsDeleted = true;
  led_flash_DW.obj.isInitialized = 0;
  led_flash_DW.obj.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty = true;
  led_flash_DW.obj.SampleTime = led_flash_P.ICM20948IMUSensor_SampleTime;
  led_flash_SystemCore_setup(&led_flash_DW.obj);

  /* Start for MATLABSystem: '<Root>/Digital Write3' */
  led_flash_DW.obj_h.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_i = true;
  led_flash_DW.obj_h.isInitialized = 1;
  led_flash_B.pinname = D8;
  led_flash_DW.obj_h.MW_DIGITALIO_HANDLE = MW_digitalIO_open(led_flash_B.pinname,
    1);
  led_flash_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input2' */
  led_flash_DW.obj_g.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_c = true;
  led_flash_DW.obj_g.SampleTime = led_flash_P.AnalogInput2_SampleTime;
  led_flash_DW.obj_g.isInitialized = 1;
  led_flash_B.pinname = A4;
  led_flash_DW.obj_g.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (led_flash_B.pinname);
  led_flash_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource(led_flash_DW.obj_g.MW_ANALOGIN_HANDLE,
    led_flash_B.trigger_val, 0U);
  led_flash_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input3' */
  led_flash_DW.obj_b.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_az = true;
  led_flash_DW.obj_b.SampleTime = led_flash_P.AnalogInput3_SampleTime;
  led_flash_DW.obj_b.isInitialized = 1;
  led_flash_B.pinname = A3;
  led_flash_DW.obj_b.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (led_flash_B.pinname);
  led_flash_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource(led_flash_DW.obj_b.MW_ANALOGIN_HANDLE,
    led_flash_B.trigger_val, 0U);
  led_flash_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Output' */
  led_flash_DW.obj_dc.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_p5 = true;
  led_flash_DW.obj_dc.isInitialized = 1;
  led_flash_B.pinname = D13;
  led_flash_DW.obj_dc.MW_ANALOGOUT_HANDLE = MW_AnalogOut_Open
    (led_flash_B.pinname);
  led_flash_DW.obj_dc.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read' */
  led_flash_DW.obj_d.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_ag = true;
  led_flash_DW.obj_d.SampleTime = led_flash_P.DigitalRead_SampleTime;
  led_flash_DW.obj_d.isInitialized = 1;
  led_flash_B.pinname = A2;
  led_flash_DW.obj_d.MW_DIGITALIO_HANDLE = MW_digitalIO_open(led_flash_B.pinname,
    0);
  led_flash_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read2' */
  led_flash_DW.obj_l.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_p = true;
  led_flash_DW.obj_l.SampleTime = led_flash_P.DigitalRead2_SampleTime;
  led_flash_DW.obj_l.isInitialized = 1;
  led_flash_B.pinname = A1;
  led_flash_DW.obj_l.MW_DIGITALIO_HANDLE = MW_digitalIO_open(led_flash_B.pinname,
    0);
  led_flash_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  led_flash_DW.obj_p.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_n = true;
  led_flash_DW.obj_p.isInitialized = 1;
  led_flash_B.pinname = PB_7;
  led_flash_DW.obj_p.MW_DIGITALIO_HANDLE = MW_digitalIO_open(led_flash_B.pinname,
    1);
  led_flash_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  led_flash_DW.obj_j.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_a = true;
  led_flash_DW.obj_j.isInitialized = 1;
  led_flash_B.pinname = PB_14;
  led_flash_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(led_flash_B.pinname,
    1);
  led_flash_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write2' */
  led_flash_DW.obj_bo.matlabCodegenIsDeleted = false;
  led_flash_DW.objisempty_m = true;
  led_flash_DW.obj_bo.isInitialized = 1;
  led_flash_B.pinname = PB_0;
  led_flash_DW.obj_bo.MW_DIGITALIO_HANDLE = MW_digitalIO_open
    (led_flash_B.pinname, 1);
  led_flash_DW.obj_bo.isSetupComplete = true;
  led_flash_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  led_flash_DW.UnitDelay_DSTATE = led_flash_P.UnitDelay_InitialCondition;

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  led_flash_DW.clockTickCounter = 0;

  /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S2>/In1' incorporates:
   *  Outport: '<S2>/Out1'
   */
  led_flash_B.In1_g = led_flash_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem' */

  /* SystemInitialize for Triggered SubSystem: '<S1>/Triggered Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S3>/In1' incorporates:
   *  Outport: '<S3>/Out1'
   */
  led_flash_B.In1 = led_flash_P.Out1_Y0_a;

  /* End of SystemInitialize for SubSystem: '<S1>/Triggered Subsystem' */
}

/* Model terminate function */
void led_flash_terminate(void)
{
  b_icm20948_led_flash_T *obj;
  b_sensors_internal_ak09916_le_T *obj_0;
  e_sensors_internal_icm20948_a_T *obj_1;

  /* Terminate for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  if (!led_flash_DW.obj.matlabCodegenIsDeleted) {
    led_flash_DW.obj.matlabCodegenIsDeleted = true;
  }

  obj = &led_flash_DW.obj._pobj2;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  obj_0 = &led_flash_DW.obj._pobj2._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }

  obj_1 = &led_flash_DW.obj._pobj2._pobj1;
  if (!obj_1->matlabCodegenIsDeleted) {
    obj_1->matlabCodegenIsDeleted = true;
    if (obj_1->isInitialized == 1) {
      obj_1->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ICM20948 IMU Sensor' */
  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!led_flash_DW.obj_h.matlabCodegenIsDeleted) {
    led_flash_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_h.isInitialized == 1) &&
        led_flash_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  if (!led_flash_DW.obj_g.matlabCodegenIsDeleted) {
    led_flash_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_g.isInitialized == 1) &&
        led_flash_DW.obj_g.isSetupComplete) {
      MW_AnalogIn_Stop(led_flash_DW.obj_g.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(led_flash_DW.obj_g.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  if (!led_flash_DW.obj_b.matlabCodegenIsDeleted) {
    led_flash_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_b.isInitialized == 1) &&
        led_flash_DW.obj_b.isSetupComplete) {
      MW_AnalogIn_Stop(led_flash_DW.obj_b.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(led_flash_DW.obj_b.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */
  /* Terminate for MATLABSystem: '<Root>/Analog Output' */
  if (!led_flash_DW.obj_dc.matlabCodegenIsDeleted) {
    led_flash_DW.obj_dc.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_dc.isInitialized == 1) &&
        led_flash_DW.obj_dc.isSetupComplete) {
      MW_AnalogOut_Close(led_flash_DW.obj_dc.MW_ANALOGOUT_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!led_flash_DW.obj_d.matlabCodegenIsDeleted) {
    led_flash_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_d.isInitialized == 1) &&
        led_flash_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */
  /* Terminate for MATLABSystem: '<Root>/Digital Read2' */
  if (!led_flash_DW.obj_l.matlabCodegenIsDeleted) {
    led_flash_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_l.isInitialized == 1) &&
        led_flash_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read2' */
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!led_flash_DW.obj_p.matlabCodegenIsDeleted) {
    led_flash_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_p.isInitialized == 1) &&
        led_flash_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!led_flash_DW.obj_j.matlabCodegenIsDeleted) {
    led_flash_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_j.isInitialized == 1) &&
        led_flash_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!led_flash_DW.obj_bo.matlabCodegenIsDeleted) {
    led_flash_DW.obj_bo.matlabCodegenIsDeleted = true;
    if ((led_flash_DW.obj_bo.isInitialized == 1) &&
        led_flash_DW.obj_bo.isSetupComplete) {
      MW_digitalIO_close(led_flash_DW.obj_bo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */
}
