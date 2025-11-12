/*
 * DataExchange.c
 *
 *  Created on: Nov 12, 2025
 *  Author: Abeer Sobhy
 */

#include "DataExtchange.h"

void Init_DataExchange()
{
	I2C_Device_Address slave =
	{
		.Addressing_Slave_Mode = Addressing_Slave_Mode_7BIT,
		.DualAddress = DualAddress_Disable,
		.Slave_PrimaryAddress = Slave_Address,
	};
	I2C_Init_t	I2C_Init =
	{
		.I2C_ACK_Control = I2C_ACK_Enable,
		.I2C_ClockSpeed = I2C_SCLK_SM_100K,
		.I2C_GeneralCall_Adressing = I2C_ENGC_Enable,
		.I2C_Master_Slave_Mode = I2C_Master_Enable,
		.I2C_Mode = I2C_Mode_I2C,
		.I2C_SM_OR_FM = I2C_SM_Enable,
		.I2Cx = I2C1,
		.slaveAddressConfig = slave,
	};
	I2Cx_Init(&I2C_Init);
	LCD_Init();
	Keypad_Init();
	LCD_Write_String((uint8_t*)"   Welcome");
}
void Start_DataExchange()
{
	uint8_t pressedKey = 0;
	uint8_t buffer_toReceive[5];

	I2C_Device_Address slave =
	{
		.Addressing_Slave_Mode = Addressing_Slave_Mode_7BIT,
		.DualAddress = DualAddress_Disable,
		.Slave_PrimaryAddress = Slave_Address,
	};

	pressedKey = Keypad_Read();
	if(pressedKey != 255)
	{
		LCD_Write_Command(LCD_Clear);
		LCD_Write_String((uint8_t*)"Key to send: ");
		LCD_Write_Number(pressedKey);
		I2C_Master_TX(I2C1, &slave,  &pressedKey , 1 , Stop, Start_Enable);
		delay_ms(50);
		I2C_Master_RX(I2C1, &slave, buffer_toReceive, 5 , Stop , Start_Enable);
		LCD_Write_Command(LINE_TWO);
		LCD_Write_String((uint8_t*)"R-Mess: ");
		LCD_Write_String(buffer_toReceive);
		delay_ms(500);
	}
}
