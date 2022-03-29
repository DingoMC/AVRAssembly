//Poniżej podaj swoje dane
//<Imię i nazwisko>
//<Nr indeksu>
//<Grupa studencka>
//<Grupa laboratoryjna>
//Cw2Z3
///////////////////////

.include "m32def.inc"	; Jakaś tam biblioteka
.org 0x00				; coś tam z pamięcią (nieważne pisz)
jmp main				; Skocz do maina
.org 0x100				; to też coś z pamięcią (też pisz)
main:					; Kod główny programu (setup)
	; Ustawienie pinów dla LED na wyjścia
	SBI DDRA, 0
	SBI DDRB, 0
	SBI DDRC, 0
	SBI DDRD, 0
	; Ustawienie pinów dla przycisków na wejścia
	CBI DDRA, 7			; Przycisk A
	SBI PORTA, 7
	CBI DDRD, 7			; Przycisk B
	SBI PORTD, 7
loop:					; Kod wykonywany cały czas (loop)
	; Sekwencja a
	SBI PORTA, 0
	SBI PORTB, 0
	CBI PORTC, 0
	CBI PORTD, 0
	SBIC PIND, 7		; Jeżeli przycisk B nie jest wciśnięty pomiń następną instrukcję
	SBI PORTD, 0		; Jeśli jest wciśnięty to włącz diodę D
	; Opóźnienie 500ms
	ldi  r18, 3
    ldi  r19, 138
    ldi  r20, 86
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
    rjmp PC+1
	; Sekwencja b
	CBI PORTA, 0
	SBIC PINA, 7		; Jeżeli przycisk A nie jest wciśnięty pomiń następną instrukcję
	SBI PORTA, 0		; Jeśli jest wciśnięty to włącz diodę A
	CBI PORTB, 0
	SBI PORTC, 0
	SBI PORTD, 0
	; Opóźnienie 200ms
	ldi  r18, 2
    ldi  r19, 4
    ldi  r20, 187
L2: dec  r20
    brne L2
    dec  r19
    brne L2
    dec  r18
    brne L2
    nop
	rjmp loop			; Wróć na początek
