program: DeckManager.out Initialiser
		./Initialiser
		rm Initialiser

DeckManager.out: global.o Shuffle.o Print.o Reader.o DeckManager.c stack.o
				gcc -o DeckManager.out DeckManager.c global.o Shuffle.o Print.o Reader.o stack.o

global.o: global.c include.h
		gcc -c -o  global.o global.c

Shuffle.o: Shuffle.c include.h Shuffle.h
		gcc -c -o Shuffle.o Shuffle.c

Print.o: Print.c Print.h include.h
		gcc -c -o  Print.o Print.c

Reader.o: Reader.c Reader.h include.h
		gcc -c -o Reader.o Reader.c

stack.o: stack.c stack.h include.h
		gcc -c -o stack.o stack.c

Initialiser: Starter.c Reader.h include.h
		gcc -o Initialiser Starter.c
