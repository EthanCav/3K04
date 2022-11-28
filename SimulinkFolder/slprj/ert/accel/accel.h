/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: accel.h
 *
 * Code generated for Simulink model 'accel'.
 *
 * Model version                  : 2.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 17:17:44 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_accel_h_
#define RTW_HEADER_accel_h_
#ifndef accel_COMMON_INCLUDES_
#define accel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_I2C.h"
#endif                                 /* accel_COMMON_INCLUDES_ */

#include "accel_types.h"

/* Block signals for model 'accel' */
typedef struct {
  real_T FXOS87006AxesSensor1[3];      /* '<Root>/FXOS8700 6-Axes Sensor1' */
  real_T rtb_MovingAverage1_m;
  real_T cumRevIndex;
} B_accel_c_T;

/* Block states (default storage) for model 'accel' */
typedef struct {
  dsp_simulink_MovingAverage_ac_T obj; /* '<Root>/Moving Average1' */
  freedomk64f_fxos8700_accel_T obj_g;  /* '<Root>/FXOS8700 6-Axes Sensor1' */
  boolean_T objisempty;                /* '<Root>/Moving Average1' */
  boolean_T objisempty_n;              /* '<Root>/FXOS8700 6-Axes Sensor1' */
} DW_accel_f_T;

/* Parameters (default storage) */
struct P_accel_T_ {
  real_T FXOS87006AxesSensor1_SampleTime;/* Expression: -1
                                          * Referenced by: '<Root>/FXOS8700 6-Axes Sensor1'
                                          */
  real_T Gain_Gain;                    /* Expression: 12.5
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_accel_T {
  const char_T **errorStatus;
};

typedef struct {
  B_accel_c_T rtb;
  DW_accel_f_T rtdw;
  RT_MODEL_accel_T rtm;
} MdlrefDW_accel_T;

/* Model reference registration function */
extern void accel_initialize(const char_T **rt_errorStatus, RT_MODEL_accel_T *
  const accel_M);
extern void accel_Init(DW_accel_f_T *localDW);
extern void accel(real_T *rty_Outport, B_accel_c_T *localB, DW_accel_f_T
                  *localDW);
extern void accel_Term(DW_accel_f_T *localDW);

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
 * '<Root>' : 'accel'
 */
#endif                                 /* RTW_HEADER_accel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */