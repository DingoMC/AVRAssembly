///////////////////////
// PA0->D0
// PB0->D1
// PC0->D2
// PD0->D3
// PA7->W1
// PD7->W2
// K4->GND

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
	CBI DDRA, 7		; Bit 7 portu A jako wejście (przycisk "A")
	SBI PORTA, 7	; Podciągnięcie PA7 do zasilania
	CBI DDRD, 7		; Bit 7 portu D jako wejście (przycisk "B")
	SBI PORTD, 7	; Podciągnięcie PD7 do zasilania
loop:			; początek pętli głównej
				; instrukcje pętli głównej
	; Sekwencja a (ON|ON|OFF|OFF)
	SBI PORTA, 0
	SBI PORTB, 0
	CBI PORTC, 0
	CBI PORTD, 0
	SBIS PIND, 7	; Jeżeli przycisk B nie będzie wciśnięty to pomiń następną instrukcję
	SBI PORTD, 0	; Jeżeli przycisk B wciśnięty to zaświeć diodę D3
	; Opóźnienie 500ms
	ldi  r18, 41
    ldi  r19, 150
    ldi  r20, 128
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
	; Sekwencja b (OFF|OFF|ON|ON)
	CBI PORTA, 0
	SBIS PINA, 7	; Jeżeli przycisk A nie będzie wciśnięty to pomiń następną instrukcję
	SBI PORTA, 0	; Jeżeli przycisk A wciśnięty to zaświeć diodę D0
	CBI PORTB, 0
	SBI PORTC, 0
	SBI PORTD, 0
	; Opóźnienie 200ms
	ldi  r18, 17
    ldi  r19, 60
    ldi  r20, 204
L2: dec  r20
    brne L2
    dec  r19
    brne L2
    dec  r18
    brne L2
	rjmp loop 	; wróć na początek pętli głównej
