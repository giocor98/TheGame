#include "Shuffle.h"

void ShuffleDeck(){
  int i;
  srand(time(NULL));
  for(i=0;i<98;i++){
    Deck[i]=0;
  }
  pila[0]=pila[1]=1;
  pila[2]=pila[3]=100;
  for (i=1;i<99;i++){
    int j;
    j = (rand()%98);
    while(Deck[j]!=0){
      j++;
      j%=98;
    }
    Deck[j]=i+1;
  }
  for(i=0;i<N_player;i++){
    for(int c = 0; c<N_carte; c++){
      mano[i][c]=0;
    }
  }
  #ifdef PRINTA
    PrintDeck();
  #endif
  status = 2;
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
        #ifdef DEBUG
          printf("[PC] %d\n", i);
        #endif
        mano[player][carta] = Deck[i];
        Deck[i] = 0;
        #ifdef PRINTA
          printf("Player %d picked up %d as its %d card\n", player, mano[player][carta], carta);
        #endif
      }
    }
  }
  ReorderCards();
}

void ReorderCards(){
  int p, c, i;
  char swap;
  for (p = 0; p<N_player;p++){
    for(c = 0;c<N_carte;c++){
      for(i=c;i<N_carte;i++){
        if(mano[p][i]<mano[p][c]){
          swap = mano[p][c];
          mano[p][c]=mano[p][i];
          mano[p][i] = swap;
        }
      }
    }
  }
}
