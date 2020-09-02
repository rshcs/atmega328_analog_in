
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile int adc_conv = 0;
int i = 11;
int main(void)
{
    ADMUX |= (1 << REFS0);
	ADCSRA |= 0B10001111;
	DIDR0 |= (1 << ADC0D);
	sei();
    while (1) 
    {
		ADCSRA |= (1 << ADSC);	
		i++;
		PORTB = ~PORTB;
		_delay_ms(100);
    }
}

ISR(ADC_vect)
{
	
	adc_conv = ADCL;
	//i++;
	adc_conv |= (8 <<ADCH);
}