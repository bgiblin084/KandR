#include <stdio.h>

#define MAX_WORD_LEN 100

static inline int isWhiteSpace(int c);
void printHistogram(int len[], int length);

int main() {
  int c, length;
  int wordlen[MAX_WORD_LEN];

  for (int i = 0; i < MAX_WORD_LEN; i++) {
    wordlen[i] = 0;
  }

  length = 0;
  while ((c = getchar()) != EOF) {
    if (!isWhiteSpace(c)) {
      length++;
    }
    else if (isWhiteSpace(c) && length > 0) {
      wordlen[(length > MAX_WORD_LEN ? MAX_WORD_LEN : length) - 1]++;
      length = 0;
    }
  }

  printHistogram(wordlen, MAX_WORD_LEN);
}

static inline int isWhiteSpace(int c) {
  return (c == ' ' || c == '\n' || c == '\t');
}

void printHistogram (int len[], int length) {
  int in = 0;
  for (int i = length - 1; i >= 0; i--) {
    if (len[i] > 0 || in) {
      in = 1;
      printf("%2d |", i + 1);
      for (int j = 0; j < len[i]; j++) {
        printf("*");
      }
      printf("\n");
    }
  }
}
