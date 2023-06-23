#include "string.h"

#define BLACK 0x0
#define WHITE 0x1

void clearScreen();

void print(const char far *str, 
	unsigned char x, unsigned char y, 
	unsigned char bg_color, unsigned char txt_color, 
	int update_cursor
);

void showCursor(int mode);