/*
Exercice 02 - Connect Four

Written by Dimitris Kokkonis
https://kokkonisd.github.io
*/

#ifndef __PRINT_BOARD_H__
#define __PRINT_BOARD_H__

#include <stdio.h>
#include "main.h"
#include "handleBoard.h"

/* === Your code starts here === */

#define SYMBOL_EMPTY ' '
#define SYMBOL_P1 '+'
#define SYMBOL_P2 '*'

extern void printCell (int piece);
extern void printBoard (void);

/* === Your code ends here === */

#endif
