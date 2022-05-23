///////////////////////
// PA0->D0
// PB0->D1
// PC0->D2
// PD0->D3
.include "m32def.inc"
	
	.org 0x00
	jmp main

	.org 0x100
main: 			; program główny
				; tutaj ciąg instrukcji inicjalizacyjnych
	; Ustawianie PA0, PB0, PC0, PD0 jako wyjścia
	SBI DDRA, 0
	SBI DDRB, 0
	SBI DDRC, 0
	SBI DDRD, 0
loop:			; początek pętli głównej
				; instrukcje pętli głównej
	; Sekwencja a (ON|ON|OFF|OFF)
	SBI PORTA, 0
	SBI PORTB, 0
	CBI PORTC, 0
	CBI PORTD, 0
	; Opóźnienie 100ms
	ldi  r18, 9
    ldi  r19, 30
    ldi  r20, 229
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
    nop
	; Sekwencja b (OFF|OFF|ON|ON)
	CBI PORTA, 0
	CBI PORTB, 0
	SBI PORTC, 0
	SBI PORTD, 0
	; Opóźnienie 400ms
	ldi  r18, 33
    ldi  r19, 120
    ldi  r20, 153
L2: dec  r20
    brne L2
    dec  r19
    brne L2
    dec  r18
    brne L2
    nop
	; Sekwencja c (OFF|ON|ON|OFF)
	; CBI PORTA, 0
	SBI PORTB, 0
	; SBI PORTC, 0
	CBI PORTD, 0
	; Opóźnienie 100ms
	ldi  r18, 9
    ldi  r19, 30
    ldi  r20, 229
L3: dec  r20
    brne L3
    dec  r19
    brne L3
    dec  r18
    brne L3
    nop
	rjmp loop 	; wróć na początek pętli głównej
