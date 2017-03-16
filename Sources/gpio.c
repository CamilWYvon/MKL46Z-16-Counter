//************************************************************************************************************
// FILE: gpio.c
//
// DESCRIPTION
// Configures the Port Data Direction Register for GPIO port x
// (GPIOx_PDDR) for output.  
// Currently only configures Port B.  
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************
#include "global.h"
#include "gpio.h"

void gpio_output_config(int n)
{
	GPIOB_PDDR |= 1 << n;
}
