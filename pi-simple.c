#include <stdio.h>
#include <stdlib.h>
#define SCALE 4
#define f ((int)1e4)
b, c, d, e, i, *a, N, L;
// Usage: pi-simple 1002 for 1002 digits of pi
int main(int C, char **argv) {
  if (C < 2)
    N = 1002;
  else
    sscanf(argv[1], "%d", &N);
  L = 10 * N / 3 + 1;
  a = malloc(L * sizeof(int));
  char *format = "%03d";
  format[2] = SCALE + '0';
  c = N / SCALE + 1;
  for (; c--; i++) {
    d %= f;
    e = d;
    for (b = L; --b > 0; d /= b * 2 - 1) {
      d = d * b + f * (i > 0 ? a[b] : 2);
      a[b] = d % (b * 2 - 1);
    }
    printf(i ? format : "3.", e + d / f);
  }
}
