program: global.o Shuffle.o Print.o main.c
		gcc -o program main.c global.o Shuffle.o Print.o

global.o: global.c include.h
		gcc -c -o  global.o global.c

Shuffle.o: Shuffle.c include.h Shuffle.h
		gcc -c -o Shuffle.o Shuffle.c

Print.o: Print.c Print.h include.h
		gcc -c -o  Print.o Print.c
