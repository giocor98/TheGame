#ifndef INCLUDE_H
  #define INCLUDE_H

  #define DEBUG

  #ifdef DEBUG
    #define PRINTA
  #endif

  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <stdlib.h>

  #ifdef PRINTA
    #include "Print.h"
  #endif

  #define MAX_PLAYER 5
  #define MAX_CARTE 8

  extern char mano [MAX_PLAYER][MAX_CARTE];

  extern char Deck[98];
  extern int N_player;
  extern int N_carte;

#endif
