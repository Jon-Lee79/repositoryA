/*
 * GccApplication2.c
 *
 * Created: 14/11/2019 10:39:46 AM
 * Author : Advanced Student
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect)
{
	PORTD ^= (1<<PD6);
}

ISR(TIMER0_COMPA_vect)
{
	
}
voidloop()
{

}

void setup()
{
	DDRD |= (1<<PD6);     //Set as output pin
	PORTD &= ~(1<<PD6);   //Start pin as 0

	TCCR0B = 0x01;  // Chooses normal mode with no clock prescaling
	
	
	TIMSK0 |= (1<<OCIE0A)|(1<<TOIE0);     //Enables timer 0 overflow interrupt
	
	OCR0A = 200; //Number to compare

	sei();
}

int main()
{
    /* Replace with your application code */
	setup();
    while (1) loop(); 
}
