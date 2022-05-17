//PORTA0 = LED0 
//PORTA7 = LED7 
//PORTC0-7 = wyswietlacz 7 segmentowy 
//PORTD2 = W2 (S8) 
 
 
#define F_CPU 1000000 
#include <avr/io.h> 
#include <util/delay.h> 
#include <avr/interrupt.h> 
 
const int TRYB_1 = 2500; 
volatile int tryb_0; 
 
ISR(TIMER1_COMPA_vect) 
{ 
 PORTA ^= 0x01; // zmieniamy stan diody LED0 
 if(OCR1A == TRYB_1) //zmiana sekwencji 
 { 
  OCR1A = tryb_0; 
 } 
 else 
 { 
  OCR1A = TRYB_1; 
 } 
} 
 
ISR(INT0_vect) 
{ 
 if( tryb_0 != 3000) //jesli nie osiagnelismy minimum 
 { 
  if(tryb_0 - 1250 >3000) // jesli mozemy jeszcze zminiejszac to zmniejszamy 
  { 
   if(OCR1A == tryb_0) 
   { 
    tryb_0 = tryb_0 - 1250; // zmniejszenie czasu 
    OCR1A = tryb_0; 
    if(tryb_0 > TCNT1) //zabezpieczenie przed przekroczeniem aktualnego stanu 
    { 
     TCNT1 = tryb_0 - 1; 
    } 
   } 
   else 
   { 
    tryb_0 = tryb_0 - 1250;// zmniejszenie czasu 
   } 
    
  } 
  else{ //jesli nie mozemy zmniejszac 
    if(OCR1A == tryb_0)  
    { 
     tryb_0 = 3000; //ustalenie minumum recznie 
     OCR1A = tryb_0; 
     if(tryb_0 > TCNT1) //zabezpieczenie przed przekroczeniem aktualnego stanu 
     { 
      TCNT1 = tryb_0 - 1; 
     } 
    } 
    else 
    { 
     tryb_0= 3000; //ustalenie minimum recznie 
    } 
     
   } 
  } 
 else 
  { 
   PORTA &= 0x7F; // wylaczenie diody 
  } 
 } 
 
 
int main(void) 
{ 
   
  DDRA |= 0x81; //podciagam 1 bit na wyjście PORTA 
  PORTD |= 0x04; //podciagam przycisk do zasilania 
  DDRC |= 0xFF; // pociagniecie linii na wyjscie PORTC 
  PORTA |= 0x80; //wlaczenie diody LED7 
  GICR |= 0x40; // inicjalizuje dzialanie przerwania INT0 na zboczu opadającym w celu wyłapania wciśniecia przycisku 
  MCUCR |= 0x02; // inicjalizacja przerwania INT0 
  TCCR1B |= 0x0B; // TIMER1 w tryb CTC i preskaler 1/64 
  TIMSK |= 0x10; //włączenie TIMER1 
  tryb_0 = 5000; // 0.36s 
  OCR1A = tryb_0; // TOP ustawiony na 0.36s 1MHz/64*0.36 
   
   
  sei(); // inicjalizacja obslugi przerwań 
  while (1) 
  { 
   PORTC ^=0xFF; //zmiana stanu diod LED PORTC 
   _delay_ms(250); //opóźnienie 250ms 
  } 
     
}
