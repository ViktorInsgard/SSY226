/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie.c
 *
 * Code generated for Simulink model 'crazyflie'.
 *
 * Model version                  : 1.370
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Nov 23 16:10:53 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "crazyflie.h"

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Model step function */
void crazyflie_step(void)
{
  /* Outport: '<Root>/Log1' incorporates:
   *  Inport: '<Root>/Acc_x'
   */
  rtY.Log1 = rtU.Acc_x;

  /* Outport: '<Root>/Log2' incorporates:
   *  Inport: '<Root>/Acc_y'
   */
  rtY.Log2 = rtU.Acc_y;

  /* Outport: '<Root>/Log3' incorporates:
   *  Inport: '<Root>/Acc_y'
   */
  rtY.Log3 = rtU.Acc_y;

  /* Outport: '<Root>/Log4' incorporates:
   *  Inport: '<Root>/Gyro_x'
   */
  rtY.Log4 = rtU.Gyro_x;

  /* Outport: '<Root>/Log5' incorporates:
   *  Inport: '<Root>/Gyro_y'
   */
  rtY.Log5 = rtU.Gyro_y;

  /* Outport: '<Root>/Log6' incorporates:
   *  Inport: '<Root>/Gyro_z'
   */
  rtY.Log6 = rtU.Gyro_z;
}

/* Model initialize function */
void crazyflie_initialize(void)
{
  /* ConstCode for Outport: '<Root>/Motor_1' */
  rtY.Motor_1 = 15000U;

  /* ConstCode for Outport: '<Root>/Motor_2' */
  rtY.Motor_2 = 15000U;

  /* ConstCode for Outport: '<Root>/Motor_3' */
  rtY.Motor_3 = 15000U;

  /* ConstCode for Outport: '<Root>/Motor_4' */
  rtY.Motor_4 = 15000U;
}

/* Model terminate function */
void crazyflie_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
