

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int chipdata();

int main(void)
{
    /* Replace with your application code */
	SPCR |= (1<<SPE); //SPI enabled
	SPCR |= (0<<SPIE); //Interrupts
	SPCR &= ~(1<<DORD); //Data Order
	SPCR |= (1<<MSTR); //Master
	SPCR |= (1<<CPOL);
	SPCR |= (1<<CPHA)|(0<<CPHA);
	DDRB |= (1<<PB3)|(1<<PB5)|(1<<PB2)|(1<<PB6); 
	PORTB |= (1<<PB3);
    while(1)
    {
	  chipdata();
    }
}

int chipdata()
{
uint8_t a;
uint8_t data;
uint8_t datareceived=0;

  for (a=0; a<255; a++)
  {
	 PORTB &= ~(1<<PB6); // Pulls chip select low
	 SPDR = a;
	 while (!(SPSR & (1<<SPIF) )); //transfer data
	 a = SPDR;
 	 PORTB |= (1<<PB6); // Set chip select high
	 _delay_ms (200);
  }

}
