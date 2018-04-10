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
segment_count_0_99.lss \

FLASH_IMAGE += \
segment_count_0_99.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: segment_count_0_99.elf secondary-outputs

# Tool invocations
segment_count_0_99.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,segment_count_0_99.map -mmcu=atmega32 -o "segment_count_0_99.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

segment_count_0_99.lss: segment_count_0_99.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S segment_count_0_99.elf  >"segment_count_0_99.lss"
	@echo 'Finished building: $@'
	@echo ' '

segment_count_0_99.hex: segment_count_0_99.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex segment_count_0_99.elf  "segment_count_0_99.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: segment_count_0_99.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 segment_count_0_99.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: segment_count_0_99.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:segment_count_0_99.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) segment_count_0_99.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
