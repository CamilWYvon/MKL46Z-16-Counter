//**********************************************************************************************************************
// FILE: bare_startup.c
//
// DESCRIPTION
// Contains startup code functions written in C. Also contains the definition of the exception vector table.
//
// AUTHOR
// Kevin R. Burger (burgerk@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
// Web: http://www.devlang.com
//**********************************************************************************************************************
#include "bare_startup.h"
#include "global.h"
#include "libcse325.h"

//======================================================================================================================
// Private Type Definitions
//======================================================================================================================

// The ROM pointer table defined in the linker script is used to copy bytes from flash (ROM) to SRAM during startup.
// The table is a 1D array of struct bare_rom_table_t entries. Each entry has three members: m_source is the address
// in flash of a block of data to be copied to RAM; m_target is the address in SRAM where the data is to be copied to;
// and m_size is the number of bytes in the block being copied. The ROM pointer table array ends with an entry where
// all three data members are 0. The ROM table is copied in the bare_coopy_rom_sections_to_ram() function which is in
// this source code file.
typedef struct {
    uint8_t *m_source; // Address of beginning of block in flash to be copied
    uint8_t *m_target; // Address of where the block is to be copied to in SRAM.
    int m_size;        // Size of the block to be copied in bytes
} bare_rom_table_t;

//======================================================================================================================
// Public Global Variable Declarations
//======================================================================================================================

// The initial value (address) of the stack pointer register is defined in the linker script. This value is used in this
// file to initialize the first entry in the exception vector table.
extern uint32_t __init_sp;

// The address of the exception vector table is defined in the linker scipt by creating this __vector_table variable.
// This value is used in bare_hw_init() to initialize SCB_VTOR.
extern uint32_t __vector_table[];

// This array variable provides access to the ROM pointer table that is defined in the linker script file. See comments
// for bare_rom_table_t typedef above.
extern bare_rom_table_t __romp[];

//======================================================================================================================
// Public Function Declarations
//======================================================================================================================

// Weak definitions of interrupt service routines point to bare_default_isr if not implemented.
void nmi_isr()       __attribute__ ((weak, alias("default_isr")));
void hardfault_isr() __attribute__ ((weak, alias("default_isr")));
void svc_isr()       __attribute__ ((weak, alias("default_isr")));
void pendsv_isr()    __attribute__ ((weak, alias("default_isr")));
void systick_isr()   __attribute__ ((weak, alias("default_isr")));
void dma0_isr()      __attribute__ ((weak, alias("default_isr")));
void dma1_isr()      __attribute__ ((weak, alias("default_isr")));
void dma2_isr()      __attribute__ ((weak, alias("default_isr")));
void dma3_isr()      __attribute__ ((weak, alias("default_isr")));
void ftfa_isr()      __attribute__ ((weak, alias("default_isr")));
void pmc_isr()       __attribute__ ((weak, alias("default_isr")));
void llw_isr()       __attribute__ ((weak, alias("default_isr")));
void i2c0_isr()      __attribute__ ((weak, alias("default_isr")));
void i2c1_isr()      __attribute__ ((weak, alias("default_isr")));
void spi0_isr()      __attribute__ ((weak, alias("default_isr")));
void spi1_isr()      __attribute__ ((weak, alias("default_isr")));
void uart0_isr()     __attribute__ ((weak, alias("default_isr")));
void uart1_isr()     __attribute__ ((weak, alias("default_isr")));
void uart2_isr()     __attribute__ ((weak, alias("default_isr")));
void adc0_isr()      __attribute__ ((weak, alias("default_isr")));
void cmp0_isr()      __attribute__ ((weak, alias("default_isr")));
void tpm0_isr()      __attribute__ ((weak, alias("default_isr")));
void tmp1_isr()      __attribute__ ((weak, alias("default_isr")));
void tmp2_isr()      __attribute__ ((weak, alias("default_isr")));
void rtcalarm_isr()  __attribute__ ((weak, alias("default_isr")));
void rtcsecs_isr()   __attribute__ ((weak, alias("default_isr")));
void pit_isr()       __attribute__ ((weak, alias("default_isr")));
void i2s0_isr()      __attribute__ ((weak, alias("default_isr")));
void usbotg_isr()    __attribute__ ((weak, alias("default_isr")));
void dac0_isr()      __attribute__ ((weak, alias("default_isr")));
void tsi0_isr()      __attribute__ ((weak, alias("default_isr")));
void mcg_isr()       __attribute__ ((weak, alias("default_isr")));
void lptimer_isr()   __attribute__ ((weak, alias("default_isr")));
void slcd_isr()      __attribute__ ((weak, alias("default_isr")));
void porta_isr()     __attribute__ ((weak, alias("default_isr")));
void portscd_isr()   __attribute__ ((weak, alias("default_isr")));

