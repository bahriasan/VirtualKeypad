
#include "stm32f407xx.h"
#include "types.h"

typedef struct
{
	uint8 pinNumber;
	uint8 mode;
	uint8 outputType;
	uint8 outputSpeed;
	uint8 pullUp_Down;
	uint8 alternateFunctionNo;
}gpio_cfg;

void Gpio_Init(gpio_cfg configGpio, GPIO_TypeDef* structGpio);
boolean Gpio_Read(uint8 pinNumber, GPIO_TypeDef* structGpio);

#define PIN_0		0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_9		9
#define PIN_10		10
#define PIN_11		11
#define PIN_12		12

#define GPIO_MODE_INPUT			0
#define GPIO_MODE_OUTPUT		1
#define GPIO_MODE_ALTERNATE		2
#define GPIO_MODE_ANALOG		3

#define OUTPUT_PUSH_PULL		0
#define OUTPUT_OPEN_DRAIN		1
#define	OUTPUT_TYPE_NA			2

#define OUTPUT_SPEED_LOW			0
#define OUTPUT_SPEED_MEDIUM			1
#define OUTPUT_SPEED_HIGH			2
#define OUTPUT_SPEED_VERY_HIGH		3
#define OUTPUT_SPEED_NA				4

#define NO_PULL						0
#define PULL_UP						1
#define PULL_DOWN					2

#define	AF0		0
#define	AF1		1
#define	AF2		2
#define	AF3		3
#define	AF4		4
#define	AF5		5
#define	AF6		6
#define	AF7		7
#define	AF8		8
#define	AF9		9
#define	AF10	10
#define	AF11	11
#define	AF12	12
#define	AF13	13
#define	AF14	14
#define	AF15	15

#define	GPIOAEN_POSITION	0
#define	GPIOBEN_POSITION	1
#define	GPIOCEN_POSITION	2
#define	GPIODEN_POSITION	3
#define	GPIOEEN_POSITION	4
#define	GPIOFEN_POSITION	5
#define	GPIOGEN_POSITION	6
#define	GPIOHEN_POSITION	7
#define	GPIOIEN_POSITION	8



