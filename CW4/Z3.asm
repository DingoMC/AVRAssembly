///////////////////////
// D0-7 -> PB0-7
// a-g,dp -> PC0-7
// GND -> C4
// GND -> W4
// K3 -> PD2
// K4 -> PD3
.include "m32def.inc"
	
	.org 0x00
	jmp main

	.org 0x002
	jmp pa				; Przerwanie INT0
	.org 0x004
	jmp pb				; Przerwanie INT1

main: 					; program główny
	CLI
	LDI R16, 0xC0		; Obsługa przerwań
	OUT GICR, R16
	SBI PORTD, 3		; przycisk INT1
	SBI PORTD, 2		; przycisk INT0
	LDI R16, 0x0A
    OUT MCUCR, R16		; Rejestr sterujący przerwaniami
	LDI R16, 0xFF
	OUT DDRB, R16
	OUT DDRC, R16		; Port B i C na wyjścia
	OUT PORTC, R16
	OUT PORTB, R16
	LDI R17, 0x00
	LDI R18, 0x00
	SEI
loop:			; początek pętli głównej
	OUT PORTB, R16
	OUT PORTC, R18
	CALL delay2

	OUT PORTC, R18
	OUT PORTB, R17
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
delay2:
	ldi r18, 13		; Opóźnienie 10ms
	ldi r19, 252
L2: dec r19
	brne L2
	dec r18
	brne L2
	nop
	RET
pa:
	ANDI R16, 0b00111100	; Diody 6, 7, 0, 1 trwale zgaszone
	OUT PORTB, R16
	LDI R24, 0x01			; Zapisz, że tryb 1 jest aktywny
	RETI
pb:
	CPI R24, 0x00			; Sprawdź, czy tryb pierwszy jest nieaktywny
	BREQ pa					; Jeśli nieaktywny tryb 1 - uaktywnij go
	ORI R16, 0xFF		
	ANDI R17, 0x00			; Wyświetlanie tak jak w trybie 0
	INC R24					
	ANDI R24, 0x01			; Po kolejnym przyciśnięciu - tryb 1
	RETI 
