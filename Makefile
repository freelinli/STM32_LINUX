TARGET=app
CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
NOT_INCLUDE_DIR=demo
RM=rm -f
CORE=3
CPUFLAGS=-mthumb -mcpu=cortex-m$(CORE)
LDFLAGS = -T stm32_flash.ld -Wl,-cref,-u,Reset_Handler -Wl,-Map=$(TARGET).map -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x80 -Wl,--start-group -lc -lm -Wl,--end-group
CFLAGS=$(INCFLAGS) -D STM32F10X_HD -D USE_STDPERIPH_DRIVER -g -o
PWD=$(shell pwd)

INCFLAGS=-I $(PWD)/cmsis -I $(PWD)/lib/inc -I $(PWD)/user
C_SRC=$(shell find . -path ./$(NOT_INCLUDE_DIR)  -prune -o -type f -name '*.c' -print)
C_OBJ=$(C_SRC:%.c=%.o)

START_SRC=$(shell find ./ -name 'startup_stm32f10x_hd.s')
START_OBJ=$(START_SRC:%.s=%.o)

all:bin

$(TARGET):$(START_OBJ) $(C_OBJ)
	$(CC) $^ $(CPUFLAGS) $(LDFLAGS) $(CFLAGS) $(TARGET).elf
$(C_OBJ):%.o:%.c
	$(CC) -c $^ $(CPUFLAGS) $(CFLAGS) $@

$(START_OBJ):$(START_SRC)
	$(CC) -c $^ $(CPUFLAGS) $(CFLAGS) $@
bin:$(TARGET)
	$(OBJCOPY) $(TARGET).elf $(TARGET).bin
hex:
	$(OBJCOPY) $(TARGET).elf -Oihex $(TARGET).hex
clean:
	$(RM) $(shell find ./ -name '*.o') $(TARGET).* *~
download:
	openocd  -f /usr/local/share/openocd/scripts/interface/stlink-v2.cfg  -f /usr/local/share/openocd/scripts/target/stm32f1x.cfg -c init -c halt -c "flash write_image erase $(PWD)/$(TARGET).bin" -c reset -c shutdown 
