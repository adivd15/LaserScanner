/**
 * @file SRV_MotorControl_main.h
 * @author Costea Adrian
 * @brief 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SRV_MOTORCONTROL_MAIN_H_
#define SRV_MOTORCONTROL_MAIN_H_
/*
    GLOBAL INCLUDE FILES
*/
#include <stdio.h>
#include <stdint.h>

#include <stm32f1xx.h>
#include <stm32f1xx_hal_gpio.h>

#include <SRV_MotorControl_api.h>
#include <SRV_MotorControl_def.h>
#include <SRV_MotorControl_swcpma.h>
#include <SRV_MotorControl_config.h>
/*
    DEFINES
*/

/*
    FUNCTIONS
*/
/**
 * @brief spins selected motor with numOfSteps and waits stepDelayuS between pulses
 *
 * @param selectMotor
 * @param numOfSteps
 * @param stepDelayuS
 * @param direction
 */
void motorControl_spinMotor(SRV_MotorControl_def_motor selectMotor, uint8_t numOfSteps, uint8_t stepDelayuS, uint8_t direction, uint8_t delay);
#endif