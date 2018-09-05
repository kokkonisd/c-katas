/*
Exercice 02 - Connect Four

Written by Dimitris Kokkonis
https://kokkonisd.github.io
*/

#include "printBoard.h"


void printCell (int piece)
{
    /* === Your code starts here === */

    switch (piece) {
        case CELL_EMPTY:
            printf("[%c]", SYMBOL_EMPTY);
            break;
        case CELL_P1:
            printf("[%c]", SYMBOL_P1);
            break;
        case CELL_P2:
            printf("[%c]", SYMBOL_P2);
            break;
        default:
            printf("ERROR: Unknown cell value '%d'.\n", piece);
    }

    /* === Your code ends here === */
}


void printBoard (void)
{
    /* === Your code starts here === */

    for (int i = 0; i < VISIBLE_ROWS; i++) {
        for (int j = 0; j < VISIBLE_COLS; j++) {
            printCell(getCellValue(i, j));
        }
        printf("\n");
    }

    /* === Your code ends here === */
}
