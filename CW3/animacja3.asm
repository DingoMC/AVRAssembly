.include "m32def.inc"
.org 0x00
jmp main
.org 0x100

main:	
	LDI R16, 0b11111111
	OUT DDRA, R16
setup:
	LDI R17, 0b10000000
	MOV R18, R17
anim:
	OUT PORTA, R17
	LSR R18
	OR R17, R18
	CPI R18, 0
	brne anim
	rjmp setup
