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
Delay_timer_function.lss \

FLASH_IMAGE += \
Delay_timer_function.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Delay_timer_function.elf secondary-outputs

# Tool invocations
Delay_timer_function.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Delay_timer_function.map -mmcu=atmega32 -o "Delay_timer_function.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Delay_timer_function.lss: Delay_timer_function.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Delay_timer_function.elf  >"Delay_timer_function.lss"
	@echo 'Finished building: $@'
	@echo ' '

Delay_timer_function.hex: Delay_timer_function.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Delay_timer_function.elf  "Delay_timer_function.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Delay_timer_function.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Delay_timer_function.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Delay_timer_function.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Delay_timer_function.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Delay_timer_function.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
