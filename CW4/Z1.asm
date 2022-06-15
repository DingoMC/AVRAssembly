///////////////////////
// D0-D7 -> PB0-7
// a-g,dp -> PC0-7
// GND -> W4
// K4 -> PD3
// GND -> C4
.include "m32def.inc"
    
    .org 0x00
    jmp main
    .org 0x004
    jmp zmien
main: 						; program główny - instrukcje inicjalizacyjne
		CLI
		LDI R16, high(RAMEND) ; inicjalizacja wskaźnika stosu
		OUT SPL, R16
		LDI R16, low(RAMEND)
		OUT SPH, R16
		LDI R16, 0x80		; Inicjalizacja INT1
		OUT GICR, R16
		SBI PORTD, 3		; Przycisk podłączony do D3
		LDI R16, 0x08
		OUT MCUCR, R16		; Rejestr sterujący przerwaniami
		LDI R16, 0xFF
		OUT DDRB, R16		;
		OUT DDRC, R16		; Port B i C jako wyjścia
		OUT PORTB, R16		; Zapalenie linijki na porcie B
		SBI PORTC, 7		; Zapalenie wyswietlacza
		SEI					; Włączenie obsługi przerwań
loop:						; początek pętli głównej
	IN R16, PORTC
    ROR R16
    OUT PORTC, R16			; Pobranie wartości z wyświetlacza i wysłanie nowej
	CALL delay
	RJMP loop 				; wróć na początek pętli głównej
delay:
    ldi  r18, 26			; Opóźnienie 20ms
    ldi  r19, 249
L1: dec  r19
    brne L1
    dec  r18
    brne L1
    RET
zmien:				; Procedura przerwania
	PUSH R16
    IN R16, SREG	; Zapamiętaj wartość rejestru na stosie
    PUSH R16

    IN R16, PORTB
    COM R16			; Zmiana stanu diod na przeciwny
    OUT PORTB, R16

    POP R16
    OUT SREG, R16	; Przywróć wartości SREG i R16 ze stosu
    POP R16
	RETI			; Powrót z przerwania
