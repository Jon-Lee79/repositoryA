* GccApplication2.c
 *
 * Created: 14/11/2019 10:39:46 AM
 * Author : Advanced Student
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void setup()
{
	DDRD |= (1<<PD6);     //Set as output pin
	DDRD |= (1<<PD5);     //Set as output pin
	//PORTD &= ~(1<<PD6);   //Start pin as 0

	//TCCR0B = 0x01;  // Chooses normal mode with no clock prescaling
	
	TCCR0A |= (1<<COM0A1)|(1<<COM0A0);
	TCCR0A |= (1<<COM0B1)|(1<<COM0B0);
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	TCCR0B |= (1<<CS00);
	
	
	//TIMSK0 |= (1<<OCIE0A)|(1<<TOIE0);     //Enables timer 0 overflow interrupt
	
	OCR0A = 200; //Number to compare

	//sei();
}

int main()
{
    /* Replace with your application code */
	setup();
    while (1) loop(); 
}


