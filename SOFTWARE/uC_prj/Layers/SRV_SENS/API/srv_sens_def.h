#ifndef SRV_SENS_DEF_H_
#define SRV_SENS_DEF_H_

/*
    GLOBAL INCLUDE FILES
*/

#include <stdio.h>
#include <stdint.h>

#include <stm32f1xx.h>
#include <stm32f1xx_hal_gpio.h>

/*
    DEFINES
*/

/*
    TYPEDEF'S
*/
/**
 * @brief Sensor data structure
*/
typedef struct sensor_data_t
{
    uint8_t     sensor_id;
    uint8_t     sensor_number;
    float     raw_sensor_voltage;
    uint8_t     sensor_decimal;
    uint8_t     sensor_unit;
    float       sensor_data;
} sensor_data_t;

#endif