/*
 * Pacemaker.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pacemaker".
 *
 * Model version              : 5.75
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Oct 20 19:01:49 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pacemaker.h"
#include "rtwtypes.h"
#include "Pacemaker_types.h"
#include "Pacemaker_private.h"
#include <math.h>
#include <string.h>

/* Named constants for Chart: '<Root>/PACING MODES' */
#define Pacem_IN_Discharge_C22_VENT_VOO ((uint8_T)5U)
#define Pacem_IN_Discharge_C22_VENT_VVI ((uint8_T)6U)
#define Pacem_IN_Sensing_Charge_C22_AAI ((uint8_T)8U)
#define Pacem_IN_Sensing_Charge_C22_VVI ((uint8_T)9U)
#define Pacema_IN_Discharge_C22_ATR_AAI ((uint8_T)3U)
#define Pacema_IN_Discharge_C22_ATR_AOO ((uint8_T)4U)
#define Pacemaker_IN_Charge_C22_AOO    ((uint8_T)1U)
#define Pacemaker_IN_Charge_C22_VOO    ((uint8_T)2U)
#define Pacemaker_IN_Mode_Selector     ((uint8_T)7U)
#define Pacemaker_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define Pacemaker_IN_Wait_AAI          ((uint8_T)10U)
#define Pacemaker_IN_Wait_VVI          ((uint8_T)11U)

/* Block signals (default storage) */
B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
DW_Pacemaker_T Pacemaker_DW;

/* Real-time model */
static RT_MODEL_Pacemaker_T Pacemaker_M_;
RT_MODEL_Pacemaker_T *const Pacemaker_M = &Pacemaker_M_;

