/*
Exercice 02 - Connect Four

Written by Dimitris Kokkonis
https://kokkonisd.github.io
*/

#include "connectFour.h"


bool isMoveInvalid (int colIndex)
{
    /* === Your code starts here === */

    if (colIndex < 0
        || colIndex > VISIBLE_COLS - 1
        || getNumberOfCellPieces(colIndex) == VISIBLE_ROWS)

        return true;

    return false;

    /* === Your code ends here === */
}


int playMove (void)
{
    /* === Your code starts here === */

    printBoard();

    printf("---\n");

    int move;
    int player = roundsPlayed % 2 == 0 ? 1 : 2;

    printf("It's Player %d's turn to play!\n", player);

    do {
        printf("Choose a column between %d and %d: ", 1, VISIBLE_COLS);
        scanf("%d", &move);
    } while (isMoveInvalid(move - 1));

    printf("---\n");

    return move - 1;

    /* === Your code ends here === */
}


bool isWinningMove (int colIndex)
{
    /* === Your code starts here === */



    /* === Your code ends here === */
}


int playGame (void)
{
    /* === Your code starts here === */

    printf("Welcome to Connect Four!\n----\n");

    while (roundsPlayed < MAX_ROUNDS) {
        addPiece(playMove());
    }

    return 0;

    /* === Your code ends here === */
}
