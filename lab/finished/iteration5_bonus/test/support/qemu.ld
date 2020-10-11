/******************************************************************************
 *
 * Linker script for applications using startup.c
 *
 *****************************************************************************/

/* Following symbols must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * Following symbols can be used without definition:
 *   __exidx_start
 *   __exidx_end
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 */

    ENTRY(ResetISR)

    MEMORY
    {
        FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
        RAM (rwx) : ORIGIN = 0x20000000,  LENGTH = 128K    /* This Appears To Be Maximum */
    }

    SECTIONS
    {
        .text :
        {
            KEEP(*(.isr_vector))
            *(.text*)

            KEEP(*(.init))
            KEEP(*(.fini))

            /* .ctors */
            *crtbegin.o(.ctors)
            *crtbegin?.o(.ctors)
            *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
            *(SORT(.ctors.*))
            *(.ctors)

            /* .dtors */
            *crtbegin.o(.dtors)
            *crtbegin?.o(.dtors)
            *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
            *(SORT(.dtors.*))
            *(.dtors)

            *(.rodata*)

            KEEP(*(.eh_frame*))
        } > FLASH

        .ARM.extab :
        {
            *(.ARM.extab* .gnu.linkonce.armextab.*)
        } > FLASH

        __exidx_start = .;
        .ARM.exidx :
        {
            *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        } > FLASH
        __exidx_end = .;

        __etext = .;

        .data : AT (__etext)
        {
            __data_start__ = .;
            Image$$RW_IRAM1$$Base = .;
            *(vtable)
            *(.data*)

            . = ALIGN(4);
            /* preinit data */
            PROVIDE (__preinit_array_start = .);
            KEEP(*(.preinit_array))
            PROVIDE (__preinit_array_end = .);

            . = ALIGN(4);
            /* init data */
            PROVIDE (__init_array_start = .);
            KEEP(*(SORT(.init_array.*)))
            KEEP(*(.init_array))
            PROVIDE (__init_array_end = .);

            . = ALIGN(4);
            /* finit data */
            PROVIDE (__fini_array_start = .);
            KEEP(*(SORT(.fini_array.*)))
            KEEP(*(.fini_array))
            PROVIDE (__fini_array_end = .);

            . = ALIGN(4);
            /* All data end */
            __data_end__ = .;

        } > RAM

        .bss :
        {
            __bss_start__ = .;
            *(.bss*)
            *(COMMON)
            __bss_end__ = .;
            Image$$RW_IRAM1$$ZI$$Limit = . ;
        } > RAM

        .heap :
        {
            __end__ = .;
            end = __end__;
            *(.heap*)
            __HeapLimit = .;
        } > RAM

	end = .;
    }

