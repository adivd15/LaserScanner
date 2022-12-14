#ifndef SRV_SENS_API_H_
#define SRV_SENS_API_H_
/*
    GLOBAL INCLUDE FILES
*/
#include <stdio.h>
#include <stdint.h>

#include <stm32f1xx.h>
#include <stm32f1xx_hal_gpio.h>

#include <srv_sens_def.h>
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
 * @brief Get the sensor data object
 * 
 * @return sensor_data_t 
 */
sensor_data_t get_sensor_data(void);
#endif