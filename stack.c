#include "stack.h"

int AddToStack( int player, int card, int Npila){
  if(VerifyAddToStack( player, card, Npila)){
    pila[Npila]= mano[player][card];
    mano[player][card]=0;
    return 1;
  }else{
    return 0;
  }
}

int VerifyAddToStack( int player, int card, int Npila){
  if(Npila == 0 || Npila == 1){
    //pila crescente
    if(pila[Npila]<mano[player][card]||pila[Npila]==10+mano[player][card]){
      return 1;
    }
  }else if(Npila == 2 || Npila == 3){
    //pila crescente
    if(pila[Npila]>mano[player][card]||pila[Npila]==mano[player][card]-10){
      return 1;
    }
  }
  return 0;
}
