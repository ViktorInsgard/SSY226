/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie.c
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

#include "crazyflie.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Forward declaration for local functions */
static void mrdivide(real_T A[18], const real_T B_0[36]);

/* Function for MATLAB Function: '<Root>/MATLAB Function3' */
static void mrdivide(real_T A[18], const real_T B_0[36])
{
  real_T b_A[36];
  int8_T ipiv[6];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&b_A[0], &B_0[0], 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    ipiv[j] = (int8_T)(1 + j);
  }

  for (j = 0; j < 5; j++) {
    jBcol = j * 7;
    iy = 0;
    ix = jBcol;
    smax = fabs(b_A[jBcol]);
    for (kBcol = 2; kBcol <= 6 - j; kBcol++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        iy = kBcol - 1;
        smax = s;
      }
    }

    if (b_A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (kBcol = 0; kBcol < 6; kBcol++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jBcol - j) + 6;
      for (ix = jBcol + 1; ix + 1 <= iy; ix++) {
        b_A[ix] /= b_A[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 6;
    for (kBcol = 1; kBcol <= 5 - j; kBcol++) {
      smax = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - j) + 12;
        for (ijA = 7 + iy; ijA + 1 <= d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jBcol = 3 * j;
    iy = 6 * j;
    for (ix = 1; ix <= j; ix++) {
      kBcol = (ix - 1) * 3;
      if (b_A[(ix + iy) - 1] != 0.0) {
        A[jBcol] -= b_A[(ix + iy) - 1] * A[kBcol];
        A[1 + jBcol] -= b_A[(ix + iy) - 1] * A[1 + kBcol];
        A[2 + jBcol] -= b_A[(ix + iy) - 1] * A[2 + kBcol];
      }
    }

    smax = 1.0 / b_A[j + iy];
    A[jBcol] *= smax;
    A[1 + jBcol] *= smax;
    A[2 + jBcol] *= smax;
  }

  for (j = 5; j >= 0; j--) {
    jBcol = 3 * j;
    iy = 6 * j - 1;
    for (ix = j + 2; ix < 7; ix++) {
      kBcol = (ix - 1) * 3;
      if (b_A[ix + iy] != 0.0) {
        A[jBcol] -= b_A[ix + iy] * A[kBcol];
        A[1 + jBcol] -= b_A[ix + iy] * A[1 + kBcol];
        A[2 + jBcol] -= b_A[ix + iy] * A[2 + kBcol];
      }
    }
  }

  for (j = 4; j >= 0; j--) {
    if (j + 1 != ipiv[j]) {
      jBcol = ipiv[j] - 1;
      smax = A[3 * j];
      A[3 * j] = A[3 * jBcol];
      A[3 * jBcol] = smax;
      smax = A[3 * j + 1];
      A[1 + 3 * j] = A[3 * jBcol + 1];
      A[1 + 3 * jBcol] = smax;
      smax = A[3 * j + 2];
      A[2 + 3 * j] = A[3 * jBcol + 2];
      A[2 + 3 * jBcol] = smax;
    }
  }
}

/* Model step function */
void crazyflie_step(void)
{
  real_T x[12];
  real_T P_0[144];
  real_T F[36];
  real_T R1;
  real_T R2;
  real_T R3;
  real_T R4;
  real_T R5;
  real_T R6;
  real_T Hx[18];
  real_T Kk[18];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T c[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
    0, 1 };

  real_T rtb_x[12];
  real_T rtb_P[144];
  int32_T i;
  real_T F_0[36];
  int32_T i_0;
  real_T Hx_0[18];
  real_T tmp[12];
  real_T R1_0[6];
  real_T tmp_0[6];
  int32_T F_tmp;
  real_T R1_tmp;
  int32_T Hx_tmp;

  /* UnitDelay: '<Root>/Unit Delay2' */
  memcpy(&rtb_x[0], &rtDW.UnitDelay2_DSTATE[0], 12U * sizeof(real_T));

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  Constant: '<Root>/Q'
   *  Constant: '<Root>/R_LPS'
   *  UnitDelay: '<Root>/Unit Delay3'
   */
  /* NONLINEARKALMANFILTER Filters measurement sequence Y using a  */
  /*  non-linear Kalman filter.  */
  /*  TODO Implement Zranger */
  /* Input: */
  /*    Y                       [m x 1] Measurement sequence for times 1,...,N */
  /*    statePrior        [n x 1] Prior mean for time 0 */
  /*    priorCovariance    [n x n] Prior covariance */
  /*    motionModel                     Motion model function handle */
  /*  */
  /* Output: */
  /*    xf          [n x 1]     Filtered estimates for times 1,...,N */
  /*    Pf          [n x n ] Filter error convariance */
  /* MATLAB Function 'MATLAB Function3': '<S2>:1' */
  /* [x, P]=predictionGyro(x, measurements, P, T,Q); %Prediction With Gyro- */
  /* '<S2>:1:19' [x, P]=predictionLPS(x, P, T,Q,u_thrust); */
  /*  The prediction for x y z  */
  /* Input: */
  /*    x            [12 x 1] Prior mean */
  /*    u_thrust     Total amount of thrust */
  /*    P            [12 x 12] Prior covariance */
  /*    T            Sampling time */
  /*    Q            [12 x 12] Process noise */
  /* Output: */
  /*    x p          [12 x 1] predicted state mean */
  /*    Pp           [12 x 12] predicted state covariance */
  /*  */
  memcpy(&P_0[0], &rtDW.UnitDelay3_DSTATE[0], 144U * sizeof(real_T));
  memcpy(&x[0], &rtb_x[0], 12U * sizeof(real_T));

  /* 'predictionLPS:14' F=[eye(3) T*eye(3); zeros(3) eye(3)]; */
  for (i = 0; i < 3; i++) {
    F[6 * i] = b[3 * i];
    F_tmp = 6 * (i + 3);
    F[F_tmp] = b[3 * i];
    F[1 + 6 * i] = b[3 * i + 1];
    F[1 + F_tmp] = b[3 * i + 1];
    F[2 + 6 * i] = b[3 * i + 2];
    F[2 + F_tmp] = b[3 * i + 2];
  }

  for (i = 0; i < 6; i++) {
    F[3 + 6 * i] = c[3 * i];
    F[4 + 6 * i] = c[3 * i + 1];
    F[5 + 6 * i] = c[3 * i + 2];
  }

  /*  Constant velocity */
  /* 'predictionLPS:16' x(7) = x(7) + T*x(10); */
  x[6] = rtb_x[6] + rtb_x[9];

  /* 'predictionLPS:17' x(8) = x(8) + T*x(11); */
  x[7] = rtb_x[7] + rtb_x[10];

  /* 'predictionLPS:18' x(9) = x(9) + T*x(12); */
  x[8] = rtb_x[8] + rtb_x[11];

  /* 'predictionLPS:20' x(10) = x(10); */
  /*  - sin(x(2))*T*u_thrust; */
  /* 'predictionLPS:21' x(11) = x(11); */
  /*  + cos(x(2))*sin(x(1))*T*u_thrust; */
  /* 'predictionLPS:22' x(12) = x(12); */
  /*  + cos(x(2))*cos(x(1))*T*u_thrust - 9.82*T; */
  /* 'predictionLPS:24' P(7:12,7:12)=F*P(7:12,7:12)*F.'+Q(7:12,7:12); */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      F_tmp = i + 6 * i_0;
      F_0[F_tmp] = 0.0;
      for (Hx_tmp = 0; Hx_tmp < 6; Hx_tmp++) {
        F_0[F_tmp] = rtDW.UnitDelay3_DSTATE[((6 + i_0) * 12 + Hx_tmp) + 6] * F[6
          * Hx_tmp + i] + F_0[6 * i_0 + i];
      }
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      R1_tmp = 0.0;
      for (Hx_tmp = 0; Hx_tmp < 6; Hx_tmp++) {
        R1_tmp += F_0[6 * Hx_tmp + i] * F[6 * Hx_tmp + i_0];
      }

      P_0[(i + 12 * (6 + i_0)) + 6] = rtConstP.Q_Value[((6 + i_0) * 12 + i) + 6]
        + R1_tmp;
    }
  }

  /* Prediction With LPS */
  /* [x, P]=updateAcc(x, measurements, P, T,R_acc);                                                 % Update With accelerometer */
  /* '<S2>:1:21' [x, P]=updateLPS(x, measurements, sensor_position, P, T,R_LPS); */
  memcpy(&rtb_x[0], &x[0], 12U * sizeof(real_T));
  memcpy(&rtb_P[0], &P_0[0], 144U * sizeof(real_T));

  /*  The update for x y z  */
  /* Input: */
  /*    x            [12 x 1]     Prior mean */
  /*    P            [12 x 12]  Prior covariance */
  /*    y            [12 x ]      LPS  measurements */
  /*   s              [6 x 3]    Sensor positions */
  /*   T                             Sampling time */
  /*   R            [6 x 6]      Measurement noise */
  /* Output: */
  /*    x f          [12 x 1] Updated state mean */
  /*    Pf           [12 x 12] Updated state covariance */
  /*  */
  /* 'updateLPS:16' R1 = sqrt((x(7)-s(1,1))^2+(x(8)-s(1,2))^2+(x(9)-s(1,3))^2); */
  R1_tmp = x[7] * x[7];
  R1 = sqrt(((x[6] - 2.9) * (x[6] - 2.9) + R1_tmp) + (x[8] - 0.57) * (x[8] -
             0.57));

  /* 'updateLPS:17' R2 = sqrt((x(7)-s(2,1))^2+(x(8)-s(2,2))^2+(x(9)-s(2,3))^2); */
  R2 = sqrt(((x[6] - 4.84) * (x[6] - 4.84) + (x[7] - 2.56) * (x[7] - 2.56)) +
            (x[8] - 1.04) * (x[8] - 1.04));

  /* 'updateLPS:18' R3 = sqrt((x(7)-s(3,1))^2+(x(8)-s(3,2))^2+(x(9)-s(3,3))^2); */
  R3 = sqrt(((x[6] - 1.18) * (x[6] - 1.18) + (x[7] - 4.72) * (x[7] - 4.72)) +
            (x[8] - 0.84) * (x[8] - 0.84));

  /* 'updateLPS:19' R4 = sqrt((x(7)-s(4,1))^2+(x(8)-s(4,2))^2+(x(9)-s(4,3))^2); */
  R4 = sqrt(((x[6] - 3.64) * (x[6] - 3.64) + (x[7] - 2.73) * (x[7] - 2.73)) + x
            [8] * x[8]);

  /* 'updateLPS:20' R5 = sqrt((x(7)-s(5,1))^2+(x(8)-s(5,2))^2+(x(9)-s(5,3))^2); */
  R5 = sqrt((x[6] * x[6] + R1_tmp) + (x[8] - 1.14) * (x[8] - 1.14));

  /* 'updateLPS:21' R6 = sqrt((x(7)-s(6,1))^2+(x(8)-s(6,2))^2+(x(9)-s(6,3))^2); */
  R6 = sqrt(((x[6] - 2.84) * (x[6] - 2.84) + R1_tmp) + (x[8] - 0.19) * (x[8] -
             0.19));

  /* 'updateLPS:23' hx=[R1;R2;R3;R4;R5;R6]; */
  /* 'updateLPS:25' Hx=[(x(7)-s(1,1))/R1 (x(8)-s(1,2))/R1 (x(9)-s(1,3))/R1 ; */
  /* 'updateLPS:26'     (x(7)-s(2,1))/R2 (x(8)-s(2,2))/R2 (x(9)-s(2,3))/R2 ; */
  /* 'updateLPS:27'     (x(7)-s(3,1))/R3 (x(8)-s(3,2))/R3 (x(9)-s(3,3))/R3 ; */
  /* 'updateLPS:28'     (x(7)-s(4,1))/R4 (x(8)-s(4,2))/R4 (x(9)-s(4,3))/R4 ; */
  /* 'updateLPS:29'     (x(7)-s(5,1))/R5 (x(8)-s(5,2))/R5 (x(9)-s(5,3))/R5 ; */
  /* 'updateLPS:30'     (x(7)-s(6,1))/R6 (x(8)-s(6,2))/R6 (x(9)-s(6,3))/R6 ]; */
  Hx[0] = (x[6] - 2.9) / R1;
  Hx[6] = x[7] / R1;
  Hx[12] = (x[8] - 0.57) / R1;
  Hx[1] = (x[6] - 4.84) / R2;
  Hx[7] = (x[7] - 2.56) / R2;
  Hx[13] = (x[8] - 1.04) / R2;
  Hx[2] = (x[6] - 1.18) / R3;
  Hx[8] = (x[7] - 4.72) / R3;
  Hx[14] = (x[8] - 0.84) / R3;
  Hx[3] = (x[6] - 3.64) / R4;
  Hx[9] = (x[7] - 2.73) / R4;
  Hx[15] = x[8] / R4;
  Hx[4] = x[6] / R5;
  Hx[10] = x[7] / R5;
  Hx[16] = (x[8] - 1.14) / R5;
  Hx[5] = (x[6] - 2.84) / R6;
  Hx[11] = x[7] / R6;
  Hx[17] = (x[8] - 0.19) / R6;

  /* 'updateLPS:32' Sk = Hx*P(7:9,7:9)*Hx.' + R_LPS; */
  for (i = 0; i < 6; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      Hx_tmp = i + 6 * i_0;
      Hx_0[Hx_tmp] = 0.0;
      F_tmp = (6 + i_0) * 12;
      Hx_0[Hx_tmp] = P_0[F_tmp + 6] * Hx[i] + Hx_0[6 * i_0 + i];
      Hx_0[Hx_tmp] = P_0[F_tmp + 7] * Hx[i + 6] + Hx_0[6 * i_0 + i];
      Hx_0[Hx_tmp] = P_0[F_tmp + 8] * Hx[i + 12] + Hx_0[6 * i_0 + i];
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      F[i + 6 * i_0] = ((Hx_0[i + 6] * Hx[i_0 + 6] + Hx_0[i] * Hx[i_0]) + Hx_0[i
                        + 12] * Hx[i_0 + 12]) + rtConstP.R_LPS_Value[6 * i_0 + i];
    }
  }

  /*  Innovation covariance */
  /* 'updateLPS:33' Kk = P(7:9,7:9)*Hx.'/Sk; */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      F_tmp = i + 3 * i_0;
      Kk[F_tmp] = 0.0;
      Kk[F_tmp] = Kk[3 * i_0 + i] + P_0[i + 78] * Hx[i_0];
      Kk[F_tmp] = Kk[3 * i_0 + i] + P_0[i + 90] * Hx[i_0 + 6];
      Kk[F_tmp] = Kk[3 * i_0 + i] + P_0[i + 102] * Hx[i_0 + 12];
    }
  }

  mrdivide(Kk, F);

  /*  The Kalman gain */
  /* 'updateLPS:34' vk = (y(7:12)-hx); */
  /*  The innovation */
  /* 'updateLPS:35' Ptemp = P(7:9,7:9)-Kk*Sk*Kk.'; */
  /*  Updated estimate covariance */
  /* 'updateLPS:36' xtemp = x(7:9)+Kk*vk; */
  /*  Updated state estimate */
  /* 'updateLPS:38' P(7:9,7:9)=Ptemp; */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      F_tmp = i + 3 * i_0;
      Hx[F_tmp] = 0.0;
      for (Hx_tmp = 0; Hx_tmp < 6; Hx_tmp++) {
        Hx[F_tmp] = Kk[3 * Hx_tmp + i] * F[6 * i_0 + Hx_tmp] + Hx[3 * i_0 + i];
      }
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      R1_tmp = 0.0;
      for (Hx_tmp = 0; Hx_tmp < 6; Hx_tmp++) {
        R1_tmp += Hx[3 * Hx_tmp + i] * Kk[3 * Hx_tmp + i_0];
      }

      rtb_P[(i + 12 * (6 + i_0)) + 6] = P_0[((6 + i_0) * 12 + i) + 6] - R1_tmp;
    }
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S8>/Gain1'
   *  Inport: '<Root>/Acc_x'
   *  Inport: '<Root>/Acc_y'
   *  Inport: '<Root>/Acc_z'
   *  Inport: '<Root>/Dist_0'
   *  Inport: '<Root>/Dist_1'
   *  Inport: '<Root>/Dist_2'
   *  Inport: '<Root>/Dist_3'
   *  Inport: '<Root>/Dist_4'
   *  Inport: '<Root>/Dist_5'
   *  Inport: '<Root>/Gyro_x'
   *  Inport: '<Root>/Gyro_y'
   *  Inport: '<Root>/Gyro_z'
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  /* 'updateLPS:39' Pf=P; */
  /* 'updateLPS:40' x(7:9)=xtemp; */
  tmp[0] = 0.017453292519943295 * rtU.Gyro_x;
  tmp[1] = 0.017453292519943295 * rtU.Gyro_y;
  tmp[2] = 0.017453292519943295 * rtU.Gyro_z;
  tmp[3] = rtU.Acc_x;
  tmp[4] = rtU.Acc_y;
  tmp[5] = rtU.Acc_z;
  tmp[6] = rtU.Dist_0;
  tmp[7] = rtU.Dist_1;
  tmp[8] = rtU.Dist_2;
  tmp[9] = rtU.Dist_3;
  tmp[10] = rtU.Dist_4;
  tmp[11] = rtU.Dist_5;

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  R1_0[0] = R1;
  R1_0[1] = R2;
  R1_0[2] = R3;
  R1_0[3] = R4;
  R1_0[4] = R5;
  R1_0[5] = R6;
  for (i = 0; i < 6; i++) {
    tmp_0[i] = tmp[6 + i] - R1_0[i];
  }

  for (i = 0; i < 3; i++) {
    R1_tmp = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      R1_tmp += Kk[3 * i_0 + i] * tmp_0[i_0];
    }

    rtb_x[6 + i] = x[6 + i] + R1_tmp;
  }

  /* Outport: '<Root>/Log1' */
  /* 'updateLPS:41' xf=x; */
  /*  Update With LPS */
  rtY.Log1 = rtb_x[0];

  /* Outport: '<Root>/Log2' */
  rtY.Log2 = rtb_x[1];

  /* Outport: '<Root>/Log3' */
  rtY.Log3 = rtb_x[2];

  /* Outport: '<Root>/Log4' */
  rtY.Log4 = rtb_x[6];

  /* Outport: '<Root>/Log5' */
  rtY.Log5 = rtb_x[7];

  /* Outport: '<Root>/Log6' */
  rtY.Log6 = rtb_x[8];

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  memcpy(&rtDW.UnitDelay2_DSTATE[0], &rtb_x[0], 12U * sizeof(real_T));

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  memcpy(&rtDW.UnitDelay3_DSTATE[0], &rtb_P[0], 144U * sizeof(real_T));
}

/* Model initialize function */
void crazyflie_initialize(void)
{
  /* ConstCode for Outport: '<Root>/Motor_2' */
  rtY.Motor_2 = 5U;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
  memcpy(&rtDW.UnitDelay3_DSTATE[0], &rtConstP.UnitDelay3_InitialCondition[0],
         144U * sizeof(real_T));
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
