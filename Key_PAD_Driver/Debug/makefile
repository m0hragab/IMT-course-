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
Key_PAD_Driver.lss \

FLASH_IMAGE += \
Key_PAD_Driver.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Key_PAD_Driver.elf secondary-outputs

# Tool invocations
Key_PAD_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Key_PAD_Driver.map -mmcu=atmega32 -o "Key_PAD_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Key_PAD_Driver.lss: Key_PAD_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Key_PAD_Driver.elf  >"Key_PAD_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Key_PAD_Driver.hex: Key_PAD_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Key_PAD_Driver.elf  "Key_PAD_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Key_PAD_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Key_PAD_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Key_PAD_Driver.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Key_PAD_Driver.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Key_PAD_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
