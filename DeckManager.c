#include "include.h"
#include "Print.h"
#include "Shuffle.h"
#include "Reader.h"
#include "stack.h"

int main(){
  int Initialised = Initialize();
  if(!Initialised){
    #ifdef PRINTA
      printf("Non posso aprire il file\ninizio una nuova partita...\n");
    #endif
    status = 1;
  }else if(Initialised==-1){
    #ifdef PRINTA
      printf("Trovato qalche errore...\n");
    #endif
    return 0;
  }
  if(status==-1||status == 0){
    #ifdef PRINTA
      printf("There is some error...\nStatus is %d\n", status);
    #endif
    return 0;
  }else if(status == 1){
    ShuffleDeck();
  }
  PescaCarte();
  #ifdef PRINTA
    PrintProgram();
  #endif
  WriteProgram();
}
