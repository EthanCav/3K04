/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: accel_model_types.h
 *
 * Code generated for Simulink model 'accel_model'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:05:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_accel_model_types_h_
#define RTW_HEADER_accel_model_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor1' */
#include "MW_SVD.h"
#include "MW_I2C.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_c_freedomk64f_Hardware_accel__T
#define typedef_c_freedomk64f_Hardware_accel__T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB c_freedomk64f_Hardware_accel__T;

#endif                             /* typedef_c_freedomk64f_Hardware_accel__T */

#ifndef struct_tag_O0UAiliRyLLAe38ibfdAhE
#define struct_tag_O0UAiliRyLLAe38ibfdAhE

struct tag_O0UAiliRyLLAe38ibfdAhE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_freedomk64f_Hardware_accel__T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_O0UAiliRyLLAe38ibfdAhE */

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_O0UAiliRyLLAe38ibfdAhE b_freedomk64f_I2CMasterWrite__T;

#endif                             /* typedef_b_freedomk64f_I2CMasterWrite__T */

#ifndef struct_tag_v5Zyp5raUQrCF4f9Ln2EwE
#define struct_tag_v5Zyp5raUQrCF4f9Ln2EwE

struct tag_v5Zyp5raUQrCF4f9Ln2EwE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /* struct_tag_v5Zyp5raUQrCF4f9Ln2EwE */

#ifndef typedef_freedomk64f_fxos8700_accel_mo_T
#define typedef_freedomk64f_fxos8700_accel_mo_T

typedef struct tag_v5Zyp5raUQrCF4f9Ln2EwE freedomk64f_fxos8700_accel_mo_T;

#endif                             /* typedef_freedomk64f_fxos8700_accel_mo_T */

#ifndef struct_tag_MpLobwgvX1LsLuxnL1ZqZH
#define struct_tag_MpLobwgvX1LsLuxnL1ZqZH

struct tag_MpLobwgvX1LsLuxnL1ZqZH
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_MpLobwgvX1LsLuxnL1ZqZH */

#ifndef typedef_g_dsp_internal_SlidingWindowA_T
#define typedef_g_dsp_internal_SlidingWindowA_T

typedef struct tag_MpLobwgvX1LsLuxnL1ZqZH g_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_accel_model_T
#define typedef_cell_wrap_accel_model_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_accel_model_T;

#endif                                 /* typedef_cell_wrap_accel_model_T */

#ifndef struct_tag_J1iBdW5I4fqaW9fhmMvNgC
#define struct_tag_J1iBdW5I4fqaW9fhmMvNgC

struct tag_J1iBdW5I4fqaW9fhmMvNgC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_accel_model_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_J1iBdW5I4fqaW9fhmMvNgC */

#ifndef typedef_dsp_simulink_MovingAverage_ac_T
#define typedef_dsp_simulink_MovingAverage_ac_T

typedef struct tag_J1iBdW5I4fqaW9fhmMvNgC dsp_simulink_MovingAverage_ac_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_ac_T */

/* Parameters (default storage) */
typedef struct P_accel_model_T_ P_accel_model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_accel_model_T RT_MODEL_accel_model_T;

#endif                                 /* RTW_HEADER_accel_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
