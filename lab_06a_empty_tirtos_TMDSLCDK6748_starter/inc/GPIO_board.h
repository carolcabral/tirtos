/**
 *  \file   GPIO_board.h
 *
 *  \brief  GPIO board header file.
 *
 *  Original file: C:\ti\pdk_omapl138_1_0_10\packages\ti\drv\gpio\test\led_blink\src\GPIO_board.h
 *
 */

/*
 * Copyright (C) 2014 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef _GPIO_BOARD_H
#define _GPIO_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif


/* Example/Board Header files */
#include <ti/board/board.h>


//*****************************************************************************
// GPIO Pin Definitions/Macros
//
// C6748 GPIO consists of one I/O port (i.e. Port 0) that's broken down
// into nine 16-bit Banks. GPIO driver configuration is based on the
// pin number within the port. The macros below convert from the Bank[Pin]
// value to the Port[Pin] value.
//
// The first two 2 LEDs (D5, D4) are defined in the board_cfg.h, but not the
// remaining LEDs and switches, therefore we define them here.
//*****************************************************************************
#define GPIO_LED2_PORT_NUM      0                                               // LED 'D6' on GPIO2[12] -> Port 0, Bank 2, Bank_Pin 12
#define GPIO_LED2_PIN_NUM       ((2*16) + 12)                                   // Calculate Port's pin #:  2*16 + 12 = 44 ==> Port0.44
#define GPIO_LED3_PORT_NUM      0                                               // LED 'D7' on GPIO0[9]  -> Port 0, Bank 0, Bank_Pin 9
#define GPIO_LED3_PIN_NUM       ((0*16) + 9)                                    // Port0.9

#define GPIO_BUTTON1_PORT_NUM   0                                               // LED 'S2' on GPIO2[4]  -> Port 0, Bank 2, Bank_Pin 4
#define GPIO_BUTTON1_PIN_NUM    ((2*16) + 4)                                    // Port0.36
#define GPIO_BUTTON2_PORT_NUM   0                                               // LED 'S3' on GPIO2[5]  -> Port 0, Bank 2, Bank_Pin 5
#define GPIO_BUTTON2_PIN_NUM    ((2*16) + 5)                                    // Port0.37


/* ON Board LED pins (and Buttons) which are connected to GPIO pins. */
typedef enum GPIO_LED {
    USER_LED0 = 0,
    USER_LED1,
    USER_LED2,
    USER_LED3,
    USER_BUTTON1,
    USER_BUTTON2
}GPIO_LED;


#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)


#ifdef __cplusplus
}
#endif

#endif /* _GPIO_LOG_H */
