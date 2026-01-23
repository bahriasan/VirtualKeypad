
#include "stm32f407xx.h"
#include "types.h"

#define CLOCK_SOURCE_HSI		0
#define	CLOCK_SOURCE_HSE		1
#define	CLOCK_SOURCE_PLL		2

#define NO_SOURCE_SELECTED		3
#define HSI_SELECTED			0
#define HSE_SELECTED			1
#define PLL_SELECTED			2

#define	APB1_AHB_DIVIDER_NO		0
#define	APB1_AHB_DIVIDER_2		4
#define	APB1_AHB_DIVIDER_4		5
#define	APB1_AHB_DIVIDER_8		6
#define	APB1_AHB_DIVIDER_16		7

#define	APB2_AHB_DIVIDER_NO		0
#define	APB2_AHB_DIVIDER_2		4
#define	APB2_AHB_DIVIDER_4		5
#define	APB2_AHB_DIVIDER_8		6
#define	APB2_AHB_DIVIDER_16		7

#define	AHB_SYS_DIVIDER_NO		0
#define	AHB_SYS_DIVIDER_2		8
#define	AHB_SYS_DIVIDER_4		9
#define	AHB_SYS_DIVIDER_8		10
#define	AHB_SYS_DIVIDER_16		11
#define	AHB_SYS_DIVIDER_64		12
#define	AHB_SYS_DIVIDER_128		13
#define	AHB_SYS_DIVIDER_256		14
#define	AHB_SYS_DIVIDER_512		15

//RCC_CR Register Bit Positions
#define HSI_POSITION			0
#define	HSE_POSITION			16
#define	PLL_POSITION			24

//RCC_CFGR Register Bit Positions
#define SW_POSITION				0
#define SWS_POSITION			2
#define AHB_POSITION			4
#define APB1_POSITION			10
#define	APB2_POSITION			13

//RCC_PLLCFGR Register Bit Positions
#define PLLM_POSITION			0
#define PLLN_POSITION			6
#define PLLP_POSITION			16
#define PLLSRC_POSITION			22
#define PLLQ_POSITION			24

//PLLSRC
#define PLLSRC_HSI				0
#define PLLSRC_HSE				1

//PLLTYPE
#define NO_PLL					0
#define PLL_USB					1
#define PLL_I2C					2
#define PLL_SAI1				3
#define PLL_SAI2				4
#define PLL_LCD					5

typedef struct
{
	uint8 systemClockSource;
	uint8 prescaler_APB1;
	uint8 prescaler_APB2;
	uint8 prescaler_AHB;
	uint8 PLLType;
	uint8 PLLSrc;
	uint16 PLL_M;
	uint16 PLL_N;
	uint16 PLL_P;
	uint16 PLL_Q;
	uint16 PLL_R;
}system_cfg;

void SystemClockConfig(system_cfg configSystem);
