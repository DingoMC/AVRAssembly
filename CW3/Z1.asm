///////////////////////
// PB0 -> K1
// PB1 -> K2
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
	LDI R16, 0b11111111
	OUT DDRA, R16			; Zapisanie stanów portów (1 - Wyjście)
	SBI PORTB, 0			; przycisk "1" na PB0
	SBI PORTB, 1			; przycisk "2" na PB1
	CBI DDRB, 0
	CBI DDRB, 1
loop:						; początek pętli głównej
	IN R16, PINB
	CPI R16, 0b00000000		; Zmiana jeśli oba przyciski są wciśnięte
	BREQ zmiana
	CPI R16, 0b00000001		; Zmiana jeśli przycisk "2" wciśnięty
	BREQ zmiana
	CPI R16, 0b00000010		; Zmiana jeśli przycisk "1" wciśnięty
	BREQ zmiana
	LDI R16, 0b00001111		; Domyślne świecenie ON|ON|ON|ON|OFF|OFF|OFF|OFF
	OUT PORTA, R16			; Wyświetlanie wzoru
	RJMP loop 				; wróć na początek pętli głównej
zmiana:
	LDI R16, 0b11110000		; Zmień stan diod na OFF|OFF|OFF|OFF|ON|ON|ON|ON
	OUT PORTA, R16			; Wyświetlanie wzoru
	RJMP loop				; wróć na początek pętli głównej
