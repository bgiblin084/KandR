#include <stdio.h>

float fahrToCels(int fahr);

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = fahrToCels(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr += step;
  }
}

float fahrToCels(int fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}
