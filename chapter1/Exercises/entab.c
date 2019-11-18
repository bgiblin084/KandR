/*
 * entab.c
 *
 * Author: Braedon Giblin <bgiblin@iastate.edu>
 *
 * Compile:
 * 	gcc entab.c -o entab.exe
 *
 * Replaces strings of spaces with minimal number of tabs and spaces
 */

#include <stdio.h>
#define TAB_STOP 4

int main() {
	int i = 0, c, len = 0;

	while ((c = getchar()) != EOF) {
		while (c == ' ') {
			len++;
			c = getchar();
		}
		if (len > 0) {
			while (len - (TAB_STOP - i) > 0) {
				putchar('\t');
				len -= (TAB_STOP - i);
				i = 0;
			}
			while (len > 0) { 
				putchar(' ');
				len--;
				i = (i + 1) % TAB_STOP;
			}
		}
		if (c == '\n') {
			putchar(c);
			i = 0;
		} else {
			putchar(c);
		}
	}
}
