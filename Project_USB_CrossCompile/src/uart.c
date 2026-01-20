/*
 * uart.c
 *
 *  Created on: 14 Oca 2024
 *      Author: bahri
 */

#include "uart.h"
#include "rcc.h"


//Static Function Declarations

static void Uart_ChannelEnable(USART_TypeDef* structUart);
static void Uart_ChannelReset(USART_TypeDef* structUart);
static void Uart_SetBaudrate(uint16 baudRate, USART_TypeDef* structUart);

//Static Function Definitions

static void Uart_ChannelEnable(USART_TypeDef* structUart)
{
	if(structUart == USART1)
	{
		RCC->APB2RSTR &= ~(1 << USART1_RESET_POSITION);
		RCC->APB2ENR |= (1 << USART1_ENABLE_POSITION);
	}
	else if(structUart == USART2)
	{
		RCC->APB1RSTR &= ~(1 << USART2_RESET_POSITION);
		RCC->APB1ENR |= (1 << USART2_ENABLE_POSITION);
	}
	else if(structUart == USART3)
	{
		RCC->APB1RSTR &= ~(1 << USART3_RESET_POSITION);
		RCC->APB1ENR |= (1 << USART3_ENABLE_POSITION);
	}
	else if(structUart == UART4)
	{
		RCC->APB1RSTR &= ~(1 << UART4_RESET_POSITION);
		RCC->APB1ENR |= (1 << UART4_ENABLE_POSITION);
	}
	else if(structUart == UART5)
	{
		RCC->APB1RSTR &= ~(1 << UART5_RESET_POSITION);
		RCC->APB1ENR |= (1 << UART5_ENABLE_POSITION);
	}
	else if(structUart == USART6)
	{
		RCC->APB2RSTR &= ~(1 << USART6_RESET_POSITION);
		RCC->APB2ENR |= (1 << USART6_ENABLE_POSITION);
	}
	else
	{
		//do Nothing
	}
}

static void Uart_ChannelReset(USART_TypeDef* structUart)
{
	if(structUart == USART1)
	{
		RCC->APB2ENR &= ~(1 << USART1_ENABLE_POSITION);
		RCC->APB2RSTR |= (1 << USART1_RESET_POSITION);
	}
	else if(structUart == USART2)
	{
		RCC->APB1ENR &= ~(1 << USART2_ENABLE_POSITION);
		RCC->APB1RSTR |= (1 << USART2_RESET_POSITION);
	}
	else if(structUart == USART3)
	{
		RCC->APB1ENR &= ~(1 << USART3_ENABLE_POSITION);
		RCC->APB1RSTR |= (1 << USART3_RESET_POSITION);
	}
	else if(structUart == UART4)
	{
		RCC->APB1ENR &= ~(1 << UART4_ENABLE_POSITION);
		RCC->APB1RSTR |= (1 << UART4_RESET_POSITION);
	}
	else if(structUart == UART5)
	{
		RCC->APB1ENR &= ~(1 << UART5_ENABLE_POSITION);
		RCC->APB1RSTR |= (1 << UART5_RESET_POSITION);
	}
	else if(structUart == USART6)
	{
		RCC->APB2ENR &= ~(1 << USART6_ENABLE_POSITION);
		RCC->APB2RSTR |= (1 << USART6_RESET_POSITION);
	}
	else
	{
		//do Nothing
	}
}

static void Uart_SetBaudrate(uint16 baudRate, USART_TypeDef* structUart)
{
	uint32 mantissa;
	uint8 fraction;
	uint32 clk;
	uint8 bus;

	if((structUart == USART1) || (structUart == USART6))
	{
		bus = APB2;
	}
	else if((structUart == USART2) || (structUart == USART3) || (structUart == UART4) || (structUart == UART5))
	{
		bus = APB1;
	}

	//Read Clock
	RCC_ReadClock(bus, &clk);

	//OVER8 = 0
	if(((structUart->CR1 >> OVER8_BIT_POSITION) & (0x01)) == 0x00)
	{
		mantissa = (uint32)(clk / 16u / baudRate /100);
		fraction = (uint8)((((uint32)(clk / 16) / baudRate % 100) * 16 + 50) / 100);
	}
	//OVER8 = 1
	else if(((structUart->CR1 >> OVER8_BIT_POSITION) & (0x01)) == 0x01)
	{
		mantissa = (uint16)((uint32)(clk / 8) / baudRate / 100);
		fraction = (uint8)((((uint32)(clk / 8) / baudRate % 100) * 8 + 50) / 100);
	}
	//Clear Mantissa and Fraction Bits
	structUart->BRR &= ~(0xF << FRACTION_BIT_POSITION);
	structUart->BRR &= ~(0xFFF << MANTISSA_BIT_POSITION);

	//Set Mantissa and Fraction Bits
	structUart->BRR |= (fraction << FRACTION_BIT_POSITION);
	structUart->BRR |= (mantissa << MANTISSA_BIT_POSITION);
}

