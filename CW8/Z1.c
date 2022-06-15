////////////////////////////
// PA4-7 -> D4-7 (JP29)
// PB1 -> E
// PB0 -> RS

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


void sendCommand(unsigned char data)
{
	PORTA = (PORTA & 0x0F) | (data & 0xF0);	// Zapisanie 4 starszych bitów
	PORTB &= ~(1 << PA0);					// RS = 0
	PORTB |= (1 << PA1);
	_delay_us(1);
	PORTB &= ~(1 << PA1);					// ENABLE = 0
	_delay_us(200);
	PORTA = (PORTA & 0x0F) | (data << 4);	// Zapisanie 4 najmłodszych bitów
	PORTB |= (1 << PA1);
	_delay_us(1);
	PORTB &= ~(1 << PA1);					// ENABLE = 0
	_delay_ms(2);
}

void sendChar(unsigned char data)
{
	PORTA = (PORTA & 0x0F) | (data & 0xF0);	// Zapisanie 4 starszych bitów
	PORTB |= (1 << PA0);
	PORTB |= (1 << PA1);
	_delay_us(1);
	PORTB &= ~(1 << PA1);					// ENABLE = 0
	_delay_us(200);
	PORTA = (PORTA & 0x0F) | (data << 4);	// Zapisanie 4 najmłodszych bitów
	PORTB |= (1 << PA1);
	_delay_us(1);
	PORTB &= ~(1 << PA1);					// ENABLE = 0
	_delay_ms(2);
}

int main(void)
{
	_delay_ms(15); 								// Czekam aż wyświetlacz LCD zostanie zainicjalizowany
	DDRA = 0xFF;								// Ustawiam całą linię A i część linii B jako wyjście
	DDRB |= 0x03;
	_delay_ms(20);
	sendCommand(0x33);		// Inicjalizacja zgodna z dokumentacją
	_delay_ms(8);
	sendCommand(0x32);
	_delay_ms(150);
	sendCommand(0x01);		// Czyszczenie wyświetlacza
	_delay_ms(10);
	sendCommand(0x28);
	sendCommand(0x0D);
	sendCommand(0x07);
	sendCommand(0x8F);
	char *n = "Basak";
	for (uint8_t i = 0; n[i] != 0; i++) {
		sendChar(n[i]);
		_delay_ms(100);
	}
}
