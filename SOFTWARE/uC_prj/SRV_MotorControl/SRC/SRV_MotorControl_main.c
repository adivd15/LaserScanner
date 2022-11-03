/**
 * @file SRV_MotorControl_main.c
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

#include <SRV_MotorControl_main.h>

/*
    DEFINES
*/

/*
    VARIABLES
*/
SRV_MotorControl_def_motor connectedMotors[2];
/*
    FUNCTIONS
*/

/**
 * @brief Initialization function for srv_motorControl
 * 
 * @return 1 if initialization succesfull
 * @return 0 if initialization not succesfull
 */
 uint8_t motorControl_init(){
    uint8_t initSuccess;
    initSuccess = 0;

    //initialize all connected motors
    connectedMotors[0].motor_dirPin = Motor1_dirPin;
    connectedMotors[0].motor_dirPort = Motor1_dirPort;

    connectedMotors[0].motor_stepPin = Motor1_stepPin;
    connectedMotors[0].motor_stepPort = Motor1_stepPort;

    HAL_GPIO_WritePin(connectedMotors[0].motor_dirPort,connectedMotors[0].motor_dirPin,GPIO_PIN_SET);

    return initSuccess;
}

/**
 * @brief Main function for motor controll
 * 
 */
void motorControl_main(){
    HAL_GPIO_WritePin(connectedMotors[0].motor_stepPort,connectedMotors[0].motor_stepPin,GPIO_PIN_SET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(connectedMotors[0].motor_stepPort,connectedMotors[0].motor_stepPin,GPIO_PIN_RESET);
}