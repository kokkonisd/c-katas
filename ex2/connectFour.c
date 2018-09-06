/*
Exercice 02 - Connect Four

Written by Dimitris Kokkonis
https://kokkonisd.github.io
*/

#include "connectFour.h"


int abs (int x)
{
    return x >= 0 ? x : -x;
}


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

    int rowIndex = OFFSET + VISIBLE_ROWS - getNumberOfCellPieces(colIndex);
    int d = 3;

    for (int i = OFFSET + colIndex - 3; i < OFFSET + colIndex + 1; i++) {
        bool isHorizontalWin = abs(board[rowIndex][i]
            + board[rowIndex][i + 1]
            + board[rowIndex][i + 2]
            + board[rowIndex][i + 3]) == 4;

        bool isDiagonalTopToBottomWin = abs(board[rowIndex - d][i]
            + board[rowIndex - d + 1][i + 1]
            + board[rowIndex - d + 2][i + 2]
            + board[rowIndex - d + 3][i + 3]) == 4;

        bool isDiagonalBottomToTopWin = abs(board[rowIndex + d][i]
            + board[rowIndex + d - 1][i + 1]
            + board[rowIndex + d - 2][i + 2]
            + board[rowIndex + d - 3][i + 3]) == 4;

        bool isDiagonalWin = isDiagonalTopToBottomWin || isDiagonalBottomToTopWin;

        if (isHorizontalWin || isDiagonalWin) return true;

        d--;
    }

    for (int i = rowIndex - 3; i < rowIndex + 1; i++) {
        bool isVerticalWin = abs(board[i][OFFSET + colIndex]
            + board[i + 1][OFFSET + colIndex]
            + board[i + 2][OFFSET + colIndex]
            + board[i + 3][OFFSET + colIndex]) == 4;

        if (isVerticalWin) return true;
    }

    return false;

    /* === Your code ends here === */
}


void playGame (void)
{
    /* === Your code starts here === */

    printf("Welcome to Connect Four!\n----\n");

    int move;

    do {
        move = playMove();

        addPiece(move);

    } while (roundsPlayed < MAX_ROUNDS && !isWinningMove(move));

    printf("\n====================\n");
    if (roundsPlayed == MAX_ROUNDS) printf("It's a tie!");
    else if (roundsPlayed % 2 != 0) printf("Player 1 wins!");
    else printf("Player 2 wins!");

    printf("\n====\n");

    printBoard();

    printf("====\n");

    /* === Your code ends here === */
}
