#include <stdlib.h>
#include <stdio.h>
//#include <system.h>

int main(){
  char ch;
  printf("Welcome in \"The Game\" game...\nPress any char to start(r to restart)");
  scanf("%c", &ch);
  if (ch == 'r'){
      system("./Initialiser");
  }
  ch = 0;
  printf("Press any char to continue, e to exit\n");
  do{
    system("./TheGameInLine");
    system("./DeckManager.out");
    system("clear");
    printf("Press any char to continue, e to exit\n");
    scanf("%c\n", &ch);
  }while(ch !='e');
  return 0;
}
