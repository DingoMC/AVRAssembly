/////////////////////////
/*
PA0 -> D0
PA7 -> D7
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

const int T_1 = 2500;
volatile int T_0;

ISR(TIMER1_COMPA_vect) {
	PORTA ^= 0x01;					// Zmieniamy stan diody D0
	if (OCR1A == T_1) OCR1A = T_0;	// Zmiana sekwencji
	else OCR1A = T_0;
}

ISR(INT0_vect) {
	if (T_0 != 3000) {				// Warunek minimalny
		if(T_0 > 4250) {			// Zmniejszenie wartości
			if(OCR1A == T_0) {
				T_0 -= 1250;		// Obniżenie czasu o 0,08s
				OCR1A = T_0;
				if(T_0 > TCNT1) TCNT1 = T_0 - 1; //przekroczenie stanu
			}
			else T_0 -= 1250;		// Obniżenie czasu o 0,08s
		}
		else {
			if (OCR1A == T_0) {
				T_0 = 3000;			// Ustalenie czasu na 0,192s
				OCR1A = T_0;
				if(T_0 > TCNT1) TCNT1 = T_0 - 1;	// Zabezpieczenie
			}
			else T_0 = 3000;		// Ustalenie czasu na 0,192s
		}
	}
	else PORTA &= 0x7F;				// Wyłączenie diody - czas < 0,192s
}


int main(void) {
	DDRA |= 0x81;
	PORTD |= 0x04;
	DDRC |= 0xFF;
	PORTA |= 0x80;
	GICR |= 0x40;		// Przerwanie INT0 - zbocze opadające
	MCUCR |= 0x02;		// Inicjalizacja przerwania INT0
	TCCR1B |= 0x0B;		// TIMER1 w tryb CTC
	TIMSK |= 0x10;		// Włączenie TIMER1
	T_0 = 5000;			// Początkowy czas trwania 0 - 0,32s
	OCR1A = T_0;		// TOP ustawiony na 0,32s
	sei();				// Włączenie obsługi przerwań
	while (1) {
		PORTC ^=0xFF;	// Zmiana animacji
		_delay_ms(250); // Opóźnienie 250ms
	}
}
