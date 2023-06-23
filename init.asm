.286
.model TINY
.extrn _Boot:near

.code

org 07c00h

main:
	jmp short start
	nop

start:
	cli
	mov ax, cs
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov bp, 7c00h
	mov sp, 7600h
	sti

	call _Boot
	ret

	END main

