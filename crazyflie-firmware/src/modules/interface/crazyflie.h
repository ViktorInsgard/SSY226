/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie.h
 *
 * Code generated for Simulink model 'crazyflie'.
 *
 * Model version                  : 1.512
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Dec  5 14:45:55 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_crazyflie_h_
#define RTW_HEADER_crazyflie_h_
#include <math.h>
#include <string.h>
#ifndef crazyflie_COMMON_INCLUDES_
# define crazyflie_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* crazyflie_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay2_DSTATE[12];        /* '<Root>/Unit Delay2' */
  real_T UnitDelay3_DSTATE[144];       /* '<Root>/Unit Delay3' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: eye(12)
   * Referenced by: '<Root>/Unit Delay3'
   */
  real_T UnitDelay3_InitialCondition[144];

  /* Expression: Q
   * Referenced by: '<Root>/Q'
   */
  real_T Q_Value[144];

  /* Expression: R_LPS
   * Referenced by: '<Root>/R_LPS'
   */
  real_T R_LPS_Value[36];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Base_Thrust;                  /* '<Root>/Base_Thrust' */
  real_T Ref_Roll;                     /* '<Root>/Ref_Roll' */
  real_T Ref_Pitch;                    /* '<Root>/Ref_Pitch' */
  real_T Ref_YawRate;                  /* '<Root>/Ref_YawRate' */
  real_T Acc_x;                        /* '<Root>/Acc_x' */
  real_T Acc_y;                        /* '<Root>/Acc_y' */
  real_T Acc_z;                        /* '<Root>/Acc_z' */
  real_T Gyro_x;                       /* '<Root>/Gyro_x' */
  real_T Gyro_y;                       /* '<Root>/Gyro_y' */
  real_T Gyro_z;                       /* '<Root>/Gyro_z' */
  real_T Dist_0;                       /* '<Root>/Dist_0' */
  real_T Dist_1;                       /* '<Root>/Dist_1' */
  real_T Dist_2;                       /* '<Root>/Dist_2' */
  real_T Dist_3;                       /* '<Root>/Dist_3' */
  real_T Dist_4;                       /* '<Root>/Dist_4' */
  real_T Dist_5;                       /* '<Root>/Dist_5' */
  real_T Range_sensor;                 /* '<Root>/Range_sensor' */
  real_T Mag_x;                        /* '<Root>/Mag_x' */
  real_T Mag_y;                        /* '<Root>/Mag_y' */
  real_T Mag_z;                        /* '<Root>/Mag_z' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint16_T Motor_1;                    /* '<Root>/Motor_1' */
  uint16_T Motor_2;                    /* '<Root>/Motor_2' */
  uint16_T Motor_3;                    /* '<Root>/Motor_3' */
  uint16_T Motor_4;                    /* '<Root>/Motor_4' */
  real_T Log1;                         /* '<Root>/Log1' */
  real_T Log2;                         /* '<Root>/Log2' */
  real_T Log3;                         /* '<Root>/Log3' */
  real_T Log4;                         /* '<Root>/Log4' */
  real_T Log5;                         /* '<Root>/Log5' */
  real_T Log6;                         /* '<Root>/Log6' */
} ExtY;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void crazyflie_initialize(void);
extern void crazyflie_step(void);
extern void crazyflie_terminate(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ToDouble' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble1' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble2' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble3' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble4' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble5' : Eliminate redundant data type conversion
 * Block '<Root>/ToUint16' : Eliminate redundant data type conversion
 * Block '<Root>/ToUint16_2' : Eliminate redundant data type conversion
 * Block '<Root>/ToUint16_3' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'crazyflie'
 * '<S1>'   : 'crazyflie/  &#x3C9;rad '
 * '<S2>'   : 'crazyflie/MATLAB Function3'
 * '<S3>'   : 'crazyflie/  &#x3C9;rad /OmegadotX'
 * '<S4>'   : 'crazyflie/  &#x3C9;rad /OmegadotY'
 * '<S5>'   : 'crazyflie/  &#x3C9;rad /OmegadotZ'
 * '<S6>'   : 'crazyflie/  &#x3C9;rad /OmegadotX/Degrees to Radians'
 * '<S7>'   : 'crazyflie/  &#x3C9;rad /OmegadotY/Degrees to Radians'
 * '<S8>'   : 'crazyflie/  &#x3C9;rad /OmegadotZ/Degrees to Radians'
 */
#endif                                 /* RTW_HEADER_crazyflie_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
