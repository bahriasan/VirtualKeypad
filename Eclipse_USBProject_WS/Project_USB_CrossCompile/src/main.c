/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "cmsis_device.h"

#include "uart.h"
#include "gpio.h"
#include "SystemInit.h"
#include "usb.h"


/*Define local functions*/
static void delay(uint32 time);
/***************************/


/*Define Global Variables*/
//UART
uint8 DataReceived_flag;
char readData[32] = {0};

//USB


/***************************/

// ----------------------------------------------------------------------------
//
// Print a greeting message on the trace device and enter a loop
// to count seconds.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace-impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//
// ----------------------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int
main (int argc, char* argv[])
{
  // Normally at this stage most of the microcontroller subsystems, including
  // the clock, were initialised by the CMSIS SystemInit() function invoked
  // from the startup file, before calling main().
  // (see system/src/cortexm/initialize-hardware.c)
  // If further initialisations are required, customise __initialize_hardware()
  // or add the additional initialisation here, for example:
  //
  // HAL_Init();

  // In this sample the SystemInit() function is just a placeholder,
  // if you do not add the real one, the clock will remain configured with
  // the reset value, usually a relatively low speed RC clock (8-12MHz).

	//SystemInit
	system_cfg configSystem = {CLOCK_SOURCE_HSI, APB1_AHB_DIVIDER_NO, APB2_AHB_DIVIDER_NO, AHB_SYS_DIVIDER_NO,
								PLL_USB, PLLSRC_HSE, 4U, 96U, 0U, 4U, 2U};
	SystemClockConfig(configSystem);

	//GPIO Init
	gpio_cfg configGpio_PA0 = {PIN_0, GPIO_MODE_ALTERNATE, OUTPUT_TYPE_NA, OUTPUT_SPEED_LOW, PULL_UP, AF7};		//USART2_CTS
								//ACTIVE LOW SO SHOULD BE PULLED UP
	gpio_cfg configGpio_PA1 = {PIN_1, GPIO_MODE_ALTERNATE, OUTPUT_PUSH_PULL, OUTPUT_SPEED_LOW, PULL_UP, AF7};	//USART2_RTS
								//ACTIVE LOW SO SHOULD BE PULLED UP
	gpio_cfg configGpio_PA2 = {PIN_2, GPIO_MODE_ALTERNATE, OUTPUT_PUSH_PULL, OUTPUT_SPEED_LOW, PULL_UP, AF7};	//USART2_TX
								//SHOULD BE PULL_UP TO BE HIGH IN IDDLE, PUSH-PULL OR OPEN-DRAIN IS OK WHEN USED WITH PULL-UP
	gpio_cfg configGpio_PA3 = {PIN_3, GPIO_MODE_ALTERNATE, OUTPUT_TYPE_NA, OUTPUT_SPEED_LOW, PULL_DOWN, AF7};		//USART2_RX
								//SHOULD BE PULL_UP TO BE HIGH IN IDDLE, PUSH-PULL WILL BE SELECTED AS RESET STATE FOR OUTPUT_TYPE_NA

	Gpio_Init(configGpio_PA0, GPIOA);
	Gpio_Init(configGpio_PA1, GPIOA);
	Gpio_Init(configGpio_PA2, GPIOA);
	Gpio_Init(configGpio_PA3, GPIOA);


	//UART Init
	uart_cfg configUart = {STOPBIT_1, MBIT_8, PARITY_NO, RTS_CTS_ENABLE, OVER8_DIS, BAUDRATE_115_2K};
	Uart_Init(configUart, USART2);
	// PA0: USART2_CTS, PA1: USART2_RTS, PA2: USART2_TX, PA3: USART2_RX, PA4: USART2_CK
	Uart_EnableInterrupt(USART2, RXNE);


	Usb_FS_Init(&USB_FS);
	uint8 buffer[8] = {0};

  // Infinite loop
  while (1)
    {
//	  /*UART Test*/
//	  char readData[32] = {0};
//	  char writeData[] = "Hello World!";
//	  Uart_Read_Inst((uint8*)readData , USART2);
//	  Uart_Read((uint8*)readData , USART2);
//	  Uart_Write(writeData, USART2, sizeof(writeData));
//	  Uart_Write_Inst(writeData, USART2, sizeof(writeData));
//	  delay(10000);//delay for Write process

	  buffer[0] = 0;
	  buffer[2] = 7;

	  Usb_FS_SendReport(&USB_FS, buffer, 8);

	  delay(10);

	  buffer[0] = 0;
	  buffer[2] = 0;

	  Usb_FS_SendReport(&USB_FS, buffer, 8);

	  delay(2000);
    }
}


void OTG_FS_IRQHandler(void)
{
	USB_FS_IRQHandler();
}


void USART2_IRQHandler(void)
{
	static uint8 index = 0;

	//Check the source of the Interrupt

	if((uint32)USART2->SR & SR_MASK(PE_BIT_POSITION))
	{
		//Handle PE
	}
	else if((uint32)USART2->SR & SR_MASK(FE_BIT_POSITION))
	{
		//Handle FE
	}
	else if((uint32)USART2->SR & SR_MASK(NF_BIT_POSITION))
	{
		//Handle NF
	}
	else if((uint32)USART2->SR & SR_MASK(ORE_BIT_POSITION))
	{
		//Handle ORE
	}
	else if((uint32)USART2->SR & SR_MASK(IDLE_BIT_POSITION))
	{
		//Handle IDLE
	}
	else if((uint32)USART2->SR & SR_MASK(RXNE_BIT_POSITION))
	{
		//Handle RXNE
		Uart_Read((uint8*)readData + index , USART2);
		index = (index + 1) % sizeof(readData); 	//ringbuffer
		//DataReceived_flag = FALSE;
	}
	else if((uint32)USART2->SR & SR_MASK(TC_BIT_POSITION))
	{
		//Handle TC
	}
	else if((uint32)USART2->SR & SR_MASK(TXE_BIT_POSITION))
	{
		//Handle TXE
	}
	else if((uint32)USART2->SR & SR_MASK(LBD_BIT_POSITION))
	{
		//Handle LBD
	}
	else if((uint32)USART2->SR & SR_MASK(CTS_BIT_POSITION))
	{
		//Handle CTS
	}
	else
	{
		// do nothing
	}
}


void delay(uint32 time)
{
	uint32 index_1, index_2;
	uint32 base = 250;

	for(int i = 0; i<base; ++i)
	{
		for(index_1=0; index_1<time; ++index_1)
		{
			for(index_2=0; index_2<sizeof(index_2); ++index_2)
			{}
		}
	}
}


//#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
