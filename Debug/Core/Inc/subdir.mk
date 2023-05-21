################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/fsm.c \
../Core/Inc/read_signals.c \
../Core/Inc/xbee.c 

OBJS += \
./Core/Inc/fsm.o \
./Core/Inc/read_signals.o \
./Core/Inc/xbee.o 

C_DEPS += \
./Core/Inc/fsm.d \
./Core/Inc/read_signals.d \
./Core/Inc/xbee.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o Core/Inc/%.su Core/Inc/%.cyclo: ../Core/Inc/%.c Core/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/fsm.cyclo ./Core/Inc/fsm.d ./Core/Inc/fsm.o ./Core/Inc/fsm.su ./Core/Inc/read_signals.cyclo ./Core/Inc/read_signals.d ./Core/Inc/read_signals.o ./Core/Inc/read_signals.su ./Core/Inc/xbee.cyclo ./Core/Inc/xbee.d ./Core/Inc/xbee.o ./Core/Inc/xbee.su

.PHONY: clean-Core-2f-Inc

