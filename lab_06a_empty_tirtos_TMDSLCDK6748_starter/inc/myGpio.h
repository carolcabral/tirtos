// ----------------------------------------------------------------------------
// myGpio.h
// ----------------------------------------------------------------------------

#ifndef MYGPIO_H_
#define MYGPIO_H_


// CSL Header Files
#include <ti/drv/gpio/GPIO.h>                                                   // TI GPIO Driver header file needed for GPIO_toggle()

// Local Header Files
#include "GPIO_board.h"                                                         // Defines LED Names for GPIO_toggle()


//***** Defines ***************************************************************
// Used to make the code more readable when 'reading' the button values in main
#define MYGPIO_BUTTON_UP        (1U)
#define MYGPIO_BUTTON_DOWN      (0U)


//***** Prototypes ************************************************************
void myGpio_init(void);


#endif /* MYGPIO_H_ */


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
