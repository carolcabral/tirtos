// ----------------------------------------------------------------------------
// myGpio_drv.c  (GPIO Driver)
//
// This file configures the GPIO pins for the board's LEDs and buttons.
//
// This file uses the TI provided GPIO Driver (DRV) to configure
// and execute peripheral functionality. This workshop provides examples for
// three different software layers (CSLR, CSL, and Driver).
//
// Note that the GPIO pins will not drive the LEDs unless:
//   1. The PinMux registers assigned to the GPIO pins are configured for GPIO.
//   2. The GPIO Module is enabled.
//
// These two conditions are enabled by Board_init() called from main().
// Lab3C explores other methods for configuring these two items.
//
// This solution file contains the "extra credit" code which configures
// the second user button.
//
// See WARNING in lab_04c_timer_nortos_solution README file!
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
// Standard C Header Files
#include <stdint.h>                                                             // Standard integer types
#include <stddef.h>                                                             // Standard variable types and macros
#include <stdio.h>                                                              // Standard I/O for printf()

// Peripheral Driver Header Files
#include <ti/drv/gpio/soc/GPIO_soc.h>                                           // Defines driver version for C6748 SOC device
#include <ti/drv/gpio/GPIO.h>                                                   // TI GPIO Driver header file

// Local Header Files
#include "GPIO_board.h"                                                         // Defines LED Names for GPIO_toggle()
#include "myGpio.h"                                                             // Header file for myGpio.c


//***** Prototypes ************************************************************
void Button1GpioCallbackFxn(void);
void Button2GpioCallbackFxn(void);


//*****************************************************************************
// Initialize GPIO
//
// This function configures the GPIO pins for the User LEDs and buttons. This
// requires setting the pin direction to 'output'. This is performed by the
// GPIO_init() function by applying the gpioPinConfigs values from GPIO_board.c.
// We also set initial values for one pin HIGH, and the other LOW.
//
//   - USER_LED0 is connected to "GREEN LED D5" on the board - GPIO6[12]
//   - USER_LED1 is connected to "GREEN LED D4" on the board - GPIO6[13]
//   - USER_LED2 is connected to "GREEN LED D6" on the board - GPIO2[12]
//   - USER_LED3 is connected to "GREEN LED D7" on the board - GPIO0[9]
//
//   - USER_BUTTON1 is connected to the "User Button 1"      - GPIO2[4]
//     The LCDK User Guide calls this button "S2".
//     Interrupts are enabled for this button.
//
//   - USER_BUTTON2 is connected to the "User Button 2"      - GPIO2[5]
//     The LCDK User Guide calls this button "S3".
//     Interrupts are enabled for this button.
//
// The order of the first two LEDs is a bit odd (D5 then D4). We are not
// sure why TI configured the board this way (in board_cfg.h).
//*****************************************************************************
void myGpio_init(void)
{
    GPIO_v0_HwAttrs gpioCfg;

    // Get the default GPIO init configuration
    GPIO_socGetInitCfg(GPIO_LED0_PORT_NUM, &gpioCfg);

    // Setup GPIO interrupt configurations
//    GPIO_socSetBankInt(GPIO_BUTTON1_PORT_NUM, GPIO_BUTTON1_PIN_NUM, NULL);      // Set Bank Interrupt for GPIO Bank 2

    // Init's GPIO driver and configures the pins defined in gpioPinConfigs[]
    GPIO_init();                                                                // Call GPIO driver init function

    // Set initial values for user LEDs
    GPIO_write(USER_LED0, GPIO_PIN_VAL_LOW);                                   // Write "1" to GPIO pin to turn on LED0 (GPIO write example)
    GPIO_write(USER_LED1, GPIO_PIN_VAL_LOW);                                    // Write "0" to GPIO pin to turn off LED1 (GPIO write example)
    GPIO_write(USER_LED2, GPIO_PIN_VAL_LOW);                                    // Write "0" to GPIO pin to turn off LED2 (GPIO write example)
    GPIO_write(USER_LED3, GPIO_PIN_VAL_LOW);                                    // Write "0" to GPIO pin to turn off LED3 (GPIO write example)

    // Set the interrupt callback functions
//    GPIO_setCallback(USER_BUTTON1, Button1GpioCallbackFxn);
//    GPIO_setCallback(USER_BUTTON2, Button2GpioCallbackFxn);
//
//    // Enable GPIO interrupt for each gpio pin
//    GPIO_enableInt(USER_BUTTON1);
//    GPIO_enableInt(USER_BUTTON2);

    printf("GPIO has been initialized\n");
}


//*****************************************************************************
// GPIO Callback Functions
//*****************************************************************************
void Button1GpioCallbackFxn(void)
{
    GPIO_toggle(USER_LED2);
}

void Button2GpioCallbackFxn(void)
{
    GPIO_toggle(USER_LED3);
}


/* ===========================================================================
   Copyright (c) 2021 Embedded Advantage LLC (www.embeddedadvantage.com)

   This software can be re-used, for personal or commercial purposes,
   provided that the conditions described below are met:

   a. Redistribution of unmodified source code outside of the license
      owner's (individual who paid for training from Embedded Advantage)
      company is prohibited. Source code may be used to create derivative
      works.
   b. Neither the name of the copyright holder nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
============================================================================ */
