/////////////////////////
// PD4-7 -> K1-K4
// PD0-3 -> W1-W4
// PA0-7 -> D0-D7
// PC0-7 -> JP24(a-dp)
// C4 -> GND

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR (TIMER0_COMP_vect) {						// Przerwanie TIMER0
	if((PIND & 0x0F) != 0x0F) {					// Wykryj 0 na jednym z wierszy klawiatury
		uint8_t wr = PIND & 0x0F;	// Zmienna przechowująca wiersz gdzie pojawiło się 0
		wr = (~wr & 0x0F);
		DDRD ^= 0xFF;							// Zamiana kierunku linii portu
		PORTD ^= 0xFF;							// Zmiana stanów na porcie D (0->1 i 1->0)
		_delay_us(2);							// Opóźnienie między odczytywaniem wiersza i kolumny
		uint8_t kl = PIND & 0xF0;
		kl = (~kl & 0xF0);
		PORTA = (wr | kl);						// Ustawienie animacji
		DDRD ^= 0xFF;							// Zamiana kierunku linii portu
		PORTD ^= 0xFF;							// Przywrócenie stanu początkowego
	}
}

int main(void) {
	DDRA = 0xFF;						 // Port A jako wyjście
	DDRC = 0xFF;						 // Port C jako wyjście
	DDRD = 0xF0;						 // Port D bity 4-7 wyjście, bit 0-3 wejście
	PORTD |= 0x0F;						 // Podciąganie zasilania do wejść portu D
	OCR0 = 49;							 // Ustawienie przerwania na 50ms
	TIMSK |= (1<<OCIE0);							// Włączenie przerwania na timerze
	TCCR0 |= (1<<WGM00) | (1<<CS02) | (1<<CS00);    // Ustawienie trybu CTC i preskalera
	sei();											// Włączenie obsługi przerwań
	
	while (1) {
		PORTC ^= 0xFF;					 // Animacja na porcie C
		_delay_ms(150);
	}
}
