/*
 * Keypad.c
 *  Author: Abeer Sobhy.
 */ 
#include "Keypad.h"

const uint8_t keypad_matrix[] = 
{
	7   , 8 ,  9   , 'C',
	4   , 5 ,  6   , '/',
	1   , 2 ,  3   , '*',
	'=' , 0 , '.'  , '+',
};
void Keypad_Init(void)
{

	GPIO_Pin_Config Pin;

	Pin.GPIO_PinNumber = GPIOx_PIN_4;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOA , &Pin);


	Pin.GPIO_PinNumber = GPIOx_PIN_5;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOA , &Pin);

	Pin.GPIO_PinNumber = GPIOx_PIN_6;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOA , &Pin);

	Pin.GPIO_PinNumber = GPIOx_PIN_7;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOA , &Pin);
	/*===========================================================*/
	Pin.GPIO_PinNumber = GPIOx_PIN_11;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB , &Pin);


	Pin.GPIO_PinNumber = GPIOx_PIN_10;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB , &Pin);

	Pin.GPIO_PinNumber = GPIOx_PIN_1;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB , &Pin);

	Pin.GPIO_PinNumber = GPIOx_PIN_0;
	Pin.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	Pin.GPIO_PinSpeed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB , &Pin);

	MCAL_GPIO_WritePin(GPIOA, GPIOx_PIN_4, TRUE);
	MCAL_GPIO_WritePin(GPIOA, GPIOx_PIN_5, TRUE);
	MCAL_GPIO_WritePin(GPIOA, GPIOx_PIN_6, TRUE);
	MCAL_GPIO_WritePin(GPIOA, GPIOx_PIN_7, TRUE);

	MCAL_GPIO_WritePin(GPIOB, GPIOx_PIN_11, TRUE);
	MCAL_GPIO_WritePin(GPIOB, GPIOx_PIN_10, TRUE);
	MCAL_GPIO_WritePin(GPIOB, GPIOx_PIN_1, TRUE);
	MCAL_GPIO_WritePin(GPIOB, GPIOx_PIN_0, TRUE);

}
uint8_t Keypad_Read()
{
	uint8_t i;


	for(i = 0; i < 4; i++)
	{
		switch(i)
		{
			case 0: COL1(0); COL2(1); COL3(1); COL4(1); break;
			case 1: COL1(1); COL2(0); COL3(1); COL4(1); break;
			case 2: COL1(1); COL2(1); COL3(0); COL4(1); break;
			case 3: COL1(1); COL2(1); COL3(1); COL4(0); break;
		}
		if(ROW1() == 0) return keypad_matrix[i];
		if(ROW2() == 0) return keypad_matrix[4+i];
		if(ROW3() == 0) return keypad_matrix[8+i];
		if(ROW4() == 0) return keypad_matrix[12+i];

		delay_ms(1);
	}
	return -1;
} 
