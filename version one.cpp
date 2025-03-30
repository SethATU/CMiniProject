#include <iostream>
using namespace std;

// Define the Tic-Tac-Toe board and game variables
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

// Function to draw the Tic-Tac-Toe board
void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2) cout << "---|---|---\n"; // Draw horizontal dividers
    }
    cout << "\n";
}

// Function to place a marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    // Check if the chosen slot is available
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

// Function to check for a winner
int winner() {
    // Check rows and columns for a winning condition
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    // Check diagonals for a winning condition
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;
    return 0;
}

// Function to swap the current player and marker
void swapPlayerAndMarker() {
    current_marker = (current_marker == 'X') ? 'O' : 'X';
    current_player = (current_player == 1) ? 2 : 1;
}

// Main game function
void game() {
    string player1, player2;

    // Allow Player 1 to choose their marker
    cout << player1 << " choose your marker (X or O): ";
    cin >> current_marker;
    current_player = 1;
    if (current_marker != 'X' && current_marker != 'O') {
        cout << "Invalid marker! Defaulting to X.\n";
        current_marker = 'X';
    }

    drawBoard();
    for (int i = 0; i < 9; i++) {
        int slot;
        cout << "Player " << current_player << "'s turn. Enter your slot: ";
        cin >> slot;

        // Validate the move
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            i--; // Retry the move
            continue;
        }

        drawBoard();
        // Check if the current player has won
        if (winner()) {
            cout << "Player " << current_player << " wins!\n";
            return;
        }
        // Switch to the next player
        swapPlayerAndMarker();
    }
    cout << "It's a tie!\n";
}

// Main function to start the game
int main() {
    game();
    return 0;
}