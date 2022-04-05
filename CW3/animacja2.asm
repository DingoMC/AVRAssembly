.include "m32def.inc"
.org 0x00
jmp main
.org 0x100

main:	
	LDI R16, 0b11111111
	OUT DDRA, R16
setup:
	LDI R17, 0b10000000
	LDI R18, 0b01000000
przod:
	OUT PORTA, R17
	OR R17, R18
	LSR R18
	CPI R17, 248
	BRNE przod
	LSL R17
tyl:
	OUT PORTA, R17
	LSL R17
	BRNE tyl
	RJMP setup
