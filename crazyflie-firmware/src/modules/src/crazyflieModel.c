/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflieModel.c
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

#include "rtwtypes.h"
#include <math.h>
#include "FreeRTOS.h"
#include "task.h"
#include "system.h"
#include "debug.h"
#include "log.h"
#include "param.h"
#include "sensors.h"
#include "commander.h"
#include "motors.h"
#include "crazyflie.h"
#include "crtp.h"
#include "crtp_localization_service.h"
#include "locodeck.h"
#include "i2cdev.h"
#include "zranger.h"
#include "vl53l0x.h"
#include "locodeck.h"

static void crazyflieModelTask(void* param);
static bool isInit;
static sensorData_t sensorData;
static setpoint_t setpoint;
static state_t state;
static float l1, l2, l3, l4, l5, l6;
static uint16_t m1, m2, m3, m4;

//LPS reading handling
static xQueueHandle distDataQueue;

#define DIST_QUEUE_LENGTH              (100)

void crazyflieModelEnqueueDistance(distanceMeasurement_t *dist)
{
  bool isInInterrupt = (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0;
  if (isInInterrupt) {
    portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;
    xQueueSendFromISR(distDataQueue, (void*)dist, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken == pdTRUE) {
      portYIELD();
    }
  } else {
    xQueueSend(distDataQueue, (void*)dist, 0);
  }
}

static inline bool hasDistanceMeasurement(distanceMeasurement_t *dist)
{
  return (pdTRUE == xQueueReceive(distDataQueue, dist, 0));
}

void acquireLPSData(distanceMeasurement_t *d)
{
  distanceMeasurement_t dist;
  while (hasDistanceMeasurement(&dist)) {
    d->x = dist.x;
    d->y = dist.y;
    d->z = dist.z;
    d->distance = dist.distance;

    //DEBUG_PRINT("Logging LPS data: %f\n", (double)dist.distance);
  }
}

// Controller/filter code
void crazyflieModelInit(void)
{
  if (isInit)
    return;
  crazyflie_initialize();
  sensorsInit();
  motorsInit(motorMapDefaultBrushed);
  distDataQueue = xQueueCreate(DIST_QUEUE_LENGTH, sizeof(distanceMeasurement_t));

#if defined(SITAW_ENABLED)

  sitAwInit();

#endif

  xTaskCreate(crazyflieModelTask, "crazyflieModel",
    /*Set Stack Size*/
              5*configMINIMAL_STACK_SIZE, NULL, /*Set Prio*/
              4, NULL);
  isInit = true;
}

bool crazyflieModelTest(void)
{
  bool pass = true;
  pass &= sensorsTest();
  pass &= motorsTest();
  pass &= deckTest();
  return pass;
}

static void crazyflieModelTask(void* param)
{
  uint32_t tick = 0;
  uint32_t lastWakeTime;

  //Wait for the system to be fully started to start stabilization loop
  systemWaitStart();

  // Wait for sensors to be calibrated
  lastWakeTime = xTaskGetTickCount ();
  while (!sensorsAreCalibrated()) {
    vTaskDelayUntil(&lastWakeTime, M2T(10.0));
  }

  while (1) {
    vTaskDelayUntil(&lastWakeTime, M2T(10.0));
    sensorsAcquire(&sensorData, tick);
    commanderGetSetpoint(&setpoint, &state);
    distanceMeasurement_t dist;
    acquireLPSData(&dist);
    rtU.Acc_x = sensorData.acc.x;
    rtU.Acc_y = sensorData.acc.y;
    rtU.Acc_z = sensorData.acc.z;
    rtU.Gyro_x = sensorData.gyro.x;
    rtU.Gyro_y = sensorData.gyro.y;
    rtU.Gyro_z = sensorData.gyro.z;

    //rtU.LPS_x = sensorData.position.x;
    //rtU.LPS_y = sensorData.position.y;
    //rtU.LPS_z = sensorData.position.z;
    rtU.Node_x0 = dist.x;
    rtU.Node_y0 = dist.y;
    rtU.Node_z0 = dist.z;
    rtU.Dist_0 = dist.distance;
    rtU.Range_sensor = sensorData.zrange.distance;
    rtU.Base_Thrust = setpoint.thrust;
    rtU.Ref_Roll = setpoint.attitude.roll;
    rtU.Ref_Pitch = setpoint.attitude.pitch;
    rtU.Ref_YawRate = setpoint.attitudeRate.yaw;

    //DEBUG_PRINT("Acc Y: %f\n", sensorData.acc.y);
    crazyflie_step();

    /* Get model outputs here */
    l1 = rtY.Log1;
    l2 = rtY.Log2;
    l3 = rtY.Log3;
    l4 = rtY.Log4;
    l5 = rtY.Log5;
    l6 = rtY.Log6;
    m1 = (uint16_t)rtY.Motor_1;
    m2 = (uint16_t)rtY.Motor_2;
    m3 = (uint16_t)rtY.Motor_3;
    m4 = (uint16_t)rtY.Motor_4;
    motorsSetRatio(MOTOR_M1, m1);
    motorsSetRatio(MOTOR_M2, m2);
    motorsSetRatio(MOTOR_M3, m3);
    motorsSetRatio(MOTOR_M4, m4);
    tick++;
  }
}

LOG_GROUP_START(acc)
  LOG_ADD(LOG_FLOAT, x, &sensorData.acc.x)
  LOG_ADD(LOG_FLOAT, y, &sensorData.acc.y)
  LOG_ADD(LOG_FLOAT, z, &sensorData.acc.z)
  LOG_GROUP_STOP(acc)
  LOG_GROUP_START(baro)
  LOG_ADD(LOG_FLOAT, asl, &sensorData.baro.asl)
  LOG_ADD(LOG_FLOAT, temp, &sensorData.baro.temperature)
  LOG_ADD(LOG_FLOAT, pressure, &sensorData.baro.pressure)
  LOG_GROUP_STOP(baro)
  LOG_GROUP_START(gyro)
  LOG_ADD(LOG_FLOAT, x, &sensorData.gyro.x)
  LOG_ADD(LOG_FLOAT, y, &sensorData.gyro.y)
  LOG_ADD(LOG_FLOAT, z, &sensorData.gyro.z)
  LOG_GROUP_STOP(gyro)
  LOG_GROUP_START(mag)
  LOG_ADD(LOG_FLOAT, x, &sensorData.mag.x)
  LOG_ADD(LOG_FLOAT, y, &sensorData.mag.y)
  LOG_ADD(LOG_FLOAT, z, &sensorData.mag.z)
  LOG_GROUP_STOP(mag)
  LOG_GROUP_START(motor)
  LOG_ADD(LOG_UINT16, m1, &m1)
  LOG_ADD(LOG_UINT16, m2, &m2)
  LOG_ADD(LOG_UINT16, m3, &m3)
  LOG_ADD(LOG_UINT16, m4, &m4)
  LOG_GROUP_STOP(motor)
  LOG_GROUP_START(range)
  LOG_ADD(LOG_FLOAT, z, &sensorData.zrange.distance)
  LOG_GROUP_STOP(range)
  LOG_GROUP_START(simulink)
  LOG_ADD(LOG_FLOAT, log_1, &l1)
  LOG_ADD(LOG_FLOAT, log_2, &l2)
  LOG_ADD(LOG_FLOAT, log_3, &l3)
  LOG_ADD(LOG_FLOAT, log_4, &l4)
  LOG_ADD(LOG_FLOAT, log_5, &l5)
  LOG_ADD(LOG_FLOAT, log_6, &l6)
  LOG_GROUP_STOP(simulink)
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
