#include "tictactoe.h"
#include <iostream>

TicTacToe::TicTacToe()
    : player(0),
    arrayGame{{-1, -1, -1},
              {-1, -1, -1},
              {-1, -1, -1}} // constructor initializer list
{

}

int TicTacToe::setPlayer() {
    return player == 0 ? player = 1 : player = 0;
}

int TicTacToe::getPlayer() {
    return player;
}

void TicTacToe::setArrayVal(int row, int col) {
    arrayGame[row][col] = player;
}

bool TicTacToe::checkWinner() {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (arrayGame[i][0] == arrayGame[i][1] && arrayGame[i][1] == arrayGame[i][2] && arrayGame[i][0] != -1) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (arrayGame[0][j] == arrayGame[1][j] && arrayGame[1][j] == arrayGame[2][j] && arrayGame[0][j] != -1) {
            return true;
        }
    }

    // Check diagonals
    if ((arrayGame[0][0] == arrayGame[1][1] && arrayGame[1][1] == arrayGame[2][2] && arrayGame[0][0] != -1) ||
        (arrayGame[0][2] == arrayGame[1][1] && arrayGame[1][1] == arrayGame[2][0] && arrayGame[0][2] != -1)) {
        return true;
    }

    return false; // No winner yet
}

bool TicTacToe::checkDraw() {
    // Check if all positions are filled
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arrayGame[i][j] == -1) {
                // If any position is empty, the game is not a draw
                return false;
            }
        }
    }

    // All positions are filled, it's a draw
    return true;
}
