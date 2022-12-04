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

    if(connectedMotors != NULL){
        //initialize all connected motors
        connectedMotors[0].motor_dirPin = Motor1_dirPin;
        connectedMotors[0].motor_dirPort = Motor1_dirPort;

        connectedMotors[0].motor_stepPin = Motor1_stepPin;
        connectedMotors[0].motor_stepPort = Motor1_stepPort;

        connectedMotors[1].motor_dirPin = Motor2_dirPin;
        connectedMotors[1].motor_dirPort = Motor2_dirPort;

        connectedMotors[1].motor_stepPin = Motor2_stepPin;
        connectedMotors[1].motor_stepPort = Motor2_stepPort;
        
        //return init successfull
        return 1;
    }

    return 0;
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