//======================================================================================================================
// Private Variable Definitions
//======================================================================================================================

// Define and initialize the interrupt vector table. Place the vector table in its own section named .vectortable
// in the .o file. The linker script will use this section name to make sure the vector table is placed in the flash
// at 0x0000_0000.
void (* const bare_vector_table[])() __attribute__ ((section(".vectortable"))) = {
    (void *)&__init_sp,	  // Initial value of the SP register
    bare_startup,         // Reset vector will jump here and begin executing code
    nmi_isr,              // Nonmaskable interrupt service routine
    hardfault_isr,        // Hardfault interrupt service routine
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    0,                    // Reserved
    svc_isr,
    0,                    // Reserved
    pendsv_isr,
    systick_isr,
    dma0_isr,             // DMA Channel 0 Transfer Complete and Error
    dma1_isr,             // DMA Channel 1 Transfer Complete and Error
    dma2_isr,             // DMA Channel 2 Transfer Complete and Error
    dma3_isr,             // DMA Channel 3 Transfer Complete and Error
    0,                    // Reserved
    ftfa_isr,             // Command complete and read collision
    pmc_isr,              // PMC Interrupt */
    llw_isr,              // Low Leakage Wake-up */
    i2c0_isr,             // I2C0 interrupt */
    i2c1_isr,             // I2C1 interrupt */
    spi0_isr,             // SPI0 Interrupt */
    spi1_isr,             // SPI1 Interrupt */
    uart0_isr,            // UART0 Status and Error interrupt */
    uart1_isr,            // UART1 Status and Error interrupt */
    uart2_isr,            // UART2 Status and Error interrupt */
    adc0_isr,             // ADC0 interrupt
    cmp0_isr,             // CMP0 interrupt
    tpm0_isr,             // TPM0
    tmp1_isr,             // TPM1
    tmp2_isr,             // TPM2
    rtcalarm_isr,         // RTC Alarm interrupt
    rtcsecs_isr,          // RTC Seconds interrupt
    pit_isr,              // PIT timer all channels interrupt
    i2s0_isr,             // Single interrupt vector for all sources
    usbotg_isr,           // USB interrupt
    dac0_isr,             // DAC0 interrupt
    tsi0_isr,             // TSI0 Interrupt
    mcg_isr,              // MCG Interrupt
    lptimer_isr,          // LPTimer interrupt
    slcd_isr,             // SLCD
    porta_isr,            // Port A interrupt
    portscd_isr           // Single interrupt vector for Port C and Port D interrupt
};

//======================================================================================================================
// Private Function Declarations
//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
// FUNCTION: bare_bss_zero_fill
//
// DESCRIPTION
// This function fills the .bss section in RAM with all zeros. __bss_begin and __bss_end are defined in the linker
// script.
//----------------------------------------------------------------------------------------------------------------------
void bare_bss_zero_fill()
{
    extern uint8_t __bss_begin[];
    extern uint8_t __bss_end[];
    cse325_memset(__bss_begin, 0, __bss_end - __bss_begin);
}

//----------------------------------------------------------------------------------------------------------------------
// FUNCTION: bare_copy_rom_sections_to_ram
//
// DESCRIPTION
// This function copies all sections marked as ROM in the .elf file to their target addresses in SRAM. __romp is
// defined in the linker script as a 1D array where each element is a structure of type bare_rom_table_t. The end of
// the ROM entries is specified by a structure with all 0's for each of the fields.
//----------------------------------------------------------------------------------------------------------------------
void bare_copy_rom_sections_to_ram()
{
    // If there are no ROM sections to copy then return.
    if (__romp == 0L) return;

    // Iterate over table entry, copying the section from ROM to SRAM.
    for (int i = 0; __romp[i].m_source != 0L; ++i) {
        cse325_memcpy(__romp[i].m_target, __romp[i].m_source, __romp[i].m_size);
    }
}

//----------------------------------------------------------------------------------------------------------------------
// FUNCTION: default_usr()
//
// DESCRIPTION
// Default interrupt service routine. All interrupt vectors direct here unless changed by writing a new address for the
// ISR to the vector table. This function simply executes an ARM breakpoint instruction, which causes execution to halt.
//----------------------------------------------------------------------------------------------------------------------
void default_isr()
{
    __asm("bkpt");
}

//----------------------------------------------------------------------------------------------------------------------
// FUNCTION: bare_hw_init()
//
// DESCRIPTION
// Called by bare_startup. Initializes SCB_VTOR and SIM_COPC.
//----------------------------------------------------------------------------------------------------------------------
void bare_hw_init()
{
    // Write the address of the exception vector table to SCB_VTOR.
    SCB_VTOR = (uint32_t)__vector_table;

    // Disable the watchdog because it may reset the core before entering main().
    SIM_COPC = 0x00000000;
}
