#ifndef SRV_SENS_SWCPMA_H_
#define SRV_SENS_SWCPMA_H_
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
    FUNCTIONS
*/
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