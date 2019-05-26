#include <stdio.h>

int main() {
  for (int c, prev = -1; (c = getchar()) != EOF;) {
    if ((c == ' ' || c == '\t' || c == '\n') && (prev != ' ' && prev != '\t' && prev != '\n')) {
      putchar('\n');
    } else if (c != ' ' && c != '\t' && c != '\n') {
      putchar(c);
    }
    prev = c;
  }
}
