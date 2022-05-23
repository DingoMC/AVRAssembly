///////////////////////
// PB0 -> K1
// PD0 -> K2
// W1 -> GND
// PA0 -> D0
// PA1 -> D1
// PA2 -> D2
// PA3 -> D3
// PA4 -> D4
// PA5 -> D5
// PA6 -> D6
// PA7 -> D7

	.include "m32def.inc"
	.org 0x00
	jmp main
	.org 0x100
main: 						; program główny
	LDI r16, low(RAMEND)	; Inicjalizacja wskaźnika stosu
	OUT SPL, r16
	LDI r16, high(RAMEND)
	OUT SPH, r16

	LDI R20, 0b00001100
	LDI R16, 0b11111111
	OUT DDRA, R16			; Zapisanie stanów portów (1 - Wyjście)
	SBI PORTB, 0			; przycisk na PB0 LED0/7 - ON
	SBI PORTD, 0			; przycisk na PD0 LED3/4 - NEG
setup:
	LDI R16, 0b00000011
loop:						; początek pętli głównej
	MOV R17, R16
	SBIS PINB, 0			; Jeśli przycisk na PB0 wciśnięty zaimplementuj maskę
	ORI R17, 0b10000001		; Implementacja maski dla D0 i D7
	SBIS PIND, 0			; Jeśli przycisk na PD0 wciśnięty zaimplementuj maskę
	EOR R17, R20			; Implementacja maski dla D3 i D4
	OUT PORTA, R17			; Wyświetlanie wzoru (z ewentualną maską)
	RCALL op				; Wywołaj procedurę opóźnienia
	OUT PORTA, R16
	LSL R16					; Przesuń wzór w lewo
	CPI R16, 128			; Jeśli wzór dojdzie do końca to zresetuj animację
	BREQ setup
	RJMP loop 				; wróć na początek pętli głównej
op:							; Opóźnienie
    ldi  r18, 104
    ldi  r19, 229
L1: dec  r19
    brne L1
    dec  r18
    brne L1
	RET
