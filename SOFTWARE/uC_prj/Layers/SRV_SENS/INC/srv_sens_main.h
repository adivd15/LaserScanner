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

#ifndef SRV_SENS_MAIN_H_
#define SRV_SENS_MAIN_H_
/*
    GLOBAL INCLUDE FILES
*/
#include <stdio.h>
#include <stdint.h>

#include <stm32f1xx.h>
#include <stm32f1xx_hal_gpio.h>

#include <srv_sens_def.h>
#include <srv_sens_api.h>
#include <srv_sens_swcpma.h>
#include <srv_sens_input.h>
#include <srv_sens_output.h>

/*
    DEFINES
*/

/*
    FUNCTIONS
*/
/**
 * @brief set adc handle
 *
 * @param hadc1
*/
void set_adc(ADC_HandleTypeDef *hadc1);
/**
 * @brief init function for srv_sens
*/
void srv_sens_init(void);
/**
 * @brief main function for srv_sens
 *
*/
void srv_sens_main(void);
#endif