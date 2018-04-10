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
Intensity_controler.lss \

FLASH_IMAGE += \
Intensity_controler.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Intensity_controler.elf secondary-outputs

# Tool invocations
Intensity_controler.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Intensity_controler.map -mmcu=atmega32 -o "Intensity_controler.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Intensity_controler.lss: Intensity_controler.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Intensity_controler.elf  >"Intensity_controler.lss"
	@echo 'Finished building: $@'
	@echo ' '

Intensity_controler.hex: Intensity_controler.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Intensity_controler.elf  "Intensity_controler.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Intensity_controler.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Intensity_controler.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Intensity_controler.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:Intensity_controler.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Intensity_controler.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
