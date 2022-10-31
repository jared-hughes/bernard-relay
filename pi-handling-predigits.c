#include <stdio.h>
#include <stdlib.h>
// https://www.maa.org/sites/default/files/pdf/pubs/amm_supplements/Monthly_Reference_12.pdf
int i, j, k, q, x, n, p, N, L, *a;
// Usage: pi-handling-predigits 1002 for 1002 digits of pi
int main(int C, char **argv) {
  if (C < 2)
    N = 1002;
  else
    sscanf(argv[1], "%d", &N);
  L = 10 * N / 3 + 1;
  a = malloc(L * sizeof(int));
  printf("3.");
  for (j = 0; j < N; j++) {
    q = 0;
    for (i = L; i >= 1; i--) {
      if (j == 0)
        a[i] = 2;
      x = 10 * a[i] + q * i;
      a[i] = x % (2 * i - 1);
      q = x / (2 * i - 1);
    }
    a[1] = q % 10;
    q = q / 10;
    if (q == 9)
      n++;
    else if (q == 10) {
      printf("%d", p + 1);
      for (; n; n--)
        printf("0");
      p = 0;
    } else {
      if (j > 1)
        printf("%d", p);
      p = q;
      for (; n; n--)
        printf("9");
    }
  }
}
