/*
 * accel_3_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "accel_3".
 *
 * Model version              : 5.305
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Nov 28 21:24:42 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_accel_3_private_h_
#define RTW_HEADER_accel_3_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "accel_3.h"
#include "accel_3_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern P_accel_3_T accel_3_P;

#endif                                 /* RTW_HEADER_accel_3_private_h_ */
