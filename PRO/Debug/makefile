################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TIMER/MCAL/TIMER0/subdir.mk
-include TIMER/MCAL/Global_Interrupt/subdir.mk
-include TIMER/MCAL/DIO/subdir.mk
-include TIMER/Debug/MCAL/TIMER0/subdir.mk
-include TIMER/Debug/MCAL/Global_Interrupt/subdir.mk
-include TIMER/Debug/MCAL/EXTI/subdir.mk
-include TIMER/Debug/MCAL/DIO/subdir.mk
-include TIMER/Debug/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/EXIT_interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Ultrasonic_Sensor/subdir.mk
-include HAL/Push_button/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Buzzer/subdir.mk
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
PRO.lss \

FLASH_IMAGE += \
PRO.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PRO.elf secondary-outputs

# Tool invocations
PRO.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PRO.map -mmcu=atmega32 -o "PRO.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PRO.lss: PRO.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PRO.elf  >"PRO.lss"
	@echo 'Finished building: $@'
	@echo ' '

PRO.hex: PRO.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PRO.elf  "PRO.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PRO.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PRO.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PRO.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
