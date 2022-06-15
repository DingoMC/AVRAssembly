////////////////////////////
//W1- > INT0
//W2 -> INT1
//PD4-7 -> K1-K4
//PA0-7 -> D0-D7
//PC0-7 -> JP24(a-dp)
//C1 -> GND

#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int l = 0;

ISR (INT0_vect) {
	_delay_ms(15);			// Oczekiwanie na stabilizację styków
	if(!(PIND & (1<<2))) {	// Sprawdź selektywnie czy przycisk INT0 jest wciśnięty
		l++;				// Zwiększ zmienną globalną
		for (int i = 0; i < 4; i++) {
			PORTD =  (PORTD & 0x0F) | (~(1<<(i+4)) & 0xF0);
			_delay_us(8);
			// Sprawdzamy czy przycisk jest wcisniety INT0
			if (!(PIND & (1<<2))) PORTA = (l & 0x0F) | (i << 5); //ustawienie animacji
		}
	}
	PORTD &= 0x0F;			// Ustawienie animacji
	GIFR &= ~(1<<INTF0);	// Czyszczenie flagi przerwań
}

ISR (INT1_vect) {
	_delay_ms(15);			// Oczekiwanie na stabilizację styków
	if(!(PIND & (1<<3))) {	// Sprawdź selektywnie czy przycisk INT0 jest wciśnięty
		l++;				// Zwiększ zmienną globalną
		for (int i = 0; i < 4; i++) {
			PORTD =  (PORTD & 0x0F) | (~(1<<(i+4)) & 0xF0);
			_delay_us(8);
			// Sprawdzamy czy przycisk jest wcisniety INT1
			if (!(PIND & (1<<3))) PORTA = (l & 0x0F) | ((i+4) <<5); //ustawienie animacji
		}
	}
	PORTD &= 0x0F;			// Ustawienie animacji
	GIFR &= ~(1<<INTF1);	// Czyszczenie flagi przerwań
}

int main(void) {
	DDRA = 0xFF;	// Port A jako wyjście
	DDRC = 0xFF;	// Port C jako wyjście
	DDRD |= 0xF0;	// Port D bity 4-7 wyjście (kolumny), bity 2-3 wejście (przerwania)
	PORTD = (1<<PD2) | (1<<PD3);		// Podciąganie zasilania do wejścia
	MCUCR = (1<<ISC11) | (1<<ISC01);	// Przerwania INT0 i INT1 na zbocze opadające
	GICR = (1<<INT1) | (1<<INT0);		// Włącz obsługe INT0 i INT1
	sei(); // Zezwól globalnie na obsługę przerwań
    while (1) {	
		PORTC ^= 0xFF;	// Animacja portu C
		_delay_ms(150);
    }
}
