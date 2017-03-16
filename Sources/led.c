//************************************************************************************************************
// FILE: led.c
//
// DESCRIPTION
//
// AUTHOR
// John J. Hritz (John.Hritz@asu.edu)
// Computer Science & Engineering
// Arizona State University, Tempe AZ 85287-8809
//************************************************************************************************************
#include "global.h"
#include "led.h"

void led_on(int n)
{
	GPIOB_PDOR |= 1 << n;
}

void led_off(int n)
{
	GPIOB_PDOR &= 0 << n;
}

//Turn off first n LEDs
void led_all_off(int n) 
{
	int i = 0;
	while(i < n)
	{
		led_off(i);
		i++;
	}
}
