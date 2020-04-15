/*
 * File: fold.c
 * Author: Braedon Giblin <bgiblin@iastate.edu>
 * Desc: Folds lines that are longer than 80 charactars.
 * Folded lines begin with 4 spaces. 
 * Compile:
 * 	gcc fold.c -o fold.exe
 */

#include <stdio.h>

#define TAB_SPACE 4
#define MAX_LINE_LENGTH 80
int main(void) {
	int c, len = 0;

	while ((c = getchar()) != EOF) {
		len++;
		if (len > MAX_LINE_LENGTH) {
			len = 1 + TAB_SPACE;
			putchar('\n');
			for (int i = 0; i < TAB_SPACE; i++) {
				putchar(' ');
			}
		}
		if (c == '\n') {
			len = 0;
		}
		putchar(c);
	}
}
