/*
 * main.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Mostafa Amr
 */


#include<avr/io.h>
#include "lcd.h"
#include "ultrasonic.h"


int main()
{
	SREG|=(1<<7);    /* Activate I-bit */
	uint16 distance=0;

	LCD_init();   /* Initialize lcd driver */
	Ultrasonic_init();    /* Initialize ultrasonic driver */

	LCD_displayString("Distance=   cm");

	while(1)
	{
		distance=Ultrasonic_readDistance();

		/* Display the distance value every time at same position */
		LCD_moveCursor(0,10);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

	}
}
