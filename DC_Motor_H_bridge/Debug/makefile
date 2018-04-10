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
DC_Motor_H_bridge.lss \

FLASH_IMAGE += \
DC_Motor_H_bridge.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: DC_Motor_H_bridge.elf secondary-outputs

# Tool invocations
DC_Motor_H_bridge.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DC_Motor_H_bridge.map -mmcu=atmega32 -o "DC_Motor_H_bridge.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DC_Motor_H_bridge.lss: DC_Motor_H_bridge.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DC_Motor_H_bridge.elf  >"DC_Motor_H_bridge.lss"
	@echo 'Finished building: $@'
	@echo ' '

DC_Motor_H_bridge.hex: DC_Motor_H_bridge.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DC_Motor_H_bridge.elf  "DC_Motor_H_bridge.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DC_Motor_H_bridge.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DC_Motor_H_bridge.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: DC_Motor_H_bridge.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:DC_Motor_H_bridge.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DC_Motor_H_bridge.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
