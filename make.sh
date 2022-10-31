#!/bin/bash

mv out/bernard-relay-0.c out/bernard-relay0.c
rm out/bernard-relay-*.c
mv out/bernard-relay0.c out/bernard-relay-0.c

set -e

for((i=0; i<4; ++i)) {
	tcc out/bernard-relay-$i.c -o bin/bernard-relay-$i -w
	./bin/bernard-relay-$i > out/bernard-relay-$[i+1].c
}
