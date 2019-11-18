#include <stdio.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 100

int getline(char s[], int lim);
int trimEnd(char s[]);

int main() {
	int len;
	int max;
	char line[MAX_LINE_LENGTH];
	char longest[MAX_LINE_LENGTH];
	
	while ((len = getline(line, MAX_LINE_LENGTH)) >  0) { 
		len = trimEnd(line);
		if (len > 0) {
			printf("%s\n", line);
		}
	}
}

int trimEnd(char s[]){
	int i = 0;
	while(s[i]) {
		i++;
	}
	i--;
	while(isspace(s[i]) && i >= 0){
		s[i--] = '\0';
	}
	return i + 1;
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

