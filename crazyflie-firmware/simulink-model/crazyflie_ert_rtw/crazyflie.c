/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie.c
 *
 * Code generated for Simulink model 'crazyflie'.
 *
 * Model version                  : 1.295
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Nov 14 17:14:10 2017
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
   *  Inport: '<Root>/Range_sensor'
   */
  rtY.Log1 = rtU.Range_sensor;

  /* Outport: '<Root>/Log2' incorporates:
   *  Inport: '<Root>/Gyro_x'
   */
  rtY.Log2 = rtU.Gyro_x;

  /* Outport: '<Root>/Log4' incorporates:
   *  Inport: '<Root>/Node_x0'
   */
  rtY.Log4 = rtU.Node_x0;

  /* Outport: '<Root>/Log6' incorporates:
   *  Inport: '<Root>/Dist_0'
   */
  rtY.Log6 = rtU.Dist_0;
}

/* Model initialize function */
void crazyflie_initialize(void)
{
  /* ConstCode for Outport: '<Root>/Motor_1' */
  rtY.Motor_1 = 10000U;

  /* ConstCode for Outport: '<Root>/Log3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtY.Log3 = 5.0;
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
