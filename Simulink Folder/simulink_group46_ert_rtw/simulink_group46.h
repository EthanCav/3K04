/*
 * simulink_group46.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simulink_group46".
 *
 * Model version              : 5.144
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Nov 14 17:01:50 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simulink_group46_h_
#define RTW_HEADER_simulink_group46_h_
#ifndef simulink_group46_COMMON_INCLUDES_
#define simulink_group46_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#include "MW_AnalogIn.h"
#endif                                 /* simulink_group46_COMMON_INCLUDES_ */

#include "simulink_group46_types.h"
#include "multiword_types.h"
#include <string.h>
#include <stddef.h>
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T TxDataLocChar[132];
  uint8_T TmpSignalConversionAtSerial[132];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  real_T Divide2;                      /* '<S3>/Divide2' */
  real_T TmpLatchAtVRPOutport1;
  real_T TmpLatchAtURIOutport1;
  real_T TmpLatchAtLRIOutport1;
  real_T TmpLatchAtARPOutport1;
  real_T TmpLatchAtVAmplitudeOutport1;
  real_T TmpLatchAtAAmplitudeOutport1;
  real_T TmpLatchAtRecoveryTimeOutport1;
  real_T TmpLatchAtResponseFactorOutport;
  real_T TmpLatchAtReactionTimeOutport1;
  real_T TmpLatchAtActivityThresholdOutp;
  real_T TmpLatchAtAtrWidthOutport1;
  real_T TmpLatchAtMSROutport1;
  real_T TmpLatchAtVentSensitivityOutpor;
  real_T TmpLatchAtAtrSensitivityOutport;
  real_T VENT_SIGNAL;                  /* '<S2>/VENT_SIGNAL' */
  real_T ATR_SIGNAL;                   /* '<S2>/ATR_SIGNAL' */
  real_T PACING_REF_PWM;               /* '<Root>/PACING MODES' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/PACING MODES' */
  int16_T TmpLatchAtVentWidthOutport1;
  int16_T TmpLatchAtmodeOutport1;
  int16_T ATR_CMP_REF_PWM;             /* '<Root>/PACING MODES' */
  uint8_T BytePack[8];                 /* '<S3>/Byte Pack' */
  uint8_T BytePack9[8];                /* '<S2>/Byte Pack9' */
  uint8_T BytePack8[2];                /* '<S2>/Byte Pack8' */
  uint8_T BytePack1[8];                /* '<S2>/Byte Pack1' */
  uint8_T BytePack2[8];                /* '<S2>/Byte Pack2' */
  uint8_T BytePack3[8];                /* '<S2>/Byte Pack3' */
  uint8_T BytePack4[2];                /* '<S2>/Byte Pack4' */
  uint8_T BytePack5[8];                /* '<S2>/Byte Pack5' */
  uint8_T BytePack_j[8];               /* '<S2>/Byte Pack' */
  uint8_T BytePack10[8];               /* '<S2>/Byte Pack10' */
  uint8_T BytePack11[8];               /* '<S2>/Byte Pack11' */
  uint8_T BytePack12[8];               /* '<S2>/Byte Pack12' */
  uint8_T BytePack13[8];               /* '<S2>/Byte Pack13' */
  uint8_T BytePack14[8];               /* '<S2>/Byte Pack14' */
  uint8_T BytePack15[8];               /* '<S2>/Byte Pack15' */
  uint8_T BytePack16[8];               /* '<S2>/Byte Pack16' */
  uint8_T BytePack17[8];               /* '<S2>/Byte Pack17' */
  uint8_T BytePack7[8];                /* '<S2>/Byte Pack7' */
  uint8_T BytePack6[8];                /* '<S2>/Byte Pack6' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/PACING MODES' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACING MODES' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACING MODES' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/PACING MODES' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/PACING MODES' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/PACING MODES' */
  boolean_T DigitalRead2;              /* '<S3>/Digital Read2' */
  boolean_T DigitalRead1;              /* '<S3>/Digital Read1' */
} B_simulink_group46_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_AnalogInput_simul_T obj; /* '<S2>/VENT_SIGNAL' */
  freedomk64f_AnalogInput_simul_T obj_e;/* '<S2>/ATR_SIGNAL' */
  freedomk64f_DigitalRead_simul_T obj_d;/* '<S3>/Digital Read2' */
  freedomk64f_DigitalRead_simul_T obj_a;/* '<S3>/Digital Read1' */
  freedomk64f_SCIRead_simulink__T obj_g;/* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_simulink_T obj_f;/* '<S2>/Serial Transmit' */
  freedomk64f_DigitalWrite_simu_T obj_c;/* '<S4>/Digital Write9' */
  freedomk64f_DigitalWrite_simu_T obj_h;/* '<S4>/Digital Write8' */
  freedomk64f_DigitalWrite_simu_T obj_b;/* '<S4>/Digital Write15' */
  freedomk64f_DigitalWrite_simu_T obj_ch;/* '<S4>/Digital Write14' */
  freedomk64f_DigitalWrite_simu_T obj_o;/* '<S4>/Digital Write13' */
  freedomk64f_DigitalWrite_simu_T obj_p;/* '<S4>/Digital Write12' */
  freedomk64f_DigitalWrite_simu_T obj_aj;/* '<S4>/Digital Write11' */
  freedomk64f_DigitalWrite_simu_T obj_e4;/* '<S4>/Digital Write10' */
  freedomk64f_DigitalWrite_simu_T obj_j;/* '<S4>/Digital Write1' */
  freedomk64f_PWMOutput_simulin_T obj_l;/* '<S4>/PWM Output3' */
  freedomk64f_PWMOutput_simulin_T obj_d4;/* '<S4>/PWM Output2' */
  freedomk64f_PWMOutput_simulin_T obj_eb;/* '<S4>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/PACING MODES' */
  uint8_T is_c3_simulink_group46;      /* '<Root>/PACING MODES' */
  uint8_T is_active_c3_simulink_group46;/* '<Root>/PACING MODES' */
  uint8_T is_c1_simulink_group46;      /* '<Root>/COM_IN' */
  uint8_T is_active_c1_simulink_group46;/* '<Root>/COM_IN' */
  boolean_T objisempty;                /* '<S2>/VENT_SIGNAL' */
  boolean_T objisempty_d;              /* '<S2>/Serial Transmit' */
  boolean_T objisempty_j;              /* '<S2>/ATR_SIGNAL' */
  boolean_T objisempty_a;              /* '<Root>/Serial Receive' */
  boolean_T natural;                   /* '<Root>/PACING MODES' */
  boolean_T objisempty_p;              /* '<S4>/PWM Output3' */
  boolean_T objisempty_ap;             /* '<S4>/PWM Output2' */
  boolean_T objisempty_o;              /* '<S4>/PWM Output' */
  boolean_T objisempty_h;              /* '<S4>/Digital Write9' */
  boolean_T objisempty_h3;             /* '<S4>/Digital Write8' */
  boolean_T objisempty_ab;             /* '<S4>/Digital Write15' */
  boolean_T objisempty_py;             /* '<S4>/Digital Write14' */
  boolean_T objisempty_n;              /* '<S4>/Digital Write13' */
  boolean_T objisempty_an;             /* '<S4>/Digital Write12' */
  boolean_T objisempty_hf;             /* '<S4>/Digital Write11' */
  boolean_T objisempty_c;              /* '<S4>/Digital Write10' */
  boolean_T objisempty_ax;             /* '<S4>/Digital Write1' */
  boolean_T objisempty_hd;             /* '<S3>/Digital Read2' */
  boolean_T objisempty_jy;             /* '<S3>/Digital Read1' */
} DW_simulink_group46_T;

