MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 128K
	RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 20K
	
	CCMRAM (xrw) : ORIGIN = 0x10000000, LENGTH = 0
	FLASHB1 (rx) : ORIGIN = 0x00000000, LENGTH = 0
	EXTMEMB0 (rx) : ORIGIN = 0x00000000, LENGTH = 0
	EXTMEMB1 (rx) : ORIGIN = 0x00000000, LENGTH = 0
	EXTMEMB2 (rx) : ORIGIN = 0x00000000, LENGTH = 0
	EXTMEMB3 (rx) : ORIGIN = 0x00000000, LENGTH = 0
}

__stack = ORIGIN(RAM) + LENGTH(RAM);
_estack = __stack;

__Main_Stack_Size = 1024;
PROVIDE (_Main_Stack_Size = __Main_Stack_Size);
__Main_Stack_Limit = __stack - __Main_Stack_Size;

_Minimum_Stack_Size = 256;

PROVIDE (_Heap_Begin = _end_noinit);
PROVIDE (_Heap_Limit = __stack - __Main_Stack_Size); 

ENTRY(_start)

SECTIONS
{
	.isr_vector : ALIGN(4)						/*Align to 4 Bytes, 32 Bits*/
	{
		FILL(0xFF) 								/*Fill empty places with 0xFF*/
		
		__vectors_start = ABSOLUTE(.);
		__vectors_start__ = ABSOLUTE(.);
		
		KEEP(*(.isr_vector))
		KEEP(*(.cfmconfig)) 
	} > FLASH
	
	.inits : ALIGN(4)
	{
		__data_regions_array_start = .;
		
		LONG(LOADADDR(.data));					/*Addr for init values of data*/
		LONG(ADDR(.data));					
		LONG(ADDR(.data)+SIZEOF(.data));
		
		LONG(LOADADDR(.data_CCMRAM));			/*Addr for init values of data*/
		LONG(ADDR(.data_CCMRAM));
		LONG(ADDR(.data_CCMRAM)+SIZEOF(.data_CCMRAM));		
		
		__data_regions_array_end = .;
		
		__bss_regions_array_start = .;
		
		LONG(ADDR(.bss));
		LONG(ADDR(.bss)+SIZEOF(.bss));
		
		LONG(ADDR(.bss_CCMRAM));
		LONG(ADDR(.bss_CCMRAM)+SIZEOF(.bss_CCMRAM));
		
		__bss_regions_array_end = .;
		
		KEEP(*(.init))
		KEEP(*(.fini))
		. = ALIGN(4);
		
		PROVIDE_HIDDEN(__preinit_array_start = .);
		
		KEEP(*(.preinit_array_sysinit .preinit_array_sysinit.*))		/*System Init*/
		KEEP(*(.preinit_array_platform .preinit_array_platform.*))		/*Platform Init*/
		KEEP(*(.preinit_array .preinit_array.*))						/*Application Init*/
		
		PROVIDE_HIDDEN(__preinit_array_end = .);
		. = ALIGN(4);
		
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);
		
		. = ALIGN(4);	
		
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);
	} >FLASH
	
	.flashtext : ALIGN(4)								/* Startup Code */
	{
		*(.flashtext .flashtext.*)						
	} >FLASH
	
	.text : ALIGN(4)									/* Code */
	{
		*(.text .text.*)								/* All remaining code */
		
		*(.rodata .rodata.* .constdata .constdata.*)	/* read only data */
		
		*(vtable)
		
		KEEP(*(.eh_frame*))
		
		*(.glue_7)
		*(.glue_7t)
	} >FLASH
	
	/* ARM Magic Sections */
	
	.ARM.extab : ALIGN(4)							
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} >FLASH
	
	. = ALIGN(4);
	
	__exidx_start = .;
	.ARM.exidx : ALIGN(4)
	{
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	} >FLASH
	__exidx_end = .;
	
	. = ALIGN(4);
	_etext = .;
	__etext = .;
	
	/* MEMORY ARRAY */
	
	.ROarraySection :
	{
		*(.ROarraySection .ROarraySection.*)
	} >MEMORY_ARRAY
	
	.data_CCMRAM : ALIGN(4)
	{
		FILL(0xFF)
		*(.data_CCMRAM .data.CCMRAM.*)
		. = ALIGN(4);		
	} >CCMRAM AT>FLASH
	
	_sidata = LOADADDR(.data);
	
	/* Initialized Data Section */
	
	.data : ALIGN(4)
	{
		FILL(0xFF)
		_sdata = .;
		__data_start__ = .;
		*(.data_begin .data_begin.*)
		*(.data .data.*)
		*(.data_end .data_end.*)
		
		. = ALIGN(4);
		_edata = .;
		__data_end__ = .;
	} >RAM AT>FLASH 
	
	/* Uninitialized Data Section */
	
	.bss_CCMRAM (NOLOAD) : ALIGN(4)
	{
		*(.bss.CCMRAM .bss.CCMRAM.*)
	} >CCMRAM 
	
	.bss (NOLOAD) : ALIGN(4)
	{
		__bss_start__ = .;
		_sbss = .;
		*(.bss_begin .bss_begin.*)
		*(.bss .bss.*)
		*(COMMON)
		*(.bss_end .bss_end.*)
		
		. = ALIGN(4);
		__bss_end__ = .;
		_ebss = .;
	} >RAM
	
	.noinit_CCMRAM (NOLOAD) : ALIGN(4)
	{
		*(.noinit.CCMRAM .noinit.CCMRAM.*)
	} >CCMRAM
	
	.noinit (NOLOAD) : ALIGN(4)
	{
		_noinit = .;
		*(.noinit .noinit.*)
		
		. = ALIGN(4);
		_end_noinit = .;		
	} >RAM
	
	PROVIDE (end = _end_noinit);
	PROVIDE (_end = _end_noinit);
	PROVIDE (__end = _end_noinit);
	PROVIDE (__end__ = _end_noinit);
	
	/* Check Stack Size */
	
	._check_stack : ALIGN(4)
	{
		. = . + _Minimum_Stack_Size;
	} >RAM
	
	.b1text : ALIGN(4)
	{
		*(.b1text)
		*(.b1rodata)
		*(.b1rodata.*)
	} >FLASHB1
	
	/* External Memory */
	
	.eb1text : ALIGN(4)
	{
		*(.eb1text)
		*(.eb1rodata)
		*(.eb1rodara.*)
	} >EXTMEMB1
	
		.eb2text : ALIGN(4)
	{
		*(.eb2text)
		*(.eb2rodata)
		*(.eb2rodara.*)
	} >EXTMEMB2
	
		.eb3text : ALIGN(4)
	{
		*(.eb3text)
		*(.eb3rodata)
		*(.eb3rodara.*)
	} >EXTMEMB3
	
	
}