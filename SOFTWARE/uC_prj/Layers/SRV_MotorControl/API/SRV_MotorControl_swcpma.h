#ifndef SRV_MOTORCONTROL_SWCPMA_H_
#define SRV_MOTORCONTROL_SWCPMA_H_

/*
    GLOBAL INCLUDE FILES
*/

#include <SRV_MotorControl_main.h>

/*
    DEFINES
*/

/*
    FUNCTIONS
*/

/**
 * @brief Initialization function for srv_motorControl
 * 
 * @return 1 if initialization succesfull
 * @return 0 if initialization not succesfull
 */
uint8_t motorControl_init();

/**
 * @brief Main function for motor controll
 * 
 */
void motorControl_main();
#endif