///////////////////////
// a -> PC0
// b -> PC1
// c -> PC2
// d -> PC3
// e -> PC4
// f -> PC5
// g -> PC6
// dp -> PC7
// GND -> C4

// D0 -> PA0

// K1 -> PD2
// K4 -> PD3
// GND -> W1


.include "m32def.inc"
	
    .org 0x00
    jmp main
    .org 0x002
    jmp prz0	; przerwanie INT0
	.org 0x004
	jmp prz1	; przerwanie INT1
main: 			; program główny
	CLI
	LDI R16, high(RAMEND) ; inicjalizacja wskaźnika stosu
	OUT SPL, R16
	LDI R16, low(RAMEND)
	OUT SPH, R16
	LDI R16, 0xC0		; Obsługa przerwań
	OUT GICR, R16
	SBI PORTD, 3		; przycisk INT1
	SBI PORTD, 2		; przycisk INT0
	LDI R16, 0x02
    OUT MCUCR, R16		; Rejestr sterujący przerwaniami
	LDI R16, 0xFF
    OUT DDRA, R16
    OUT DDRC, R16		; Port A i C jako wyjścia
	SBI PORTC, 7		; Zapalenie wyswietlacza
	CBI PORTA, 0		; Dioda na początku wyłączona
	SEI					; Włączenie obsługi przerwań
loop:			; początek pętli głównej
	IN R16, PORTC
    ROR R16
    OUT PORTC, R16	; Pobranie wartości z wyświetlacza i wysłanie nowej
	CALL delay
	rjmp loop 	; wróć na początek pętli głównej
delay:
    ldi  r18, 26	; Opóźnienie 20ms
    ldi  r19, 249
L1: dec  r19
    brne L1
    dec  r18
    brne L1
    RET
prz0:
	PUSH R16
    IN R16, SREG
    PUSH R16
	SBI PORTA, 0		; Zapalenie diody po wciśnięciu 
    POP R16
    OUT SREG, R16
    POP R16
	RETI
prz1:
	PUSH R16
    IN R16, SREG
    PUSH R16
    IN R16, PORTA
    COM R16				; Zmiana stanu diody na przeciwny
    OUT PORTA, R16
    POP R16
    OUT SREG, R16
    POP R16
	RETI
