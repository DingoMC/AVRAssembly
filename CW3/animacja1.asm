.include "m32def.inc"
.org 0x00
jmp main
.org 0x100

main:	
	LDI R16, 0b11111111
	OUT DDRA, R16
setup:
	LDI R17, 0b11000000
przod:
	OUT PORTA, R17
	LSR R17
	CPI R17, 3
	brne przod
tyl:
	OUT PORTA, R17
	LSL R17
	CPI R17, 192
	brne tyl
	rjmp setup
