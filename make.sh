#!/bin/bash

set -e

tcc bernard-relay.c -o bin/bernard-relay -w
./bin/bernard-relay > out/bernard-relay-1.c

for((i=1; i<3; ++i)) {
	tcc out/bernard-relay-$i.c -o bin/bernard-relay-$i -w
	./bin/bernard-relay-$i > out/bernard-relay-$[i+1].c
}