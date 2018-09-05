/*
Exercice 02 - Connect Four

Written by Dimitris Kokkonis
https://kokkonisd.github.io
*/

#include "main.h"

/* === Your code starts here === */

int roundsPlayed;
int board[MODEL_ROWS][MODEL_COLS];
int numberOfPieces[MODEL_COLS];

/* === Your code ends here === */


void initGame (void)
{
    /* === Your code starts here === */

    roundsPlayed = 0;

    for (int i = 0; i < MODEL_COLS; i++) {
        numberOfPieces[i] = 0;

        for (int j = 0; j < MODEL_ROWS; j++) {
            board[j][i] = CELL_EMPTY;
        }
    }

    /* === Your code ends here === */
}


int main (int argc, char *argv[])
{
    /* === Your code starts here === */

    initGame();

    playGame();

    /* === Your code ends here === */

    return 0;
}
