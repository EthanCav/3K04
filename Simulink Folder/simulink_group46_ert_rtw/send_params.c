/*
 * Code generation for system system '<Root>/COM_OUT'
 *
 * Model                      : simulink_group46
 * Model version              : 5.144
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Nov 14 17:01:50 2022
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "simulink_group46_types.h"
#include "send_params_private.h"
#include "simulink_group46.h"
#include "send_params.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "simulink_group46_private.h"

/* Forward declaration for local functions */
static void simulink_group_SystemCore_setup(freedomk64f_SCIWrite_simulink_T *obj);
static void simulink_group_SystemCore_setup(freedomk64f_SCIWrite_simulink_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Start for Simulink Function: '<Root>/COM_OUT' */
void send_params_Start(void)
{
  MW_AnalogIn_TriggerSource_Type trigger_val;
  freedomk64f_AnalogInput_simul_T *obj;

  /* Start for MATLABSystem: '<S2>/ATR_SIGNAL' */
  simulink_group46_DW.obj_e.matlabCodegenIsDeleted = false;
  simulink_group46_DW.objisempty_j = true;
  simulink_group46_DW.obj_e.SampleTime =
    simulink_group46_P.ATR_SIGNAL_SampleTime;
  obj = &simulink_group46_DW.obj_e;
  simulink_group46_DW.obj_e.isInitialized = 1;
  obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
  trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource(simulink_group46_DW.obj_e.MW_ANALOGIN_HANDLE,
    trigger_val, 0U);
  simulink_group46_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/VENT_SIGNAL' */
  simulink_group46_DW.obj.matlabCodegenIsDeleted = false;
  simulink_group46_DW.objisempty = true;
  simulink_group46_DW.obj.SampleTime = simulink_group46_P.VENT_SIGNAL_SampleTime;
  obj = &simulink_group46_DW.obj;
  simulink_group46_DW.obj.isInitialized = 1;
  obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
  trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource(simulink_group46_DW.obj.MW_ANALOGIN_HANDLE,
    trigger_val, 0U);
  simulink_group46_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S2>/Serial Transmit' */
  simulink_group46_DW.obj_f.isInitialized = 0;
  simulink_group46_DW.obj_f.matlabCodegenIsDeleted = false;
  simulink_group46_DW.objisempty_d = true;
  simulink_group_SystemCore_setup(&simulink_group46_DW.obj_f);
}

/* Output and update for Simulink Function: '<Root>/COM_OUT' */
void send_params(void)
{
  int32_T i;
  uint8_T status;

  /* SignalConversion generated from: '<S2>/VRP' */
  simulink_group46_B.TmpLatchAtVRPOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/VentWidth' */
  simulink_group46_B.TmpLatchAtVentWidthOutport1 = 0;

  /* SignalConversion generated from: '<S2>/URI' */
  simulink_group46_B.TmpLatchAtURIOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/LRI' */
  simulink_group46_B.TmpLatchAtLRIOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/ARP' */
  simulink_group46_B.TmpLatchAtARPOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/mode' */
  simulink_group46_B.TmpLatchAtmodeOutport1 = 0;

  /* SignalConversion generated from: '<S2>/VAmplitude' */
  simulink_group46_B.TmpLatchAtVAmplitudeOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/AAmplitude' */
  simulink_group46_B.TmpLatchAtAAmplitudeOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/RecoveryTime' */
  simulink_group46_B.TmpLatchAtRecoveryTimeOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/ResponseFactor' */
  simulink_group46_B.TmpLatchAtResponseFactorOutport = 0.0;

  /* SignalConversion generated from: '<S2>/ReactionTime' */
  simulink_group46_B.TmpLatchAtReactionTimeOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/ActivityThreshold' */
  simulink_group46_B.TmpLatchAtActivityThresholdOutp = 0.0;

  /* SignalConversion generated from: '<S2>/AtrWidth' */
  simulink_group46_B.TmpLatchAtAtrWidthOutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/MSR' */
  simulink_group46_B.TmpLatchAtMSROutport1 = 0.0;

  /* SignalConversion generated from: '<S2>/VentSensitivity' */
  simulink_group46_B.TmpLatchAtVentSensitivityOutpor = 0.0;

  /* SignalConversion generated from: '<S2>/AtrSensitivity' */
  simulink_group46_B.TmpLatchAtAtrSensitivityOutport = 0.0;

  /* S-Function (any2byte): '<S2>/Byte Pack9' */

  /* Pack: <S2>/Byte Pack9 */
  (void) memcpy(&simulink_group46_B.BytePack9[0],
                &simulink_group46_B.TmpLatchAtVRPOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack8' */

  /* Pack: <S2>/Byte Pack8 */
  (void) memcpy(&simulink_group46_B.BytePack8[0],
                &simulink_group46_B.TmpLatchAtVentWidthOutport1,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack1' */

  /* Pack: <S2>/Byte Pack1 */
  (void) memcpy(&simulink_group46_B.BytePack1[0],
                &simulink_group46_B.TmpLatchAtURIOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack2' */

  /* Pack: <S2>/Byte Pack2 */
  (void) memcpy(&simulink_group46_B.BytePack2[0],
                &simulink_group46_B.TmpLatchAtLRIOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack3' */

  /* Pack: <S2>/Byte Pack3 */
  (void) memcpy(&simulink_group46_B.BytePack3[0],
                &simulink_group46_B.TmpLatchAtARPOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack4' */

  /* Pack: <S2>/Byte Pack4 */
  (void) memcpy(&simulink_group46_B.BytePack4[0],
                &simulink_group46_B.TmpLatchAtmodeOutport1,
                2);

  /* S-Function (any2byte): '<S2>/Byte Pack5' */

  /* Pack: <S2>/Byte Pack5 */
  (void) memcpy(&simulink_group46_B.BytePack5[0],
                &simulink_group46_B.TmpLatchAtVAmplitudeOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack' */

  /* Pack: <S2>/Byte Pack */
  (void) memcpy(&simulink_group46_B.BytePack_j[0],
                &simulink_group46_B.TmpLatchAtAAmplitudeOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack10' */

  /* Pack: <S2>/Byte Pack10 */
  (void) memcpy(&simulink_group46_B.BytePack10[0],
                &simulink_group46_B.TmpLatchAtRecoveryTimeOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack11' */

  /* Pack: <S2>/Byte Pack11 */
  (void) memcpy(&simulink_group46_B.BytePack11[0],
                &simulink_group46_B.TmpLatchAtResponseFactorOutport,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack12' */

  /* Pack: <S2>/Byte Pack12 */
  (void) memcpy(&simulink_group46_B.BytePack12[0],
                &simulink_group46_B.TmpLatchAtReactionTimeOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack13' */

  /* Pack: <S2>/Byte Pack13 */
  (void) memcpy(&simulink_group46_B.BytePack13[0],
                &simulink_group46_B.TmpLatchAtActivityThresholdOutp,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack14' */

  /* Pack: <S2>/Byte Pack14 */
  (void) memcpy(&simulink_group46_B.BytePack14[0],
                &simulink_group46_B.TmpLatchAtAtrWidthOutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack15' */

  /* Pack: <S2>/Byte Pack15 */
  (void) memcpy(&simulink_group46_B.BytePack15[0],
                &simulink_group46_B.TmpLatchAtMSROutport1,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack16' */

  /* Pack: <S2>/Byte Pack16 */
  (void) memcpy(&simulink_group46_B.BytePack16[0],
                &simulink_group46_B.TmpLatchAtVentSensitivityOutpor,
                8);

  /* S-Function (any2byte): '<S2>/Byte Pack17' */

  /* Pack: <S2>/Byte Pack17 */
  (void) memcpy(&simulink_group46_B.BytePack17[0],
                &simulink_group46_B.TmpLatchAtAtrSensitivityOutport,
                8);

  /* MATLABSystem: '<S2>/ATR_SIGNAL' */
  if (simulink_group46_DW.obj_e.SampleTime !=
      simulink_group46_P.ATR_SIGNAL_SampleTime) {
    simulink_group46_DW.obj_e.SampleTime =
      simulink_group46_P.ATR_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(simulink_group46_DW.obj_e.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S2>/ATR_SIGNAL' */
  MW_AnalogInSingle_ReadResult(simulink_group46_DW.obj_e.MW_ANALOGIN_HANDLE,
    &simulink_group46_B.ATR_SIGNAL, 7);

  /* S-Function (any2byte): '<S2>/Byte Pack7' */

  /* Pack: <S2>/Byte Pack7 */
  (void) memcpy(&simulink_group46_B.BytePack7[0], &simulink_group46_B.ATR_SIGNAL,
                8);

  /* MATLABSystem: '<S2>/VENT_SIGNAL' */
  if (simulink_group46_DW.obj.SampleTime !=
      simulink_group46_P.VENT_SIGNAL_SampleTime) {
    simulink_group46_DW.obj.SampleTime =
      simulink_group46_P.VENT_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(simulink_group46_DW.obj.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S2>/VENT_SIGNAL' */
  MW_AnalogInSingle_ReadResult(simulink_group46_DW.obj.MW_ANALOGIN_HANDLE,
    &simulink_group46_B.VENT_SIGNAL, 7);

  /* S-Function (any2byte): '<S2>/Byte Pack6' */

  /* Pack: <S2>/Byte Pack6 */
  (void) memcpy(&simulink_group46_B.BytePack6[0],
                &simulink_group46_B.VENT_SIGNAL,
                8);

  /* SignalConversion generated from: '<S2>/Serial Transmit' */
  simulink_group46_B.TmpSignalConversionAtSerial[8] =
    simulink_group46_B.BytePack8[0];
  simulink_group46_B.TmpSignalConversionAtSerial[9] =
    simulink_group46_B.BytePack8[1];
  simulink_group46_B.TmpSignalConversionAtSerial[34] =
    simulink_group46_B.BytePack4[0];
  simulink_group46_B.TmpSignalConversionAtSerial[35] =
    simulink_group46_B.BytePack4[1];
  for (i = 0; i < 8; i++) {
    simulink_group46_B.TmpSignalConversionAtSerial[i] =
      simulink_group46_B.BytePack9[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 10] =
      simulink_group46_B.BytePack1[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 18] =
      simulink_group46_B.BytePack2[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 26] =
      simulink_group46_B.BytePack3[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 36] =
      simulink_group46_B.BytePack5[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 44] =
      simulink_group46_B.BytePack_j[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 52] =
      simulink_group46_B.BytePack10[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 60] =
      simulink_group46_B.BytePack11[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 68] =
      simulink_group46_B.BytePack12[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 76] =
      simulink_group46_B.BytePack13[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 84] =
      simulink_group46_B.BytePack14[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 92] =
      simulink_group46_B.BytePack15[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 100] =
      simulink_group46_B.BytePack16[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 108] =
      simulink_group46_B.BytePack17[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 116] =
      simulink_group46_B.BytePack7[i];
    simulink_group46_B.TmpSignalConversionAtSerial[i + 124] =
      simulink_group46_B.BytePack6[i];
  }

  /* End of SignalConversion generated from: '<S2>/Serial Transmit' */

  /* MATLABSystem: '<S2>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&simulink_group46_B.TxDataLocChar[0], (void *)
           &simulink_group46_B.TmpSignalConversionAtSerial[0], (size_t)132 *
           sizeof(uint8_T));
    status = MW_SCI_Transmit(simulink_group46_DW.obj_f.MW_SCIHANDLE,
      &simulink_group46_B.TxDataLocChar[0], 132U);
  }

  /* End of MATLABSystem: '<S2>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/COM_OUT' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S2>/ATR_SIGNAL' */
  if (!simulink_group46_DW.obj_e.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_e.isInitialized == 1) &&
        simulink_group46_DW.obj_e.isSetupComplete) {
      MW_AnalogIn_Stop(simulink_group46_DW.obj_e.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(simulink_group46_DW.obj_e.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_SIGNAL' */

  /* Terminate for MATLABSystem: '<S2>/VENT_SIGNAL' */
  if (!simulink_group46_DW.obj.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj.isInitialized == 1) &&
        simulink_group46_DW.obj.isSetupComplete) {
      MW_AnalogIn_Stop(simulink_group46_DW.obj.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(simulink_group46_DW.obj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_SIGNAL' */

  /* Terminate for MATLABSystem: '<S2>/Serial Transmit' */
  if (!simulink_group46_DW.obj_f.matlabCodegenIsDeleted) {
    simulink_group46_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((simulink_group46_DW.obj_f.isInitialized == 1) &&
        simulink_group46_DW.obj_f.isSetupComplete) {
      MW_SCI_Close(simulink_group46_DW.obj_f.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Transmit' */
}
