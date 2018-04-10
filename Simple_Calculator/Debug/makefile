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
Simple_Calculator.lss \

FLASH_IMAGE += \
Simple_Calculator.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Simple_Calculator.elf secondary-outputs

# Tool invocations
Simple_Calculator.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Simple_Calculator.map -mmcu=atmega32 -o "Simple_Calculator.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Simple_Calculator.lss: Simple_Calculator.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Simple_Calculator.elf  >"Simple_Calculator.lss"
	@echo 'Finished building: $@'
	@echo ' '

Simple_Calculator.hex: Simple_Calculator.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Simple_Calculator.elf  "Simple_Calculator.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Simple_Calculator.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Simple_Calculator.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Simple_Calculator.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Simple_Calculator.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Simple_Calculator.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
