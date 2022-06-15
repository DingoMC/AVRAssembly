/////////////////////////
// PA4-7 -> D4-7 (JP29)
// PA1 -> E
// PA0 -> RS
// PC0-7 -> D0-D7 (JP22)
// PD2 -> W1
// PD3 -> W2
// K4 -> GND


#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

volatile int counter = 0;								// Globalny licznik

const char data[] = { 0x02, 0xF1, 0x38, 0xBA, 0x97 };	// Tablica bajtów

const char transcode[] PROGMEM  = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' }; // Tablica transkodująca

void sendCommand(unsigned char data)
{
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

void sendChar(unsigned char data)
{
	PORTA = (PORTA & 0x0F) | (data & 0xF0);	// Zapisanie 4 starszych bitów
	PORTA |= (1 << PA0);					// RS = 0
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

ISR (INT0_vect) 								// Przerwanie INT0
{
	if(counter < 5)								// Jeżeli nie napotkałem końca tablicy to wypisuję kolejną literę
	{
		if(counter > 0)
		{
			sendChar(' ');						// Jeżeli trzeba wypisuję spację
		}
		// Pobieram dane z pamięci programu
		sendChar(pgm_read_byte_near(transcode + (data[counter] >> 4)));					// Wypisuję górną połowę
		sendChar(pgm_read_byte_near(transcode + (data[counter] & 0x0F)));				// Wypisuję dolną połowę
		counter++;
	}
}

ISR (INT1_vect) 								// Przerwanie INT1
{
	PORTA &= 0xFE;								// Przełączam LCD w tryb wprowadzania komend
	_delay_us(2);								// Opóźnienie w celu wykrycia stanu "0" na pinie RS
	sendCommand(0x01);							// Czyszczę wyświetlacz
	sendCommand(0x90);							// Ustawiam kursor na odpowiedniej pozycji
	counter = 0;								// Resetuję licznik
	PORTA |= 0x01;								// Przełączam LCD w tryb wprowadzania danych
}
int main(void)
{
	_delay_ms(15); 								// Czekam aż wyświetlacz LCD zostanie zainicjalizowany
	DDRA |= 0xF3;								// Ustawiam bity 4 - 7, 0, 1 jako wyjście
	DDRC |= 0xFF;								// Linijka diod na wyjście
	PORTD |= 0x0C;								// podciągam 2 i 3 PIND pod zasilanie
	MCUCR |= 0x0A;								// Ustawienie aktywacji obu przerwań w tryb falling-edge;
	GICR |= 0xC0;								// Włączenie przerwań INT0 i INT1
	_delay_ms(20);
	sendCommand(0x33);		// Inicjalizacja zgodna z dokumentacją
	_delay_ms(8);
	sendCommand(0x32);
	_delay_ms(150);
	sendCommand(0x01);		// Czyszczenie wyświetlacza
	_delay_ms(10);
	sendCommand(0x28);
	sendCommand(0x0D);
	sendCommand(0x07);		// Ustawienie kursora
	sendCommand(0x8F);
	sei();										// Włączam obsługe przerwań

	while(1)									// Animacja
	{
		PORTC ^= 0xFF;
		_delay_ms(50);
	}
}
