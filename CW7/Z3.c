/////////////////////////
// PD4-7 -> K1-K4
// PD0-3 -> W1-W4
// PA0-7 -> D0-D7
// PC0-7 -> JP24(a-dp)
// C4 -> GND

#define F_CPU 1000000
#define _BV(bit) (1<<bit)
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int counter = 0;					// licznik multipleksacji

int debinary(int x) {							// wyodrębniam numer bitu na podstawie wartości dziesiętnej
	if(x == 8) return 4;
	if(x == 4) return 3;
	return x;
}

ISR (TIMER0_COMP_vect) {        						// Przerwanie TIMER0
	PORTD = (~_BV(counter+4) & 0xF0) | (PORTD & 0x0F);	// Ustawiam 0 na dany bit w PORTD a resztę starszych bitów na 1
	if((PIND & 0x0F) != 0x0F)							// Sprawdzam czy dany klawisz jest naciśnięty
	{
		PORTA = (((debinary(~PIND & 0x0F)-1) * 4) + counter) | (PORTA & 0xF0);		// wypisuję zdekodowany znak klawisza
	}
	counter++;										// zwiększam licznik multipleksacji i w razie czego wracam do 0
	if(counter >= 4)
	{
		counter = 0;
	}
	
}

int main(void) {
	DDRA = 0xFF;			// Port A jako wyjście
	DDRC = 0xFF;			// Port C jako wyjście
	DDRD = 0xF0;			// Port D bity 4-7 wyjście, bit 0-3 wejście
	PORTD |= 0x0F;			// Podciąganie zasilania do wejść portu D
	OCR0 = 49;				// Ustawienie przerwania na 50ms
	TIMSK |= (1<<OCIE0);	// Włączenie przerwania na timerze
	TCCR0 |= (1<<WGM00) | (1<<CS02) | (1<<CS00);      // Ustawienie trybu CTC i preskalera
	sei();                  // Włączenie obsługi przerwań
	
	while (1)
	{
		PORTC ^= 0xFF;            // zmiana animacji
		_delay_ms(150);
	}
}
