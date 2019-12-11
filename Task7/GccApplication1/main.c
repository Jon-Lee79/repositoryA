/*
 * GccApplication1.c
 *
 * Created: 11/4/2019 11:51:23 AM
 * Author : Advanced Student
 */ 




#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 1000000UL


void loop()
{
	PORTD |= (1<<PD1);
	_delay_ms(150);
	PORTD &= ~(1<<PD1);
	_delay_ms(150);
}



int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		loop();
    }
}

