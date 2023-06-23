#include "displaymanager.h"

void clearScreen(){
	asm(
		"mov al, 02h\n"
        "mov ah, 00h\n"
        "int 10h\n"
	)
}

void print(const char far *str, 
	unsigned char x, unsigned char y, 
	unsigned char bg_color, unsigned char txt_color,
	int update_cursor){

	unsigned char txt = ((txt_color) | (bg_color << 4));
	unsigned char str_len = strlen(str);

	asm(
		"push bp\n"
		"mov al, %0\n"
		"xor bh, bh\n"
		"mov bl, %1\n"
		"xor cx, cx\n"
		"mov cl, %2\n"
		"mov dh, %3\n"
		"mov dl, %4\n"
		"mov es, word ptr [%5 + 2]\n"
		"mov ds, word ptr [%5]\n"
		"mov ah, 0x13\n"
		"int 0x10\n"
		"pop bp\n"
		:
		:"r" (update_cursor), "r" (txt), "r" (str_len), "r" (str)
		:
	);
}

void showCursor(int mode){
	unsigned char flag = mode ? 0 : 0x32;
	asm(
		"mov ch, %0\n"
		"mov cl, 0Ah\n"
		"mov ah, 01h\n"
		"int 0x10\n"
		:
		:"r" (flag)
		:
	);
}