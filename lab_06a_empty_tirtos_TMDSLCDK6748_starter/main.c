// ----------------------------------------------------------------------------
// main.c
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
// XDC module Header Files
#include <xdc/std.h>                                                            // XDC "base types" - must be included FIRST
#include <xdc/runtime/Types.h>                                                  // XDC constants/types used in xdc.runtime pkg
#include <xdc/cfg/global.h>                                                     // For all BIOS instances created statically in RTOS .cfg file
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log.h>                                                    // Needed for any Log_info() call
#include <xdc/runtime/Error.h>                                                  // For error handling (e.g. Error block)
#include <xdc/runtime/System.h>                                                 // XDC System functions (e.g. System_abort(), System_printf())
#include <xdc/runtime/Timestamp.h>                                              // Needed when using Timestamp APIs (TSCL/H), 32bit, 64bit

// TI-RTOS Kernel Header Files
#include <ti/sysbios/BIOS.h>                                                    // BIOS kernel API
#include <ti/sysbios/knl/Task.h>                                                // BIOS Task API

// Standard C Header Files
#include <stdint.h>                                                             // Standard integer types
#include <stddef.h>                                                             // Standard variable types and macros

// Peripheral Driver Header Files
#include <ti/board/board.h>                                                     // Board init enables C6748 modules (e.g. GPIO Module)

//***** Library Files **********************************************************
#include "myGpio.h"

//*****************************************************************************
// Main
//*****************************************************************************
void main(void)
{
    // Initialize Peripherals
    Board_init(BOARD_INIT_PINMUX_CONFIG |                                       // Initialize PinMux registers and GPIO Module/Clock
               BOARD_INIT_MODULE_CLOCK);

    myGpio_init();

    BIOS_start();                                                               // Start TI-RTOS (SYS/BIOS kernel) services - it does not return
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
