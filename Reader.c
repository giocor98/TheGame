#include "Reader.h"

FILE * fp;

int Initialize(){
  fp = fopen (FILENAME, "r");
  char ch = 0;
  if (fp == NULL){
    #ifdef PRINTA
      printf("Il file di gioo non esiste\n");
    #endif
    return 0;
  }
  fscanf(fp, "N_P: %d", &N_player);
  fscanf(fp, "N_C: %d", &N_carte);

  for(int p = 0; p<N_player;p++){
    ch = fgetc(fp);
    while (ch != 'c'){
      ch = fgetc(fp);
    }
    for(int c = 0; c<N_carte; c++){
      fscanf(fp, " ;%d ", &mano[p][c]);
    }

  }
  ch = fgetc(fp);
  while (ch!='m'){
    ch = fgetc(fp);
  }
  for (int i=0;i<98;i++){
    fscanf(fp, "\n%d ", &Deck[i]);
  }

  fclose(fp);
  PrintDeck();
  return 1;
}

int WriteProgram(){
  fp = fopen (FILENAME, "w");
  if (fp == NULL){
    #ifdef PRINTA
      printf("Non riesco a scrivere il programma...\n");
    #endif
    return 0;
  }
  fprintf(fp, "N_P: %d\nN_C: %d\n", N_player, N_carte);

  int p, c;
  for(p = 0; p<N_player; p ++){
    fprintf(fp, "\nCarte di %d:\nc", p);
    for(c = 0;c<N_carte;c++){
      fprintf(fp, " ;%d ", mano[p][c]);
    }
  }

  fprintf(fp, "\n\nm\n");

  for (int i=0;i<98;i++){
    fprintf(fp, "%d\n", Deck[i]);
  }
  fclose(fp);
  printf("\nfine\n");
  return 1;
}
