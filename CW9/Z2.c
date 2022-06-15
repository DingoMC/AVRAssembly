//Poniżej podaj swoje dane
//Marcin Basak
//95365
//IIST 4
//GL01
//Cw9Z2
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
volatile char no_entry = 1;							// Flaga pamiętająca czy było jakiegokolwiek wejście
volatile char was_changed = 0;						// Flaga trybu wpisywania
volatile int clear_counter = 0;						// Licznik naciśnięć przycisku clear
volatile char was_up = 1;							// Flaga spawdzająca czy kursor został przeniesiony do nowej linii

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

void clear_LCD()								// Funkcja czyszcząca LCD
{
	PORTA &= 0xFE;								// Przełączam LCD w tryb wprowadzania komend
	_delay_us(2);								// Opóźnienie w celu wykrycia stanu "0" na pinie RS
	sendCommand(0x01);							// Czyszczę wyświetlacz
	sendCommand(0x06);							// Ustawiam poprzedni kierunek wyprowadzania
	was_up = 1;									// Resetuję flagę przeniesiena na dół
	write_counter = 0;							// Resetuję licznik wpisywania na ekran
	PORTA |= 0x01;								// Przełączam LCD w tryb wprowadzania danych
}

ISR (TIMER0_COMP_vect) {        								// Przerwanie TIMER0
	PORTB = (~_BV(multi_counter+4) & 0xF0) | (PORTB & 0x0F);	// Ustawiam 0 na dany bit w PORTB a resztę starszych bitów na 1
	if((PINB & 0x0F) != 0x0F)									// Sprawdzam czy dany klawisz jest naciśnięty
	{
		char code = pgm_read_byte_near(transcode + ((debinary(~PINB & 0x0F)-1) * 4) + multi_counter);	// Dekoduję znak z klawiatury
		if(code != last_character || no_entry)							// Zapobiegam niepotrzebym wywołaniom timera
		{
			if(code == 'C') {												// Sprawdzam czy trzeba czyścić ekran
				clear_LCD();
				clear_counter++;										// Zwiększam licznik
			}
			else if(code != 'X') {
				if(write_counter < 16) write_counter++;					// Sprawdzam czy można wpisać kolejny znak
				else if(!was_changed) {
					PORTA &= 0xFE;								// Przełączam LCD w tryb wprowadzania komend
					_delay_us(2);								// Opóźnienie w celu wykrycia stanu "0" na pinie RS
					sendCommand(0x07);							// Ustawiam tryb wprowadzania od prawej z cofaniem się
					PORTA |= 0x01;								// Przełączam LCD w tryb wprowadzania danych
					_delay_us(2);
				}
				sendChar(code);
			}
		}
		else if(code == 'C') {
			if(clear_counter > 5 && was_up) {				// Sprawdzam czy po 1s mogę przenieść kursor na dół
				PORTA &= 0xFE;								// Przełączam LCD w tryb wprowadzania komend
				_delay_us(2);								// Opóźnienie w celu wykrycia stanu "0" na pinie RS
				sendCommand(0xC0);							// Ustawiam LCD do nowej linii
				PORTA |= 0x01;								// Przełączam LCD w tryb wprowadzania danych
				_delay_us(2);
				was_up = 0;
			}
			else
			{
				clear_counter++;
			}
		}
		last_character = code;									// Zapamiętuję kod klawisza
		was_char_pressed = 1;									// Zauważam że wcisnąłem jakiś klawisz
	}
	multi_counter++;											// zwiększam licznik multipleksacji i w razie czego wracam do 0
	if(multi_counter >= 4) {
		if(was_char_pressed) {									// sprawdzam czy w poprzedniej iteracji został naciśnięty jakiś klawisz
			no_entry = 0;										// ustawiam flagę braku wpisywania na wartość fałsz
			clear_counter = 0;									// Resetuję
		}
		else no_entry = 1;
		was_char_pressed = 0;									// resetuję flagę sprawdzającą czy nacisnąłem jakiś klawisz
		multi_counter = 0;
	}
}

int main(void) {
	_delay_ms(15); 								// Czekam aż wyświetlacz LCD zostanie zainicjalizowany
	DDRA |= 0xF3;								// Ustawiam bity 4 - 7, 0, 1 jako wyjście
	DDRB |= 0xF0;								// Ustawiam kolumny jako wejście
	PORTD |= 0x04;								// Podciągam 2 PIND pod zasilanie
	PORTB |= 0x0F;								// Podciągam wiersze (PB0-3) pod zasilanie
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
	PORTA |= 0x01;
	sei();										// Włączam obsługe przerwań
	while (1){}
}
