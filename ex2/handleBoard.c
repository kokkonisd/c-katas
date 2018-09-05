/*
Exercice 02 - Connect Four

Written by Dimitris Kokkonis
https://kokkonisd.github.io
*/

#include "handleBoard.h"


int getCellValue (int visibleX, int visibleY)
{
    /* === Your code starts here === */

    return board[OFFSET + visibleX][OFFSET + visibleY];

    /* === Your code ends here === */
}


int getNumberOfCellPieces (int colIndex)
{
    /* === Your code starts here === */

    return numberOfPieces[colIndex];

    /* === Your code ends here === */
}


void addPiece (int colIndex)
{
    /* === Your code starts here === */

    int piece = (roundsPlayed % 2 == 0) ? 1 : -1;
    int rowIndex = OFFSET + VISIBLE_ROWS - getNumberOfCellPieces(colIndex) - 1;

    board[rowIndex][OFFSET + colIndex] = piece;

    roundsPlayed++;
    numberOfPieces[colIndex]++;

    /* === Your code ends here === */
}
