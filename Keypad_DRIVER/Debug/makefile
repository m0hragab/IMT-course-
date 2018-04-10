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
Keypad_DRIVER.lss \

FLASH_IMAGE += \
Keypad_DRIVER.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Keypad_DRIVER.elf secondary-outputs

# Tool invocations
Keypad_DRIVER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Keypad_DRIVER.map -mmcu=atmega32 -o "Keypad_DRIVER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Keypad_DRIVER.lss: Keypad_DRIVER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Keypad_DRIVER.elf  >"Keypad_DRIVER.lss"
	@echo 'Finished building: $@'
	@echo ' '

Keypad_DRIVER.hex: Keypad_DRIVER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Keypad_DRIVER.elf  "Keypad_DRIVER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Keypad_DRIVER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Keypad_DRIVER.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Keypad_DRIVER.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Keypad_DRIVER.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Keypad_DRIVER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