/* Parameters (default storage) */
struct P_simulink_group46_T_ {
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S3>/Digital Read1'
                                        */
  real_T DigitalRead2_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S3>/Digital Read2'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T ATR_SIGNAL_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_SIGNAL'
                                        */
  real_T VENT_SIGNAL_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_SIGNAL'
                                        */
  real_T VRPin_Value;                  /* Expression: 320
                                        * Referenced by: '<S3>/VRP in'
                                        */
  real_T ARPin_Value;                  /* Expression: 250
                                        * Referenced by: '<S3>/ARP in'
                                        */
  real_T Constant_Value;               /* Expression: 4
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S3>/Constant1'
                                        */
  int64m_T ScaleFactor1_Value;         /* Computed Parameter: ScaleFactor1_Value
                                        * Referenced by: '<S3>/Scale Factor1'
                                        */
  int64m_T ScaleFactor2_Value;         /* Computed Parameter: ScaleFactor2_Value
                                        * Referenced by: '<S3>/Scale Factor2'
                                        */
  int16_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S3>/Constant2'
                                        */
  int16_T URL_Value;                   /* Computed Parameter: URL_Value
                                        * Referenced by: '<S3>/URL'
                                        */
  int16_T LRL_Value;                   /* Computed Parameter: LRL_Value
                                        * Referenced by: '<S3>/LRL'
                                        */
  int16_T mode_Value;                  /* Computed Parameter: mode_Value
                                        * Referenced by: '<S3>/mode'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_simulink_group46_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_simulink_group46_T simulink_group46_P;

/* Block signals (default storage) */
extern B_simulink_group46_T simulink_group46_B;

/* Block states (default storage) */
extern DW_simulink_group46_T simulink_group46_DW;

/* External data declarations for dependent source files */
extern const real_T simulink_group46_RGND;/* real_T ground */

/* External function called from main */
extern void simulink_group46_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void simulink_group46_initialize(void);
extern void simulink_group46_step0(void);
extern void simulink_group46_step1(void);
extern void simulink_group46_step(int_T tid);
extern void simulink_group46_terminate(void);

/* Real-time Model object */
extern RT_MODEL_simulink_group46_T *const simulink_group46_M;
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
 * '<Root>' : 'simulink_group46'
 * '<S1>'   : 'simulink_group46/COM_IN'
 * '<S2>'   : 'simulink_group46/COM_OUT'
 * '<S3>'   : 'simulink_group46/INPUTS'
 * '<S4>'   : 'simulink_group46/OUTPUTS'
 * '<S5>'   : 'simulink_group46/PACING MODES'
 */
#endif                                 /* RTW_HEADER_simulink_group46_h_ */
