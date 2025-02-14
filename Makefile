CFLAGS = -ansi -pedantic -Wall

all: partA partB

partA: cs457_crypto.h cs457_crypto.c demo.c
	gcc $(CFLAGS) -o crypto cs457_crypto.c demo.c

partB: ask7.c
	gcc $(CFLAGS) -o ask7 ask7.c
