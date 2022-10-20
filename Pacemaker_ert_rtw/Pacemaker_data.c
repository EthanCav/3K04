/*
 * Pacemaker_data.c
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

/* Block parameters (default storage) */
P_Pacemaker_T Pacemaker_P = {
  /* Expression: SampleTime
   * Referenced by: '<S1>/Digital Read1'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S1>/Digital Read2'
   */
  -1.0,

  /* Expression: 320
   * Referenced by: '<S1>/VRP in'
   */
  320.0,

  /* Expression: 250
   * Referenced by: '<S1>/ARP in'
   */
  250.0,

  /* Computed Parameter: ScaleFactor_Value
   * Referenced by: '<S1>/Scale Factor'
   */
  { { 0xEA60UL, 0UL } },

  /* Computed Parameter: ScaleFactor1_Value
   * Referenced by: '<S1>/Scale Factor1'
   */
  { { 0xEA60UL, 0UL } },

  /* Computed Parameter: ScaleFactor2_Value
   * Referenced by: '<S1>/Scale Factor2'
   */
  { { 0xEA60UL, 0UL } },

  /* Computed Parameter: BPM_Value
   * Referenced by: '<S1>/BPM'
   */
  60,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S1>/Constant2'
   */
  1,

  /* Computed Parameter: URL_Value
   * Referenced by: '<S1>/URL'
   */
  120,

  /* Computed Parameter: LRL_Value
   * Referenced by: '<S1>/LRL'
   */
  60,

  /* Computed Parameter: mode_Value
   * Referenced by: '<S1>/mode'
   */
  2
};
