//Poniżej podaj swoje dane
//<Imię i nazwisko>
//<Nr indeksu>
//<Grupa studencka>
//<Grupa laboratoryjna>
//Cw2Z2
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
loop:					; Kod wykonywany cały czas (loop)
	; Sekwencja a
	SBI PORTA, 0
	SBI PORTB, 0
	CBI PORTC, 0
	CBI PORTD, 0
	; Opóźnienie 100ms
    ldi  r18, 130
    ldi  r19, 222
L1: dec  r19
    brne L1
    dec  r18
    brne L1
    nop
	; Sekwencja b
	CBI PORTA, 0
	CBI PORTB, 0
	SBI PORTC, 0
	SBI PORTD, 0
	; Opóźnienie 400ms
	ldi  r18, 3
    ldi  r19, 8
    ldi  r20, 120
L2: dec  r20
    brne L2
    dec  r19
    brne L2
    dec  r18
    brne L2
	; Sekwencja c
	; CBI PORTA, 0 <- to samo co w sekwencji b - useless
	SBI PORTB, 0
	; SBI PORTC, 0 <- to samo co w sekwencji b - useless
	CBI PORTD, 0
	; Opóźnienie 100ms
    ldi  r18, 130
    ldi  r19, 222
L3: dec  r19
    brne L3
    dec  r18
    brne L3
    nop
	rjmp loop			; Wróć na początek
