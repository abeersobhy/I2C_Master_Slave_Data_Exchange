/*
 * Keypad.h
 *  Author: Abeer Sobhy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "gpio.h"

#define COL_PORT 		GPIOB
#define ROW_PORT		GPIOA

#define COL1_PIN		GPIOx_PIN_11
#define COL2_PIN        GPIOx_PIN_10
#define COL3_PIN        GPIOx_PIN_1
#define COL4_PIN        GPIOx_PIN_0

#define ROW1_PIN		GPIOx_PIN_4
#define ROW2_PIN        GPIOx_PIN_5
#define ROW3_PIN        GPIOx_PIN_6
#define ROW4_PIN        GPIOx_PIN_7

/*======================================================================================================*/

#define COL1(val) if(val == 0)  CLR_BIT(COL_PORT->ODR,COL1_PIN);  else  SET_BIT(COL_PORT->ODR,COL1_PIN);
#define COL2(val) if(val == 0)  CLR_BIT(COL_PORT->ODR,COL2_PIN);  else  SET_BIT(COL_PORT->ODR,COL2_PIN);
#define COL3(val) if(val == 0)  CLR_BIT(COL_PORT->ODR,COL3_PIN);  else  SET_BIT(COL_PORT->ODR,COL3_PIN);
#define COL4(val) if(val == 0)  CLR_BIT(COL_PORT->ODR,COL4_PIN);  else  SET_BIT(COL_PORT->ODR,COL4_PIN);

#define ROW1()  GET_BIT(ROW_PORT->IDR,ROW1_PIN)
#define ROW2()  GET_BIT(ROW_PORT->IDR,ROW2_PIN)
#define ROW3()  GET_BIT(ROW_PORT->IDR,ROW3_PIN)
#define ROW4()  GET_BIT(ROW_PORT->IDR,ROW4_PIN)

/*****************************************************************************
* Function Name: Keypad_Init
* Purpose      : initialize keypad pins
* Parameters   : void
* Return value : void
*****************************************************************************/
void Keypad_Init(void);
/*****************************************************************************
* Function Name: keypad_Read.
* Purpose      : Read_pressed key of keypad buttons.
* Parameters   : void
* Return value : number of the pressed button.
*****************************************************************************/
uint8_t Keypad_Read();
#endif /* KEYPAD_H_ */
