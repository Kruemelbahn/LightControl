################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../LaufLicht_ATiny13.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
LaufLicht_ATiny13.o

OBJS_AS_ARGS +=  \
LaufLicht_ATiny13.o

C_DEPS +=  \
LaufLicht_ATiny13.d

C_DEPS_AS_ARGS +=  \
LaufLicht_ATiny13.d

OUTPUT_FILE_PATH +=LaufLicht_ATiny13.elf

OUTPUT_FILE_PATH_AS_ARGS +=LaufLicht_ATiny13.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./LaufLicht_ATiny13.o: .././LaufLicht_ATiny13.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.0.78\include" -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.8.332\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=attiny13a -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.8.332\gcc\dev\attiny13a" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="LaufLicht_ATiny13.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=attiny13a -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.8.332\gcc\dev\attiny13a"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "LaufLicht_ATiny13.elf" "LaufLicht_ATiny13.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "LaufLicht_ATiny13.elf" "LaufLicht_ATiny13.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "LaufLicht_ATiny13.elf" > "LaufLicht_ATiny13.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "LaufLicht_ATiny13.elf" "LaufLicht_ATiny13.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "LaufLicht_ATiny13.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "LaufLicht_ATiny13.elf" "LaufLicht_ATiny13.a" "LaufLicht_ATiny13.hex" "LaufLicht_ATiny13.lss" "LaufLicht_ATiny13.eep" "LaufLicht_ATiny13.map" "LaufLicht_ATiny13.srec" "LaufLicht_ATiny13.usersignatures"
	