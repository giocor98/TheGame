#include "include.h"
#include "Print.h"
#include "Shuffle.h"
#include "Reader.h"

int main(){
  if(!Initialize()){
    ShuffleDeck();
    PescaCarte();
  }
  PrintMano();
  WriteProgram();
}
