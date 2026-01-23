################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SystemInit.c \
../src/gpio.c \
../src/main.c \
../src/rcc.c \
../src/uart.c \
../src/usb.c \
../src/usbd.c \
../src/usbd_hid.c 

C_DEPS += \
./src/SystemInit.d \
./src/gpio.d \
./src/main.d \
./src/rcc.d \
./src/uart.d \
./src/usb.d \
./src/usbd.d \
./src/usbd_hid.d 

OBJS += \
./src/SystemInit.o \
./src/gpio.o \
./src/main.o \
./src/rcc.o \
./src/uart.o \
./src/usb.o \
./src/usbd.o \
./src/usbd_hid.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -std=c11 -DSTM32F407xx -DDEBUG -DTRACE -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\include" -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\system\include" -I"C:\Users\bahri\eclipse-workspace\Project_USB_CrossCompile\system\include\cmsis" -O0 -g3 -Wall -c -fmessage-length=0 -mthumb -mcpu=cortex-m4 -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/SystemInit.d ./src/SystemInit.o ./src/gpio.d ./src/gpio.o ./src/main.d ./src/main.o ./src/rcc.d ./src/rcc.o ./src/uart.d ./src/uart.o ./src/usb.d ./src/usb.o ./src/usbd.d ./src/usbd.o ./src/usbd_hid.d ./src/usbd_hid.o

.PHONY: clean-src

