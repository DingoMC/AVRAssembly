///////////////////////
// a-g,dp -> PC0-7
// GND -> C4
// D0 -> PA0
// K3 -> PD2
// K4 -> PD3
// GND -> W4


.include "m32def.inc"
	
    .org 0x00
    jmp main
    .org 0x002
    jmp prz0	; przerwanie INT0
	.org 0x004
	jmp prz1	; przerwanie INT1
main: 			; program główny
	CLI
	LDI R16, 0xC0		; Obsługa przerwań
	OUT GICR, R16
	SBI PORTD, 3		; przycisk INT1
	SBI PORTD, 2		; przycisk INT0
	LDI R16, 0x0A		; Reakcja przerwań tylko na zbocze opadające
    OUT MCUCR, R16		; Rejestr sterujący przerwaniami
	LDI R16, 0xFF
    OUT DDRA, R16
    OUT DDRC, R16		; Port A i C jako wyjścia
	SBI PORTC, 7		; Zapalenie wyswietlacza
	CBI PORTA, 0		; Dioda na początku wyłączona
	SEI					; Włączenie obsługi przerwań
loop:				; początek pętli głównej
	IN R16, PORTC
    ROR R16
    OUT PORTC, R16	; Pobranie wartości z wyświetlacza i wysłanie nowej
	CALL delay
	rjmp loop 		; wróć na początek pętli głównej
delay:
    ldi  r18, 26	; Opóźnienie 20ms
    ldi  r19, 249
L1: dec  r19
    brne L1
    dec  r18
    brne L1
    RET
prz0:
	SBI PORTA, 0		; Zapalenie diody po wciśnięciu (SBI nie narusza SREG zatem nie trzeba korzystać ze stosu)
	RETI
prz1:
	SBIS PORTA, 0				; Jeżeli D0 jest wyłączona to skocz do instrukcji włączenia
	RJMP LED_on
	SBIC PORTA, 0				; Jeżeli D0 jest włączona wyłącz
	CBI PORTA, 0
	RETI						; Powrót z przerwania
LED_on:							; Instrukcja właczenia D0
	SBI PORTA, 0
	RETI						; Powrót z przerwania
