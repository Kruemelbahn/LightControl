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
../Belebtes_Haus_mit_TV_Attiny.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Belebtes_Haus_mit_TV_Attiny.o

OBJS_AS_ARGS +=  \
Belebtes_Haus_mit_TV_Attiny.o

C_DEPS +=  \
Belebtes_Haus_mit_TV_Attiny.d

C_DEPS_AS_ARGS +=  \
Belebtes_Haus_mit_TV_Attiny.d

OUTPUT_FILE_PATH +=Belebtes_Haus_mit_TV_Attiny.elf

OUTPUT_FILE_PATH_AS_ARGS +=Belebtes_Haus_mit_TV_Attiny.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./Belebtes_Haus_mit_TV_Attiny.o: .././Belebtes_Haus_mit_TV_Attiny.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DNDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.172\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=attiny45 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.172\gcc\dev\attiny45" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Belebtes_Haus_mit_TV_Attiny.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=attiny45 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.3.172\gcc\dev\attiny45"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Belebtes_Haus_mit_TV_Attiny.elf" "Belebtes_Haus_mit_TV_Attiny.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Belebtes_Haus_mit_TV_Attiny.elf" "Belebtes_Haus_mit_TV_Attiny.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Belebtes_Haus_mit_TV_Attiny.elf" > "Belebtes_Haus_mit_TV_Attiny.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Belebtes_Haus_mit_TV_Attiny.elf" "Belebtes_Haus_mit_TV_Attiny.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Belebtes_Haus_mit_TV_Attiny.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Belebtes_Haus_mit_TV_Attiny.elf" "Belebtes_Haus_mit_TV_Attiny.a" "Belebtes_Haus_mit_TV_Attiny.hex" "Belebtes_Haus_mit_TV_Attiny.lss" "Belebtes_Haus_mit_TV_Attiny.eep" "Belebtes_Haus_mit_TV_Attiny.map" "Belebtes_Haus_mit_TV_Attiny.srec" "Belebtes_Haus_mit_TV_Attiny.usersignatures"
	