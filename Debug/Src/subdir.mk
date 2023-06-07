################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/30010_io.c \
../Src/LUTsin.c \
../Src/ansi.c \
../Src/ansiE.c \
../Src/main.c \
../Src/mainE.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f30x.c 

OBJS += \
./Src/30010_io.o \
./Src/LUTsin.o \
./Src/ansi.o \
./Src/ansiE.o \
./Src/main.o \
./Src/mainE.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f30x.o 

C_DEPS += \
./Src/30010_io.d \
./Src/LUTsin.d \
./Src/ansi.d \
./Src/ansiE.d \
./Src/main.d \
./Src/mainE.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f30x.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F302R8Tx -DSTM32F3 -DNUCLEO_F302R8 -DDEBUG -DUSE_STDPERIPH_DRIVER=1 -c -I"C:/Users/alexg/OneDrive/Dokumenter/STM32/BaseProject/SPL/inc" -I"C:/Users/alexg/OneDrive/Dokumenter/STM32/BaseProject/Inc" -I"C:/Users/alexg/OneDrive/Dokumenter/STM32/BaseProject/cmsis" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/30010_io.d ./Src/30010_io.o ./Src/LUTsin.d ./Src/LUTsin.o ./Src/ansi.d ./Src/ansi.o ./Src/ansiE.d ./Src/ansiE.o ./Src/main.d ./Src/main.o ./Src/mainE.d ./Src/mainE.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/system_stm32f30x.d ./Src/system_stm32f30x.o

.PHONY: clean-Src

