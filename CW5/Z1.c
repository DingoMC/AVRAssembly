////////////////////////////
/*
PA0 -> D0
PD2 -> W4
K4 -> GND
PC0-6 -> a-g
PC7 -> dp
C4 -> GND
*/

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR (INT0_vect) { // Przerwanie INT0 zeruje licznik, ustawia go w tryb CTC i uruchamia D0
	TCNT1 = 0;
	TCCR1B = 0x03;
	PORTA |= 0x01;
}

ISR (TIMER1_COMPA_vect) { // Przerwanie TIMER1, wyłącza D0 i TIMER1
	PORTA &= 0xBE;
	TCCR1B &= 0xF8;
}

int main(void) {
	DDRA |= 0x01;
	PORTD |= 0x04;
	DDRC |= 0xFF;
	GICR |= 0x40;	// Przerwanie INT0 - zbocze opadające
	MCUCR |= 0x02;	// Inicjalizacja przerwania INT0
	TCCR1B |= 0x0B;	// TIMER1 w tryb CTC
	TIMSK |= 0x10;	// TIMER1
	OCR1A = 7813;	// TOP ustawiony na 0.5s 1MHz/64*0.5
	sei();			// Włączenie obsługi przerwań
	while (1) {
		PORTC ^= 0xFF; // Zmiana animacji
		_delay_ms(150); // Opóźnienie 150ms
	}
}
