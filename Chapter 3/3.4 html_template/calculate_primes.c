#include <stdlib.h>
#include <stdio.h>
#include <emscripten.h>

int IsPrime(int n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  }
  return 1;
}

int main() {
  int start = 3;
  int end = 100000;

  printf("Prime  numbers between %d and %d:\n", start, end);

  for (int i = start; i <= end; i += 2) {
    if(IsPrime(i)){
        printf("%d ", i);
    }
  }

  printf("\n");
}

