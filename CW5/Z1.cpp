#define F_CPU 1000000 
#include <avr/io.h> 
#include <util/delay.h> 
#include <avr/interrupt.h> 
 
//PORTA0 = LED0 
//PORTC0-7 = wyswietlacz 7 segmentowy 
//PORTD2 = W2 (S8) 
 
ISR(INT0_vect) //przerwanie INT0 
{ 
 TCNT1 = 0;     //zeruje aktualny licznik w celu zresetowania czasu 
 TCCR1B = 0x0B; // ustawiam TIMER1 w tryb CTC oraz preskaler w tryb 1/64 
 PORTA |= 0x01; // uruchamiam diode LED0 
} 
 
ISR(TIMER1_COMPA_vect) //przerwanie TIMER1 
{ 
 PORTA &= 0xBE; //wyłączam diode LED0 
 TCCR1B &= 0xF8; // wyłączam TIMER1 
} 
 
int main(void) 
{ 
 DDRA |= 0x01; //podciagam 1 bit na wyjście PORTA  
 PORTD |= 0x04; //podciagam przycisk do zasilania 
 DDRC |= 0xFF; // podciagam linie na wyjście PORTC 
  
 GICR |= 0x40; // inicjalizuje dzialanie przerwania INT0 na zboczu opadającym w celu wyłapania wciśniecia przycisku 
 MCUCR |= 0x02; // inicjalizacja przerwania INT0 
  
 TIMSK |= 0x10; //włączenie TIMER1 
 OCR1A = 7813; // TOP ustawiony na 0.5s 1MHz/64*0.5 
  
  
 sei(); // inicjalizacja obslugi przerwań 
    while (1)  
    {  
  PORTC ^=0xFF; //zmiana stanu diod LED 
  _delay_ms(150); //opóźnienie 150ms 
    } 
}
