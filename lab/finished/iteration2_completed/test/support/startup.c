#include "unity.h"

// UART0 address for Stellaris LM3S6965 eval board
// (Cortex M3 machine emulation option for Qemu)
static volatile unsigned int * const UART0DR = (unsigned int *)0x4000c000;

//*****************************************************************************
//
// startup.c - Startup code for use with GNU tools.
//
//*****************************************************************************

#ifndef STACK_SIZE
#define STACK_SIZE (1024)
#endif

//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************

void ResetISR(void);

static void NmiSR(void);

static void FaultISR(void);

static void IntDefaultHandler(void);

static void SystemReset(void);

//*****************************************************************************
//
// The entry point for the application.
//
//*****************************************************************************

extern int main(void);

//*****************************************************************************
//
// Reserve space for the system stack.
//
//*****************************************************************************

static unsigned char pulStack[STACK_SIZE];

//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//
//*****************************************************************************

__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
    (void (*)(void))((unsigned long)pulStack + sizeof(pulStack)),

                                            // The initial stack pointer
    ResetISR,                               // The reset handler
    NmiSR,                                  // The NMI handler
    FaultISR,                               // The hard fault handler
    IntDefaultHandler,                      // The MPU fault handler
    IntDefaultHandler,                      // The bus fault handler
    IntDefaultHandler,                      // The usage fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    IntDefaultHandler,                      // SVCall handler
    IntDefaultHandler,                      // Debug monitor handler
    0,                                      // Reserved
    IntDefaultHandler,                      // The PendSV handler
    IntDefaultHandler                       // The SysTick handler
};

//*****************************************************************************
//
// The following are constructs created by the linker, indicating where the
// the "data" and "bss" segments reside in memory.  The initializers for the
// "data" segment resides immediately following the "text" segment.
//
//*****************************************************************************

extern unsigned long __etext;
extern unsigned long __data_start__;
extern unsigned long __data_end__;

extern unsigned long __bss_start__;
extern unsigned long __bss_end__;

//*****************************************************************************
//
// This is the code that gets called when the processor first starts execution
// following a reset event.  Only the absolutely necessary set is performed,
// after which the application supplied entry() routine is called.
//
//*****************************************************************************
void ResetISR(void)
{
    unsigned long *pulSrc, *pulDest;

    //
    // Copy the data segment initializers from flash to SRAM.
    //

    pulSrc = &__etext;
    pulDest = &__data_start__;

    while(pulDest < &__data_end__ )
    {
        *pulDest++ = *pulSrc++;
    }

    //
    // Zero fill the bss segment.
    //

    __asm("    ldr     r0, =__bss_start__\n"
          "    ldr     r1, =__bss_end__\n"
          "    mov     r2, #0\n"
          "    .thumb_func\n"
          "zero_loop:\n"
          "        cmp     r0, r1\n"
          "        it      lt\n"
          "        strlt   r2, [r0], #4\n"
          "        blt     zero_loop");

    //
    // Call the application's entry point.
    //
    main();
    SystemReset();
}

//*****************************************************************************
//
// Handle errors by outputting the message and then force a test abort by calling
// system reset.
//
//*****************************************************************************
static void AbortTestWithError(const char* error)
{
    int max_counter = 100;
    char* c = (char*)(error);
    while (*c && max_counter--)
    {
        *UART0DR = (unsigned int)(*c++);
    }

    Unity.NumberOfTests++;
    Unity.TestFailures++;
    (void)UnityEnd();
    SystemReset();
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a NMI. If this
// happens we output an error message and then force a test abort by calling
// system reset.
//
//*****************************************************************************
static void NmiSR(void)
{
    const char* err = "startup.c:0:Unexpected Non Maskable Interrupt Called:FAIL\n";
    AbortTestWithError(err);
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a fault
// interrupt.
//
//*****************************************************************************
static void FaultISR(void)
{
    const char* err = "startup.c:0:Unexpected Fault Interrupt Called:FAIL\n";
    AbortTestWithError(err);
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.
//
//*****************************************************************************
static void IntDefaultHandler(void)
{
    const char* err = "startup.c:0:Unexpected Default Interrupt Called:FAIL\n";
    AbortTestWithError(err);
}

//*****************************************************************************
//
// System Reset via reset vector
//
//*****************************************************************************

typedef unsigned char uint8_t;
typedef unsigned long uint32_t;

/* memory mapping struct for System Control Block */
typedef struct
{
  uint32_t CPUID;                        /*!< CPU ID Base Register                                     */
  uint32_t ICSR;                         /*!< Interrupt Control State Register                         */
  uint32_t VTOR;                         /*!< Vector Table Offset Register                             */
  uint32_t AIRCR;                        /*!< Application Interrupt / Reset Control Register           */
} SCB_Type;

#define SCS_BASE            (0xE000E000)                              /*!< System Control Space Base Address    */
#define SCB_BASE            (SCS_BASE +  0x0D00)                      /*!< System Control Block Base Address    */
#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct             */

#define NVIC_AIRCR_VECTKEY    (0x5FA << 16)   /*!< AIRCR Key for write access   */
#define NVIC_SYSRESETREQ            2         /*!< System Reset Request         */

static void SystemReset(void)
{
  SCB->AIRCR = (NVIC_AIRCR_VECTKEY | (SCB->AIRCR & (0x700)) | (1<<NVIC_SYSRESETREQ)); /* Keep priority group unchanged */
}
