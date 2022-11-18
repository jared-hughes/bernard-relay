# Bernard Relay

`bernard-relay-sub.c` contains C source code in the shape of Bernard (from Desmos). Running the codee gives you an output that's C source code in the shape of a bigger Bernard, and the process continues forever (in theory; I think it's limited to 7 or something due to some golfing optimization).

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