/* Forward declaration for local functions */
static void Pac_enter_atomic_Charge_C22_AOO(void);
static void Pac_enter_atomic_Charge_C22_VOO(void);
static void Pacemaker_Mode_Selector(void);
real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void Pac_enter_atomic_Charge_C22_AOO(void)
{
  Pacemaker_B.PACING_REF_PWM = 40;
  Pacemaker_B.PACE_CHARGE_CTRL = true;
  Pacemaker_B.PACE_GND_CTRL = true;
  Pacemaker_B.VENT_PACE_CTRL = false;
  Pacemaker_B.Z_ATR_CTRL = false;
  Pacemaker_B.Z_VENT_CTRL = false;
  Pacemaker_B.ATR_PACE_CTRL = false;
  Pacemaker_B.VENT_GND_CTRL = false;
  Pacemaker_B.ATR_GND_CTRL = true;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void Pac_enter_atomic_Charge_C22_VOO(void)
{
  Pacemaker_B.PACING_REF_PWM = 40;
  Pacemaker_B.PACE_CHARGE_CTRL = true;
  Pacemaker_B.PACE_GND_CTRL = true;
  Pacemaker_B.VENT_PACE_CTRL = false;
  Pacemaker_B.Z_ATR_CTRL = false;
  Pacemaker_B.Z_VENT_CTRL = false;
  Pacemaker_B.ATR_PACE_CTRL = false;
  Pacemaker_B.ATR_GND_CTRL = false;
  Pacemaker_B.VENT_GND_CTRL = true;
}

/* Function for Chart: '<Root>/PACING MODES' */
static void Pacemaker_Mode_Selector(void)
{
  /* Constant: '<S1>/mode' */
  if (Pacemaker_P.mode_Value == 1) {
    Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Charge_C22_VOO;
    Pacemaker_DW.temporalCounter_i1 = 0U;
    Pac_enter_atomic_Charge_C22_VOO();
  } else if (Pacemaker_P.mode_Value == 2) {
    Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Wait_VVI;
    Pacemaker_DW.temporalCounter_i1 = 0U;
    Pacemaker_B.FRONTEND_CTRL = false;
    Pacemaker_B.VENT_CMP_REF_PWM = 53.0;
    Pacemaker_B.PACE_GND_CTRL = true;
    Pacemaker_B.VENT_PACE_CTRL = false;
    Pacemaker_B.Z_ATR_CTRL = false;
    Pacemaker_B.Z_VENT_CTRL = false;
    Pacemaker_B.ATR_PACE_CTRL = false;
    Pacemaker_B.ATR_GND_CTRL = false;
    Pacemaker_B.VENT_GND_CTRL = true;
  } else if (Pacemaker_P.mode_Value == 3) {
    Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Charge_C22_AOO;
    Pacemaker_DW.temporalCounter_i1 = 0U;
    Pac_enter_atomic_Charge_C22_AOO();
  } else if (Pacemaker_P.mode_Value == 4) {
    Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Wait_AAI;
    Pacemaker_DW.temporalCounter_i1 = 0U;
    Pacemaker_B.ATR_CMP_REF_PWM = 53;
    Pacemaker_B.FRONTEND_CTRL = false;
    Pacemaker_B.PACE_GND_CTRL = true;
    Pacemaker_B.VENT_PACE_CTRL = false;
    Pacemaker_B.Z_ATR_CTRL = false;
    Pacemaker_B.Z_VENT_CTRL = false;
    Pacemaker_B.ATR_PACE_CTRL = false;
    Pacemaker_B.VENT_GND_CTRL = false;
    Pacemaker_B.ATR_GND_CTRL = true;
  }

  /* End of Constant: '<S1>/mode' */
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

/* Model step function */
void Pacemaker_step(void)
{
  real_T Divide;
  real_T Divide2;
  int16_T tmp;
  boolean_T DigitalRead1;
  boolean_T DigitalRead2;

  /* MATLABSystem: '<S1>/Digital Read1' */
  if (Pacemaker_DW.obj_a.SampleTime != Pacemaker_P.DigitalRead1_SampleTime) {
    Pacemaker_DW.obj_a.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
  }

  DigitalRead1 = MW_digitalIO_read(Pacemaker_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/BPM'
   *  Constant: '<S1>/Scale Factor'
   */
  Divide = sMultiWord2Double(&Pacemaker_P.ScaleFactor_Value.chunks[0U], 2, 0) /
    (real_T)Pacemaker_P.BPM_Value;

  /* Product: '<S1>/Divide2' incorporates:
   *  Constant: '<S1>/LRL'
   *  Constant: '<S1>/Scale Factor2'
   */
  Divide2 = sMultiWord2Double(&Pacemaker_P.ScaleFactor2_Value.chunks[0U], 2, 0) /
    (real_T)Pacemaker_P.LRL_Value;

  /* MATLABSystem: '<S1>/Digital Read2' */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.DigitalRead2_SampleTime) {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead2_SampleTime;
  }

  DigitalRead2 = MW_digitalIO_read(Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/PACING MODES' incorporates:
   *  Constant: '<S1>/ARP in'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/VRP in'
   *  MATLABSystem: '<S1>/Digital Read1'
   *  MATLABSystem: '<S1>/Digital Read2'
   */
  if (Pacemaker_DW.temporalCounter_i1 < MAX_uint32_T) {
    Pacemaker_DW.temporalCounter_i1++;
  }

  if (Pacemaker_DW.is_active_c3_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c3_Pacemaker = 1U;
    Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Mode_Selector;
  } else {
    switch (Pacemaker_DW.is_c3_Pacemaker) {
     case Pacemaker_IN_Charge_C22_AOO:
      Pacemaker_B.PACING_REF_PWM = 40;
      Pacemaker_B.PACE_CHARGE_CTRL = true;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = false;
      Pacemaker_B.ATR_GND_CTRL = true;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(Divide)) {
        Pacemaker_DW.is_c3_Pacemaker = Pacema_IN_Discharge_C22_ATR_AOO;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.PACE_CHARGE_CTRL = false;
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.ATR_GND_CTRL = false;
        Pacemaker_B.ATR_PACE_CTRL = true;
      }
      break;

     case Pacemaker_IN_Charge_C22_VOO:
      Pacemaker_B.PACING_REF_PWM = 40;
      Pacemaker_B.PACE_CHARGE_CTRL = true;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.ATR_GND_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = true;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)
          Pacemaker_P.Constant2_Value) {
        Pacemaker_DW.is_c3_Pacemaker = Pacem_IN_Discharge_C22_VENT_VOO;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.PACE_CHARGE_CTRL = false;
        Pacemaker_B.ATR_PACE_CTRL = false;
        Pacemaker_B.VENT_GND_CTRL = false;
        Pacemaker_B.VENT_PACE_CTRL = true;
      }
      break;

     case Pacema_IN_Discharge_C22_ATR_AAI:
      Pacemaker_B.PACE_CHARGE_CTRL = false;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.ATR_GND_CTRL = false;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = false;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)
          Pacemaker_P.Constant2_Value) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Wait_AAI;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.ATR_CMP_REF_PWM = 53;
        Pacemaker_B.FRONTEND_CTRL = false;
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.ATR_PACE_CTRL = false;
        Pacemaker_B.ATR_GND_CTRL = true;
      }
      break;

     case Pacema_IN_Discharge_C22_ATR_AOO:
      Pacemaker_B.PACE_CHARGE_CTRL = false;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.ATR_GND_CTRL = false;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = false;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)
          Pacemaker_P.Constant2_Value) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Charge_C22_AOO;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pac_enter_atomic_Charge_C22_AOO();
      }
      break;

     case Pacem_IN_Discharge_C22_VENT_VOO:
      Pacemaker_B.PACE_CHARGE_CTRL = false;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.ATR_GND_CTRL = false;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = false;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(Divide)) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Charge_C22_VOO;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pac_enter_atomic_Charge_C22_VOO();
      }
      break;

     case Pacem_IN_Discharge_C22_VENT_VVI:
      Pacemaker_B.FRONTEND_CTRL = false;
      Pacemaker_B.PACE_CHARGE_CTRL = false;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.ATR_GND_CTRL = false;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = false;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)
          Pacemaker_P.Constant2_Value) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Wait_VVI;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.VENT_CMP_REF_PWM = 53.0;
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.ATR_PACE_CTRL = false;
        Pacemaker_B.VENT_GND_CTRL = true;
      }
      break;

     case Pacemaker_IN_Mode_Selector:
      Pacemaker_Mode_Selector();
      break;

     case Pacem_IN_Sensing_Charge_C22_AAI:
      Pacemaker_B.FRONTEND_CTRL = true;
      Pacemaker_B.PACING_REF_PWM = 40;
      Pacemaker_B.PACE_CHARGE_CTRL = true;
      if (DigitalRead2) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Wait_AAI;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.ATR_CMP_REF_PWM = 53;
        Pacemaker_B.FRONTEND_CTRL = false;
        Pacemaker_B.PACE_GND_CTRL = true;
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.Z_ATR_CTRL = false;
        Pacemaker_B.Z_VENT_CTRL = false;
        Pacemaker_B.ATR_PACE_CTRL = false;
        Pacemaker_B.VENT_GND_CTRL = false;
        Pacemaker_B.ATR_GND_CTRL = true;
      } else {
        Divide = rt_roundd_snf((Divide2 - Pacemaker_P.ARPin_Value) - (real_T)
          Pacemaker_P.Constant2_Value);
        if (Divide < 32768.0) {
          if (Divide >= -32768.0) {
            tmp = (int16_T)Divide;
          } else {
            tmp = MIN_int16_T;
          }
        } else {
          tmp = MAX_int16_T;
        }

        if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)tmp) {
          Pacemaker_DW.is_c3_Pacemaker = Pacema_IN_Discharge_C22_ATR_AAI;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.PACE_CHARGE_CTRL = false;
          Pacemaker_B.PACE_GND_CTRL = true;
          Pacemaker_B.VENT_PACE_CTRL = false;
          Pacemaker_B.ATR_GND_CTRL = false;
          Pacemaker_B.Z_ATR_CTRL = false;
          Pacemaker_B.Z_VENT_CTRL = false;
          Pacemaker_B.VENT_GND_CTRL = false;
          Pacemaker_B.ATR_PACE_CTRL = true;
        }
      }
      break;

     case Pacem_IN_Sensing_Charge_C22_VVI:
      Pacemaker_B.FRONTEND_CTRL = true;
      Pacemaker_B.PACING_REF_PWM = 40;
      Pacemaker_B.PACE_CHARGE_CTRL = true;
      if (DigitalRead1) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Wait_VVI;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.FRONTEND_CTRL = false;
        Pacemaker_B.VENT_CMP_REF_PWM = 53.0;
        Pacemaker_B.PACE_GND_CTRL = true;
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.Z_ATR_CTRL = false;
        Pacemaker_B.Z_VENT_CTRL = false;
        Pacemaker_B.ATR_PACE_CTRL = false;
        Pacemaker_B.ATR_GND_CTRL = false;
        Pacemaker_B.VENT_GND_CTRL = true;
      } else {
        Divide = rt_roundd_snf((Divide2 - Pacemaker_P.VRPin_Value) - (real_T)
          Pacemaker_P.Constant2_Value);
        if (Divide < 32768.0) {
          if (Divide >= -32768.0) {
            tmp = (int16_T)Divide;
          } else {
            tmp = MIN_int16_T;
          }
        } else {
          tmp = MAX_int16_T;
        }

        if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)tmp) {
          Pacemaker_DW.is_c3_Pacemaker = Pacem_IN_Discharge_C22_VENT_VVI;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.FRONTEND_CTRL = false;
          Pacemaker_B.PACE_CHARGE_CTRL = false;
          Pacemaker_B.PACE_GND_CTRL = true;
          Pacemaker_B.ATR_PACE_CTRL = false;
          Pacemaker_B.ATR_GND_CTRL = false;
          Pacemaker_B.Z_ATR_CTRL = false;
          Pacemaker_B.Z_VENT_CTRL = false;
          Pacemaker_B.VENT_GND_CTRL = false;
          Pacemaker_B.VENT_PACE_CTRL = true;
        }
      }
      break;

     case Pacemaker_IN_Wait_AAI:
      Pacemaker_B.ATR_CMP_REF_PWM = 53;
      Pacemaker_B.FRONTEND_CTRL = false;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = false;
      Pacemaker_B.ATR_GND_CTRL = true;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_P.ARPin_Value)) {
        Pacemaker_DW.is_c3_Pacemaker = Pacem_IN_Sensing_Charge_C22_AAI;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.FRONTEND_CTRL = true;
        Pacemaker_B.ATR_PACE_CTRL = false;
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.PACING_REF_PWM = 40;
        Pacemaker_B.PACE_CHARGE_CTRL = true;
      }
      break;

     default:
      /* case IN_Wait_VVI: */
      Pacemaker_B.FRONTEND_CTRL = false;
      Pacemaker_B.VENT_CMP_REF_PWM = 53.0;
      Pacemaker_B.PACE_GND_CTRL = true;
      Pacemaker_B.Z_ATR_CTRL = false;
      Pacemaker_B.Z_VENT_CTRL = false;
      Pacemaker_B.ATR_GND_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = true;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Pacemaker_P.VRPin_Value)) {
        Pacemaker_DW.is_c3_Pacemaker = Pacem_IN_Sensing_Charge_C22_VVI;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacemaker_B.FRONTEND_CTRL = true;
        Pacemaker_B.ATR_PACE_CTRL = false;
        Pacemaker_B.VENT_PACE_CTRL = false;
        Pacemaker_B.PACING_REF_PWM = 40;
        Pacemaker_B.PACE_CHARGE_CTRL = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/PACING MODES' */

  /* MATLABSystem: '<S2>/PWM Output2' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_d.MW_PWM_HANDLE,
                      Pacemaker_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S2>/Digital Write9' */
  MW_digitalIO_write(Pacemaker_DW.obj_c.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S2>/PWM Output3' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_l.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/Digital Write10' */
  MW_digitalIO_write(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S2>/Digital Write11' */
  MW_digitalIO_write(Pacemaker_DW.obj_aj.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write12' */
  MW_digitalIO_write(Pacemaker_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write13' */
  MW_digitalIO_write(Pacemaker_DW.obj_o.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S2>/Digital Write14' */
  MW_digitalIO_write(Pacemaker_DW.obj_ch.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S2>/Digital Write15' */
  MW_digitalIO_write(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(Pacemaker_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.FRONTEND_CTRL);

  /* MATLABSystem: '<S2>/PWM Output' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_eb.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.ATR_CMP_REF_PWM);
}

/* Model initialize function */
void Pacemaker_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Pacemaker_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Pacemaker_B), 0,
                sizeof(B_Pacemaker_T));

  /* states (dwork) */
  (void) memset((void *)&Pacemaker_DW, 0,
                sizeof(DW_Pacemaker_T));

  {
    freedomk64f_DigitalRead_Pacem_T *obj;
    freedomk64f_DigitalWrite_Pace_T *obj_1;
    freedomk64f_PWMOutput_Pacemak_T *obj_0;

    /* Start for MATLABSystem: '<S1>/Digital Read1' */
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_j = true;
    Pacemaker_DW.obj_a.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
    obj = &Pacemaker_DW.obj_a;
    Pacemaker_DW.obj_a.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Read2' */
    Pacemaker_DW.obj.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_hd = true;
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead2_SampleTime;
    obj = &Pacemaker_DW.obj;
    Pacemaker_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Pacemaker_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output2' */
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_a = true;
    obj_0 = &Pacemaker_DW.obj_d;
    Pacemaker_DW.obj_d.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 53.0);
    MW_PWM_Start(Pacemaker_DW.obj_d.MW_PWM_HANDLE);
    Pacemaker_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write9' */
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_h = true;
    obj_1 = &Pacemaker_DW.obj_c;
    Pacemaker_DW.obj_c.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_h3 = true;
    obj_1 = &Pacemaker_DW.obj_h;
    Pacemaker_DW.obj_h.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output3' */
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty = true;
    obj_0 = &Pacemaker_DW.obj_l;
    Pacemaker_DW.obj_l.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 40.0);
    MW_PWM_Start(Pacemaker_DW.obj_l.MW_PWM_HANDLE);
    Pacemaker_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write10' */
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_c = true;
    obj_1 = &Pacemaker_DW.obj_e;
    Pacemaker_DW.obj_e.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write11' */
    Pacemaker_DW.obj_aj.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_hf = true;
    obj_1 = &Pacemaker_DW.obj_aj;
    Pacemaker_DW.obj_aj.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_DW.obj_aj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write12' */
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_an = true;
    obj_1 = &Pacemaker_DW.obj_p;
    Pacemaker_DW.obj_p.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write13' */
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_n = true;
    obj_1 = &Pacemaker_DW.obj_o;
    Pacemaker_DW.obj_o.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Pacemaker_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write14' */
    Pacemaker_DW.obj_ch.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_p = true;
    obj_1 = &Pacemaker_DW.obj_ch;
    Pacemaker_DW.obj_ch.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Pacemaker_DW.obj_ch.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write15' */
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_ab = true;
    obj_1 = &Pacemaker_DW.obj_b;
    Pacemaker_DW.obj_b.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_ax = true;
    obj_1 = &Pacemaker_DW.obj_j;
    Pacemaker_DW.obj_j.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    Pacemaker_DW.obj_eb.matlabCodegenIsDeleted = false;
    Pacemaker_DW.objisempty_o = true;
    obj_0 = &Pacemaker_DW.obj_eb;
    Pacemaker_DW.obj_eb.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 53.0);
    MW_PWM_Start(Pacemaker_DW.obj_eb.MW_PWM_HANDLE);
    Pacemaker_DW.obj_eb.isSetupComplete = true;
  }

  /* SystemInitialize for Chart: '<Root>/PACING MODES' */
  Pacemaker_DW.temporalCounter_i1 = 0U;
  Pacemaker_DW.is_active_c3_Pacemaker = 0U;
  Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_NO_ACTIVE_CHILD;
  Pacemaker_B.ATR_PACE_CTRL = false;
  Pacemaker_B.VENT_PACE_CTRL = false;
  Pacemaker_B.PACING_REF_PWM = 0;
  Pacemaker_B.PACE_CHARGE_CTRL = false;
  Pacemaker_B.PACE_GND_CTRL = false;
  Pacemaker_B.ATR_GND_CTRL = false;
  Pacemaker_B.Z_ATR_CTRL = false;
  Pacemaker_B.Z_VENT_CTRL = false;
  Pacemaker_B.VENT_GND_CTRL = false;
  Pacemaker_B.FRONTEND_CTRL = false;
  Pacemaker_B.VENT_CMP_REF_PWM = 0.0;
  Pacemaker_B.ATR_CMP_REF_PWM = 0;
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Read1' */
  if (!Pacemaker_DW.obj_a.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_a.isInitialized == 1) &&
        Pacemaker_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Read1' */

  /* Terminate for MATLABSystem: '<S1>/Digital Read2' */
  if (!Pacemaker_DW.obj.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj.isInitialized == 1) &&
        Pacemaker_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Read2' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output2' */
  if (!Pacemaker_DW.obj_d.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_d.isInitialized == 1) &&
        Pacemaker_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write9' */
  if (!Pacemaker_DW.obj_c.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_c.isInitialized == 1) &&
        Pacemaker_DW.obj_c.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_c.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write9' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  if (!Pacemaker_DW.obj_h.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_h.isInitialized == 1) &&
        Pacemaker_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output3' */
  if (!Pacemaker_DW.obj_l.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_l.isInitialized == 1) &&
        Pacemaker_DW.obj_l.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_l.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_l.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output3' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write10' */
  if (!Pacemaker_DW.obj_e.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_e.isInitialized == 1) &&
        Pacemaker_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write10' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write11' */
  if (!Pacemaker_DW.obj_aj.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_aj.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_aj.isInitialized == 1) &&
        Pacemaker_DW.obj_aj.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_aj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write11' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write12' */
  if (!Pacemaker_DW.obj_p.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_p.isInitialized == 1) &&
        Pacemaker_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write12' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write13' */
  if (!Pacemaker_DW.obj_o.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_o.isInitialized == 1) &&
        Pacemaker_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write13' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write14' */
  if (!Pacemaker_DW.obj_ch.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_ch.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_ch.isInitialized == 1) &&
        Pacemaker_DW.obj_ch.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_ch.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write14' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write15' */
  if (!Pacemaker_DW.obj_b.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_b.isInitialized == 1) &&
        Pacemaker_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write15' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  if (!Pacemaker_DW.obj_j.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_j.isInitialized == 1) &&
        Pacemaker_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  if (!Pacemaker_DW.obj_eb.matlabCodegenIsDeleted) {
    Pacemaker_DW.obj_eb.matlabCodegenIsDeleted = true;
    if ((Pacemaker_DW.obj_eb.isInitialized == 1) &&
        Pacemaker_DW.obj_eb.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_DW.obj_eb.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_DW.obj_eb.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM Output' */
}
