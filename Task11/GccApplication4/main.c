/*
 * GccApplication4.c
 *
 * Created: 21/11/2019 11:14:20 AM
 * Author : Advanced Student
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

void setup()
{

uint16_t lowbyte;
uint16_t highbyte; 

// 1011101101

PORTD |= (1<<PD7);     //Set as output pin
PORTD |= (1<<PD6);     //Set as output pin
PORTD |= (1<<PD5);     //Set as output pin

ADMUX |= (1<<ADC5);
ADMUX |= (1<<);

ADCSRA |= (1<<ADEN); // Turns ADC on
ADCSRA |= (1<<ADSC); // Starts data collection
ADCSRA |= (1<<ADBS2-0); // Frequency

while(! ADCSRA & (1<<ADIF)); // Loop until ADC complete

lowbyte = ADCL; // 00000000 11101101
highbyte = ADCH; // 00000000 00000010

uint16_t finalvalue; 

finalvalue = (highbyte << 8) | lowbyte;

}