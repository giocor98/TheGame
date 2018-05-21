#include "Print.h"

void PrintDeck(){
  int i;
  for(i=0;i<98;i++){
    printf("%d - %d\n", i+1, Deck[i]);
  }
}

void PrintMano(){
  int p, c;
  for(p = 0;p<N_player;p++){
    printf("Mano di %d:\n", p);
    for(c = 0; c<N_carte; c++){
      printf("%d ;", mano[p][c]);
    }
    printf("\n");
  }
}

void PrintPila(){
  for(int i = 0;i<N_PILE;i++){
    printf("Pila %s %d:\t%d\n", (i<=CRESCENTI?"crescente":"decrescente"), i, pila[i]);
  }
}

void PrintProgram(){
  PrintMano();
  PrintPila();
}