//Global Function Definitions

void Uart_Init(uart_cfg configUart, USART_TypeDef* structUart)
{
	//1. Enable Channel Clock
	Uart_ChannelEnable(structUart);

	//0. Enable USART
	structUart->CR1 |= (1 << USART_ENABLE_BIT_POSITION);

	//2. Configure StopBit
	//Clear CR2 Bit#12-13
	structUart->CR2 &= ~(3 << STOP_BIT_POSITION);
	//Set CR2 Bit#12-13 Stop Bit Config
	structUart->CR2 |= (configUart.stopBit << STOP_BIT_POSITION);

	//3. Configure MBit
	//Clear CR1 Bit#12
	structUart->CR1 &= ~(1 << M_BIT_POSITION);
	//Set CR1 Bit#12 to MBit Config
	structUart->CR1 |= (configUart.mBit << M_BIT_POSITION);

	//4. Configure Parity Bit
	if(configUart.parityControl == PARITY_NO)
	{
		//Set CR1 Bit#10 to 0(Parity Disable)
		structUart->CR1 &= ~(1 << PARITY_ENABLE_BIT_POSITION);
	}
	else if((configUart.parityControl == PARITY_EVEN) || (configUart.parityControl == PARITY_ODD))
	{
		//Set CR1 Bit#10 to 1(Parity Enable)
		structUart->CR1 |= (1 << PARITY_ENABLE_BIT_POSITION);
		//Clear CR1 Bit#9
		structUart->CR1 &= ~(1 << PARITY_SELECTION_BIT_POSITION);
		//Set CR1 Bit#9 to Even or Odd
		structUart->CR1 |= (configUart.parityControl << PARITY_SELECTION_BIT_POSITION);
	}
	else
	{
		//Do Nothing
	}


	//5. Configure Control Flow Feature

	//Clear Bit Positions
	structUart->CR3 &= ~(3 << RTSE_BIT_POSITION);
	//Set Bit Configuration
	structUart->CR3 |= (configUart.controlFlow << RTSE_BIT_POSITION);


	//6. Configure BaudRate
	//Set Over8 Bit
	structUart->CR1 &= ~(1 << OVER8_BIT_POSITION);
	structUart->CR1 |= (configUart.over8Bit << OVER8_BIT_POSITION);

	Uart_SetBaudrate(configUart.baudRate, structUart);

	//7. Enable Receive Process to find Start Bit
	structUart->CR1 |= (1 << RECEIVE_ENABLE_BIT_POSITION);

	//8. Enable Transmit
	structUart->CR1 |= (1 << TRANSMIT_ENABLE_BIT_POSITION);

}

void Uart_Read(uint8* readData, USART_TypeDef* structUart)
{
	//Read RXNE bit
	if((uint32)1u == ((structUart->SR >> RXNE_BIT_POSITION) & (uint32)1u))
	{
		if(((uint8)(structUart->CR1 >> M_BIT_POSITION) & 0x01) == 0x01)						//9 Bits
		{
			if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x01)		//Parity Enable
			{
				*readData = (uint8) (structUart->DR) >> 1;
			}
			else if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x00)	//Parity Disable
			{
				*readData = (uint8) (structUart->DR);
				*(readData + 1) = (uint8) (structUart->DR) >> 8;
			}
		}
		else if(((uint8)(structUart->CR1 >> M_BIT_POSITION) & 0x01) == 0x00)					//8 Bits
		{
			if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x01)		//Parity Enable
			{
				*readData = (uint8) (structUart->DR) & 0xFE;
			}
			else if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x00)	//Parity Disable
			{
				*readData = (uint8) (structUart->DR);
				++readData;
			}
		}
	}
}

