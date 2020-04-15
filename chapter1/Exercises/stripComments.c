/*
 * File:
 * 	stripComments.c
 * Author:
 * 	Braedon Giblin <bgiblin@iastate.edu>
 * Desc:
 * 	Removes all comments from a C file
 * Compile:
 * 	gcc stripComments.c -o stripComments.exe
 */

#include <stdio.h>

#define MAX_LINE_LEN 200

typedef enum _state{IN_STRING, IN_INLINE_COMMENT, IN_MULTILINE_COMMENT, OUT} state_t;

int getLine(char s[], int lim);
void putLine(char s[]);

int main() {
	state_t state = OUT;
	char buff[MAX_LINE_LEN]; //, outBuff[MAX_LINE_LENGTH]
	int c, len, prev;

	while ((len = getLine(buff, MAX_LINE_LEN)) > 0) {
		for (int i = 0; buff[i]; i++) {
			if (state == OUT) {
				if (buff[i] == '"') {
					state = IN_STRING;
			//		putchar(buff[i]);
				} else if (buff[i] == '/' && prev == '/') {
					state = IN_INLINE_COMMENT;
				} else if (buff[i] == '*' && prev == '/') {
					state = IN_MULTILINE_COMMENT;
				} else {
			//		putchar(buff[i]);
				}
			} else if (state == IN_STRING) {
				if (buff[i] == '"') {
					state = OUT;
				}
			//	putchar(buff[i]);
			} else if (state == IN_INLINE_COMMENT) {
				state = OUT;
				break;
			} else if (state == IN_MULTILINE_COMMENT) {
				if (buff[i] == '/' && prev == '*') {
					state = OUT;
				}
			}
			if (state == OUT || state == IN_STRING) {
				putchar(prev);
			}
			prev = buff[i];
		}
	}
}

void putLine(char s[]) {
	printf("%s", s);
}

int getLine(char s[], int lim) {
	int c, i = 0;

	while ((c = getchar()) != EOF && c != '\n' && i < (lim - 2)) {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
}
		
