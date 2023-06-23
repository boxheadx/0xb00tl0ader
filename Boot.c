#include "displaymanager.h"

#define str "niggaaaaa caaaaaaaat"

extern void Boot(){
	clearScreen();
	showCursor(0);
	print(str, 0,0, BLACK, WHITE, 0);
}