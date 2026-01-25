/*
 * gpio.c
 *
 *  Created on: 14 Oca 2024
 *      Author: bahri
 */

#include "gpio.h"
static void Gpio_ChannelEnable(GPIO_TypeDef* structGpio);


void Gpio_Init(gpio_cfg configGpio, GPIO_TypeDef* structGpio)
{
	//0.Enable Channel
	Gpio_ChannelEnable(structGpio);

	//1. Configure Mode
	//Clear Bit Positions
	structGpio->MODER &= ~(3 << (configGpio.pinNumber * 2));
	//Set Bits
	structGpio->MODER |= (configGpio.mode << (configGpio.pinNumber * 2));

	//2. Output Type
	if(configGpio.outputType != OUTPUT_TYPE_NA)
	{
		//Clear Bit Position
		structGpio->OTYPER &= ~(1 << configGpio.pinNumber);
		//Set Bit
		structGpio->OTYPER |= (configGpio.outputType << configGpio.pinNumber);
	}

	//3. Output Speed
	if(configGpio.outputType != OUTPUT_SPEED_NA)
	{
		//Clear Bit Position
		structGpio->OSPEEDR &= ~(3 << (configGpio.pinNumber * 2));
		//Set Bit
		structGpio->OSPEEDR |= (configGpio.outputType << (configGpio.pinNumber * 2));
	}

	//4. PullUp/PullDown

	//Clear Bit Positions
	structGpio->PUPDR &= ~(3 << (configGpio.pinNumber *2));
	//Set Bit
	structGpio->PUPDR |= (configGpio.pullUp_Down << (configGpio.pinNumber * 2));

	//5. Alternate Function

	if( GPIO_MODE_ALTERNATE == configGpio.mode)
	{
		if(configGpio.pinNumber < 8)
		{
			//Clear Bit Positions
			structGpio->AFR[0] &= ~(0xF << (configGpio.pinNumber * 4));
			//Set Bit
			structGpio->AFR[0] |= (configGpio.alternateFunctionNo << (configGpio.pinNumber * 4));
		}
		else if((configGpio.pinNumber > 7) && (configGpio.pinNumber < 15))
		{
			//Clear Bit Positions
			structGpio->AFR[1] &= ~(0xF << ((configGpio.pinNumber - 8) * 4));
			//Set Bit
			structGpio->AFR[1] |= (configGpio.alternateFunctionNo << ((configGpio.pinNumber - 8) * 4));
		}
		else
		{ /* do Nothing */ }
	}
}

static void Gpio_ChannelEnable(GPIO_TypeDef* structGpio)
{
	if(GPIOA == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOAEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOAEN_POSITION);
	}
	else if(GPIOB == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOBEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOBEN_POSITION);
	}
	else if(GPIOC == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOCEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOCEN_POSITION);
	}
	else if(GPIOD == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIODEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIODEN_POSITION);
	}
	else if(GPIOE == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOEEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOEEN_POSITION);
	}
	else if(GPIOF == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOFEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOFEN_POSITION);
	}
	else if(GPIOG == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOGEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOGEN_POSITION);
	}
	else if(GPIOH == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOHEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOHEN_POSITION);
	}
	else if(GPIOI == structGpio)
	{
		RCC->AHB1RSTR &= ~(1 << GPIOIEN_POSITION);
		RCC->AHB1ENR |= (1 << GPIOIEN_POSITION);
	}
}

boolean Gpio_Read(uint8 pinNumber, GPIO_TypeDef* structGpio)
{
	boolean retVal = FALSE;
	uint32 idr_reg = structGpio->IDR;

	if(((idr_reg >> pinNumber) & 0x1ul) == 0x1ul)
	{
		retVal = TRUE;
	}

	return retVal;
}


















