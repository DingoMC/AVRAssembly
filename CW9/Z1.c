//Poniżej podaj swoje dane
//Marcin Basak
//95365
//IIST 4
//GL01
//Cw9Z1
//////////////////////////////////////////
// PA7-4 -> D7-4 (JP29)
// PA1 -> E (JP29)
// PA0 -> RS (JP29)
// K1-K4 -> PB4-7
// W1-W4 -> PB0-3

#define F_CPU 4000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>


volatile int multi_counter = 0;						// Licznik multipleksacji
volatile int write_counter = 0;						// Licznik wpisywania
volatile char last_character = -1;					// Flaga ostatniego znaku
volatile char was_char_pressed = 0;					// Flaga pomagająca stwierdzić czy w poprzedniej iteracji został wciśnięty klawisz
volatile char no_entry = 1;							// Flaga pamiętająca czy było jakieś wejście

const char transcode[] PROGMEM  = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }; // Tablica transkodowa

void sendCommand(unsigned char data) {
	PORTA = (PORTA & 0x0F) | (data & 0xF0);	// Zapisanie 4 starszych bitów
	PORTA &= ~(1 << PA0);					// RS = 0
	PORTA |= (1 << PA1);
	_delay_us(1);
	PORTA &= ~(1 << PA1);					// ENABLE = 0
	_delay_us(200);
	PORTA = (PORTA & 0x0F) | (data << 4);	// Zapisanie 4 najmłodszych bitów
	PORTA |= (1 << PA1);
	_delay_us(1);
	PORTA &= ~(1 << PA1);					// ENABLE = 0
	_delay_ms(2);
}

void sendChar(unsigned char data) {
	PORTA = (PORTA & 0x0F) | (data & 0xF0);	// Zapisanie 4 starszych bitów
	PORTA |= (1 << PA0);
	PORTA |= (1 << PA1);
	_delay_us(1);
	PORTA &= ~(1 << PA1);					// ENABLE = 0
	_delay_us(200);
	PORTA = (PORTA & 0x0F) | (data << 4);	// Zapisanie 4 najmłodszych bitów
	PORTA |= (1 << PA1);
	_delay_us(1);
	PORTA &= ~(1 << PA1);					// ENABLE = 0
	_delay_ms(2);
}

int debinary(int x)	{						// Wyodrębniam numer bitu na podstawie wartości dziesiętnej
	if(x == 8) return 4;
	if(x == 4) return 3;
	return x;
}

ISR (INT0_vect) {								// Przerwanie INT0
	PORTA &= 0xFE;								// Przełączam LCD w tryb wprowadzania komend
	_delay_us(2);								// Opóźnienie w celu wykrycia stanu "0" na pinie RS
	sendCommand(0x01);							// Czyszczę wyświetlacz
	write_counter = 0;							// Resetuję licznik wpisywania na ekran
	PORTA |= 0x01;								// Przełączam LCD w tryb wprowadzania danych
}

ISR (TIMER0_COMP_vect) {        								// Przerwanie TIMER0
	PORTB = (~_BV(multi_counter+4) & 0xF0) | (PORTB & 0x0F);	// Ustawiam 0 na dany bit w PORTA a resztę starszych bitów na 1
	if((PINB & 0x0F) != 0x0F) {									// Sprawdzam czy dany klawisz jest naciśnięty
		char code = ((debinary(~PINB & 0x0F)-1) * 4) + multi_counter;	// Dekoduję znak z klawiatury
		if(write_counter < 16 && (code != last_character || no_entry)) {			// Sprawdzam czy można wpisać kolejny znak
			sendChar(pgm_read_byte_near(transcode + code));		// wypisuję zdekodowany znak klawisza
			write_counter++;
		}
		last_character = code;									// Zapamiętuję kod klawisza
		was_char_pressed = 1;									// Zauważam że wcisnąłem jakiś klawisz
	}
	multi_counter++;											// zwiększam licznik multipleksacji i w razie czego wracam do 0
	if(multi_counter >= 4)
	{
		if(was_char_pressed)									// sprawdzam czy w poprzedniej iteracji został naciśnięty jakiś klawisz
		{
			no_entry = 0;										// ustawiam flagę braku wpisywania na wartość fałsz
		}
		else no_entry = 1;
		was_char_pressed = 0;									// resetuję flagę sprawdzającą czy nacisnąłem jakiś klawisz
		multi_counter = 0;
	}
}

int main(void) {
	_delay_ms(15); 								// Czekam aż wyświetlacz LCD zostanie zainicjalizowany
	DDRA |= 0xF3;								// Ustawiam bity 4 - 7, 0, 1 jako wyjście
	PORTD |= 0x04;								// Podciągam 2 PIND pod zasilanie
	PORTB |= 0x0F;								// Podciągam wiersze (PB0-3) pod zasilanie
	MCUCR |= 0x0A;								// Ustawienie aktywacji przerwań w tryb falling-edge;
	GICR |= 0x40;								// Włączenie przerwania INT0
	OCR0 = 156;                    				// Ustawienie momentu przerwania na 156 (0,01s)
	TIMSK |= 0x02;                 				// Włączenie przerwania TIMER0
	TCCR0 |= 0b01000100;            			// tryb CTC, Preskaler 1/256
	_delay_ms(20);
	sendCommand(0x33);							// Inicjalizacja zgodna z dokumentacją
	_delay_ms(8);
	sendCommand(0x32);
	_delay_ms(150);
	sendCommand(0x01);							// Czyszczenie wyświetlacza
	_delay_ms(10);
	sendCommand(0x28);
	sendCommand(0x0D);
	sendCommand(0x06);							// Ustawienie kursora
	sendCommand(0x8F);
	sendCommand(0x04);
	sendCommand(0x00);
	PORTA |= 0x01;
	sei();										// Włączam obsługe przerwań
	while (1){}
}
