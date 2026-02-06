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
#include "SystemInit.h"
#include "usb.h"
#include "App.h"


/*Define local functions*/
static void delayMs(uint32 time);
/***************************/


/*Define Global Variables*/



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

int main (int argc, char* argv[])
{
	//SystemInit
	system_cfg configSystem = {CLOCK_SOURCE_HSI, APB1_AHB_DIVIDER_NO, APB2_AHB_DIVIDER_NO, AHB_SYS_DIVIDER_NO,
								PLL_USB, PLLSRC_HSE, 4U, 96U, 0U, 4U, 2U};
	SystemClockConfig(configSystem);

	//UART Init
//	uart_cfg configUart = {STOPBIT_1, MBIT_8, PARITY_NO, RTS_CTS_ENABLE, OVER8_DIS, BAUDRATE_115_2K};
//	Uart_Init(configUart, USART2);

	//USB Init
	Usb_FS_Init();

	//External Input Config
//	Exti_Init();

	//Input Init Config
	Input_Init();



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

	  InputPolling();
	  Usb_FS_SendReport(&USB_FS, USB_buffer, 8);
	  delayMs(200);
    }
}




void OTG_FS_IRQHandler(void)
{
	USB_FS_IRQHandler();
}

void USART2_IRQHandler(void)
{
	Uart_IRQHandler();
}

void delayMs(uint32 time)
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
