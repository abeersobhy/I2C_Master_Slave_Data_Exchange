################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad/Keypad.c 

OBJS += \
./HAL/Keypad/Keypad.o 

C_DEPS += \
./HAL/Keypad/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad/%.o HAL/Keypad/%.su: ../HAL/Keypad/%.c HAL/Keypad/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/HAL/Keypad" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/STM32F103_MCAL" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/Application" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/STM32F103_MCAL/EXTI" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/STM32F103_MCAL/GPIO" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/STM32F103_MCAL/I2C" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/STM32F103_MCAL/RCC" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/STM32F103_MCAL/SPI" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/STM32F103_MCAL/UART" -I"F:/Embedded/LearnInDepth/WS/I2C_Master_Slave_Data_Exchange/HAL/LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-Keypad

clean-HAL-2f-Keypad:
	-$(RM) ./HAL/Keypad/Keypad.d ./HAL/Keypad/Keypad.o ./HAL/Keypad/Keypad.su

.PHONY: clean-HAL-2f-Keypad

