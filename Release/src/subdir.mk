################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/whiteblacklist.cpp \
../src/whiteblacklist_test.cpp 

OBJS += \
./src/whiteblacklist.o \
./src/whiteblacklist_test.o 

CPP_DEPS += \
./src/whiteblacklist.d \
./src/whiteblacklist_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


