#include <stdio.h>

int main() {
  int prev;
  for (int c; (c = getchar()) != EOF;) {
    if (prev != ' ' || c != ' ') {
      putchar(c);
    }
    prev = c;
  }
}
