#include "Reader.h"

#define FILETURNO "turnogame"

FILE * fp;

int main(){
  fp = fopen(FILENAME, "w");
  if (fp == NULL){
    printf("Error!!\nI cannot open the file\n");
    return 1;
  }
  fprintf(fp, "st: 1\n");
  fclose (fp);
  fp = fopen(FILETURNO, "w");
  if (fp == NULL){
    printf("Error!!\nI cannot open the file\n");
    return 1;
  }
  fprintf(fp, "p 0\n");
  fclose (fp);
  return 0;
}
