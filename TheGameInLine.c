#include "include.h"
#include "Reader.h"
#include "Print.h"
#include "stack.h"

#define FILETURNO "turnogame"

int mano [MAX_PLAYER][MAX_CARTE];
int Deck[98], pila[N_PILE];
int N_player;
int N_carte;
int status;

int player;

int main(){
  int Initialised = Initialize();
  int mossa = 0;
  printf("Initialised: %d\n", Initialised);

  if (status == 1||status == 0){
    printf("Starting a new game\n");
    printf("Insert the number of players...");
    scanf("%d", &N_player);
    printf("Insert the number of cards...");
    scanf("%d", &N_carte);
    WriteProgram();
    return 1;
  }

  FILE * fp;
  char ch;
  printf("OK\n");
  fp = fopen(FILETURNO, "r");
  if(fp == NULL){
    player = 0;
  }else{
    do{
      ch = fgetc(fp);
    }while(ch!='p'&&ch!=EOF);
    if (ch == EOF){
      player = 0;
    }else{
      fscanf(fp, "%d", &player);
    }
    fclose(fp);
  }
  ch = 0;
  while(ch!='p'&& ch!='l'){
    if (player>=N_player){
      player = 0;
    }
    printf("Player : %d\n", player);
    PrintPlayerHand(player);
    PrintPila();
    printf("movment : %d\nWhat to do?(p->pass turn, l->lose, anyother -> play)", mossa);
    scanf(" %c", &ch);
    if (ch == 'l'){
      status = 0;
      break;
    }else if(ch !='p'){
      int c, x;
      printf("che carta scegli?\n");
      scanf(" %d", &c);
      printf("Su che pila la metti?\n");
      scanf(" %d", &x);
      if(AddToStack(player, c, x)){
        printf("Fatto!\n\n\n\n");
        mossa ++;
      }else{
        printf("Non e' possibile\n\n\n");
      }
    }
  }
  if (mossa <1){
    printf("\n\n\nYou've lost!!\n\n");
    status = -2;
    player = 0;
  }else if (mossa <2 && Deck[98]!=0){
    printf("\n\nYou've lost!!!\n\n\n");
    status = -2;
    player = 0;
  }else{
    printf("\n\nNext Turn\n\n\n");
    player ++;
  }
  WriteProgram();
  fp = fopen(FILETURNO, "w");
  if (fp == NULL){
    printf("ERROR\nI cannot open the turno file\n");
    return -1;
  }
  fprintf(fp, "p %d\n", player);
  fclose(fp);
}
