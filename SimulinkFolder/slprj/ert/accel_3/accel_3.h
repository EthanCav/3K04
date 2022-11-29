/*
 * Code generation for system model 'accel_3'
 * For more details, see corresponding source file accel_3.c
 *
 */

#ifndef RTW_HEADER_accel_3_h_
#define RTW_HEADER_accel_3_h_
#ifndef accel_3_COMMON_INCLUDES_
#define accel_3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#endif                                 /* accel_3_COMMON_INCLUDES_ */

#include "accel_3_types.h"
#include <string.h>

/* Block signals for model 'accel_3' */
typedef struct {
  real_T FXOS87006AxesSensor1[3];      /* '<Root>/FXOS8700 6-Axes Sensor1' */
  real_T rtb_MovingAverage1_m;
  real_T cumRevIndex;
} B_accel_3_c_T;

/* Block states (default storage) for model 'accel_3' */
typedef struct {
  dsp_simulink_MovingAverage_ac_T obj; /* '<Root>/Moving Average1' */
  freedomk64f_fxos8700_accel_3_T obj_i;/* '<Root>/FXOS8700 6-Axes Sensor1' */
  boolean_T objisempty;                /* '<Root>/Moving Average1' */
  boolean_T objisempty_m;              /* '<Root>/FXOS8700 6-Axes Sensor1' */
} DW_accel_3_f_T;

/* Parameters (default storage) */
struct P_accel_3_T_ {
  real_T FXOS87006AxesSensor1_SampleTime;/* Expression: -1
                                          * Referenced by: '<Root>/FXOS8700 6-Axes Sensor1'
                                          */
  real_T Gain_Gain;                    /* Expression: 12.5
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_accel_3_T {
  const char_T **errorStatus;
};

typedef struct {
  B_accel_3_c_T rtb;
  DW_accel_3_f_T rtdw;
  RT_MODEL_accel_3_T rtm;
} MdlrefDW_accel_3_T;

/* Model reference registration function */
extern void accel_3_initialize(const char_T **rt_errorStatus, RT_MODEL_accel_3_T
  *const accel_3_M, DW_accel_3_f_T *localDW);
extern void accel_3_Init(DW_accel_3_f_T *localDW);
extern void accel_3_Reset(DW_accel_3_f_T *localDW);
extern void accel_3_Start(DW_accel_3_f_T *localDW);
extern void accel_3(real_T *rty_Outport, B_accel_3_c_T *localB, DW_accel_3_f_T
                    *localDW);
extern void accel_3_Term(DW_accel_3_f_T *localDW);

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
 * '<Root>' : 'accel_3'
 */
#endif                                 /* RTW_HEADER_accel_3_h_ */
