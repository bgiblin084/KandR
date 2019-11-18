#include <stdio.h>

int main() {
	int c, i = 0;
	char buff[100];
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (i > 80) {
				// Print lines greater than 80 Chars
				printf("%s\n", buff);
			}
			i = 0;
		} else {
			buff[i++] = c;
			buff[i] = '\0';
		}
	}
}

//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
