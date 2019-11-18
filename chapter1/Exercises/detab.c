/* detab.c
 * 
 * Author: Braedon Giblin <bgiblin@iastate.edu>
 *
 * To compile:
 * 	gcc detab.c -o detab.exe
 *
 */

#include <stdio.h>

#define TAB_STOP 4

int main() {
	int c;
	int i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t'){
			do {
				putchar(' ');
				i = (i + 1) % TAB_STOP;
			} while (i);
		} else if(c == '\n') {
			putchar(c);
			i = 0;	
		} else {
			putchar(c);
			i = (i + 1) % TAB_STOP;
		}
	}
}
