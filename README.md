# Bernard Relay

`bernard-relay-sub.c` contains C source code in the shape of Bernard (from Desmos). Running the code gives you an output that's C source code in the shape of a bigger Bernard, and the process continues forever (in theory; I think it's limited to 7 or something due to some golfing optimization).

The code is repeated here, since it's short:

```c
                            char*s="*(_; bg`q)r  <! *(r9w*x"
                            "*b*n;10::.9k_gl&`*v'yr;q9dmp&)"
                            ")qY10[*w;n9w++9'dmp&v;n(09|v9n"
                            "sraf_p&|++v=v:x=(_=(_))+/8(r=x"
                                                    ")|v$$v"
                                                        "=("
                                            "r))8128`=`++(1"
                                            "28(q=0)(q))8x+"
"v<0=v)w$w=24+v(w#18138258108/.''dmp&b;1(w+n+n-1(1*x;0::1#&"
"b#1'9x(x:b(b9'x(;29{--",*a="dibs+t>#",*t;x,y=32,z,d;main(b)
{t=s;for(++s[32];y--;)for(x=64;~x;putchar(~--x?x<z?*a?*a++-1
:*t?z+~x&&x?*t++:34:b?b--*34:*s?2+*s++:z-x>2?x+y&y?46-x*y%3:
35:47:32:10))for(d=3*y-62,z=3-d%3&6;z*z<d*d;)z*=4;}//Bernard
// Best compiled with tcc (tiny c compiler). To compile with
// gcc, replace `char*s="abc"` with `char*s=(char[]){"abc"}`
```

This was originally made for a Forum Signature Golf challenge: do anything cool, as long as it fits in a 60x15 code box.

## Quick testing

`./run-sun.sh` runs a few iterations of running the code. The outputs are placed into the `./out/` directory.

## How it works

The main code is in `bernard-relay-dev.c`. I got it all working there, then `bernard-relay-sub.c` is just that with some spaces added to look like Bernard.

`bernard-relay-dev.c` looks like the following structure:

```c
char*s=",*a=\"char*s=\\\"\",*t;[draw Bernard]"
,*a="char*s=\"",*t;[draw Bernard]
```

Except, replace `[draw Bernard]` with some code which actually draws Bernard, and the character codes in the strings are offset to avoid any backslash escapes. This is how the Quine-like part works: The string inside `s` is exactly the (offset) text of the second line, so `[draw Bernard]` just has to write `char*s="`, then write the string inside `s`, then a closing quote and a newline, then write the (offset) string inside `s`.

Bernard is drawn based on an implicit inequality described in <https://codegolf.stackexchange.com/a/248827/68261>. Whenever the inequality holds true, the next character is written; otherwise, a space is written. After all the characters in `s` are written, the program starts writing comments filled in with Sierpinski triangles. This took a bunch of manual adjustment to avoid line breaking in the middle of keywords and strings.
