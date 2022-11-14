/*
 * simulink_group46_data.c
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

/* Block parameters (default storage) */
P_simulink_group46_T simulink_group46_P = {
  /* Expression: SampleTime
   * Referenced by: '<S3>/Digital Read1'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S3>/Digital Read2'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Serial Receive'
   */
  0.1,

  /* Expression: SampleTime
   * Referenced by: '<S2>/ATR_SIGNAL'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S2>/VENT_SIGNAL'
   */
  -1.0,

  /* Expression: 320
   * Referenced by: '<S3>/VRP in'
   */
  320.0,

  /* Expression: 250
   * Referenced by: '<S3>/ARP in'
   */
  250.0,

  /* Expression: 4
   * Referenced by: '<S3>/Constant'
   */
  4.0,

  /* Expression: 2
   * Referenced by: '<S3>/Constant1'
   */
  2.0,

  /* Computed Parameter: ScaleFactor1_Value
   * Referenced by: '<S3>/Scale Factor1'
   */
  { { 0xEA60UL, 0UL } },

  /* Computed Parameter: ScaleFactor2_Value
   * Referenced by: '<S3>/Scale Factor2'
   */
  { { 0xEA60UL, 0UL } },

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S3>/Constant2'
   */
  1,

  /* Computed Parameter: URL_Value
   * Referenced by: '<S3>/URL'
   */
  120,

  /* Computed Parameter: LRL_Value
   * Referenced by: '<S3>/LRL'
   */
  60,

  /* Computed Parameter: mode_Value
   * Referenced by: '<S3>/mode'
   */
  2
};
