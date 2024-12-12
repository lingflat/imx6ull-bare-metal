TOOL_CHAIN = arm-linux-gnueabihf-
CC = ${TOOL_CHAIN}gcc
AS = ${TOOL_CHAIN}as
LD = ${TOOL_CHAIN}ld
OBJCOPY = ${TOOL_CHAIN}objcopy
OBJDUMP = $(TOOL_CHAIN)objdump

CFLAGS          := -Wall -g -fno-builtin -gdwarf-2 -gstrict-dwarf -Iinclude -mcpu=cortex-a7
LDFLAGS         := -g

objs := ./src/start.o \
        ./src/main.o \
        ./src/led.o \
        ./src/delay.o 

imx6ull.bin: $(objs)
	#${LD} -T imx6ull.ld -o imx6ull.elf $^     #请查明$^ 到底是啥意思为什么用 $^ 就链接失败
	${LD} -T imx6ull.ld -o imx6ull.elf $(objs)
	${OBJCOPY} -O binary -S imx6ull.elf $@
	${OBJDUMP} -D -m arm imx6ull.elf > imx6ull.dis
	make -C debug

%.o:%.c
	${CC} $(CFLAGS) -c -o $@ $<

%.o:%.s
	${CC}  $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(objs) *.elf *.bin *.dis
	make -C debug clean
