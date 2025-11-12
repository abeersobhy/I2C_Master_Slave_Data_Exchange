/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abeer Sobhy
 * @brief          : Main program body
 ******************************************************************************
 */

#include "DataExtchange.h"

int main(void)
{

	Init_DataExchange();
	while(1)
	{
		Start_DataExchange();
	}
}
