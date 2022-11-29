/*
 * Code generation for system model 'accel_3'
 *
 * Model                      : accel_3
 * Model version              : 5.305
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Nov 28 21:24:42 2022
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "accel_3.h"
#include "rtwtypes.h"
#include "accel_3_types.h"
#include "accel_3_private.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "MW_I2C.h"

P_accel_3_T accel_3_P = {
  /* Expression: -1
   * Referenced by: '<Root>/FXOS8700 6-Axes Sensor1'
   */
  -1.0,

  /* Expression: 12.5
   * Referenced by: '<Root>/Gain'
   */
  12.5
};

/* Forward declaration for local functions */
static void accel_3_SystemCore_setup(freedomk64f_fxos8700_accel_3_T *obj);
static void accel_3_SystemCore_setup_n(dsp_simulink_MovingAverage_ac_T *obj);
static void accel_3_SystemCore_setup(freedomk64f_fxos8700_accel_3_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue;
  uint8_T status;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (size_t)1 * sizeof(uint8_T));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  obj->isSetupComplete = true;
}

static void accel_3_SystemCore_setup_n(dsp_simulink_MovingAverage_ac_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* System initialize for referenced model: 'accel_3' */
void accel_3_Init(DW_accel_3_f_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Average1' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average1' */
}

/* System reset for referenced model: 'accel_3' */
void accel_3_Reset(DW_accel_3_f_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* InitializeConditions for MATLABSystem: '<Root>/Moving Average1' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average1' */
}

/* Start for referenced model: 'accel_3' */
void accel_3_Start(DW_accel_3_f_T *localDW)
{
  /* Start for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor1' */
  localDW->obj_i.isInitialized = 0;
  localDW->obj_i.i2cobj.isInitialized = 0;
  localDW->obj_i.i2cobj.matlabCodegenIsDeleted = false;
  localDW->obj_i.matlabCodegenIsDeleted = false;
  localDW->objisempty_m = true;
  localDW->obj_i.SampleTime = accel_3_P.FXOS87006AxesSensor1_SampleTime;
  accel_3_SystemCore_setup(&localDW->obj_i);

  /* Start for MATLABSystem: '<Root>/Moving Average1' */
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.FrameLength = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  accel_3_SystemCore_setup_n(&localDW->obj);
}

/* Output and update for referenced model: 'accel_3' */
void accel_3(real_T *rty_Outport, B_accel_3_c_T *localB, DW_accel_3_f_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real_T csum;
  real_T modValueRev;
  real_T rtb_Sqrt1;
  real_T z;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;

  /* MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor1' */
  if (localDW->obj_i.SampleTime != accel_3_P.FXOS87006AxesSensor1_SampleTime) {
    localDW->obj_i.SampleTime = accel_3_P.FXOS87006AxesSensor1_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(localDW->obj_i.i2cobj.MW_I2C_HANDLE, 29U, &status,
    1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(localDW->obj_i.i2cobj.MW_I2C_HANDLE, 29U, &output_raw[0],
                      6U, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)3 *
           sizeof(int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[0], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[0], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[1], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[1], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[2], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[2], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
    b_RegisterValue[2] = 0;
  }

  localB->FXOS87006AxesSensor1[0] = (real_T)(int16_T)(b_RegisterValue[0] >> 2) *
    2.0 * 0.244 / 1000.0;
  localB->FXOS87006AxesSensor1[1] = (real_T)(int16_T)(b_RegisterValue[1] >> 2) *
    2.0 * 0.244 / 1000.0;
  localB->FXOS87006AxesSensor1[2] = (real_T)(int16_T)(b_RegisterValue[2] >> 2) *
    2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor1' */

  /* Sqrt: '<Root>/Sqrt1' incorporates:
   *  Math: '<Root>/Square3'
   *  Math: '<Root>/Square4'
   *  Math: '<Root>/Square5'
   *  Sum: '<Root>/Sum1'
   */
  rtb_Sqrt1 = sqrt((localB->FXOS87006AxesSensor1[0] *
                    localB->FXOS87006AxesSensor1[0] +
                    localB->FXOS87006AxesSensor1[1] *
                    localB->FXOS87006AxesSensor1[1]) +
                   localB->FXOS87006AxesSensor1[2] *
                   localB->FXOS87006AxesSensor1[2]);

  /* MATLABSystem: '<Root>/Moving Average1' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  localB->cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  localB->FXOS87006AxesSensor1[0] = obj->pCumSumRev[0];
  localB->FXOS87006AxesSensor1[1] = obj->pCumSumRev[1];
  localB->FXOS87006AxesSensor1[2] = obj->pCumSumRev[2];
  modValueRev = obj->pModValueRev;
  z = 0.0;
  localB->rtb_MovingAverage1_m = 0.0;
  csum += rtb_Sqrt1;
  if (modValueRev == 0.0) {
    z = localB->FXOS87006AxesSensor1[(int32_T)localB->cumRevIndex - 1] + csum;
  }

  localB->FXOS87006AxesSensor1[(int32_T)localB->cumRevIndex - 1] = rtb_Sqrt1;
  if (localB->cumRevIndex != 3.0) {
    localB->cumRevIndex++;
  } else {
    localB->cumRevIndex = 1.0;
    csum = 0.0;
    localB->FXOS87006AxesSensor1[1] += localB->FXOS87006AxesSensor1[2];
    localB->FXOS87006AxesSensor1[0] += localB->FXOS87006AxesSensor1[1];
  }

  if (modValueRev == 0.0) {
    localB->rtb_MovingAverage1_m = z / 4.0;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = localB->FXOS87006AxesSensor1[0];
  obj->pCumSumRev[1] = localB->FXOS87006AxesSensor1[1];
  obj->pCumSumRev[2] = localB->FXOS87006AxesSensor1[2];
  obj->pCumRevIndex = localB->cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Moving Average1'
   */
  *rty_Outport = accel_3_P.Gain_Gain * localB->rtb_MovingAverage1_m;
}

/* Termination for referenced model: 'accel_3' */
void accel_3_Term(DW_accel_3_f_T *localDW)
{
  g_dsp_internal_SlidingWindowA_T *obj;

  /* Terminate for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor1' */
  if (!localDW->obj_i.matlabCodegenIsDeleted) {
    localDW->obj_i.matlabCodegenIsDeleted = true;
    if ((localDW->obj_i.isInitialized == 1) && localDW->obj_i.isSetupComplete) {
      MW_I2C_Close(localDW->obj_i.i2cobj.MW_I2C_HANDLE);
    }
  }

  if (!localDW->obj_i.i2cobj.matlabCodegenIsDeleted) {
    localDW->obj_i.i2cobj.matlabCodegenIsDeleted = true;
    if (localDW->obj_i.i2cobj.isInitialized == 1) {
      localDW->obj_i.i2cobj.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor1' */

  /* Terminate for MATLABSystem: '<Root>/Moving Average1' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
      localDW->obj.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Moving Average1' */
}

/* Model initialize function */
void accel_3_initialize(const char_T **rt_errorStatus, RT_MODEL_accel_3_T *const
  accel_3_M, DW_accel_3_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(accel_3_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_accel_3_f_T));
}
