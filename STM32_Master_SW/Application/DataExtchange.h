/*
 * DataExtchange.h
 *  Created on: Nov 12, 2025
 *  Author: Abeer Sobhy
 */

#ifndef DATAEXTCHANGE_H_
#define DATAEXTCHANGE_H_

#include "I2C.h"
#include "LCD.h"
#include "Keypad.h"

#define Slave_Address	0x2A


void Init_DataExchange();
void Start_DataExchange();

#endif /* DATAEXTCHANGE_H_ */
