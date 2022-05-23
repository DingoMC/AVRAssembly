/////////////////////////
// PD4 -> D0

#define F_CPU 1000000
#include <avr/io.h>

int main(void)
{
	DDRD = 0x10;			// OC1B na wyjście
	TCCR1B = 0x03;			// Tryb PWM z preskalerem 1/64
	TCCR1A = 0x0b;
	OCR1A = 5938;			// Wartość TOP - od 0 do 5938 z preskalerem 1/64 - 380ms
	TCNT1 = 2968;			// Faza 1 190ms
	
	while (1) {
		if(TIFR & (1 << OCF1A)) {	// Jeśli koniec cyklu (TOP) to wyłącz diodę
			PORTD = 0;
		}
		if(TIFR & (1 << TOV1)) {		// Jesli BOTTOM to ustaw wartość counter na pośrednią by zmienić wartość
			PORTD = 0x10;				// Włącz diodę
			TCNT1 = 2968;				// Pośrednia wartość - początek fazy 1 - 190ms - pomiędzy OCR1A i 0
			TIFR |= (1 << TOV1);		// Reset flagi - powtórz cykl
		}
	}
}
