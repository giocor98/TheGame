#include "Reader.h"

FILE * fp;

int main(){
  fp = fopen(FILENAME, "w");
  if (fp == NULL){
    printf("Error!!\nI cannot open the file\n");
    return 1;
  }
  fprintf(fp, "st: 0\n");
  return 0;
}
