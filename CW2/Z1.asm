//Poniżej podaj swoje dane
//<Imię i nazwisko>
//<Nr indeksu>
//<Grupa studencka>
//<Grupa laboratoryjna>
//Cw2Z1
///////////////////////

.include "m32def.inc"	; Jakaś tam biblioteka
.org 0x00				; coś tam z pamięcią (nieważne pisz)
jmp main				; Skocz do maina
.org 0x100				; to też coś z pamięcią (też pisz)
main:					; Kod główny programu (setup)
	; Rejestr DDR odpowiada za ustalenie kierunku portu (0->wejście, 1->wyjście)
	CBI DDRA, 1			; Wyzeruj bit 1 w DDRA (bit 1 jest wejściem)
	SBI DDRA, 0			; Ustaw bit 0 w DDRA (bit 0 jest wyjściem)
	; Rejestr PORT odpowiada za ustalenie bitów wyjścia. Bity wejściowe domyślnie powinny mieć ustawione 1
	SBI PORTA, 1		; Domyślne ustawienie bitu 1 w DDRA (bit wejściowy => Domyślne 1)
	rjmp loop			; Skocz do pętli nieskończonej
loop:					; Kod wykonywany cały czas (loop)
	; Rejestr PIN przechowuje stany z zewnątrz (wejścia)
	SBIS PINA, 1		; Pomiń następną instrukcję jeśli bit 1 w PINA jest ustawiony (Przycisk wciśnięty)
	CBI PORTA, 0		; Wyzeruj bit 0 na PORTA (Dioda LED nie zapali się) -> Wykona się jeśli nie spełni się warunek powyżej (coś jakby else)
	SBIC PINA, 1		; Pomiń następną instrukcję jeśli bit 1 w PINA jest wyzerowany (Przycisk wyłączony)
	SBI PORTA, 0		; Ustaw bit 0 na PORTA (Dioda LED zapali się) -> Wykona się jak przycisk będzie włączony
	rjmp loop			; wróć na początek
