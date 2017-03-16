/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "global.h"
#include "main.h"
#include "sleazy_delay.h"
#include "led.h"
#include "sim.h"
#include "port.h"
#include "gpio.h"

void hardware_init()
{
	enableSIM(10); //Enable SIM for Port B

	port_gpio_config();	//configure port B for GPIO

	//Configure direction of bits 0-3 for output
	int n=0;
	while(n < 4)
	{
		gpio_output_config(n); //Configure
		n++;
	}
}

void run()
{
	int count = 0;
	while(1)
	{
		switch(count)
		{
			case(0):
			{
				//turn on correct LEDs
				//no LEDS
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			case(1):
			{
				//turn on correct LEDs
				led_on(0); //1 = 2^0
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(2):
			{
				//turn on correct LEDs
				led_on(1); //2 = 2^1
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(3):
			{
				//turn on correct LEDs
				led_on(0);	//3 = 2^0
				led_on(1);	//  + 2^1
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(4):
			{
				//turn on correct LEDs
				led_on(2);	//4 = 2^2
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(5):
			{
				//turn on correct LEDs
				led_on(0);	//5 = 2^0
				led_on(2);	//	+ 2^2
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(6):
			{
				//turn on correct LEDs
				led_on(1);	//6 = 2^1
				led_on(2);	//	+ 2^2
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(7):
			{
				//turn on correct LEDs
				led_on(0);	//7 = 2^0
				led_on(1);	//	+ 2^1
				led_on(2);	//  + 2^2 
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(8):
			{
				//turn on correct LEDs
				led_on(3);	//8 = 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(9):
			{
				//turn on correct LEDs
				led_on(0);	//9 = 2^0
				led_on(3);	//	+ 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(10):
			{
				//turn on correct LEDs
				led_on(1);	//10 = 2^1
				led_on(3);	//	 + 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(11):
			{
				//turn on correct LEDs
				led_on(0);	//11 = 2^0
				led_on(1);	//	 + 2^1
				led_on(3); 	//	 + 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(12):
			{
				//turn on correct LEDs
				led_on(2);	//12 = 2^2
				led_on(3);	//	 + 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(13):
			{
				//turn on correct LEDs
				led_on(0);	//13 = 2^0
				led_on(2);	//	 + 2^2
				led_on(3);	//	 + 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(14):
			{
				//turn on correct LEDs
				led_on(1);	//14 = 2^1
				led_on(2);	//	 + 2^2
				led_on(3);	//	 + 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			case(15):
			{
				//turn on correct LEDs
				led_on(0);	//15 = 2^0
				led_on(1);	//	 + 2^1
				led_on(2);	//	 + 2^2
				led_on(3);	//	 + 2^3
				//wait
				sleazy_delay(400000);
				//turn LEDs off
				led_all_off(4);
				//wait
				sleazy_delay(400000);
				count++;
				break;
			}
			
			default:
			{
				count = 0; //reset count
				break;
			}

		}
	}
}

int main()
{
	hardware_init();
	
	run();
	
	return 0;
}
