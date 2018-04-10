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
Stepper_MOTOR_Driver.lss \

FLASH_IMAGE += \
Stepper_MOTOR_Driver.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Stepper_MOTOR_Driver.elf secondary-outputs

# Tool invocations
Stepper_MOTOR_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Stepper_MOTOR_Driver.map -mmcu=atmega32 -o "Stepper_MOTOR_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Stepper_MOTOR_Driver.lss: Stepper_MOTOR_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Stepper_MOTOR_Driver.elf  >"Stepper_MOTOR_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Stepper_MOTOR_Driver.hex: Stepper_MOTOR_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Stepper_MOTOR_Driver.elf  "Stepper_MOTOR_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Stepper_MOTOR_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Stepper_MOTOR_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Stepper_MOTOR_Driver.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Stepper_MOTOR_Driver.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Stepper_MOTOR_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
