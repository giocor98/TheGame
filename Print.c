#include "Print.h"

void PrintDeck(){
  int i;
  for(i=0;i<98;i++){
    printf("%d - %d\n", i+1, Deck[i]);
  }
}
