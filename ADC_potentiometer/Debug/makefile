################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ADC_potentiometer.lss \

FLASH_IMAGE += \
ADC_potentiometer.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: ADC_potentiometer.elf secondary-outputs

# Tool invocations
ADC_potentiometer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ADC_potentiometer.map -mmcu=atmega32 -o "ADC_potentiometer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC_potentiometer.lss: ADC_potentiometer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ADC_potentiometer.elf  >"ADC_potentiometer.lss"
	@echo 'Finished building: $@'
	@echo ' '

ADC_potentiometer.hex: ADC_potentiometer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ADC_potentiometer.elf  "ADC_potentiometer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ADC_potentiometer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ADC_potentiometer.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: ADC_potentiometer.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:ADC_potentiometer.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ADC_potentiometer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
