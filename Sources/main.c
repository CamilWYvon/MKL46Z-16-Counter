#include "global.h"

#define forever for(;;)

int main()
{
    forever 
	{
		// Enable the clock to Port D.
		SIM_SCGC5 = SIM_SCGC5_PORTD_MASK;
		// Configure Port D pin 5 for the GPIO function by writing 1 the MUX field of PORTD_PCR5.
		PORTD_PCR(GREEN_LED_PIN) = PORT_PCR_MUX(GPIO);
		// Configure Port D pin 5 as an output pin by writing 1 to bit 5 of GPIOD_PDDR.
		GPIOD_PDDR |= 1 << 5;
		// Turn off the green LED by bringing the voltage on pin d5 high.
		GPIOD_PDOR |= 1 << 5;
		// Create an infinite loop. Note that main() should never return.
		forever {
		// Turn on the green LED by bringing the voltage on pin d5 low.
		GPIOD_PDOR &= ~(1 << 5);
		// Delay for a while.
		sleazy_delay(500000);
		// Turn off the green LED by bringing the voltage on pin d5 high.
		GPIOD_PDOR |= 1 << 5;
		// Delay for a while.
		sleazy_delay(500000);
    }

    // main() should never return, but C requires that main() return an int, so here it is.
    return 0;
}
