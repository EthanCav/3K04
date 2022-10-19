/*
 * Pacemaker.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pacemaker".
 *
 * Model version              : 5.65
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 19 18:48:10 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pacemaker_h_
#define RTW_HEADER_Pacemaker_h_
#ifndef Pacemaker_COMMON_INCLUDES_
#define Pacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

#include "Pacemaker_types.h"
#include "multiword_types.h"
#include <math.h>
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Divide2;                      /* '<S1>/Divide2' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/PACING MODES' */
  int16_T PACING_REF_PWM;              /* '<Root>/PACING MODES' */
  int16_T ATR_CMP_REF_PWM;             /* '<Root>/PACING MODES' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/PACING MODES' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACING MODES' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACING MODES' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/PACING MODES' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/PACING MODES' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T DigitalRead1;              /* '<S1>/Digital Read1' */
} B_Pacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Pacem_T obj; /* '<S1>/Digital Read2' */
  freedomk64f_DigitalRead_Pacem_T obj_a;/* '<S1>/Digital Read1' */
  freedomk64f_DigitalWrite_Pace_T obj_c;/* '<S2>/Digital Write9' */
  freedomk64f_DigitalWrite_Pace_T obj_h;/* '<S2>/Digital Write8' */
  freedomk64f_DigitalWrite_Pace_T obj_b;/* '<S2>/Digital Write15' */
  freedomk64f_DigitalWrite_Pace_T obj_ch;/* '<S2>/Digital Write14' */
  freedomk64f_DigitalWrite_Pace_T obj_o;/* '<S2>/Digital Write13' */
  freedomk64f_DigitalWrite_Pace_T obj_p;/* '<S2>/Digital Write12' */
  freedomk64f_DigitalWrite_Pace_T obj_aj;/* '<S2>/Digital Write11' */
  freedomk64f_DigitalWrite_Pace_T obj_e;/* '<S2>/Digital Write10' */
  freedomk64f_DigitalWrite_Pace_T obj_j;/* '<S2>/Digital Write1' */
  freedomk64f_PWMOutput_Pacemak_T obj_l;/* '<S2>/PWM Output3' */
  freedomk64f_PWMOutput_Pacemak_T obj_d;/* '<S2>/PWM Output2' */
  freedomk64f_PWMOutput_Pacemak_T obj_eb;/* '<S2>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACING MODES' */
  uint8_T is_c3_Pacemaker;             /* '<Root>/PACING MODES' */
  uint8_T is_active_c3_Pacemaker;      /* '<Root>/PACING MODES' */
  boolean_T objisempty;                /* '<S2>/PWM Output3' */
  boolean_T objisempty_a;              /* '<S2>/PWM Output2' */
  boolean_T objisempty_o;              /* '<S2>/PWM Output' */
  boolean_T objisempty_h;              /* '<S2>/Digital Write9' */
  boolean_T objisempty_h3;             /* '<S2>/Digital Write8' */
  boolean_T objisempty_ab;             /* '<S2>/Digital Write15' */
  boolean_T objisempty_p;              /* '<S2>/Digital Write14' */
  boolean_T objisempty_n;              /* '<S2>/Digital Write13' */
  boolean_T objisempty_an;             /* '<S2>/Digital Write12' */
  boolean_T objisempty_hf;             /* '<S2>/Digital Write11' */
  boolean_T objisempty_c;              /* '<S2>/Digital Write10' */
  boolean_T objisempty_ax;             /* '<S2>/Digital Write1' */
  boolean_T objisempty_hd;             /* '<S1>/Digital Read2' */
  boolean_T objisempty_j;              /* '<S1>/Digital Read1' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/Digital Read1'
                                        */
  real_T DigitalRead2_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/Digital Read2'
                                        */
  real_T VRPin_Value;                  /* Expression: 320
                                        * Referenced by: '<S1>/VRP in'
                                        */
  real_T ARPin_Value;                  /* Expression: 250
                                        * Referenced by: '<S1>/ARP in'
                                        */
  int64m_T ScaleFactor_Value;          /* Computed Parameter: ScaleFactor_Value
                                        * Referenced by: '<S1>/Scale Factor'
                                        */
  int64m_T ScaleFactor1_Value;         /* Computed Parameter: ScaleFactor1_Value
                                        * Referenced by: '<S1>/Scale Factor1'
                                        */
  int64m_T ScaleFactor2_Value;         /* Computed Parameter: ScaleFactor2_Value
                                        * Referenced by: '<S1>/Scale Factor2'
                                        */
  int16_T BPM_Value;                   /* Computed Parameter: BPM_Value
                                        * Referenced by: '<S1>/BPM'
                                        */
  int16_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S1>/Constant2'
                                        */
  int16_T URL_Value;                   /* Computed Parameter: URL_Value
                                        * Referenced by: '<S1>/URL'
                                        */
  int16_T LRL_Value;                   /* Computed Parameter: LRL_Value
                                        * Referenced by: '<S1>/LRL'
                                        */
  int16_T mode_Value;                  /* Computed Parameter: mode_Value
                                        * Referenced by: '<S1>/mode'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Pacemaker_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Pacemaker_T Pacemaker_P;

/* Block signals (default storage) */
extern B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
extern DW_Pacemaker_T Pacemaker_DW;

/* Model entry point functions */
extern void Pacemaker_initialize(void);
extern void Pacemaker_step(void);
extern void Pacemaker_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pacemaker_T *const Pacemaker_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Pacemaker'
 * '<S1>'   : 'Pacemaker/INPUTS'
 * '<S2>'   : 'Pacemaker/OUTPUTS'
 * '<S3>'   : 'Pacemaker/PACING MODES'
 */
#endif                                 /* RTW_HEADER_Pacemaker_h_ */
