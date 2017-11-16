/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie.c
 *
 * Code generated for Simulink model 'crazyflie'.
 *
 * Model version                  : 1.317
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Nov 16 13:40:51 2017
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
   *  Inport: '<Root>/Dist_0'
   */
  rtY.Log1 = rtU.Dist_0;

  /* Outport: '<Root>/Log2' incorporates:
   *  Inport: '<Root>/Dist_1'
   */
  rtY.Log2 = rtU.Dist_1;

  /* Outport: '<Root>/Log3' incorporates:
   *  Inport: '<Root>/Dist_2'
   */
  rtY.Log3 = rtU.Dist_2;

  /* Outport: '<Root>/Log4' incorporates:
   *  Inport: '<Root>/Dist_3'
   */
  rtY.Log4 = rtU.Dist_3;

  /* Outport: '<Root>/Log5' incorporates:
   *  Inport: '<Root>/Dist_4'
   */
  rtY.Log5 = rtU.Dist_4;

  /* Outport: '<Root>/Log6' incorporates:
   *  Inport: '<Root>/Dist_5'
   */
  rtY.Log6 = rtU.Dist_5;
}

/* Model initialize function */
void crazyflie_initialize(void)
{
  /* (no initialization code required) */
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
