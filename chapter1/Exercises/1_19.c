#include <stdio.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 100

int getline(char s[], int lim);
void reverse(char s[]);

int main() {
	int len;
	int max;
	char line[MAX_LINE_LENGTH];
	char longest[MAX_LINE_LENGTH];
	
	while ((len = getline(line, MAX_LINE_LENGTH)) >  0) { 
		reverse(line);
		printf("%s\n", line);
	}
}

void reverse(char s[]) {
	char swap;
	int len = 0;
	while(s[len++]);
	len -= 2;
	for (int i = 0; i < len / 2; i++) {
		swap = s[len - i];
		s[len - i] = s[i];
		s[i] = swap;
	}
}

int getline(char s[], int lim) {
	int c, i;
	i = 0;

	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
	  s[i++] = c;
	}
	if (c == '\n') {
	  s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

