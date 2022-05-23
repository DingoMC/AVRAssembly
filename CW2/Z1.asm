///////////////////////
//PA0->D0
//PA1->W1
//K1->GND

.include "m32def.inc"
	
	.org 0x00
	jmp main

	.org 0x100
main: 				; program główny
					; tutaj ciąg instrukcji inicjalizacyjnych
	CBI DDRA, 1		; Bit 1 jako wejście (przycisk "1")
	SBI PORTA, 1	; Podciągnięcie PA1 do zasilania
	SBI DDRA, 0		; Bit 0 jako wyjście (dioda LED D0)
loop:				; początek pętli głównej
					; instrukcje pętli głównej
	SBIS PINA, 1	; Jeżeli przycisk "1" nie będzie wciśnięty to pomiń następną instrukcję
	CBI PORTA, 0	; Jeżeli przycisk "1" jest wciśnięty to zgaś diodę D0
	SBIC PINA, 1	; Jeżeli przycisk "1" będzie wciśnięty to pomiń następną instrukcję
	SBI PORTA, 0	; Jeżeli przycisk "1" nie jest wciśnięty to zapal diodę D0
	rjmp loop 		; wróć na początek pętli głównej

