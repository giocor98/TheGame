#ifndef INCLUDE_H
  #define INCLUDE_H

  //#define DEBUGVV
  //#define DEBUG
  //#define PRINTA

  #ifdef DEBUGVV
    #define DEBUG
  #endif

  #ifdef DEBUG
    #define PRINTA
  #endif

  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>

  #ifdef PRINTA
    #include "Print.h"
  #endif

  #define MAX_PLAYER 5
  #define MAX_CARTE 8

  #define N_PILE 4
  #define CRESCENTI 1

  extern int mano [MAX_PLAYER][MAX_CARTE];

  extern int Deck[98], pila[N_PILE];
  extern int N_player;
  extern int N_carte;
  extern int status;

#endif
