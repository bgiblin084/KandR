#include <stdio.h>
#include <ctype.h>

static inline int isWhiteSpace(int c);
void printHistogram(int len[], int length);

int main() {
  int c;

  int letters[26];
  int numbers[10];


  for (int i = 0; i < 26; i++) {
    letters[i] = 0;
  }

  for (int i = 0; i < 10; i++) {
    numbers[i] = 0;
  }

  while ((c = toupper(getchar())) != EOF) {
    if (c >= 'A' && c <= 'Z') {
      letters[c - 'A']++;
    } else if (c >= '0' && c <= '9') {
      numbers[c - '0']++;
    }
  }

  printHistogram(letters, 26);
  printHistogram(numbers, 10);
}

static inline int isWhiteSpace(int c) {
  return (c == ' ' || c == '\n' || c == '\t');
}

void printHistogram (int len[], int length) {
  int in = 0;
  for (int i = length - 1; i >= 0; i--) {
    in = 1;
    if (length == 26)
      printf("%c |", i + 'A');
    else printf("%d |", i);
    for (int j = 0; j < len[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}
