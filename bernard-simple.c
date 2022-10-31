n, x, y, d, z;
main() {
  n = 4;
  for (y = 1 << n; y; y--) {
    for (x = 1 << n; x; x--) {
      d = 3 * y - (2 << n) - 2 + n % 2;
      for (z = 1 + (1 & n ^ (d > 0)); z * 2 < (d < 0 ? -d : d); z *= 4) {
      }
      printf(z >= x ? "██" : "  ");
    }
    puts("");
  }
}
