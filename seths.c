#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3]; // Global tic-tac-toe board

// Function declarations
void boardReset();
void boardSetUp();
int freeSpace();
void moveComputer();
void movePlayer();
char checkWin();
void printWin();

int main()
{
    char play = ' ';
    srand(time(0)); // Seed random number generator

    printf("Would you like to play? (Y = yes, N = no): ");
    scanf_s(" %c", &play, 1);

    if (play == 'y' || play == 'Y') {
        boardReset(); // Reset the board before starting

        do {
            boardSetUp(); // Display the board
            movePlayer(); // Player's move
            if (checkWin() != ' ' || freeSpace() == 0) break; // Check if game is over

            printf("\nCPU's turn\n");
            moveComputer(); // CPU's move
        } while (checkWin() == ' ' && freeSpace() > 0);

        boardSetUp(); // Display final board
        printWin(); // Print winner or tie
    }
    return 0;
}

// Resets the board to empty spaces
void boardReset() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Displays the current board state
void boardSetUp() {
    printf("\n");
    int position = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                printf(" %d ", position); // Show position number
            else
                printf(" %c ", board[i][j]);
            if (j < 2) printf("|"); // Print column dividers
            position++;
        }
        if (i < 2) printf("\n---|---|---\n"); // Print row dividers
    }
    printf("\n");
}

// Checks how many spaces are free
int freeSpace() {
    int empty = 9;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != ' ') empty--;
    return empty;
}

// CPU randomly selects an empty spot
void moveComputer() {
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != ' ');
    board[x][y] = 'O';
}

// Handles player's move (now uses 1-9 input)
void movePlayer() {
    int pos;
    do {
        printf("\nEnter position (1-9): ");
        scanf_s("%d", &pos);

        if (pos < 1 || pos > 9) {
            printf("Invalid input! Try again.\n");
            continue;
        }

        int x = (pos - 1) / 3;
        int y = (pos - 1) % 3;

        if (board[x][y] != ' ') {
            printf("Position already taken! Try again.\n");
        }
        else {
            board[x][y] = 'X';
            break;
        }
    } while (1);
}

// Checks for a winning condition
char checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0]; // Check rows
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i]; // Check columns
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0]; // Check diagonal
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2]; // Check diagonal
    return ' ';
}

// Displays the game result
void printWin() {
    char winner = checkWin();
    if (winner == 'X')
        printf("\nYou Win!!!\n");
    else if (winner == 'O')
        printf("\nCPU Wins!!!\n");
    else
        printf("\nIt's a tie!\n");
}
