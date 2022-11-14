/*
 * simulink_group46.c
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

#include "simulink_group46.h"
#include "simulink_group46_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "rt_roundd_snf.h"
#include "simulink_group46_private.h"
#include "sMultiWord2Double.h"
#include "send_params_private.h"
#include "send_params.h"

/* Named constants for Chart: '<Root>/COM_IN' */
#define simulink_gro_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define simulink_group46_IN_ECHO_PARAM ((uint8_T)1U)
#define simulink_group46_IN_INITIAL    ((uint8_T)2U)
#define simulink_group46_IN_SET_PARAM  ((uint8_T)3U)
#define simulink_group46_IN_STANDBY    ((uint8_T)4U)

/* Named constants for Chart: '<Root>/PACING MODES' */
#define simul_IN_Discharge_C22_VENT_VOO ((uint8_T)8U)
#define simul_IN_Discharge_C22_VENT_VVI ((uint8_T)9U)
#define simul_IN_Sensing_Charge_C22_AAI ((uint8_T)2U)
#define simul_IN_Sensing_Charge_C22_VVI ((uint8_T)10U)
#define simuli_IN_Discharge_C22_ATR_AAI ((uint8_T)1U)
#define simuli_IN_Discharge_C22_ATR_AOO ((uint8_T)5U)
#define simulink_grou_IN_Charge_C22_AOO ((uint8_T)4U)
#define simulink_grou_IN_Charge_C22_VOO ((uint8_T)7U)
#define simulink_group46_IN_Wait_AAI   ((uint8_T)3U)
#define simulink_group46_IN_Wait_VVI   ((uint8_T)11U)
#define simulink_group_IN_Mode_Selector ((uint8_T)6U)

const real_T simulink_group46_RGND = 0.0;/* real_T ground */

/* Block signals (default storage) */
B_simulink_group46_T simulink_group46_B;

/* Block states (default storage) */
DW_simulink_group46_T simulink_group46_DW;

/* Real-time model */
static RT_MODEL_simulink_group46_T simulink_group46_M_;
RT_MODEL_simulink_group46_T *const simulink_group46_M = &simulink_group46_M_;

