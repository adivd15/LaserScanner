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
uint8_t motorControl_init()
{

    if (connectedMotors != NULL)
    {
        // initialize all connected motors
        connectedMotors[0].motor_dirPin = Motor1_dirPin;
        connectedMotors[0].motor_dirPort = Motor1_dirPort;

        connectedMotors[0].motor_stepPin = Motor1_stepPin;
        connectedMotors[0].motor_stepPort = Motor1_stepPort;

        connectedMotors[1].motor_dirPin = Motor2_dirPin;
        connectedMotors[1].motor_dirPort = Motor2_dirPort;

        connectedMotors[1].motor_stepPin = Motor2_stepPin;
        connectedMotors[1].motor_stepPort = Motor2_stepPort;

        // return init successfull
        return 1;
    }

    return 0;
}

/**
 * @brief spins selected motor with numOfSteps and waits stepDelayuS between pulses
 *
 * @param selectMotor
 * @param numOfSteps
 * @param stepDelayuS
 * @param direction
 */
void motorControl_spinMotor(SRV_MotorControl_def_motor selectMotor, uint8_t numOfSteps, uint8_t stepDelayuS, uint8_t direction, uint8_t delay)
{
    if (direction == 1)
    {
        HAL_GPIO_WritePin(selectMotor.motor_dirPort, selectMotor.motor_dirPin, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(selectMotor.motor_dirPort, selectMotor.motor_dirPin, GPIO_PIN_RESET);
    }
    for (int i = 0; i < numOfSteps; i++)
    {
        HAL_GPIO_WritePin(selectMotor.motor_stepPort, selectMotor.motor_stepPin, GPIO_PIN_SET);
        HAL_Delay(stepDelayuS);
        HAL_GPIO_WritePin(selectMotor.motor_stepPort, selectMotor.motor_stepPin, GPIO_PIN_RESET);
        HAL_Delay(delay);
    }
}

/**
 * @brief Main function for motor controll
 *
 */
void motorControl_main()
{
    motorControl_spinMotor(connectedMotors[1], 200, 3, 0, 20);
    motorControl_spinMotor(connectedMotors[0], 30, 3, 1, 5);
}