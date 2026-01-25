/*
 * App.h
 *
 *  Created on: 22 Oca 2026
 *      Author: bahri
 */

#ifndef APP_H_
#define APP_H_

#include "gpio.h"
#include "keyboardUsageTag.h"

#define EXTI_ARRAY_SIZE			16u
#define INPUT_ARRAY_SIZE		36u

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}pinNo_type;

typedef enum
{
	FALLING_EDGE,
	RISING_EDGE
}trigger_type;

typedef struct
{
	pinNo_type pinNumber;
	GPIO_TypeDef* gpioPort;
	trigger_type intType;
}exti_t;

typedef struct
{
	pinNo_type pinNumber;
	GPIO_TypeDef* gpioPort;
	KeyCode_type keyCode;
}input_type;

typedef enum
{
	E_OK,
	E_NOT_OK
}Std_ReturnType;

void Exti_Init(void);
void Input_Init(void);
void InputPolling(void);

extern uint8 USB_buffer[8];

#endif /* APP_H_ */
