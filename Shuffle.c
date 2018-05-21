#include "Shuffle.h"

void ShuffleDeck(){
  int i;
  srand(time(NULL));
  for(i=0;i<98;i++){
    Deck[i]=0;
  }
  for (i=1;i<99;i++){
    int j;
    j = (rand()%98);
    while(Deck[j]!=0){
      j++;
      j%=98;
    }
    Deck[j]=i+1;
  }
  #ifdef PRINTA
  PrintDeck();
  #endif
}

int GetLeftCards (int *i){
  (*i) = 0;
  while  (Deck[(*i)]==0){
    (*i)++;
  }
  //printf("[GLC] %d %d\n", Deck[(*i)], (*i));
  return 98-(*i);
}

void PescaCarte(){
  int player, carta;
  for(player = 0; player < N_player; player ++){
    for(carta = 0;carta<N_carte;carta++){
      if (mano[player][carta] == 0){
        int i = 0, left = 0;
        left = GetLeftCards(&i);
        //printf("[PC] %d\n", i);
        mano[player][carta] = Deck[i];
        Deck[i] = 0;
        #ifdef PRINTA
          printf("Player %d picked up %d as its %d card\n", player, mano[player][carta], carta);
        #endif
      }
    }
  }
}
