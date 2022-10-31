char*s=";;n=6,x,y,d,z;putchar();main(){char*a=(char[]){99,104,97,114,42,115,61,34,0},*t=s,*b=(char[]){34,0};for(y=1<<n;y;y--){for(x=2<<n;x;x--){d=3*y-(2<<n)-2+n%2;for(z=1+(1&n^(d>0));z*2<(d<0?-d:d);z*=4){}putchar(z*2<x?32:*a?*a++:*t?*t++:*b?*b++:*s?*s++:47);}putchar(10);}}";
n = 6, x, y, d, z;
putchar();
main() {
  char *a = (char[]){99,104,97,114,42,115,61,34,0}, *t=s, *b = (char[]){34,0};
  for (y = 1 << n; y; y--) {
    for (x = 2 << n; x; x--) {
      d = 3 * y - (2 << n) - 2 + n % 2;
      for (z = 1 + (1 & n ^ (d > 0)); z * 2 < (d < 0 ? -d : d); z *= 4) {
      }
      putchar(
        z * 2 < x ? 32
          : *a ? *a++
          : *t ? *t++
          : *b ? *b++
          : *s ? *s++
          : 47
      );
    }
    putchar(10);
  }
}
