#define F_CPU 1000000 
#include <avr/io.h> 
 //PD5 = OC1A 
int main(void) 
{ 
 DDRD |= 0x20; //wyjscie na PIND 
 TCCR1B |= 0x18;// ustawienie TIMER1 w tryb Fast PWM i preskaler 1/64 
 TCCR1B |= 0x03; // ustawienie TIMER1 w tryb Fast PWM 
 TCCR1A |= 0x82; // ustawienie TIMER1 w tryb Fast PWM 
 ICR1 = 8906; // moment TOP na 0.57s 
 OCR1A = 2969; // moment ponawiania 0.19s 
    while (1)  
    {  
 asm("nop"); //pusta instrukcja 
    } 
}
