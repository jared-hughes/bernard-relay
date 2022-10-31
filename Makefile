out/bernard-relay-4.c: out/bernard-relay-3.c
	tcc out/bernard-relay-3.c -o bin/bernard-relay-3
	./bin/bernard-relay-3 > out/bernard-relay-4.c

out/bernard-relay-3.c: out/bernard-relay-2.c
	tcc out/bernard-relay-2.c -o bin/bernard-relay-2
	./bin/bernard-relay-2 > out/bernard-relay-3.c

out/bernard-relay-2.c: bernard-relay.c
	tcc bernard-relay.c -o bin/bernard-relay
	./bin/bernard-relay > out/bernard-relay-2.c
