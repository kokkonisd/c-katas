# Exercise 02 - Connect Four

This time, you'll have to code a terminal implementation of (Connect Four)[https://en.wikipedia.org/wiki/Connect_Four].

### Data model definition
In order to make this kata a bit less ambiguous/open, let's define how the game will be displayed and how its data will be handled.

First of all, in order to display the game's board (aka the cells in which you can put the pieces) we're gonna use a 2D array (the board is 7 by 6 cells). Each case of the board array will only take one of three values, that we're going to represent graphically by an empty case and two symbols to distinguish between the two players.

Secondly, to indicate the height at which the piece was placed, we will use an additional 1D array which will serve as a counter of how many pieces are contained in each column. So finally it would look something like this:

```
[ ][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][+][ ][ ][ ]
[ ][ ][ ][+][+][*][ ]
[ ][*][*][+][*][+][ ]
[ ][+][*][*][+][*][+]
[*][*][+][*][+][+][*]
=====================
[1][3][3][5][4][4][2]
```

In this case, crosses (`+`) win.

Finally, in order to make figuring out who won easier, we'll configure the board based on the following values:

- `VISIBLE_COLS`, which refers to the actual number of columns the user will see on the screen;
- `VISIBLE_ROWS`, which refers to the actual number of rows the user will see on the screen;
- `WINNING_LENGTH`, which refers to the _length_ your "chain" of pieces needs to have in order for you to win the game (in this case it's gonna be fixed to 4, because the game's called _connect **four**_);
- `OFFSET`, which refers to an offset taken on all sides of the board so as to facilitate the implementation of the winning algorithm (`WINNING_LENGTH - 1` is all we need);
- `MODEL_COLS`, which refers to the total number of columns of the array (`VISIBLE_COLS + OFFSET`);
- `MODEL_ROWS`, which refers to the total number of rows of the array (`VISIBLE_ROWS + OFFSET`); and finally,
- `MAX_ROUNDS`, which refers to the maximum number of rounds that can be played (`VISIBLE_COLS * VISIBLE_ROWS`).

Not to worry, all of this will be taken care of for you by the code skeleton. Here's the snippet of how all this is defined:

```
#define VISIBLE_COLS 7
#define VISIBLE_ROWS 6
#define WINNING_LENGTH 4
#define OFFSET (WINNING_LENGTH - 1)
#define MODEL_COLS (VISIBLE_COLS + 2 * OFFSET)
#define MODEL_ROWS (VISIBLE_ROWS + 2 * OFFSET)
#define MAX_ROUNDS (VISIBLE_COLS * VISIBLE_ROWS)
```

And that's it!

The steps in the list below will guide you through the kata. Keep in mind that this program needs to be modular; that will mainly happen via directives you will write each time I tell you to _complete `xxx.h` accordingly_.

### Steps of implementation
1. Add three constants in `main.h` to represent the three possible states of each cell (0, -1 and 1). By default, let's say that 0 means that the cell is empty, 1 means that player one has placed a piece in the cell, and -1 means that the cell is occupied by one of player two's pieces. That way, to find out if someone has won, all we need to do is sum the absolute values of neighboring cells and compare it to 4.
2. In `main.c`, define the global variables that will be used to keep track of the number of rounds played (`roundsPlayed`), the board array itself (as explained previously) as well as another array that will keep track of how many pieces are currently contained in each column. Make sure to update `main.h` accordingly.
3. In `main.c`, complete the function called `initGame` that initializes all the global variables correctly.
4. In `printBoard.c`, complete the function called `printCell` that prints a cell of the board based on an integer value.
5. In `printBoard.c`, complete the function called `printBoard` that prints the entire board using the global variables from `main.h` as well as `printBoard` from the previous step.
6. Complete `printBoard.h` accordingly (by adding the three character constants used to visualise the state of each cell).
7. In `handleBoard.c`, complete the function called `getCellValue` that takes in the `x` and `y` coordinates of the **visible** board and returns the integer value of the cell (0, 1 or -1).
8. In `handleBoard.c`, complete the function called `getNumberOfCellPieces` that takes in a column index and returns the number of pieces in that column.
9. In `handleBoard.c`, complete the function called `addPiece` that takes in a column index that the user has specified and correctly inserts the piece in that column. Do not add a test to check if the column is already full; that will be part of step 11.
10. Complete `handleBoard.h` accordingly.
11. In `connectFour.c`, complete the function called `isMoveInvalid` that takes a column index chosen by the player and determines wether the move is valid (false) or invalid (true).
12. In `connectFour.c`, complete the function called `playMove` that prints the board, then prompts the user to enter a column index number until the move the user chooses is valid. The function must return the final choice of the user.
13. In `connectFour.c`, temporarily/partially complete the function called `playGame` so as to be able to play a game of Connect Four without checking if anyone has won (which means you just keep on playing until you reach the maximum number of rounds). You will finish this function in step 15.
14. In `connectFour.c`, complete the function called `isWinningMove` that takes in a column index (referring to the last move played) and determines if that move has won the game or not.
15. In `connectFour.c`, finish the function called `playGame` so as to take into consideration if each move is a winning move (using the previous function, of course). This function also has to print the board once more at the end of the game, as well as print an appropriate message (either "It's a draw", "Player 1 wins" or "Player 2 wins").
16. Complete `connectFour.h` accordingly and complete the `main` function in `main.c` so as to have a working game of Connect Four.

Good luck, and have fun!
