/**
 *  \file   GPIO_board.c
 *
 *  \brief  OMAPL138 EVM board specific GPIO parameters.
 *
 *  Original File: C:\ti\pdk_omapl138_1_0_10\packages\ti\drv\gpio\test\led_blink\omapl138\GPIO_board.c
 *
 */

/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <ti/csl/soc.h>
#include <ti/csl/csl_types.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include "GPIO_board.h"


/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] =
{
    /* Output pin */
    GPIO_DEVICE_CONFIG(GPIO_LED0_PORT_NUM, GPIO_LED0_PIN_NUM) |                 // LED 'D5' - with interrupt removed from TI's original example
    GPIO_CFG_OUTPUT,

    /* Output pin */
    GPIO_DEVICE_CONFIG(GPIO_LED1_PORT_NUM, GPIO_LED1_PIN_NUM) |                 // LED 'D4' - TI's original example configures LED1 for (only) output
    GPIO_CFG_OUTPUT,

    // Configure additional two LEDs (extending the TI PDK example GPIO_board file)
    GPIO_DEVICE_CONFIG(GPIO_LED2_PORT_NUM, GPIO_LED2_PIN_NUM) |                 // LED 'D6'
    GPIO_CFG_OUTPUT,

    GPIO_DEVICE_CONFIG(GPIO_LED3_PORT_NUM, GPIO_LED3_PIN_NUM) |                 // LED 'D7'
    GPIO_CFG_OUTPUT,

    // Configure pins for Expansion Connector (GPIO1.4, GPIO1.5)
       // While this would not be difficult, we only implemented
       // the expansion connector GPIO pins for the CSL solution.
       // Please refer to "lab_03d_expansionGpio_csl".

    // Configure User Buttons 1 & 2 (further extending the TI PDK example board file)
    GPIO_DEVICE_CONFIG(GPIO_BUTTON1_PORT_NUM, GPIO_BUTTON1_PIN_NUM) |           // Button 'S2'
    GPIO_CFG_INPUT,                                                             // See WARNING in lab_04c_timer_nortos_solution README file!

    GPIO_DEVICE_CONFIG(GPIO_BUTTON2_PORT_NUM, GPIO_BUTTON2_PIN_NUM) |           // Button 'S3'
    GPIO_CFG_INPUT                                                              // See WARNING in lab_04c_timer_nortos_solution README file!
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] =
{
    NULL,                                                                       // Callback function set in myGpio_init()
    NULL,                                                                       // Not used as an interrupt pin
    NULL,                                                                       // Not used as an interrupt pin
    NULL,                                                                       // Not used as an interrupt pin
    NULL,                                                                       // Callback function set in myGpio_init()
    NULL                                                                        // Not used as an interrupt pin
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config =
{
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    12,
};
