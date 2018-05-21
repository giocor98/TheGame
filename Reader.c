#include "Reader.h"


FILE * fp;

int Initialize(){
  fp = fopen (FILENAME, "r");
  char ch = 0;
  if (fp == NULL){
    #ifdef PRINTA
      printf("Il file di gioco non esiste\n");
    #endif
    return 0;
  }
  fscanf(fp, "st: %d\n", &status);
  if(status == 0||status == -1){
    fclose(fp);
    return 1;
  }
  fscanf(fp, "N_P: %d\n", &N_player);
  fscanf(fp, "N_C: %d\n", &N_carte);
  #ifdef DEBUG
    printf("Read:\n\tstatus : %d\n\tPlayers : %d\n\tCarte : %d\n", status, N_player, N_carte);
  #endif
  if(status == 1){
    fclose(fp);
    return 1;
  }

  for(int p = 0; p<N_player;p++){
    ch = fgetc(fp);
    while (ch != 'c'&&ch!=EOF){
      ch = fgetc(fp);
    }
    for(int c = 0; c<N_carte; c++){
      fscanf(fp, " ;%d ", &mano[p][c]);
    }

  }

  ch = fgetc(fp);
  while (ch!='p'&&ch!=EOF){
    ch = fgetc(fp);
  }

  for(int i = 0; i<N_PILE; i++){
    fscanf(fp, "\n%d", &pila[i]);
  }
  ch = fgetc(fp);
  while (ch!='m'){
    ch = fgetc(fp);
  }
  for (int i=0;i<98;i++){
    fscanf(fp, "\n%d ", &Deck[i]);
  }

  do{
    ch = fgetc(fp);
    if(ch == 'P'){
      int p, c, x;
      fscanf(fp, "%d, %d, %d\n", &p, &c, &x);
      if(p<0||c<0||x<0||p>N_player||c>N_carte||x>N_PILE){
        #ifdef PRINTA
          printf("Errore nel passaggio parametri\n");
        #endif
        return -1;
      }
      if(AddToStack(p, c, x)){
        #ifdef PRINTA
          printf("\n\n[GAME]added the %d card (%d) of %d player to %d stack\n", c, pila[x], p, x);
        #endif
      }else{
        #ifdef PRINTA
          printf("ERROR\nIcannot add the selected card to the stack\n");
        #endif
        return -1;
      }
    }
  }while(ch!=EOF);

  fclose(fp);
  #ifdef DEBUGVV
    PrintDeck();
  #endif
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
  fprintf(fp, "st: %d\nN_P: %d\nN_C: %d\n", status, N_player, N_carte);

  int p, c;
  for(p = 0; p<N_player; p ++){
    fprintf(fp, "\nCarte di %d:\nc", p);
    for(c = 0;c<N_carte;c++){
      fprintf(fp, " ;%d ", mano[p][c]);
    }
  }

  fprintf(fp, "\n\n\n-p\n");
  for(int i=0;i<N_PILE;i++){
    fprintf(fp, "%d\n", pila[i]);
  }

  fprintf(fp, "\n\n-m\n");

  for (int i=0;i<98;i++){
    fprintf(fp, "%d\n", Deck[i]);
  }
  fclose(fp);
  #ifdef PRINTA
    printf("\nfine\n");
  #endif
  return 1;
}
