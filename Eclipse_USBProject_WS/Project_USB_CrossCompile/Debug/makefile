################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/src/cmsis/subdir.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Project_USB_CrossCompile
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: Project_USB_CrossCompile.elf

# Tool invocations
Project_USB_CrossCompile.elf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-none-eabi-gcc -L"C:\Users\bahri\Y_GitHub\VirtualKeypad\Eclipse_USBProject_WS\Project_USB_CrossCompile\ldscript" -T linkerbasic.ld -nostartfiles -Wl,-Map,"Project_Cross.map" --specs=nosys.specs -Xlinker --gc-sections -o "Project_USB_CrossCompile.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Project_USB_CrossCompile.elf
	-@echo ' '

post-build:
	-arm-none-eabi-objcopy -O binary "Project_USB_CrossCompile.elf" "Project_USB_CrossCompile.bin"
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
