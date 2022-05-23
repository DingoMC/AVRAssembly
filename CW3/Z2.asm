///////////////////////
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

	LDI R16, 0b11111111	 
	OUT DDRA, R16			; Zapisanie stanów portów (1 - Wyjście)
ustaw:
	LDI R16, 0b00000011
	RJMP anim
anim:
	OUT PORTA, R16			; Wyświetl wzór
	LSL R16					; Przesuń wzór w lewo
	ldi  r18, 104			; Opóźnienie
    ldi  r19, 229
L1: dec  r19
    brne L1
    dec  r18
    brne L1
	CPI R16, 128			; Jeśli wzór dojdzie do końca to przejdź na początek
	BRNE anim
	RJMP ustaw
