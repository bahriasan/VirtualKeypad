################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/cmsis/system_stm32f4xx.c 

S_SRCS += \
../system/src/cmsis/startup.s 

C_DEPS += \
./system/src/cmsis/system_stm32f4xx.d 

OBJS += \
./system/src/cmsis/startup.o \
./system/src/cmsis/system_stm32f4xx.o 


# Each subdirectory must supply rules for building sources it contributes
system/src/cmsis/%.o: ../system/src/cmsis/%.s system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	arm-none-eabi-as -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\system\include\cmsis" -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\system\include" -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\include" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/cmsis/%.o: ../system/src/cmsis/%.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -std=c11 -DSTM32F407xx -DDEBUG -DTRACE -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\include" -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\system\include" -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\system\include\cmsis" -O0 -g3 -Wall -c -fmessage-length=0 -mthumb -mcpu=cortex-m4 -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-system-2f-src-2f-cmsis

clean-system-2f-src-2f-cmsis:
	-$(RM) ./system/src/cmsis/startup.o ./system/src/cmsis/system_stm32f4xx.d ./system/src/cmsis/system_stm32f4xx.o

.PHONY: clean-system-2f-src-2f-cmsis

