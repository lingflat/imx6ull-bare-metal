ENTRY(_start)
SECTIONS
{
        . = 0x80000000;
        .startup . : { ./src/start.o(.text) }
        .text : { *(.text) }
        .rodata ALIGN(4) : {*(.rodata*)}
        .data ALIGN(4)   : { *(.data) }
        __bss_start = .;
        .bss ALIGN(4)  : { *(.bss)}
        __bss_end = .;
        .rel.plt :
        {
                *(.rel.plt)
        }

}
