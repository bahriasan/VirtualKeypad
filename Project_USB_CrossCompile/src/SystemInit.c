/*
 * SystemInit.c
 *
 *  Created on: 15 Oca 2024
 *      Author: bahri
 */

#include "SystemInit.h"

void SystemClockConfig(system_cfg configSystem)
{
//First Oscillator Config
	if((CLOCK_SOURCE_HSE == configSystem.systemClockSource) || ((configSystem.PLLType != NO_PLL) && (configSystem.PLLSrc == PLLSRC_HSE)))
	{
		RCC->CR |= RCC_CR_HSEON;
		while((RCC->CR & RCC_CR_HSERDY_Msk) != RCC_CR_HSERDY);
	}

	if((CLOCK_SOURCE_HSI == configSystem.systemClockSource) || ((configSystem.PLLType != NO_PLL) && (configSystem.PLLSrc == PLLSRC_HSI)))
	{
		RCC->CR |= RCC_CR_HSION;
		while((RCC->CR & RCC_CR_HSIRDY_Msk) != RCC_CR_HSIRDY);
	}

	if((CLOCK_SOURCE_PLL == configSystem.systemClockSource) || (configSystem.PLLType != NO_PLL))
	{
		// Select HSE Source for PLL
		// Don't forget to clear initial value in case |= used
		RCC->PLLCFGR = ((configSystem.PLLSrc << PLLSRC_POSITION) |
						(configSystem.PLL_M << PLLM_POSITION) |
						(configSystem.PLL_N << PLLN_POSITION) |
						(configSystem.PLL_P << PLLP_POSITION) |
						(configSystem.PLL_Q << PLLQ_POSITION));
		// HSI(8MHz) / M(4) x N(96) / Q(4) = 48 MHz

		RCC->CR |= RCC_CR_PLLON;
		while((RCC->CR & RCC_CR_PLLRDY_Msk) != RCC_CR_PLLRDY);
	}

//System Clock Config

	//Set AHB Bus Prescaler
	//Clear Bit#4-7
	RCC->CFGR &= ~(15 << AHB_POSITION);
	//Set Config
	RCC->CFGR |= (configSystem.prescaler_AHB << AHB_POSITION);

	//Set APB1 Bus Prescaler
	//Clear Bit#10-12
	RCC->CFGR &= ~(7 << APB1_POSITION);
	//Set Config
	RCC->CFGR |= (configSystem.prescaler_APB1 << APB1_POSITION);

	//Set APB2 Bus PreScaler
	//Clear Bit#13-15
	RCC->CFGR &= ~(7 << APB2_POSITION);
	//Set Config
	RCC->CFGR |= (configSystem.prescaler_APB2 << APB2_POSITION);

	//Select System Clock Source
	RCC->CFGR |= (configSystem.systemClockSource << SW_POSITION);
}
