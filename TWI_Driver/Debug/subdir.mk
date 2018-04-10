################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dio.c \
../EEPROM_Pro.c \
../LCD_pro.c \
../Main.c \
../TWI_Pro.c 

OBJS += \
./Dio.o \
./EEPROM_Pro.o \
./LCD_pro.o \
./Main.o \
./TWI_Pro.o 

C_DEPS += \
./Dio.d \
./EEPROM_Pro.d \
./LCD_pro.d \
./Main.d \
./TWI_Pro.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


