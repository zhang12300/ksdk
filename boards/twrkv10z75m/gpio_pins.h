/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : gpio_pins.h
**     Project     : twrk64f120m-pin
**     Processor   : MK64FN1M0VMD12
**     Component   : fsl_gpio
**     Version     : Component 01.106, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-06-08, 17:51, # CodeGen: 7
**     Contents    :
**         GPIO_DRV_Init            - void GPIO_DRV_Init(const gpio_input_pin_user_config_t * inputPins,const...
**         GPIO_DRV_InputPinInit    - void GPIO_DRV_InputPinInit(const gpio_input_pin_user_config_t * inputPin);
**         GPIO_DRV_OutputPinInit   - void GPIO_DRV_OutputPinInit(const gpio_output_pin_user_config_t * outputPin);
**         GPIO_DRV_GetPinDir       - gpio_pin_direction_t GPIO_DRV_GetPinDir(uint32_t pinName);
**         GPIO_DRV_SetPinDir       - void GPIO_DRV_SetPinDir(uint32_t pinName,gpio_pin_direction_t direction);
**         GPIO_DRV_WritePinOutput  - void GPIO_DRV_WritePinOutput(uint32_t pinName,uint32_t output);
**         GPIO_DRV_SetPinOutput    - void GPIO_DRV_SetPinOutput(uint32_t pinName);
**         GPIO_DRV_ClearPinOutput  - void GPIO_DRV_ClearPinOutput(uint32_t pinName);
**         GPIO_DRV_TogglePinOutput - void GPIO_DRV_TogglePinOutput(uint32_t pinName);
**         GPIO_DRV_ReadPinInput    - uint32_t GPIO_DRV_ReadPinInput(uint32_t pinName);
**         GPIO_DRV_ClearPinIntFlag - void GPIO_DRV_ClearPinIntFlag(uint32_t pinName);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file gpio_pins.h
** @version 01.00
*/         
/*!
**  @addtogroup gpio_pins_module gpio_pins module documentation
**  @{
*/         

#ifndef __gpio_pins_H
#define __gpio_pins_H

/* MODULE gpio_pins. */

/* Include inherited beans */
#include "fsl_gpio_driver.h"


/*! @brief Configuration structure 0 for input pins */
extern gpio_input_pin_user_config_t switchPins[];
/*! @brief Configuration structure 1 for input pins */
extern const gpio_input_pin_user_config_t accelIntPins[];
/*! @brief Configuration structure 3 for input pins */
extern const gpio_input_pin_user_config_t sdhcCdPin[];

/*! @brief Configuration structure 0 for output pins */
extern const gpio_output_pin_user_config_t ledPins[];

extern const gpio_output_pin_user_config_t spiCsPin[];

/*! @brief Pin names */
enum _gpio_pins_pinNames{
  kGpioSW1 = GPIO_MAKE_PIN(HW_GPIOA, 4U),
  kGpioSW2 = GPIO_MAKE_PIN(HW_GPIOB, 0),
  kGpioAccelINT1 = GPIO_MAKE_PIN(HW_GPIOB, 2U),
  kGpioAccelINT2 = GPIO_MAKE_PIN(HW_GPIOA, 4U),
  kGpioLED1 = GPIO_MAKE_PIN(HW_GPIOC, 1U),
  kGpioLED2 = GPIO_MAKE_PIN(HW_GPIOE, 25U),
  kGpioLED3 = GPIO_MAKE_PIN(HW_GPIOC, 3U),
  kGpioLED4 = GPIO_MAKE_PIN(HW_GPIOC, 4U),
  kGpioLED5 = GPIO_MAKE_PIN(HW_GPIOD, 4U),
  kGpioLED6 = GPIO_MAKE_PIN(HW_GPIOD, 5U),
  kGpioLED7 = GPIO_MAKE_PIN(HW_GPIOD, 6U),
  kGpioLED8 = GPIO_MAKE_PIN(HW_GPIOD, 7U),
  
};

  
#endif

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.10]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
