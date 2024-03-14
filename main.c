
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define sbi(reg, bit) reg|=(1<<(bit))
#define cbi(reg, bit) reg|=~(1<<(bit))

int led[]={0xfe, 0xfd, 0xfb, 0xf7};

void timer0_init();

int main(void)
{
	DDRG=0xff;
	float duty;
	int i=0;
	timer0_init();
	PORTG=0x00;
    while (1) 
    {
		for(duty=0.0; duty<1.0; duty+=0.1)
		{
			
			OCR0=255*duty; _delay_ms(2000);
			OCR0=0; _delay_ms(2000);
			i++;
			if(i==3)
			i=0;
		}
		OCR0=0; _delay_ms(4000);
    }
}

void timer0_init()
{
	float duty=0.0;
	DDRB|=0x30;
	cbi(PORTB,5);
	TCCR0=0b01100011;
	OCR0=255*duty;
}
