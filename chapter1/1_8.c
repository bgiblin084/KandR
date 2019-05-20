#include <stdio.h>

int main() {
  int c, blanks, tabs, nl;

  blanks = tabs = nl = 0;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case ' ':
        blanks++;
        break;
      case '\t':
        tabs++;
        break;
      case '\n':
        nl++;
        break;
      default:
        break;
    }
  }
  printf("Blanks: %d\nTabs: %d\nNewlines: %d", blanks, tabs, nl);
}
