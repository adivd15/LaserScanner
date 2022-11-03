#ifndef SRV_MOTORCONTROL_DEF_H_
#define SRV_MOTORCONTROL_DEF_H_

/*
    GLOBAL INCLUDE FILES
*/



/*
    DEFINES
*/

/*
    TYPEDEF'S
*/

/**
 * @brief motor_struct
 * 
 */
typedef struct SRV_MotorControl_def_motor
{
    uint16_t motor_dirPin;
    GPIO_TypeDef* motor_dirPort;
    uint16_t motor_stepPin;
    GPIO_TypeDef* motor_stepPort;
    uint8_t controlMotor;
    uint8_t motorPos;
}SRV_MotorControl_def_motor;

#endif