void Uart_Write(uint8* writeDataBuffer, USART_TypeDef* structUart, uint32 size)
{
	uint8 i = 0;
	static uint8 j = 0;

	while(i < size)
	{
		if(((uint8)(structUart->SR >> CTS_BIT_POSITION) & 0x01u) == 0x00u)			//CTS is not toggeled
		{
			if(((uint8)(structUart->SR >> TXE_BIT_POSITION) & 0x01u) == 0x01u)		//if TDR is empty, TXE=1
			{
				if(((uint8)(structUart->CR1 >> M_BIT_POSITION) & 0x01) == 0x01)						//9 Bits
				{
					if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x01)		//Parity Enable
					{
						(structUart->DR) = *writeDataBuffer;		//8 Bits
					}
					else if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x00)	//Parity Disable
					{
						(structUart->DR) = *writeDataBuffer;		//9 Bits
					}
				}
				else if(((uint8)(structUart->CR1 >> M_BIT_POSITION) & 0x01) == 0x00)					//8 Bits
				{
					if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x01)		//Parity Enable
					{
						(structUart->DR) = *writeDataBuffer;		//7 Bits
					}
					else if(((uint8)(structUart->CR1 >> PARITY_ENABLE_BIT_POSITION) & 0x01) == 0x00)	//Parity Disable
					{
						(structUart->DR) = *writeDataBuffer;		//8 Bits
					}
				}

				while(!(uint8)(structUart->SR >> TC_BIT_POSITION) & 0x01);		//Wait for TC=1, TX completed

				++writeDataBuffer;
				++i;
			}
		}
		else
		{
			(structUart->DR) = '0';
			++j;
		}
	}
}


void Uart_Write_Inst(uint8* writeDataBuffer, USART_TypeDef* structUart, uint32 size)
{
	uint8 i = 0, j = 0, k = 0;

	while(i < size)
	{

		structUart->DR = *writeDataBuffer; //*writeDataBuffer;

		//while(!(uint8)(structUart->SR >> TXE_BIT_POSITION) & 0x01)
			//{++j;}		//Wait for TC=1, TX completed

		while(!(uint8)(structUart->SR >> TC_BIT_POSITION) & 0x01)
			{++k;}		//Wait for TC=1, TX completed

		++writeDataBuffer;
		++i;
	}
}

void Uart_Read_Inst(uint8* readDataBuffer, USART_TypeDef* structUart)
{
	static uint8 i = 0;

	if((structUart->SR >> RXNE_BIT_POSITION) & 0x01 == 0x01)
	{
		*(readDataBuffer + i) = structUart->DR;
		++i;
	}
}

void Uart_EnableInterrupt(USART_TypeDef* structUart, Uart_interrupt eventFlag)
{

//Enable Interrupt in NVIC and set Priority
	if(USART1 == structUart)
	{
		NVIC_SetPriority(USART1_IRQn, 0);
		NVIC_EnableIRQ(USART1_IRQn);
	}
	else if(USART2 == structUart)
	{
		NVIC_SetPriority(USART2_IRQn, 0);
		NVIC_EnableIRQ(USART2_IRQn);
	}
	else if(USART3 == structUart)
	{
		NVIC_SetPriority(USART3_IRQn, 0);
		NVIC_EnableIRQ(USART3_IRQn);
	}
	else if(UART4 == structUart)
	{
		NVIC_SetPriority(UART4_IRQn, 0);
		NVIC_EnableIRQ(UART4_IRQn);
	}
	else if(UART5 == structUart)
	{
		NVIC_SetPriority(UART5_IRQn, 0);
		NVIC_EnableIRQ(UART5_IRQn);
	}

//Enable Interrupt Trigger
	switch(eventFlag)
	{
		case TXE:
			structUart->CR1 |= (1 << TXEIE_BIT_POSITION);
			break;
		case CTS:
			structUart->CR3 |= (1 << CTSIE_BIT_POSITION);
			break;
		case TC:
			structUart->CR1 |= (1 << TCIE_BIT_POSITION);
			break;
		case RXNE:
			structUart->CR1 |= (1 << RXNEIE_BIT_POSITION);
			break;
		case ORE:
			structUart->CR1 |= (1 << RXNEIE_BIT_POSITION);
			break;
		case IDLE:
			structUart->CR1 |= (1 << IDLEIE_BIT_POSITION);
			break;
		case PE:
			structUart->CR1 |= (1 << PEIE_BIT_POSITION);
		case LBD:
			break;
		case NF_ORE_FE:
			structUart->CR3 |= (1 << EIE_BIT_POSITION);
			break;
		default:
			break;
	}
}


