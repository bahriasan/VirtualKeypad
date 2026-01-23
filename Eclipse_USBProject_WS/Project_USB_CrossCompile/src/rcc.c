/*
 * rcc.c
 *
 *  Created on: 12 May 2024
 *      Author: bahri
 */

#include "rcc.h"


uint8 Prescaler_AHB[8]={1,2,3,4,5,6,7,8};
uint8 Prescaler_APB[8]={1,2,3,4};


uint32 RCC_ReadClock(bus_type bus, uint32* ret_clk)
{
	uint8 temp, ps_apb1, ps_apb2, ps_ahb;
	uint32 clk;

	//1. Check Clock Source
	if(((RCC->CFGR >> SWS_POSITION) & 0x3u) == 0x0u)	//HSI ENABLE
	{
		clk = 16000000u;
	}
	else if(((RCC->CFGR >> SWS_POSITION) & 0x3u) == 0x1u)	//HSE ENABLE
	{
		clk = 8000000u;
	}
	else if(((RCC->CFGR >> SWS_POSITION) & 0x3u) == 0x2u)	//PLL ENABLE
	{
		//TBD
	}

	//2. Read Prescaler Values
	//AHB_PreScaler
	temp = (RCC->CFGR >> AHB_POSITION) & 0xFu;
	if(temp < 8)
	{
		ps_ahb = 0;
	}
	else
	{
		ps_ahb = Prescaler_AHB[temp-8];
	}

	//APB1_PreScaler
	temp = (RCC->CFGR >> APB1_POSITION) & 0x7u;
	if(temp < 4)
	{
		ps_apb1 = 0;
	}
	else
	{
		ps_apb1 = Prescaler_APB[temp-4];
	}

	//APB2_PreScaler
	temp = (RCC->CFGR >> APB2_POSITION) & 0x7u;
	if(temp < 4)
	{
		ps_apb2 = 0;
	}
	else
	{
		ps_apb2 = Prescaler_APB[temp-4];
	}

	//3. Check which clock is needed
	clk = clk >> ps_ahb;

	if(bus == AHB)
	{
		*ret_clk = clk;
	}
	else if(bus == APB1)
	{
		*ret_clk = clk >> ps_apb1;
	}
	else if(bus == APB2)
	{
		*ret_clk = clk >> ps_apb1;
	}

}
