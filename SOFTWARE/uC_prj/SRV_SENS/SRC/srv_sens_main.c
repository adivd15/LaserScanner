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
 * @brief Get the sensor data object
 * 
 * @return sensor_data_t 
 */
sensor_data_t get_sensor_data(void){
    return data_meadian;
}
/**
 * @brief main function for srv_sens
 *
*/
void srv_sens_main(void)
{
    uint16_t raw;
    float sensor_data_sum;
    for(int i = 0; i < 20; i++)
    {
        //read sensor data
        HAL_ADC_Start(&hadc);
        HAL_ADC_PollForConversion(&hadc, 100);
        raw = HAL_ADC_GetValue(&hadc);
        HAL_ADC_Stop(&hadc);
        sensor_readings[i].raw_sensor_voltage =(float)raw*(3.3/4096);
        //convert raw_sensor_voltage to sensor_data
        /*
            using curve expert we know that: raw_sensor_voltage = 7.747/(1+sensor_data/4.271)
            so we can calculate sensor_data using the following formula: sensor_data = 33.087/raw_sensor_voltage-7.747
        */
        sensor_readings[i].sensor_data = 33.087/sensor_readings[i].raw_sensor_voltage-7.747;
        //get medium value from sensor_data
        sensor_data_sum += sensor_readings[i].sensor_data;
        //wait 5ms
        HAL_Delay(5);
    }
    //calculate medium value
    data_meadian.sensor_data = sensor_data_sum/20;
    data_meadian.sensor_decimal = (int)(data_meadian.sensor_data);
    data_meadian.sensor_unit = (int)((data_meadian.sensor_data - data_meadian.sensor_decimal)*1000);
}
