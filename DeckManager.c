#include "include.h"
#include "Print.h"
#include "Shuffle.h"
#include "Reader.h"
#include "stack.h"

int main(){
  if(!Initialize()){
    #ifdef PRINTA
      printf("Non posso aprire il file\ninizio una nuova partita...\n");
    #endif
    status = 1;
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
