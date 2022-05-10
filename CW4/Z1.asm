//Poniżej podaj swoje dane
//<Imię i nazwisko>
//<Nr indeksu>
//<Grupa studencka>
//<Grupa laboratoryjna>
//Cw4Z1
///////////////////////

.include "m32def.inc"
	.org 0x00
	JMP main

	.org $0002
	JMP proc_interrupt

main:			//początek programu głównego
	//inicjalizacje, konfiguracje
	// Port A i C na wyjście
	IN R16, DDRA
	ANDI R16, 0
	OUT DDRA, R16
	IN R16, DDRC
	ANDI R16, 0
	OUT DDRC, R16
	// Port D - linia 2 na wejście
	IN R16, DDRD
	ORI R16, (1<<2)
	OUT DDRD, R16
	// Podciąganie zasilania do linii D->2
	IN R16, PORTD
	ORI R16, (1<<2)
	OUT PORTD, R16
	// Port A na wyjściu same ON
	IN R16, PORTA
	ORI R16, 255
	OUT PORTA, R16
	// Port C na wyjściu pierwsza ON reszta OFF
	IN R16, PORTC
	ORI R16, (1<<7)
	ANDI R16, 128
	OUT PORTC, R16
	CLI // Blokada przerwań
	ANDI MCUCR, 0b11111100	// Bity 0 i 1 odpowiadają za INT 0
	ORI MCUCR, 0b10			// Bit 0 - 0, Bit 1 - 1 > Reakcja na zbocze 1 -> 0
	ORI GICR, (1<<INT0)	// What the fuck
	SEI // Odblokowanie przerwań
work:
	//kod programu głównego, zgodnie z wymaganiami, co ten program ma wykonywać
	IN R16, PORTC
	ROR R16
	CPI R16, 0
	BRNE PC + 2
	ORI R16, 0b10000000
	OUT PORTC, R16
	CALL delay
	JMP work	//jeżeli działania programu głównego mają być realizowane w nieskończonej pętli
delay: // Opóżnienie 20ms
	ldi  r18, 104
		ldi  r19, 229
	L1: dec  r19
		brne L1
		dec  r18
		brne L1
	RET
proc_interrupt:
	// kod wymagany do prawidłowej obsługi przerwania (ew. także zamierzonej interakcji z programem głównym)
	// Port A zmiana
	IN R16, PORTA
	EOR R16, 255
	OUT PORTA, R16
	RETI		//powrót z procedury obsługi przerwania
