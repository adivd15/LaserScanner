/**
 * @file srv_sens_main.c
 * @author Costea Adrian
 * @brief main file for motor control
 * @version 0.1
 * @date 2022-11-03
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
    GLOBAL INCLUDE FILES
*/

#include <srv_sens_main.h>

/*
    DEFINES
*/

/*
    VARIABLES
*/
ADC_HandleTypeDef hadc;
sensor_data_t sensor_readings[20];
sensor_data_t data_meadian;
/*
    FUNCTIONS
*/
/**
 * @brief set adc handle
 *
 * @param hadc1
*/
void set_adc(ADC_HandleTypeDef *hadc1)
{
    hadc = *hadc1;
}
/**
 * @brief init function for srv_sens
*/
void srv_sens_init(void)
{
    //init sensor readings
    for(int i=0;i<20;i++){
        sensor_readings[i].sensor_id = 1;
        sensor_readings[i].sensor_number = 1;
        sensor_readings[i].raw_sensor_voltage = 0;
        sensor_readings[i].sensor_decimal = 0;
        sensor_readings[i].sensor_unit = 0;
        sensor_readings[i].sensor_data = 0;
    }

}
/**
 * @brief main function for srv_sens
 *
*/
void srv_sens_main(void)
{
    float sensor_data_sum;
    for(int i = 0; i < 20; i++)
    {
        //read sensor data
        HAL_ADC_Start(&hadc);
        HAL_ADC_PollForConversion(&hadc, 100);
        sensor_readings[0].raw_sensor_voltage = HAL_ADC_GetValue(&hadc);
        HAL_ADC_Stop(&hadc);
        sensor_readings[0].raw_sensor_voltage = sensor_readings[0].raw_sensor_voltage*(3.3/4096);
        //convert raw_sensor_voltage to sensor_data

        //get medium value from sensor_data
        sensor_data_sum += sensor_readings[i].sensor_data;
        //wait 5ms
        HAL_Delay(5);
    }
    //calculate medium value
    data_meadian.sensor_data = sensor_data_sum/20;
}
