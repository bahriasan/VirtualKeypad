#ifndef UART_H
#define UART_H


#include "stm32f407xx.h"
#include "types.h"

typedef struct
{
	uint8 stopBit;
	uint8 mBit;
	uint8 parityControl;
	uint8 controlFlow;
	uint8 over8Bit;
	uint16 baudRate;
}uart_cfg;

//#define F_CLK			(uint32)16000000

#define STOPBIT_1		0
#define STOPBIT_0_5		1
#define STOPBIT_2		2
#define	STOPBIT_1_5		3

#define MBIT_8			0
#define MBIT_9			1

#define	BAUDRATE_1_2K		12
#define	BAUDRATE_2_4K		24
#define	BAUDRATE_9_6K		96
#define	BAUDRATE_19_2K		192
#define	BAUDRATE_38_4K		384
#define	BAUDRATE_57_6K		576
#define	BAUDRATE_115_2K		1152
#define	BAUDRATE_230_4K		2304
#define	BAUDRATE_460_8K		4608
#define	BAUDRATE_921_6K		9216
#define	BAUDRATE_2M			20000u
#define	BAUDRATE_3M			30000

#define PARITY_EVEN		0
#define	PARITY_ODD		1
#define	PARITY_NO		2

#define OVER8_DIS		0
#define	OVER8_EN		1

#define	RTS_CTS_DISABLE				0
#define	RTS_ENABLE_CTS_DISABLE		1
#define CTS_ENABLE_RTS_DISABLE		2
#define	RTS_CTS_ENABLE				3

//RCC_APB1ENR Register Bit Positions
#define USART2_ENABLE_POSITION		17
#define USART3_ENABLE_POSITION		18
#define UART4_ENABLE_POSITION		19
#define UART5_ENABLE_POSITION		20

//RCC_APB2ENR Register Bit Positions
#define USART1_ENABLE_POSITION		4
#define USART6_ENABLE_POSITION		5

//RCC_APB1RSTR Register Bit Positions
#define USART2_RESET_POSITION		17
#define USART3_RESET_POSITION		18
#define UART4_RESET_POSITION		19
#define UART5_RESET_POSITION		20

//RCC_APB2RSTR Register Bit Positions
#define USART1_RESET_POSITION		4
#define USART6_RESET_POSITION		5

//USART_SR Register Bit Positions
#define PE_BIT_POSITION				0u
#define FE_BIT_POSITION				1u
#define NF_BIT_POSITION				2u
#define ORE_BIT_POSITION			3u
#define IDLE_BIT_POSITION			4u
#define RXNE_BIT_POSITION			5u
#define	TC_BIT_POSITION				6u
#define	TXE_BIT_POSITION			7u
#define LBD_BIT_POSITION			8u
#define	CTS_BIT_POSITION			9u

//USART_CR1 Register Bit Positions
#define RECEIVE_ENABLE_BIT_POSITION		2
#define TRANSMIT_ENABLE_BIT_POSITION	3
#define IDLEIE_BIT_POSITION				4
#define RXNEIE_BIT_POSITION				5
#define TCIE_BIT_POSITION				6
#define TXEIE_BIT_POSITION				7
#define PEIE_BIT_POSITION				8
#define	PARITY_SELECTION_BIT_POSITION	9
#define PARITY_ENABLE_BIT_POSITION		10
#define M_BIT_POSITION					12
#define USART_ENABLE_BIT_POSITION		13
#define OVER8_BIT_POSITION				15

//USART_CR2 Register Bit Positions
#define LBDIE_BIT_POSITION			6

//USART_BRR Bit Register Positions
#define FRACTION_BIT_POSITION		0
#define MANTISSA_BIT_POSITION		4
#define STOP_BIT_POSITION			12

//USART_CR3	Bit Register Positions
#define EIE_BIT_POSITION			0
#define	RTSE_BIT_POSITION			8
#define	CTSE_BIT_POSITION			9
#define CTSIE_BIT_POSITION			10

//USART Interrupts
typedef enum
{
	TXE=0,
	CTS,
	TC,
	RXNE,
	ORE,
	IDLE,
	PE,
	LBD,
	NF_ORE_FE
}Uart_interrupt;

#define SR_MASK(X)		(uint32)(1u << X)


void Uart_Init(uart_cfg configUart, USART_TypeDef* structUart);
void Uart_Read(uint8* readData, USART_TypeDef* structUart);
void Uart_Write(uint8* writeDataBuffer, USART_TypeDef* structUart, uint32 size);
void Uart_Write_Inst(uint8* writeDataBuffer, USART_TypeDef* structUart, uint32 size);
void Uart_Read_Inst(uint8* readDataBuffer, USART_TypeDef* structUart);
void Uart_EnableInterrupt(USART_TypeDef* structUart, Uart_interrupt eventFlag);
void Uart_IRQHandler(void);


#endif