/* Forward declaration for local functions */
static void simulink_gro_SystemCore_setup_g(freedomk64f_SCIRead_simulink__T *obj);
static void simulink__enter_atomic_Wait_AAI(void);
static void simulink_Sensing_Charge_C22_AAI(void);
static void sim_enter_atomic_Charge_C22_AOO(void);
static void simulink__enter_atomic_Wait_VVI(void);
static void sim_enter_atomic_Charge_C22_VOO(void);
static void simulink_Sensing_Charge_C22_VVI(void);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void simulink_group46_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(simulink_group46_M, 1));
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
  (simulink_group46_M->Timing.TaskCounters.TID[1])++;
  if ((simulink_group46_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    simulink_group46_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void simulink_gro_SystemCore_setup_g(freedomk64f_SCIRead_simulink__T *obj)
{
  obj->isInitialized = 1;
  simulink_group46_B.TxPinLoc = MW_UNDEFINED_VALUE;
  simulink_group46_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&simulink_group46_B.SCIModuleLoc, false, 10U,
    simulink_group46_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  simulink_group46_B.StopBitsValue = MW_SCI_STOPBITS_1;
  simulink_group46_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, simulink_group46_B.ParityValue,
                        simulink_group46_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void simulink__enter_atomic_Wait_AAI(void)
{
  simulink_group46_B.ATR_CMP_REF_PWM = 53;
  simulink_group46_B.FRONTEND_CTRL = false;
  simulink_group46_B.PACE_GND_CTRL = true;
  simulink_group46_B.VENT_PACE_CTRL = false;
  simulink_group46_B.Z_ATR_CTRL = false;
  simulink_group46_B.Z_VENT_CTRL = false;
  simulink_group46_B.ATR_PACE_CTRL = false;
  simulink_group46_B.VENT_GND_CTRL = false;
  simulink_group46_B.ATR_GND_CTRL = true;
  simulink_group46_B.PACE_CHARGE_CTRL = true;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void simulink_Sensing_Charge_C22_AAI(void)
{
  real_T tmp;
  real_T tmp_1;
  uint32_T tmp_2;
  int16_T tmp_0;
  boolean_T guard1 = false;
  simulink_group46_B.FRONTEND_CTRL = true;
  simulink_group46_B.PACE_CHARGE_CTRL = true;
  if (simulink_group46_B.DigitalRead2) {
    simulink_group46_DW.natural = true;
    simulink_group46_DW.is_c3_simulink_group46 = simulink_group46_IN_Wait_AAI;
    simulink_group46_DW.temporalCounter_i1 = 0U;
    simulink__enter_atomic_Wait_AAI();
  } else {
    /* Constant: '<S3>/ARP in' */
    tmp_1 = simulink_group46_B.Divide2 - simulink_group46_P.ARPin_Value;

    /* Constant: '<S3>/Constant2' */
    tmp = rt_roundd_snf(tmp_1 - (real_T)simulink_group46_P.Constant2_Value);
    if (tmp < 32768.0) {
      if (tmp >= -32768.0) {
        tmp_0 = (int16_T)tmp;
      } else {
        tmp_0 = MIN_int16_T;
      }
    } else {
      tmp_0 = MAX_int16_T;
    }

    tmp_2 = (uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100);
    guard1 = false;
    if ((tmp_2 >= (uint32_T)tmp_0) && (!simulink_group46_DW.natural)) {
      guard1 = true;
    } else if ((tmp_2 >= (uint32_T)ceil(tmp_1)) && simulink_group46_DW.natural)
    {
      simulink_group46_DW.natural = false;
      guard1 = true;
    }

    if (guard1) {
      simulink_group46_DW.is_c3_simulink_group46 =
        simuli_IN_Discharge_C22_ATR_AAI;
      simulink_group46_DW.temporalCounter_i1 = 0U;
      simulink_group46_B.FRONTEND_CTRL = false;
      simulink_group46_B.PACE_CHARGE_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.VENT_PACE_CTRL = false;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      simulink_group46_B.ATR_PACE_CTRL = true;
    }
  }
}

/* Function for Chart: '<Root>/PACING MODES' */
static void sim_enter_atomic_Charge_C22_AOO(void)
{
  /* Constant: '<S3>/Constant1' */
  simulink_group46_B.PACING_REF_PWM = simulink_group46_P.Constant1_Value / 5.0 *
    100.0;
  simulink_group46_B.PACE_CHARGE_CTRL = true;
  simulink_group46_B.PACE_GND_CTRL = true;
  simulink_group46_B.VENT_PACE_CTRL = false;
  simulink_group46_B.Z_ATR_CTRL = false;
  simulink_group46_B.Z_VENT_CTRL = false;
  simulink_group46_B.ATR_PACE_CTRL = false;
  simulink_group46_B.VENT_GND_CTRL = false;
  simulink_group46_B.ATR_GND_CTRL = true;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void simulink__enter_atomic_Wait_VVI(void)
{
  simulink_group46_B.VENT_CMP_REF_PWM = 70.0;
  simulink_group46_B.FRONTEND_CTRL = false;
  simulink_group46_B.PACE_GND_CTRL = true;
  simulink_group46_B.VENT_PACE_CTRL = false;
  simulink_group46_B.Z_ATR_CTRL = false;
  simulink_group46_B.Z_VENT_CTRL = false;
  simulink_group46_B.ATR_PACE_CTRL = false;
  simulink_group46_B.ATR_GND_CTRL = false;
  simulink_group46_B.VENT_GND_CTRL = true;
  simulink_group46_B.PACE_CHARGE_CTRL = true;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void sim_enter_atomic_Charge_C22_VOO(void)
{
  /* Constant: '<S3>/Constant' */
  simulink_group46_B.PACING_REF_PWM = simulink_group46_P.Constant_Value / 5.0 *
    100.0;
  simulink_group46_B.PACE_CHARGE_CTRL = true;
  simulink_group46_B.PACE_GND_CTRL = true;
  simulink_group46_B.VENT_PACE_CTRL = false;
  simulink_group46_B.Z_ATR_CTRL = false;
  simulink_group46_B.Z_VENT_CTRL = false;
  simulink_group46_B.ATR_PACE_CTRL = false;
  simulink_group46_B.ATR_GND_CTRL = false;
  simulink_group46_B.VENT_GND_CTRL = true;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void simulink_Sensing_Charge_C22_VVI(void)
{
  real_T tmp_0;
  int16_T tmp;
  boolean_T guard1 = false;
  simulink_group46_B.FRONTEND_CTRL = true;
  simulink_group46_B.PACE_CHARGE_CTRL = true;
  if (simulink_group46_B.DigitalRead1) {
    simulink_group46_DW.natural = true;
    simulink_group46_DW.is_c3_simulink_group46 = simulink_group46_IN_Wait_VVI;
    simulink_group46_DW.temporalCounter_i1 = 0U;
    simulink__enter_atomic_Wait_VVI();
  } else {
    /* Constant: '<S3>/VRP in' */
    tmp_0 = simulink_group46_B.Divide2 - simulink_group46_P.VRPin_Value;
    guard1 = false;
    if (((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
         (uint32_T)ceil(tmp_0)) && simulink_group46_DW.natural) {
      simulink_group46_DW.natural = false;
      guard1 = true;
    } else {
      /* Constant: '<S3>/Constant2' */
      tmp_0 = rt_roundd_snf(tmp_0 - (real_T)simulink_group46_P.Constant2_Value);
      if (tmp_0 < 32768.0) {
        if (tmp_0 >= -32768.0) {
          tmp = (int16_T)tmp_0;
        } else {
          tmp = MIN_int16_T;
        }
      } else {
        tmp = MAX_int16_T;
      }

      if (((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
           (uint32_T)tmp) && (!simulink_group46_DW.natural)) {
        guard1 = true;
      }
    }

    if (guard1) {
      simulink_group46_DW.is_c3_simulink_group46 =
        simul_IN_Discharge_C22_VENT_VVI;
      simulink_group46_DW.temporalCounter_i1 = 0U;
      simulink_group46_B.PACE_CHARGE_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.ATR_PACE_CTRL = false;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      simulink_group46_B.VENT_PACE_CTRL = true;
    }
  }
}

/* Model step function for TID0 */
void simulink_group46_step0(void)      /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void simulink_group46_step1(void)      /* Sample time: [0.1s, 0.0s] */
{
  uint8_T RxData[10];
  uint8_T RxDataLocChar[10];
  uint8_T status;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (simulink_group46_DW.obj_g.SampleTime !=
      simulink_group46_P.SerialReceive_SampleTime) {
    simulink_group46_DW.obj_g.SampleTime =
      simulink_group46_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(simulink_group46_DW.obj_g.MW_SCIHANDLE,
    &RxDataLocChar[0], 10U);
  memcpy((void *)&RxData[0], (void *)&RxDataLocChar[0], (size_t)10 * sizeof
         (uint8_T));

  /* End of MATLABSystem: '<Root>/Serial Receive' */

  /* Chart: '<Root>/COM_IN' */
  if (simulink_group46_DW.is_active_c1_simulink_group46 == 0U) {
    simulink_group46_DW.is_active_c1_simulink_group46 = 1U;
    simulink_group46_DW.is_c1_simulink_group46 = simulink_group46_IN_INITIAL;
  } else {
    switch (simulink_group46_DW.is_c1_simulink_group46) {
     case simulink_group46_IN_ECHO_PARAM:
      simulink_group46_DW.is_c1_simulink_group46 = simulink_group46_IN_STANDBY;
      break;

     case simulink_group46_IN_INITIAL:
      simulink_group46_DW.is_c1_simulink_group46 = simulink_group46_IN_STANDBY;
      break;

     case simulink_group46_IN_SET_PARAM:
      simulink_group46_DW.is_c1_simulink_group46 = simulink_group46_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (RxData[0] == 22) {
          if (RxData[1] == 34) {
            simulink_group46_DW.is_c1_simulink_group46 =
              simulink_group46_IN_SET_PARAM;
          } else if (RxData[1] == 51) {
            simulink_group46_DW.is_c1_simulink_group46 =
              simulink_group46_IN_ECHO_PARAM;
            send_params();
          } else {
            simulink_group46_DW.is_c1_simulink_group46 =
              simulink_group46_IN_STANDBY;
          }
        } else {
          simulink_group46_DW.is_c1_simulink_group46 =
            simulink_group46_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/COM_IN' */

  /* MATLABSystem: '<S3>/Digital Read1' */
  if (simulink_group46_DW.obj_a.SampleTime !=
      simulink_group46_P.DigitalRead1_SampleTime) {
    simulink_group46_DW.obj_a.SampleTime =
      simulink_group46_P.DigitalRead1_SampleTime;
  }

  /* MATLABSystem: '<S3>/Digital Read1' */
  simulink_group46_B.DigitalRead1 = MW_digitalIO_read
    (simulink_group46_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* Product: '<S3>/Divide2' incorporates:
   *  Constant: '<S3>/LRL'
   *  Constant: '<S3>/Scale Factor2'
   */
  simulink_group46_B.Divide2 = sMultiWord2Double
    (&simulink_group46_P.ScaleFactor2_Value.chunks[0U], 2, 0) / (real_T)
    simulink_group46_P.LRL_Value;

  /* MATLABSystem: '<S3>/Digital Read2' */
  if (simulink_group46_DW.obj_d.SampleTime !=
      simulink_group46_P.DigitalRead2_SampleTime) {
    simulink_group46_DW.obj_d.SampleTime =
      simulink_group46_P.DigitalRead2_SampleTime;
  }

  /* MATLABSystem: '<S3>/Digital Read2' */
  simulink_group46_B.DigitalRead2 = MW_digitalIO_read
    (simulink_group46_DW.obj_d.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/PACING MODES' incorporates:
   *  Constant: '<S3>/ARP in'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/VRP in'
   *  Constant: '<S3>/mode'
   */
  if (simulink_group46_DW.temporalCounter_i1 < MAX_uint32_T) {
    simulink_group46_DW.temporalCounter_i1++;
  }

  if (simulink_group46_DW.is_active_c3_simulink_group46 == 0U) {
    simulink_group46_DW.is_active_c3_simulink_group46 = 1U;
    simulink_group46_DW.is_c3_simulink_group46 = simulink_group_IN_Mode_Selector;
    simulink_group46_DW.natural = false;
  } else {
    switch (simulink_group46_DW.is_c3_simulink_group46) {
     case simuli_IN_Discharge_C22_ATR_AAI:
      simulink_group46_B.FRONTEND_CTRL = false;
      simulink_group46_B.PACE_CHARGE_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)simulink_group46_P.Constant2_Value) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_group46_IN_Wait_AAI;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink__enter_atomic_Wait_AAI();
      }
      break;

     case simul_IN_Sensing_Charge_C22_AAI:
      simulink_Sensing_Charge_C22_AAI();
      break;

     case simulink_group46_IN_Wait_AAI:
      simulink_group46_B.ATR_CMP_REF_PWM = 53;
      simulink_group46_B.FRONTEND_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      simulink_group46_B.ATR_GND_CTRL = true;
      simulink_group46_B.PACE_CHARGE_CTRL = true;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)ceil(simulink_group46_P.ARPin_Value)) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simul_IN_Sensing_Charge_C22_AAI;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink_group46_B.FRONTEND_CTRL = true;
        simulink_group46_B.ATR_PACE_CTRL = false;
        simulink_group46_B.VENT_PACE_CTRL = false;
        simulink_group46_B.PACING_REF_PWM = simulink_group46_P.Constant1_Value /
          5.0 * 100.0;
        simulink_group46_B.PACE_CHARGE_CTRL = true;
      }
      break;

     case simulink_grou_IN_Charge_C22_AOO:
      simulink_group46_B.PACE_CHARGE_CTRL = true;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      simulink_group46_B.ATR_GND_CTRL = true;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)ceil(simulink_group46_B.Divide2)) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simuli_IN_Discharge_C22_ATR_AOO;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink_group46_B.PACE_CHARGE_CTRL = false;
        simulink_group46_B.PACE_GND_CTRL = true;
        simulink_group46_B.VENT_PACE_CTRL = false;
        simulink_group46_B.ATR_GND_CTRL = false;
        simulink_group46_B.Z_ATR_CTRL = false;
        simulink_group46_B.Z_VENT_CTRL = false;
        simulink_group46_B.VENT_GND_CTRL = false;
        simulink_group46_B.ATR_PACE_CTRL = true;
      }
      break;

     case simuli_IN_Discharge_C22_ATR_AOO:
      simulink_group46_B.PACE_CHARGE_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)simulink_group46_P.Constant2_Value) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_grou_IN_Charge_C22_AOO;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        sim_enter_atomic_Charge_C22_AOO();
      }
      break;

     case simulink_group_IN_Mode_Selector:
      if (simulink_group46_P.mode_Value == 1) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_grou_IN_Charge_C22_VOO;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        sim_enter_atomic_Charge_C22_VOO();
      } else if (simulink_group46_P.mode_Value == 2) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_group46_IN_Wait_VVI;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink__enter_atomic_Wait_VVI();
      } else if (simulink_group46_P.mode_Value == 3) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_grou_IN_Charge_C22_AOO;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        sim_enter_atomic_Charge_C22_AOO();
      } else if (simulink_group46_P.mode_Value == 4) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_group46_IN_Wait_AAI;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink__enter_atomic_Wait_AAI();
      }
      break;

     case simulink_grou_IN_Charge_C22_VOO:
      simulink_group46_B.PACE_CHARGE_CTRL = true;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = true;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)simulink_group46_P.Constant2_Value) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simul_IN_Discharge_C22_VENT_VOO;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink_group46_B.PACE_CHARGE_CTRL = false;
        simulink_group46_B.PACE_GND_CTRL = true;
        simulink_group46_B.ATR_PACE_CTRL = false;
        simulink_group46_B.ATR_GND_CTRL = false;
        simulink_group46_B.Z_ATR_CTRL = false;
        simulink_group46_B.Z_VENT_CTRL = false;
        simulink_group46_B.VENT_GND_CTRL = false;
        simulink_group46_B.VENT_PACE_CTRL = true;
      }
      break;

     case simul_IN_Discharge_C22_VENT_VOO:
      simulink_group46_B.PACE_CHARGE_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)ceil(simulink_group46_B.Divide2)) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_grou_IN_Charge_C22_VOO;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        sim_enter_atomic_Charge_C22_VOO();
      }
      break;

     case simul_IN_Discharge_C22_VENT_VVI:
      simulink_group46_B.PACE_CHARGE_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = false;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)simulink_group46_P.Constant2_Value) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simulink_group46_IN_Wait_VVI;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink__enter_atomic_Wait_VVI();
      }
      break;

     case simul_IN_Sensing_Charge_C22_VVI:
      simulink_Sensing_Charge_C22_VVI();
      break;

     default:
      /* case IN_Wait_VVI: */
      simulink_group46_B.VENT_CMP_REF_PWM = 70.0;
      simulink_group46_B.FRONTEND_CTRL = false;
      simulink_group46_B.PACE_GND_CTRL = true;
      simulink_group46_B.Z_ATR_CTRL = false;
      simulink_group46_B.Z_VENT_CTRL = false;
      simulink_group46_B.ATR_GND_CTRL = false;
      simulink_group46_B.VENT_GND_CTRL = true;
      simulink_group46_B.PACE_CHARGE_CTRL = true;
      if ((uint32_T)((int32_T)simulink_group46_DW.temporalCounter_i1 * 100) >=
          (uint32_T)ceil(simulink_group46_P.VRPin_Value)) {
        simulink_group46_DW.is_c3_simulink_group46 =
          simul_IN_Sensing_Charge_C22_VVI;
        simulink_group46_DW.temporalCounter_i1 = 0U;
        simulink_group46_B.FRONTEND_CTRL = true;
        simulink_group46_B.ATR_PACE_CTRL = false;
        simulink_group46_B.VENT_PACE_CTRL = false;
        simulink_group46_B.PACING_REF_PWM = simulink_group46_P.Constant_Value /
          5.0 * 100.0;
        simulink_group46_B.PACE_CHARGE_CTRL = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/PACING MODES' */

  /* MATLABSystem: '<S4>/PWM Output2' */
  MW_PWM_SetDutyCycle(simulink_group46_DW.obj_d4.MW_PWM_HANDLE,
                      simulink_group46_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write9' */
  MW_digitalIO_write(simulink_group46_DW.obj_c.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write8' */
  MW_digitalIO_write(simulink_group46_DW.obj_h.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/PWM Output3' */
  MW_PWM_SetDutyCycle(simulink_group46_DW.obj_l.MW_PWM_HANDLE,
                      simulink_group46_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write10' */
  MW_digitalIO_write(simulink_group46_DW.obj_e4.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write11' */
  MW_digitalIO_write(simulink_group46_DW.obj_aj.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write12' */
  MW_digitalIO_write(simulink_group46_DW.obj_p.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write13' */
  MW_digitalIO_write(simulink_group46_DW.obj_o.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S4>/Digital Write14' */
  MW_digitalIO_write(simulink_group46_DW.obj_ch.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S4>/Digital Write15' */
  MW_digitalIO_write(simulink_group46_DW.obj_b.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(simulink_group46_DW.obj_j.MW_DIGITALIO_HANDLE,
                     simulink_group46_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(simulink_group46_DW.obj_eb.MW_PWM_HANDLE, (real_T)
                      simulink_group46_B.ATR_CMP_REF_PWM);

  /* S-Function (any2byte): '<S3>/Byte Pack' */

  /* Pack: <S3>/Byte Pack */
  (void) memcpy(&simulink_group46_B.BytePack[0], ((const real_T*)
    &simulink_group46_RGND),
                8);
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void simulink_group46_step(int_T tid)
{
  switch (tid) {
   case 0 :
    simulink_group46_step0();
    break;

   case 1 :
    simulink_group46_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void simulink_group46_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)simulink_group46_M, 0,
                sizeof(RT_MODEL_simulink_group46_T));

  /* block I/O */
  (void) memset(((void *) &simulink_group46_B), 0,
                sizeof(B_simulink_group46_T));

  /* states (dwork) */
  (void) memset((void *)&simulink_group46_DW, 0,
                sizeof(DW_simulink_group46_T));

  {
    freedomk64f_DigitalRead_simul_T *obj;
    freedomk64f_DigitalWrite_simu_T *obj_1;
    freedomk64f_PWMOutput_simulin_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    simulink_group46_DW.obj_g.isInitialized = 0;
    simulink_group46_DW.obj_g.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_a = true;
    simulink_group46_DW.obj_g.SampleTime =
      simulink_group46_P.SerialReceive_SampleTime;
    simulink_gro_SystemCore_setup_g(&simulink_group46_DW.obj_g);

    /* Start for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' incorporates:
     *  SubSystem: '<Root>/COM_OUT'
     */
    send_params_Start();

    /* End of Start for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' */

    /* Start for MATLABSystem: '<S3>/Digital Read1' */
    simulink_group46_DW.obj_a.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_jy = true;
    simulink_group46_DW.obj_a.SampleTime =
      simulink_group46_P.DigitalRead1_SampleTime;
    obj = &simulink_group46_DW.obj_a;
    simulink_group46_DW.obj_a.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    simulink_group46_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Read2' */
    simulink_group46_DW.obj_d.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_hd = true;
    simulink_group46_DW.obj_d.SampleTime =
      simulink_group46_P.DigitalRead2_SampleTime;
    obj = &simulink_group46_DW.obj_d;
    simulink_group46_DW.obj_d.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    simulink_group46_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output2' */
    simulink_group46_DW.obj_d4.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_ap = true;
    obj_0 = &simulink_group46_DW.obj_d4;
    simulink_group46_DW.obj_d4.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 53.0);
    MW_PWM_Start(simulink_group46_DW.obj_d4.MW_PWM_HANDLE);
    simulink_group46_DW.obj_d4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write9' */
    simulink_group46_DW.obj_c.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_h = true;
    obj_1 = &simulink_group46_DW.obj_c;
    simulink_group46_DW.obj_c.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    simulink_group46_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    simulink_group46_DW.obj_h.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_h3 = true;
    obj_1 = &simulink_group46_DW.obj_h;
    simulink_group46_DW.obj_h.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    simulink_group46_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output3' */
    simulink_group46_DW.obj_l.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_p = true;
    obj_0 = &simulink_group46_DW.obj_l;
    simulink_group46_DW.obj_l.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 40.0);
    MW_PWM_Start(simulink_group46_DW.obj_l.MW_PWM_HANDLE);
    simulink_group46_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write10' */
    simulink_group46_DW.obj_e4.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_c = true;
    obj_1 = &simulink_group46_DW.obj_e4;
    simulink_group46_DW.obj_e4.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    simulink_group46_DW.obj_e4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write11' */
    simulink_group46_DW.obj_aj.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_hf = true;
    obj_1 = &simulink_group46_DW.obj_aj;
    simulink_group46_DW.obj_aj.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    simulink_group46_DW.obj_aj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write12' */
    simulink_group46_DW.obj_p.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_an = true;
    obj_1 = &simulink_group46_DW.obj_p;
    simulink_group46_DW.obj_p.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    simulink_group46_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write13' */
    simulink_group46_DW.obj_o.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_n = true;
    obj_1 = &simulink_group46_DW.obj_o;
    simulink_group46_DW.obj_o.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    simulink_group46_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write14' */
    simulink_group46_DW.obj_ch.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_py = true;
    obj_1 = &simulink_group46_DW.obj_ch;
    simulink_group46_DW.obj_ch.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    simulink_group46_DW.obj_ch.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write15' */
    simulink_group46_DW.obj_b.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_ab = true;
    obj_1 = &simulink_group46_DW.obj_b;
    simulink_group46_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    simulink_group46_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    simulink_group46_DW.obj_j.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_ax = true;
    obj_1 = &simulink_group46_DW.obj_j;
    simulink_group46_DW.obj_j.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    simulink_group46_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    simulink_group46_DW.obj_eb.matlabCodegenIsDeleted = false;
    simulink_group46_DW.objisempty_o = true;
    obj_0 = &simulink_group46_DW.obj_eb;
    simulink_group46_DW.obj_eb.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 53.0);
    MW_PWM_Start(simulink_group46_DW.obj_eb.MW_PWM_HANDLE);
    simulink_group46_DW.obj_eb.isSetupComplete = true;
  }

  /* SystemInitialize for Chart: '<Root>/COM_IN' */
  simulink_group46_DW.is_active_c1_simulink_group46 = 0U;
  simulink_group46_DW.is_c1_simulink_group46 = simulink_gro_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/PACING MODES' */
  simulink_group46_DW.temporalCounter_i1 = 0U;
  simulink_group46_DW.is_active_c3_simulink_group46 = 0U;
  simulink_group46_DW.is_c3_simulink_group46 = simulink_gro_IN_NO_ACTIVE_CHILD;
  simulink_group46_DW.natural = false;
  simulink_group46_B.ATR_PACE_CTRL = false;
  simulink_group46_B.VENT_PACE_CTRL = false;
  simulink_group46_B.PACING_REF_PWM = 0.0;
  simulink_group46_B.PACE_CHARGE_CTRL = false;
  simulink_group46_B.PACE_GND_CTRL = false;
  simulink_group46_B.ATR_GND_CTRL = false;
  simulink_group46_B.Z_ATR_CTRL = false;
  simulink_group46_B.Z_VENT_CTRL = false;
  simulink_group46_B.VENT_GND_CTRL = false;
  simulink_group46_B.FRONTEND_CTRL = false;
  simulink_group46_B.VENT_CMP_REF_PWM = 0.0;
  simulink_group46_B.ATR_CMP_REF_PWM = 0;
}

/* Model terminate function */
void simulink_group46_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!simulink_group46_DW.obj_g.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_g.isInitialized == 1) &&
        simulink_group46_DW.obj_g.isSetupComplete) {
      MW_SCI_Close(simulink_group46_DW.obj_g.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' incorporates:
   *  SubSystem: '<Root>/COM_OUT'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/COM_OUT' */

  /* Terminate for MATLABSystem: '<S3>/Digital Read1' */
  if (!simulink_group46_DW.obj_a.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_a.isInitialized == 1) &&
        simulink_group46_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S3>/Digital Read2' */
  if (!simulink_group46_DW.obj_d.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_d.isInitialized == 1) &&
        simulink_group46_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Read2' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output2' */
  if (!simulink_group46_DW.obj_d4.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_d4.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_d4.isInitialized == 1) &&
        simulink_group46_DW.obj_d4.isSetupComplete) {
      MW_PWM_Stop(simulink_group46_DW.obj_d4.MW_PWM_HANDLE);
      MW_PWM_Close(simulink_group46_DW.obj_d4.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write9' */
  if (!simulink_group46_DW.obj_c.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_c.isInitialized == 1) &&
        simulink_group46_DW.obj_c.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_c.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write9' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write8' */
  if (!simulink_group46_DW.obj_h.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_h.isInitialized == 1) &&
        simulink_group46_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output3' */
  if (!simulink_group46_DW.obj_l.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_l.isInitialized == 1) &&
        simulink_group46_DW.obj_l.isSetupComplete) {
      MW_PWM_Stop(simulink_group46_DW.obj_l.MW_PWM_HANDLE);
      MW_PWM_Close(simulink_group46_DW.obj_l.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output3' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write10' */
  if (!simulink_group46_DW.obj_e4.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_e4.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_e4.isInitialized == 1) &&
        simulink_group46_DW.obj_e4.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_e4.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write11' */
  if (!simulink_group46_DW.obj_aj.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_aj.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_aj.isInitialized == 1) &&
        simulink_group46_DW.obj_aj.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_aj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write11' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write12' */
  if (!simulink_group46_DW.obj_p.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_p.isInitialized == 1) &&
        simulink_group46_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write12' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write13' */
  if (!simulink_group46_DW.obj_o.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_o.isInitialized == 1) &&
        simulink_group46_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write13' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write14' */
  if (!simulink_group46_DW.obj_ch.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_ch.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_ch.isInitialized == 1) &&
        simulink_group46_DW.obj_ch.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_ch.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write14' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write15' */
  if (!simulink_group46_DW.obj_b.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_b.isInitialized == 1) &&
        simulink_group46_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write15' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!simulink_group46_DW.obj_j.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_j.isInitialized == 1) &&
        simulink_group46_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(simulink_group46_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!simulink_group46_DW.obj_eb.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_eb.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_eb.isInitialized == 1) &&
        simulink_group46_DW.obj_eb.isSetupComplete) {
      MW_PWM_Stop(simulink_group46_DW.obj_eb.MW_PWM_HANDLE);
      MW_PWM_Close(simulink_group46_DW.obj_eb.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */
}
