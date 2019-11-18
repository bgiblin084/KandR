#include <stdio.h>

#define MAX_LINE_LENGTH 50

int getline(char s[], int lim);
int copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAX_LINE_LENGTH];
  char longest[MAX_LINE_LENGTH];

  while ((len = getline(line, MAX_LINE_LENGTH)) > 0) {
    if (len >= MAX_LINE_LENGTH - 1) {
      max += len;
    } else if (len > max) {
      max = len;
      copy(longest, line);
    }

  }
  if (max > 0) {
    printf("%d\n", max);
    printf("%s", longest);
  }
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
      s[i] = c;
    }
    if (c == '\n') {
      s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int copy(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i++]) != '\0')
    ;
}
