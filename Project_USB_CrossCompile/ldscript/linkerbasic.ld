MEMORY
{
	FLASH (rx): ORIGIN = 0x08000000, LENGTH = 128K
	RAM (rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

__stack = ORIGIN(RAM) + LENGTH(RAM);
_estack = __stack;

__Main_Stack_Size = 1024;
PROVIDE (_Main_Stack_Size = __Main_Stack_Size); 
__Main_Stack_Limit = __stack - __Main_Stack_Size;

__Minimum_Stack_Size = 256;
PROVIDE (_Heap_Begin = _sheap);
PROVIDE (_Heap_Limit = __stack - __Main_Stack_Size);

ENTRY(_start)

SECTIONS
{
	.isr_vector : ALIGN(4)
	{
		FILL(0xFF)
		KEEP(*(.isr_vector))
	} > FLASH
	
	.text : ALIGN(4)
	{
		*(.text .text.*)
		*(.rodata .rodata.* .constdata .constdata.*)
		*(vtable)
	} > FLASH
	
	_sidata = LOADADDR(.data);
	
	.data : ALIGN(4)
	{
		_sdata = (.);
		*(.data .data.*)
		. = ALIGN(4);
		_edata = (.);
	} > RAM AT > FLASH
	
	.bss (NOLOAD) : ALIGN(4)
	{
		__bss_start__ = (.);
		_sbss = (.);
		*(.bss .bss.*)
		. = ALIGN(4);
		_ebss = (.);
		__bss_end__ = (.);
		_sheap = (.);
	} > RAM
}






